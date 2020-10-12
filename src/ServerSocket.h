//
// Created by szab on 11.10.2020.
//

#ifndef SOCKETWRAPPER_SERVERSOCKET_H
#define SOCKETWRAPPER_SERVERSOCKET_H

#include "Socket.h"

    class ServerSocket : public Socket {

    public:
        ServerSocket();

        ServerSocket(int port);

        void listen();

        int accept();

        sockaddr_in* getClientInfo();

        int test();

        int recieveInt();

        [[nodiscard]] const Socket* getClientSocket() const;

    private:
        struct sockaddr_in serverAddress{}, clientAddress{};
        socklen_t clientLength;
        Socket* clientSocket;

    };


#endif //SOCKETWRAPPER_SERVERSOCKET_H

