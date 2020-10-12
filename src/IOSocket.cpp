//
// Created by szab on 11.10.2020.
//

#include <utility>
#include "IOSocket.h"
#include "SocketException.h"
/*
using namespace ezSocket;

IOSocket::IOSocket(int socket) : Socket(socket) {

}

IOSocket::~IOSocket() {
    delete[] buffer;
}

void IOSocket::sendString(const std::string& message) {
    const unsigned char* message_cStr = (unsigned char*)message.c_str();
    this->sendMessage(message_cStr, message.length());
}

std::string IOSocket::getMessage() {
    std::pair<const unsigned char*, int> messagePair(getMessageAndLength());
    std::string returnString((char*)std::get<0>(messagePair), std::get<1>(messagePair));
    return returnString;
}



IOSocket::IOSocket() {

}

const unsigned char *IOSocket::getMessage(int length) {
    int messageLength = this->readMessageLength();
    if(messageLength != length){
        throw SocketException("The internet is a time sink. The internet is also a package sink");
    }
    this->readMessage(length);
    return buffer;
}

std::pair<const unsigned char *, int> IOSocket::getMessageAndLength() {
    int messageLength = this->readMessageLength();
    readMessage(messageLength);
    std::pair<const unsigned char*, int> message(buffer, messageLength);
    return message;
}




int IOSocket::readMessageLength() {
    int messageLength = 0;
    int bytesRead = 0;
    int totalBytesRead = 0;
    while(totalBytesRead < 4 && messageLength == 0){
        bytesRead = ::read(getSocket(), &messageLength + totalBytesRead, 4 - totalBytesRead);
        if(bytesRead < 0){
            throw SocketException("Error reading length of the message");
        }
        else if(bytesRead == 0){
            throw SocketException("Disconnected");
        }
        totalBytesRead += bytesRead;
    }
    return messageLength;
}

void IOSocket::writeMessage(const unsigned char *message, int length) {
    int bytesWritten = 0;
    int totalBytesWritten = 0;
    while(totalBytesWritten < length){

    }
}

*/



