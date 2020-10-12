//
// Created by szab on 11.10.2020.
//

#ifndef SOCKETWRAPPER_SOCKETEXCEPTION_H
#define SOCKETWRAPPER_SOCKETEXCEPTION_H

#include <exception>

class SocketException : public std::exception {
public:
    explicit SocketException(const char* message);
    [[nodiscard]] const char* what() const noexcept override;

private:
    const char* message;
};


#endif //SOCKETWRAPPER_SOCKETEXCEPTION_H
