#include "random_randint.h"
#include <random>
#include <chrono>

int random_randint(int start, int end) {
    static std::default_random_engine engine(
        std::chrono::steady_clock::now().time_since_epoch().count()
    );
    std::uniform_int_distribution<int> distInt(start, end);
    return distInt(engine);
}
