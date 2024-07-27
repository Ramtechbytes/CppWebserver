#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <unistd.h>
#include <fstream>
#include <string>
#include "../include/htmlreader.h"
#include "../include/client.h"
#include "../include/logger.h"


int main(){

    //Create the Socket
    int serverSocket = socket(AF_INET, SOCK_STREAM,0);

    //Define the Server Address
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    //bind ip and port
    bind(serverSocket, (struct sockaddr*)&serverAddress,
    sizeof(serverAddress));

    //Listen for connections
    listen(serverSocket, 5);

    std::cout << "Server Running on port 8080" << std::endl;

    //Accept Connection
    while(true){
        int clientSocket = accept(serverSocket, nullptr, nullptr);

        sockaddr clientAddr;

        std::string IP = inet_ntoa(((sockaddr_in*)&clientAddr)->sin_addr);

        log(IP);

        std::cout<< IP << " connected to this server."<<std::endl;
        clientHandler(clientSocket);
    }


    return 0;
    
}