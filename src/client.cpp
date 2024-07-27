#include "../include/client.h"
#include <string>
#include <sys/socket.h>
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <unistd.h>
#include <fstream>
#include "../include/htmlreader.h"
//Response
void clientHandler(int clientSocket){
    std::string filePath = "../html/index.html";
    std::string fileContent = getFileContent(filePath);
    // Prepare the HTTP Response
    std::string response = "HTTP/1.1 200 OK\r\n";
    response += "Content-Type: text/html\r\n";
    response += "Content-Length: " + std::to_string(fileContent.size()) + "\r\n";
    response += "\r\n"; // End of headers
    response += fileContent; // Add file content
    send(clientSocket,response.c_str(),response.size(),0);
    close(clientSocket);  
}
