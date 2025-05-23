#include <iostream>
#include <cstring>
#include <cstdlib>

// バッファオーバーフローを意図的に発生
void vulnerable_copy(const char* input) {
    char buffer[8];
    strcpy(buffer, input);  // ✅ CodeQLが検出（CWE-121: Stack-based Buffer Overflow）
    std::cout << "Copied: " << buffer << std::endl;
}

// メモリリークの例
void memory_leak() {
    char* data = (char*)malloc(100);
    strcpy(data, "Leaked memory");  // ✅ CodeQLが検出（CWE-401: Memory Leak）
    // free(data); ←解放しない
}

// 未使用の関数（品質指摘対象）
void unused_function() {
    std::cout << "This function is never used." << std::endl;  // ✅ CodeQLが検出
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ./main <input>" << std::endl;
        return 1;
    }

    vulnerable_copy(argv[1]);
    memory_leak();

    return 0;
}
