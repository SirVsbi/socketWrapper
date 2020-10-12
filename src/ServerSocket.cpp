//
// Created by szab on 11.10.2020.
//

#include <cstdio>
#include "ServerSocket.h"
#include "SocketException.h"
#include <cstring>
#include <iostream>
#include <algorithm>

ServerSocket::ServerSocket() = default;

ServerSocket::ServerSocket(int port) : Socket(port) {
    this->serverAddress.sin_port = htons(port);
    this->serverAddress.sin_family = AF_INET; //use TCP
    this->serverAddress.sin_addr.s_addr = INADDR_ANY;

    setSocket(::socket(AF_INET, SOCK_STREAM, 0));

    //error handling
    if(this->getSocket() < 0){
        throw SocketException("Error creating the socket");
    }

    //bind socket to port
    if(::bind(getSocket(), (struct sockaddr*) &this->serverAddress, sizeof(serverAddress))
           < 0 ){
        //@TODO: make std::perror() work with std::exception
        //throw SocketException("Error binding socket to port: ");
        std::perror("Error binding socket to port");
    }

}

void ServerSocket::listen() {
    ::listen(this->getSocket(), 5);
     memset(&this->clientAddress, 0, sizeof(this->clientAddress));
}

Socket* ServerSocket::accept() {
    socklen_t address_size = sizeof(this->clientAddress);
    auto* newClientSocket = new Socket(::accept(this->getSocket(), (struct sockaddr*)&this->clientAddress, &address_size));
    if(newClientSocket->getSocket() < 0){
        //@TODO: Get the error code, with std::errno
        throw SocketException("Error connecting client with the server");
    }

    this->threads.emplace_back(new std::thread(&ServerSocket::handleClient, this, newClientSocket))->detach();



    return newClientSocket;
}

sockaddr_in* ServerSocket::getClientInfo() {
    return &this->clientAddress;
}


const Socket* ServerSocket::getClientSocket() const{
    return this->clientSocket;
}

void ServerSocket::handleClient(Socket* clientSocket) {
    try{
        int a = this->getint_32_t(clientSocket);
        std::cout << a;

    }catch(std::exception& e){
        std::cout << e.what();
    }

    //@TODO put the vector in a mutex
    using uniquePtr = std::unique_ptr<std::thread>;
    auto iterator = std::find_if(this->threads.begin(), this->threads.end(), [&](uniquePtr& ptr){ return ptr->get_id() == std::this_thread::get_id();});
    this->threads.erase(iterator);


}




