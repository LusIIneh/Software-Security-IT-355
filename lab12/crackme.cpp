#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

bool check_password(string input) {
    // "secret" encoded with XOR 0x55
    // s=115, e=101, c=99, r=114, e=101, t=116
    // Results after ^ 0x55: 30, 50, 46, 39, 50, 33
    int key[] = { 30, 50, 46, 39, 50, 33 };
    if (input.length() != 6) return false;

    for (int i = 0; i < 6; i++) {
        if ((input[i] ^ 0x55) != key[i]) return false;
    }
    return true;
}

int main() {
    if (IsDebuggerPresent()) {
        cout << "Don't debug me!" << endl;
        return 1;
    }

    string pass;
    cout << "--- CRACKME LEVEL 1 ---" << endl;
    cout << "Enter Password: ";
    cin >> pass;

    if (check_password(pass)) {
        cout << "ACCESS GRANTED! You are a pro hacker." << endl;
    }
    else {
        cout << "ACCESS DENIED!" << endl;
    }
    system("pause");
    return 0;
}