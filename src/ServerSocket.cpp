//
// Created by szab on 11.10.2020.
//

#include <cstdio>
#include "ServerSocket.h"
#include "SocketException.h"
#include <string.h>

ServerSocket::ServerSocket() = default;

ServerSocket::ServerSocket(int port) : Socket(port) {
    this->serverAddress.sin_port = htons(port);
    this->serverAddress.sin_family = AF_INET; //use TCP
    this->serverAddress.sin_family = INADDR_ANY;

    setSocket(::socket(AF_INET, SOCK_STREAM, 0));

    //error handling
    int fileDescriptor;
    if(getSocket() < 0){
        throw SocketException("Error creating the socket");
    }

    //bind socket to port
    if(::bind(getSocket(), (struct sockaddr*) &this->serverAddress, sizeof(this->serverAddress))
           < 0 ){
        //@TODO: make std::perror() work with std::exception
        //throw SocketException("Error binding socket to port: ");
        std::perror("Error binding socket to port");
    }


}

void ServerSocket::listen() {
    ::listen(getSocket(), 5);
    memset(&this->clientAddress, 0, sizeof(this->clientAddress));
}

int ServerSocket::accept() {
    this->clientSocket = new Socket(::accept(getSocket(), (struct sockaddr*)&this->clientAddress, &this->clientLength));
    if(clientSocket->getSocket() < 0){
        //@TODO: Get the error code, with std::errno
        throw SocketException("Error connecting client with the server");
    }
}

sockaddr_in *ServerSocket::getClientInfo() {
    return &this->clientAddress;
}

/*
int ServerSocket::recieveInt() {
    uint32_t a;
    recv(this->clientFd, (char*)&a, sizeof(a), 0);
    a = ntohl(a);
    return a;
}
 */

const Socket* ServerSocket::getClientSocket() const{
    return this->clientSocket;
}




