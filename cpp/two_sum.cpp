// Function to find all pairs in a list of integers that can make a given sum

#include <cassert>
#include <iostream>
#include <vector>


// Helper struct to make code more readable
struct SumPair {
    int x;
    int y;
};


// Returns list of integer pairs that make the input sum. Assumes input vector is sorted.
std::vector<SumPair> TwoSum(const std::vector<int>& values, int sum) {
    // Initialize result vector
    std::vector<SumPair> result;

    // Initialize left and right indexes starting at the front and back of the vector
    int right = values.size() - 1;
    int left = 0;

    // For loop advancing left index
    for (; left < right; ++left) {
        // Calculate the number we are looking for
        int target = sum - values[left];

        // While loop decrementing the right index while the values are equal or greater than the target number
        while (values[right] >= target && left < right) {
            // Check if solution
            if (values[right] == target) {
                result.emplace_back(SumPair{values[left], values[right]});
            }
            --right;
        }
    }

    return result;
}


void TestTwoSum() {
    std::vector<int> values;
    std::vector<SumPair> result;

    std::cout << "Testing empty list..." << std::endl;
    values = {};
    result = TwoSum(values, 0);
    assert(result.empty());
    std::cout << "=== Success ===" << std::endl;

    std::cout << "Testing mixed values..." << std::endl;
    values = {-3, -2, -1, 0, 1, 2, 3};
    result = TwoSum(values, 0);
    assert(result.size() == 3);
    assert(result[0].x == -3);
    assert(result[0].y == 3);
    assert(result[1].x == -2);
    assert(result[1].y == 2);
    assert(result[2].x == -1);
    assert(result[2].y == 1);
    std::cout << "=== Success ===" << std::endl;

    std::cout << "Testing negative sum..." << std::endl;
    values = {-30, -15, -9, -1, 5, 11, 20};
    result = TwoSum(values, -10);
    assert(result.size() == 3);
    assert(result[0].x == -30);
    assert(result[0].y == 20);
    assert(result[1].x == -15);
    assert(result[1].y == 5);
    assert(result[2].x == -9);
    assert(result[2].y == -1);
    std::cout << "=== Success ===" << std::endl;

    std::cout << "Testing positive sum..." << std::endl;
    values = {0, 8, 11, 14, 15, 23, 27, 29, 59, 60, 7009};
    result = TwoSum(values, 29);
    assert(result.size() == 2);
    assert(result[0].x == 0);
    assert(result[0].y == 29);
    assert(result[1].x == 14);
    assert(result[1].y == 15);
    std::cout << "=== Success ===" << std::endl;
}


int main() {
    TestTwoSum();
}
