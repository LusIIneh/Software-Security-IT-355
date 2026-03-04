#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// --- ENCODE ---
string RLE1_encode(const string& input) {
    string result = "";
    int n = input.length();

    for (int i = 0; i < n; i++) {
        int count = 1;

        while (i < n - 1 && input[i] == input[i + 1]) {
            count++;
            i++;
        }

        result += char(count);
        result += input[i];
    }

    return result;
}

// --- DECODE ---
string RLE1_decode(const string& input) {
    string result = "";
    int n = input.length();
    int i = 0;

    while (i < n) {
        int count = 0;
        count = input[i]
        result.append(count, input[i + 1]);
        i += 2;
    }

    return result;
}

int main() {
    string text;

    cout << "Enter text: ";
    cin >> text;

    string encoded = RLE1_encode(text);
    cout << "Encoded: " << encoded << endl;

    cout << "Decoded: " << RLE1_decode(encoded) << endl;

    return 0;

}
