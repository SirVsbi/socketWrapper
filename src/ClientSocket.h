//
// Created by szab on 11.10.2020.
//

#ifndef SOCKETWRAPPER_CLIENTSOCKET_H
#define SOCKETWRAPPER_CLIENTSOCKET_H

#include "Socket.h"
#include <netdb.h>
#include <string>


class ClientSocket : public Socket{
public:
    ClientSocket();
    ClientSocket(std::string host, int port);
    void connect(std::string host, int port);


private:
    struct sockaddr_in serverAddress;
    struct hostent* server;
};


#endif //SOCKETWRAPPER_CLIENTSOCKET_H
