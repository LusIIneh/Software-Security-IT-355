#include <iostream>

int main() {
    char data = 'A';
    int key = 50;
    char encoded = data ^ key;
    char decoded = encoded ^ key;

    std::cout << "Original: " << data << "\nEncoded: " << (int)encoded << "\nDecoded: " << decoded << std::endl;
    return 0;
}