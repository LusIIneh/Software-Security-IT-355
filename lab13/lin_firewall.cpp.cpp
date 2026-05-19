#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void blockPort(int port) {
    string command = "sudo iptables -A INPUT -p tcp --dport " + to_string(port) + " -j DROP";
    int result = system(command.c_str());
    if (result == 0) {
        cout << "Port " << port << " has been blocked successfully." << endl;
    }
    else {
        cout << "Failed to block port. (Run with sudo)" << endl;
    }
}

void listRules() {
    cout << "\n--- Current Iptables Rules ---" << endl;
    system("sudo iptables -L -n -v");
}

int main() {
    int choice, port;
    cout << "1. Block a Port\n2. View Rules\n3. Exit\nChoice: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter port to block: ";
        cin >> port;
        blockPort(port);
    }
    else if (choice == 2) {
        listRules();
    }

    return 0;
}