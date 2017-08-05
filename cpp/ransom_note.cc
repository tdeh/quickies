// Function to determine if note is constructable

#include <cassert>
#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>


// Function to check if a note can be constructed using the characters from a magazine.
// Ignores whitespace characters and case.
bool RansomNote(std::string magazine, std::string note) {
    std::unordered_map<char, int> char_hist;

    // Build histogram of non-whitespace characters in the magazine
    for (char character : magazine) {
        if (isspace(character)) {
            continue;
        }

        // Convert to lower case (does nothing for non alphabetical chars)
        char sanitized_char = tolower(character);
        if (char_hist.find(sanitized_char) != char_hist.end()) {
            ++char_hist[sanitized_char];
        } else {
            char_hist[sanitized_char] = 1;
        }
    }

    // Check if all the non-whitespace characters in the note exist in the magazine
    for (char character : note) {
        if (isspace(character)) {
            continue;
        }

        // Convert to lower case (does nothing for non alphabetical chars)
        char sanitized_char = tolower(character);
        if (char_hist.find(sanitized_char) != char_hist.end() && char_hist[sanitized_char] != 0) {
            --char_hist[sanitized_char];
        } else {
            return false;
        }
    }

    return true;
}


void TestRansomNote() {
    // Test edge cases
    std::cout << "Testing edge cases..." << std::endl;
    assert(RansomNote("", ""));
    assert(!RansomNote("", "garbage"));
    assert(RansomNote("garbage", ""));
    assert(RansomNote("", "       "));
    assert(RansomNote("", "\n\t"));
    std::cout << "=== Success ===" << std::endl;

    std::cout << "Testing case sensitivety..." << std::endl;
    assert(RansomNote("CaMeL", "camel"));
    assert(RansomNote("camEL", "CAMel"));
    std::cout << "=== Success ===" << std::endl;

    std::cout << "Testing simple strings..." << std::endl;
    assert(RansomNote("simple", "simple"));
    assert(RansomNote("shortest", "short"));
    assert(RansomNote("unrealistic", "realistic"));
    assert(!RansomNote("ofbyone", "offbyone"));
    std::cout << "=== Success ===" << std::endl;

    std::cout << "Testing complex strings..." << std::endl;
    std::string test_str = "This is a long test string. It contains numbers like 123 and non-alphanumeric characters"
                           "like :;'<#$&^. and whitespace characters like \n\t\r";
    assert(RansomNote(test_str, "S\nU\nB\nS\tE\tT\r ;'#$31"));
    assert(!RansomNote("This string does not have apostrophies", "apostrophies' string"));
    std::cout << "=== Success ===" << std::endl;
}


int main() {
    TestRansomNote();
}
