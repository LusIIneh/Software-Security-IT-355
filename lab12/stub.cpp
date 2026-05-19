#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h> // IsDebuggerPresent-? ?????

using namespace std;

void xor_decrypt(vector<char>& data, char key) {
    for (auto& b : data) b ^= key;
}

int main() {
    // Anti-debugging check
    if (IsDebuggerPresent()) {
        cout << "Debugger detected! Exiting..." << endl;
        return 1;
    }

    ifstream file("packed.bin", ios::binary);
    if (!file) { cout << "Error: packed.bin missing!"; return 1; }

    vector<char> data((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    xor_decrypt(data, 0xAA);

    ofstream out("unpacked_temp.exe", ios::binary);
    out.write(data.data(), data.size());
    out.close();

    cout << "Unpacking and launching..." << endl;
    system("unpacked_temp.exe");

    // Cleanup
    remove("unpacked_temp.exe");
    return 0;
}