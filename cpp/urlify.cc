// Function to turn a string into a URL

#include <cassert>
#include <cctype>
#include <iostream>
#include <string>


// Function to turn a string into a URL (replace spaces with %20)
// Assumes that there's enough room in the string
bool Urlify(std::string& input) {
    // TODO: handle case where there are no spaces to replace, but trailling spaces at the end
    // since this solution will still move the characters to the end of the string.
    int idx = input.size() - 1;
    while (isspace(input[idx])) {
        --idx;
    }

    for (int write_idx = input.size() - 1; write_idx >= 0 && idx >= 0; --write_idx, --idx) {
        if (!isspace(input[idx])) {
            input[write_idx] = input[idx];
        } else {
            input[write_idx] = '0';
            --write_idx;
            input[write_idx] = '2';
            --write_idx;
            input[write_idx] = '%';
        }
    }
}


void TestUrlify() {
    std::string input;

    // Test edge cases
    std::cout << "Testing edge cases..." << std::endl;
    input = "";
    Urlify(input);
    assert(input == "");
    std::cout << "=== Success ===" << std::endl;

    std::cout << "Testing simple strings..." << std::endl;
    input = "This is a simple string        ";
    Urlify(input);
    assert(input == "This%20is%20a%20simple%20string");
    std::cout << "=== Success ===" << std::endl;
}


int main() {
    TestUrlify();
}
