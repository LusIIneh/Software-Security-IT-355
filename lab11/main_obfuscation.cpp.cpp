#include <iostream>
#include <cstdarg>
#include <vector>

using namespace std;

// ---  Argument Count Obfuscation ---

// 1. Packed Parameters (2 tiv mekum)
int obf_add_packed(int packed) {
    int a = (packed >> 16) & 0xFFFF;
    int b = packed & 0xFFFF;
    return a + b;
}

// 2. Variadic Functions 
int obf_add_variadic(int count, ...) {
    va_list args;
    va_start(args, count);
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += va_arg(args, int);
    }
    va_end(args);
    return sum;
}

// --- Code Scattering ---

int part_logic_1(int x) { return x * 10; }
int part_logic_2(int x) { return x + 5; }

void run_scattered_logic() {
    // functionneri hascenery pahvum en zangvacnerum (Dispatch table)
    int (*functions[])(int) = { part_logic_1, part_logic_2 };

    int val = 5;
    int step1 = functions[0](val);   // calls part_logic_1
    int final_res = functions[1](step1); // callls part_logic_2

    cout << "Scattered Result: " << final_res << endl;
}

int main() {
    cout << "--- Argument Obfuscation ---" << endl;
    int p = (10 << 16) | 20;
    cout << "Packed Add (10+20): " << obf_add_packed(p) << endl;
    cout << "Variadic Add (5+5+5): " << obf_add_variadic(3, 5, 5, 5) << endl;

    cout << "\n--- Code Scattering ---" << endl;
    run_scattered_logic();

    return 0;
}