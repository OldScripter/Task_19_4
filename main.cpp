#include <iostream>
#include <fstream>
#include <cassert>
#include <string>

/*
 * Return true if file is .png.
 */
bool checkIfPng(std::ifstream& stream)
{
    assert(stream.is_open());
    char buffer[4];
    stream.read(buffer, 4);
    if ((int)buffer[0] == -119 && buffer[1] == 'P' && buffer[2] == 'N' && buffer[3] == 'G')
        return true;
    else
        return false;
}

int main() {
    std::ifstream stream;
    std::string path;
    do
    {
        std::cout << "Enter the path: ";
        getline(std::cin, path);
        stream.open(path, std::ios::binary);
        if (!stream.is_open()) std::cout << "Bad path or file. Try again.\n";
    }
    while (!stream.is_open());

    std::string extension = path.substr(path.size() - 3, 3);
    if ((extension[0] == 'p' || extension[0] == 'P') &&
        (extension[1] == 'n' || extension[1] == 'N') &&
        (extension[2] == 'g' || extension[2] == 'G'))
        std::cout << "File extension is .png\n";
    else
        std::cout << "File extension is NOT .png\n";

    std::cout << "Analysing the file content...\n";
    std::cout << "File " << (checkIfPng(stream) ? "is " : "is NOT ") << "PNG.\n";

    stream.close();
    return 0;
}
