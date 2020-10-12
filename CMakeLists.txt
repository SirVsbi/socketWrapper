cmake_minimum_required(VERSION 3.17)
project(socketWrapper)

set(CMAKE_CXX_STANDARD 20)

add_executable(socketWrapper main.cpp src/Socket.cpp src/Socket.h src/ServerSocket.cpp src/ServerSocket.h src/SocketException.cpp src/SocketException.h src/IOSocket.cpp src/IOSocket.h)
add_executable(client client.cpp src/Socket.cpp src/Socket.h src/ServerSocket.cpp src/ServerSocket.h src/SocketException.cpp src/SocketException.h src/IOSocket.cpp src/IOSocket.h src/ClientSocket.cpp src/ClientSocket.h)