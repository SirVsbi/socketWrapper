//
// Created by szab on 11.10.2020.
//

#include <string>
#include <cstring>
#include "Socket.h"
#include "SocketException.h"

//using namespace ezSocket;


Socket::Socket() = default;


Socket::Socket(int _fd) {
    setSocket(_fd);
}

void Socket::setSocket(int _fd) {
    this->fd = _fd;
}


int Socket::getSocket() const {
    return this->fd;
}


Socket::~Socket() {
    ::close(fd);

}

/*void Socket::send(const char *data, unsigned int length) {
    const char *buffer = data;
    int bytesSent = 0;
    int bytesLeftToSend = length;
    int status = 0;
    while (bytesSent < length) {
        status = ::send(this->getSocket(), buffer + bytesSent, bytesLeftToSend, 0);
        if (status == -1) {
            throw SocketException(std::string(std::strerror(errno)).c_str());
        } else {
            bytesSent += status;
            bytesLeftToSend -= status;
        }
    }
}*/

bool Socket::recieve(char *msg, int len) {
    int status;
    status = ::recv(this->getSocket(), msg, len, 0);
    if (status == 0)
        return false;
    return true;
}


void Socket::sendInt(int data){
   uint32_t sent = htonl(data);
    send(this->getSocket(), &sent, sizeof(sent), 0);
}


uint32_t Socket::getint_32_t(const Socket* listeningSocket){
    uint32_t a;
    recv(listeningSocket->getSocket(), (char*)&a, sizeof(a), 0);
    a = ntohl(a);
    return a;
}

Socket::Socket(Socket* pSocket) {
    this->setSocket(pSocket->getSocket());

}







