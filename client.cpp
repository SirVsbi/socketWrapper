//
// Created by szab on 11.10.2020.
//

#include <iostream>
#include "src/ClientSocket.h"

int main(){
    try{
        ClientSocket socket("test", 25565);
        uint32_t sent = 42;
        socket.sendInt(sent);
    }catch(std::exception& e){
        std::cout << e.what();
    }
}