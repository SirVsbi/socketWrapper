#include <iostream>
#include <libnet.h>
#include "src/ServerSocket.h"




int main() {
    try {
        ServerSocket socket(25566);
        socket.listen();
        for(;;) {
            socket.accept();
        }
    } catch (std::exception& e) {
        std::cout << e.what();

    }
}


