#include <iostream>
//#include <cstddef>
#include<chrono>

int main() {
    std::cout << "size_t is " << sizeof(size_t) * 8 << " bits.\n";
    std::cout << "int is " << sizeof(int) * 8 << " bits.\n";

    if constexpr (std::is_same_v<std::chrono::high_resolution_clock, std::chrono::steady_clock>) {
        std::cout << "std::high_resolution_clock is std::chrono::steady_clock\n";
    } else if constexpr (std::is_same_v<std::chrono::high_resolution_clock, std::chrono::system_clock>) {
        std::cout << "std::high_resolution_clock is std::chrono::system_clock\n";
    } else {
        std::cout << "std::high_resolution_clock is a separate clock type\n";
    }
    return 0;
}
