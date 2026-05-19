#include <iostream>
#include <windows.h>

// Instruction Substitution 
#define OBF_ADD(a,b) ((a ^ b) + 2*(a & b))

int main() {
    if (IsDebuggerPresent()) {
        std::cout << "Debugger detected! Closing program." << std::endl;
        return 1;
    }

    std::cout << "Secure calculation result: " << OBF_ADD(100, 200) << std::endl;
    return 0;
}