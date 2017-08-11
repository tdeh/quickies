// Functions to find all pairs in a list of integers that can make a given sum

#include <cassert>
#include <iostream>
#include <vector>


// Helper structs to make code more readable
struct TwoSumPair {
    int x;
    int y;

    TwoSumPair(int a, int b) : x(a), y(b) {}
};

struct ThreeSumPair {
    int x;
    int y;
    int z;

    ThreeSumPair(int a, int b, int c) : x(a), y(b), z(c) {}
};


// Helper functions to print results
void PrintThreeSum(const std::vector<ThreeSumPair>& results, int sum) {
    for (auto it : results) {
        std::cout << it.x << " + " << it.y << " + " << it.z << " = " << sum << std::endl;
    }
}

void PrintTwoSum(const std::vector<TwoSumPair>& results, int sum) {
    for (auto it : results) {
        std::cout << it.x << " + " << it.y << " = " << sum << std::endl;
    }
}


// Returns list of integer pairs that make the input sum. Assumes input vector is sorted.
std::vector<TwoSumPair> TwoSum(const std::vector<int>& values, int sum, int left=0, int right=-1) {
    // Initialize result vector
    std::vector<TwoSumPair> result;

    if (right < 0) {
        right = values.size() - 1;
    }

    // For loop advancing left index
    for (; left < right; ++left) {
        // Calculate the number we are looking for
        int target = sum - values[left];

        // While loop decrementing the right index while the values are equal or greater than the target number
        while (values[right] >= target && left < right) {
            // Check if solution
            if (values[right] == target) {
                result.emplace_back(values[left], values[right]);
            }
            --right;
        }
    }

    return result;
}


// Returns list of integer pairs that make the input sum. Assumes input vector is sorted.
std::vector<ThreeSumPair> ThreeSum(const std::vector<int>& values, int sum) {
    // Initialize result vector
    std::vector<ThreeSumPair> result;

    // Initialize left and right indexes starting at the front and back of the vector
    int right = values.size() - 1;
    int left = 0;

    // For loop advancing left index
    for (; left < right; ++left) {
        // Calculate the two sum we are looking for
        int target = sum - values[left];

        // Find pairs that can make the two sum
        std::vector<TwoSumPair> two_sum_result = TwoSum(values, target, left + 1, right);
        for (auto it : two_sum_result) {
            result.emplace_back(values[left], it.x, it.y);
        }
    }

    return result;
}



void TestTwoSum() {
    std::cout << "|---- Test Two Sum ----|" << std::endl;

    std::vector<int> values;
    std::vector<TwoSumPair> result;
    int sum;

    std::cout << "Testing empty list..." << std::endl;
    values = {};
    result = TwoSum(values, 0);
    assert(result.empty());
    std::cout << "=== Success ===\n" << std::endl;

    std::cout << "Testing mixed values..." << std::endl;
    values = {-3, -2, -1, 0, 1, 2, 3};
    sum = 0;
    result = TwoSum(values, sum);
    PrintTwoSum(result, sum);

    assert(result.size() == 3);
    assert(result[0].x == -3);
    assert(result[0].y == 3);
    assert(result[1].x == -2);
    assert(result[1].y == 2);
    assert(result[2].x == -1);
    assert(result[2].y == 1);
    std::cout << "=== Success ===\n" << std::endl;

    std::cout << "Testing negative sum..." << std::endl;
    values = {-30, -15, -9, -1, 5, 11, 20};
    sum = -10;
    result = TwoSum(values, sum);
    PrintTwoSum(result, sum);

    assert(result.size() == 3);
    assert(result[0].x == -30);
    assert(result[0].y == 20);
    assert(result[1].x == -15);
    assert(result[1].y == 5);
    assert(result[2].x == -9);
    assert(result[2].y == -1);
    std::cout << "=== Success ===\n" << std::endl;

    std::cout << "Testing positive sum..." << std::endl;
    values = {0, 8, 11, 14, 15, 23, 27, 29, 59, 60, 7009};
    sum = 29;
    result = TwoSum(values, sum);
    PrintTwoSum(result, sum);

    assert(result.size() == 2);
    assert(result[0].x == 0);
    assert(result[0].y == 29);
    assert(result[1].x == 14);
    assert(result[1].y == 15);
    std::cout << "=== Success ===\n\n" << std::endl;
}


void TestThreeSum() {
    std::cout << "|---- Test Three Sum ----|" << std::endl;

    std::vector<int> values;
    std::vector<ThreeSumPair> result;
    int sum;

    std::cout << "Testing empty list..." << std::endl;
    values = {};
    result = ThreeSum(values, 0);
    assert(result.empty());
    std::cout << "=== Success ===\n" << std::endl;

    std::cout << "Testing mixed values..." << std::endl;
    values = {-289, -92, -57, -32, -6, 2, 19, 92, 165, 924};
    sum = -105;
    result = ThreeSum(values, sum);
    PrintThreeSum(result, sum);

    assert(result.size() == 2);
    assert(result[0].x == -289);
    assert(result[0].y == 19);
    assert(result[0].z == 165);
    assert(result[1].x == -92);
    assert(result[1].y == -32);
    assert(result[1].z == 19);
    std::cout << "=== Success ===\n" << std::endl;

    std::cout << "Testing positive sum..." << std::endl;
    values = {0, 8, 11, 14, 15, 21, 23, 27, 29, 50, 60, 7009};
    sum = 50;
    result = ThreeSum(values, sum);
    PrintThreeSum(result, sum);

    assert(result.size() == 4);
    assert(result[0].x == 0);
    assert(result[0].y == 21);
    assert(result[0].z == 29);
    assert(result[1].x == 0);
    assert(result[1].y == 23);
    assert(result[1].z == 27);
    assert(result[2].x == 8);
    assert(result[2].y == 15);
    assert(result[2].z == 27);
    assert(result[3].x == 14);
    assert(result[3].y == 15);
    assert(result[3].z == 21);
    std::cout << "=== Success ===\n" << std::endl;
}


int main() {
    TestTwoSum();
    TestThreeSum();
}
