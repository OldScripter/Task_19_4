#include <iostream>
#include <fstream>
#include <string>

/*
 * Return true if file is .png.
 */
bool checkIfPng(std::ifstream& stream)
{
    if (stream.is_open())
    {
        char buffer[4];
        stream.read(buffer, 4);
        return ((int)buffer[0] == -119 && buffer[1] == 'P' && buffer[2] == 'N' && buffer[3] == 'G');
    }
    else
    {
        std::cerr << "File read error! Check path or file.\n";
        return false;
    }


}

int main() {
    const int EXTENSION_LENGTH = 4;
    std::ifstream stream;
    std::string path;
    do
    {
        std::cout << "Enter the path: ";
        //Use for test ..\\test.png
        getline(std::cin, path);
        stream.open(path, std::ios::binary);
        if (!stream.is_open()) std::cout << "Bad path or file. Try again.\n";
    }
    while (!stream.is_open());
    
    std::cout << "...Analysing the file extension...\n";
        std::string extension;
    if (path.size() >= 4)
    {
        extension = path.substr(path.size() - EXTENSION_LENGTH, EXTENSION_LENGTH);
        if (extension[0] == '.' &&
            (extension[1] == 'p' || extension[1] == 'P') &&
            (extension[2] == 'n' || extension[2] == 'N') &&
            (extension[3] == 'g' || extension[3] == 'G'))
            std::cout << "File extension is .png\n";
        else
            std::cout << "File extension is NOT .png\n";
    }
    else
        std::cout << "Bad file extension.\n";

    std::cout << "...Analysing the file content...\n";
    std::cout << "File " << (checkIfPng(stream) ? "is " : "is NOT ") << "PNG.\n";

    stream.close();
    return 0;
}
