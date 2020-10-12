#include <iostream>
#include <libnet.h>
#include "src/ServerSocket.h"
int main() {
    try {
        ServerSocket socket(25565);
        socket.listen();
        socket.accept();
        sockaddr_in* clientInfo = socket.getClientInfo();
        std::cout << "Client connected from: " << inet_ntoa(clientInfo->sin_addr) << ":" << clientInfo->sin_port << '\n';
        int a = socket.getint_32_t(socket.getClientSocket());
        std::cout << a;

    } catch (std::exception& e) {
        std::cout << e.what();

    }
}


