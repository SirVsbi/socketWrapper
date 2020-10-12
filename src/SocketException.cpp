//
// Created by szab on 11.10.2020.
//

#include "SocketException.h"


SocketException::SocketException(const char* message) {
    this->message = message;
}

const char* SocketException::what() const noexcept{
    return this->message;
}