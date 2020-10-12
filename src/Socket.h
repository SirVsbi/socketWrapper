//
// Created by szab on 11.10.2020.
//

#ifndef SOCKETWRAPPER_SOCKET_H
#define SOCKETWRAPPER_SOCKET_H


#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


class Socket {

public:
    //void send(const char *data, unsigned int length);

    Socket(Socket *pSocket);

    bool recieve(char *msg, int len);

    void sendInt(int data);

    uint32_t getint_32_t(const Socket* listeningSocket);

    explicit Socket(int);


    ~Socket();

/*
 * returns the file descriptor
 */
[[nodiscard]] int getSocket() const;

    Socket();

protected:


    /*
     * Sets the file descriptor of the socket
     */
    void setSocket(int);


private:
    int fd{};


};


#endif //SOCKETWRAPPER_SOCKET_H
