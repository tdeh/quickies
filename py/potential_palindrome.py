"""
Test whether a string is a potential palindrome.
"""

def potential_palindrome(s):
    """ Assumes that 's' is a string of only alphabetical characters """
    # Input checks
    if len(s) is 0:
        return False

    char_hist = {}
    even_len = len(s) % 2 == 0
    odd_cnt = False

    # Build histogram
    for char in s:
        if char in char_hist:
            char_hist[char] += 1
        else:
            char_hist[char] = 1

    # Look through histogram for violation to palindrome properties
    for cnt in char_hist.values():
        if cnt % 2 == 1:
            if even_len or odd_cnt:
                # String length is even or there is already a char
                # with an odd count => can't be a palindrome
                return False
            else:
                # String length is odd, this is the only char that can have an
                # odd count
                odd_cnt = True

    # Passed palindrome property test
    return True

def test_potential_palindrome():
    print "Testing potential palindrome..."

    # Test empty string
    assert(not potential_palindrome(""))

    # Test single character
    assert(potential_palindrome("a"))

    # Test even and odd length palindromes
    assert(potential_palindrome("abbdd"))
    assert(potential_palindrome("aabbdd"))

    # Test even and odd length non-palindromes
    assert(not potential_palindrome("abbdze"))
    assert(not potential_palindrome("abbddz"))

    # Test all same character
    assert(potential_palindrome("a" * 999))

    # Test long non-palindrome
    assert(not potential_palindrome("aasdfjkoinvaliuhsglawiovaiasdnuilsoindaualsdiulnbwieurh"))

    # Test long palindrome
    assert(potential_palindrome("qwertyuiopasdfghjklzxcvbnmqwertyuiopasdfghjklmnbvcxz"))

    print "=== Success ==="


if __name__ == "__main__":
    test_potential_palindrome()
