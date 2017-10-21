// Function to determine if string is unique

#include <cassert>
#include <iostream>
#include <string>
#include <unordered_set>


// Function to check if a string is made of unique characters
bool IsUnique(std::string input) {
    std::unordered_set<char> char_set;

    for (auto& c : input) {
        if (char_set.find(c) != char_set.end()) {
            return false;
        } else {
            char_set.emplace(c);
        }
    }

    return true;
}


void TestIsUnique() {
    // Test edge cases
    std::cout << "Testing edge cases..." << std::endl;
    assert(IsUnique(""));
    std::cout << "=== Success ===" << std::endl;

    std::cout << "Testing case sensitivety..." << std::endl;
    assert(IsUnique("CalceL"));
    std::cout << "=== Success ===" << std::endl;

    std::cout << "Testing simple strings..." << std::endl;
    assert(!IsUnique("simple pimple"));
    assert(IsUnique("uniqe"));
    std::cout << "=== Success ===" << std::endl;

    std::cout << "Testing complex strings..." << std::endl;
    assert(IsUnique("1*730()^aNKSOGiwjflsz"));
    assert(!IsUnique("1*730()^aNKSOGiwjflsz^"));
    std::cout << "=== Success ===" << std::endl;
}


int main() {
    TestIsUnique();
}
