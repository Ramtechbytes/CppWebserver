#include <fstream>
#include "../include/logger.h"

void log(std::string IP){
    std::fstream MyFile("../log.txt", std::ios::app);

    MyFile << IP << " connected to this server." <<std::endl;

    MyFile.close();
}