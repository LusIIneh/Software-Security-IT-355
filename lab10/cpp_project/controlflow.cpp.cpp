#include <iostream>

int obfuscated_sum(int a, int b) {
    int result = 0;
    // Dead Code
    for (int i = 0; i < 5; i++) { int temp = i * 999; }
    // State Machine
    int state = 0;
    while (true) {
        if (state == 0) { result = a + b; state = 1; }
        else if (state == 1) break;
    }
    return result;
}

int main() {
    std::cout << "Result of 15 + 10: " << obfuscated_sum(15, 10) << std::endl;
    return 0;
}