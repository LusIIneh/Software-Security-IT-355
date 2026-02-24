#include <iostream>
#include <cstdlib>

using namespace std;

int main() {

    cout << "====================" << endl;
    cout << "SYSTEM INFORMATION" << endl;
    cout << "====================" << endl;

    cout << "\nCPU INFO:" << endl;
    system("lscpu | grep 'Model name'");

    cout << "\nMEMORY INFO:" << endl;
    system("free -h");

    cout << "\nDISK INFO:" << endl;
    system("lsblk");

    cout << "\nMAC ADDRESS:" << endl;
    system("ip link | grep link/ether");

    cout << "\nOS VERSION:" << endl;
    system("uname -a");

    return 0;
}
