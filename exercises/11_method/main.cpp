#include "../exercise.h"

struct Fibonacci {
    unsigned long long cache[128];
    int cached;

    unsigned long long get(int i) {
        if (cached < i) {
            for (int j = cached; j <= i; j++) {
                if (j == 0) {
                    cache[j] = 0;
                } else if (j == 1) {
                    cache[j] = 1;
                } else {
                    cache[j] = cache[j - 1] + cache[j - 2];
                }
            }
            cached = i;
        }
        return cache[i];
    }
};

int main(int argc, char **argv) {
    // TODO: 初始化缓存结构体，使计算正确
    Fibonacci fib{};
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}
