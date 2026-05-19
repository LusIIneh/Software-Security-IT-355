#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void xor_encrypt(vector<char>& data, char key) {
    for (auto& b : data) b ^= key;
}

int main() {
    string input = "hello.exe";
    string output = "packed.bin";
    char key = 0xAA;

    ifstream file(input, ios::binary);
    if (!file) { cout << "Error: hello.exe not found!"; return 1; }

    vector<char> data((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    xor_encrypt(data, key);

    ofstream out(output, ios::binary);
    out.write(data.data(), data.size());
    out.close();

    cout << "Success: hello.exe was XORed and saved as packed.bin" << endl;
    return 0;
}