//
// Created by szab on 11.10.2020.
//

#include <libnet.h>
#include "ClientSocket.h"
#include "SocketException.h"

ClientSocket::ClientSocket() {

}

ClientSocket::ClientSocket(std::string host, int port) {
    //creating socket
    setSocket(::socket(AF_INET, SOCK_STREAM, 0));
    this->connect(host, port);
}

void ClientSocket::connect(std::string host, int port) {


    this->serverAddress.sin_port = htons(port);
    this->serverAddress.sin_family = AF_INET;
    this->serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(getSocket() < 0){
        throw SocketException("Error creating socket");
    }
    if(::connect(getSocket(), (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0){
        throw SocketException("Error connecting to ther server");
    }


}




