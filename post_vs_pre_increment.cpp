#include <iostream>
#include <chrono>

int main(void) {
    int p = 0;

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000000; ++i) {
        p++;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration_p = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "p++ took " << duration_p << " milliseconds\n";
    
    p = 0; 
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000000; ++i) {
        ++p;
    }
    end = std::chrono::high_resolution_clock::now();
    auto duration_prefix = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "++p took " << duration_prefix << " milliseconds\n";
    
    return 0;
}
