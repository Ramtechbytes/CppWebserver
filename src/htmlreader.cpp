#include <fstream>
#include "../include/htmlreader.h"
#include <string>

std::string getFileContent(const std::string& filePath){
    std::ifstream file(filePath, std::ios::in | std::ios::binary | std::ios::ate);

    std::streampos size = file.tellg();
    file.seekg(0, std::ios::beg);

    std::string content(size, '\0');
    file.read(&content[0], size);
    file.close();

    return content;
}