//
// Created by szab on 11.10.2020.
//

#ifndef SOCKETWRAPPER_IOSOCKET_H
#define SOCKETWRAPPER_IOSOCKET_H


#include <string>
#include "Socket.h"

namespace ezSocket {

    class IOSocket : public Socket {
    public:
        IOSocket(int socket);
        ~IOSocket();
        virtual void sendString(const std::string& message);
        virtual std::string getMessage();

    protected:
        IOSocket();
        const unsigned char* getMessage(int length); //get buffer with given length
        std::pair<const unsigned char*, int> getMessageAndLength(); //get length of the buffer and the buffer
        void sendMessage(const unsigned char* message, int length);

    private:
        int bufferSize{};
        unsigned char* buffer{};
        int readMessageLength();
        void readMessage(int length);
        void writeMessage(const unsigned char* message, int length);


    };

}




#endif //SOCKETWRAPPER_IOSOCKET_H




