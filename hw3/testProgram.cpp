#include "printbits.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

void testInts() {
    int arr[] = { 1, 0, -1, -10000202, 12301923, 1000000000 };
    std::cout << "Testing integer representation:\n";

    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        std::cout << arr[i] << ":\n";
        std::cout << "LE: ";
        printlebits(&arr[i], sizeof(arr[i]));
        std::cout << "\nBE: ";
        printbebits(&arr[i], sizeof(arr[i]));
        std::cout << "\n\n";
    }
}

void testFloats() {
    float arr[] = { 1., 2., 4., 0.25, 0.125, 0.333, 0.1, 1e14, 2e14 };
    std::cout << "Testing floating point representation:\n";

    for (int i = 0; i < sizeof(arr) / sizeof(float); i++) {
        std::cout << arr[i] << ":\n";
        std::cout << "LE: ";
        printlebits(&arr[i], sizeof(arr[i]));
        std::cout << "\nBE: ";
        printbebits(&arr[i], sizeof(arr[i]));
        std::cout << "\n\n";
    }
}

void testStrings() {
    std::vector<std::string> myStrs = { "this is", "wordle" };
    
    for (int i = 0; i < myStrs.size(); i++) {
        std::cout << myStrs.at(i) << ":\n";
        std::cout << "LE: ";
        printlebits(&myStrs.at(i), myStrs.at(i).length());
        std::cout << "\nBE: ";
        printbebits(&myStrs.at(i), myStrs.at(i).length());
        std::cout << "\n\n";
    }
}

int main() {
    testInts();
    testFloats();
    testStrings();

    return 0;
}
