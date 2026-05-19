#include <iostream>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

// 1. VM-Based Obfuscator (Custom Bytecode Interpreter)
enum OpCodes { OP_PUSH, OP_ADD, OP_PRINT, OP_HALT };

void virtual_machine(vector<int> bytecode) {
    vector<int> stack;
    int pc = 0;
    while (bytecode[pc] != OP_HALT) {
        switch (bytecode[pc]) {
        case OP_PUSH: stack.push_back(bytecode[++pc]); break;
        case OP_ADD: {
            int a = stack.back(); stack.pop_back();
            int b = stack.back(); stack.pop_back();
            stack.push_back(a + b);
            break;
        }
        case OP_PRINT: cout << "VM Output: " << stack.back() << endl; break;
        }
        pc++;
    }
}

// 2. Control Flow Flattening (kodi hajordakanutyan xaxtum)
void flattened_logic(int x) {
    int state = 1;
    while (state != 0) {
        switch (state) {
        case 1: x += 10; state = 3; break;
        case 2: cout << "Flattened Result: " << x << endl; state = 0; break;
        case 3: x *= 2; state = 2; break;
        }
    }
}

// 3. Anti-Debugging
void check_debugger() {
#ifdef _WIN32
    if (IsDebuggerPresent()) {
        cout << "DEBUGGER DETECTED! Exiting..." << endl;
        exit(1);
    }
    else {
        cout << "No debugger detected. Safe to run." << endl;
    }
#else
    cout << "Anti-debug check skipped (Non-Windows system)." << endl;
#endif
}

int main() {
    cout << "--- Advanced Protection ---" << endl;
    check_debugger();

    cout << "\n1. Custom VM Execution:" << endl;
    // Bytecode for: PUSH 10, PUSH 20, ADD, PRINT, HALT
    vector<int> code = { OP_PUSH, 10, OP_PUSH, 20, OP_ADD, OP_PRINT, OP_HALT };
    virtual_machine(code);

    cout << "\n2. Control Flow Flattening:" << endl;
    flattened_logic(5);

    return 0;
}