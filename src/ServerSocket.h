//
// Created by szab on 11.10.2020.
//

#ifndef SOCKETWRAPPER_SERVERSOCKET_H
#define SOCKETWRAPPER_SERVERSOCKET_H

#include <vector>
#include <thread>
#include "Socket.h"

    class ServerSocket : public Socket {

    public:
        ServerSocket();

        explicit ServerSocket(int port);

        void listen();

        Socket* accept();

        sockaddr_in* getClientInfo();

        [[nodiscard]] const Socket* getClientSocket() const;


        void handleClient( Socket* clientSocket);

    private:
        struct sockaddr_in serverAddress{};
        struct sockaddr_in clientAddress{};
        socklen_t clientLength{};
        Socket* clientSocket{};
        std::vector<std::unique_ptr<std::thread>> threads;
    };


#endif //SOCKETWRAPPER_SERVERSOCKET_H

