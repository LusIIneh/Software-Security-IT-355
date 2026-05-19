#include <iostream>
#include <string>
#include <vector>

std::vector<int> xor_encode(const std::string& text, int key) {
    std::vector<int> encoded;
    for (char c : text) encoded.push_back(c ^ key);
    return encoded;
}

std::string xor_decode(const std::vector<int>& encoded, int key) {
    std::string decoded = "";
    for (int val : encoded) decoded += (char)(val ^ key);
    return decoded;
}

int main() {
    std::string secret = "MyPassword123";
    int key = 42;
    std::vector<int> encrypted = xor_encode(secret, key);

    std::cout << "Encrypted: ";
    for (int n : encrypted) std::cout << n << " ";
    std::cout << "\nDecrypted: " << xor_decode(encrypted, key) << std::endl;
    return 0;
}