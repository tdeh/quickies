// Function to count how many ways to make a number using 1's, 2's, or 3's

#include <cassert>
#include <iostream>
#include <vector>


// Function to count how many ways to make a number using 1's, 2's, or 3's
int WaysToMake(int number, std::vector<int>& memo) {
    if (number < 0) {
        return 0;
    } else if (number == 0) {
        return 1;
    } else if (memo[number] != -1) {
        return memo[number];
    } else {
        int result = WaysToMake(number-1, memo) + WaysToMake(number-2, memo) + WaysToMake(number-3, memo);
        memo[number] = result;
        return result;
    }
}


// Entry point for WaysToMake
int WaysToMake(int number) {
    if (number <= 0) {
        return 0;
    }

    std::vector<int> memo(number + 1, -1);
    return WaysToMake(number, memo);
}


void TestWaysToMake() {
    // Test edge cases
    std::cout << "Testing edge cases..." << std::endl;
    assert(WaysToMake(-1) == 0);
    assert(WaysToMake(0) == 0);
    assert(WaysToMake(-10989752) == 0);
    std::cout << "=== Success ===" << std::endl;

    std::cout << "Testing simple cases..." << std::endl;
    assert(WaysToMake(1) == 1);
    assert(WaysToMake(2) == 2);
    assert(WaysToMake(3) == 4);
    std::cout << "=== Success ===" << std::endl;

    std::cout << "Testing complex cases..." << std::endl;
    assert(WaysToMake(15) == 5768);
    std::cout << "=== Success ===" << std::endl;
}


int main() {
    TestWaysToMake();
}
