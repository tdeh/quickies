"""
Compress a string by replacing repeated characters with a numeric count.
"""

def compress_string(s):
    """
    Assumes that 's' is a string of only alphabetical characters.
    """
    comp_s = ""
    count = 1
    for idx in range(len(s)):
        # Check if character is a repeat or if we are at the end of the string
        if idx + 1 == len(s) or s[idx] != s[idx+1]:
            comp_s += s[idx]

            # Append count if it is greater than 1
            if count > 1:
                comp_s += str(count)

            # Reset the count
            count = 1
        else:
            # Repeated character; increment count
            count += 1

    return comp_s


def test_compress_string():
    print "Testing empty string..."
    assert(compress_string("") == "")
    print "=== Success ==="

    print "Testing single character string..."
    assert(compress_string("c") == "c")
    print "=== Success ==="

    print "Testing strings with various repeats..."
    assert(compress_string("abbcccdddd") == "ab2c3d4")
    assert(compress_string("zzzzzzzzzzzzzbccc") == "z13bc3")
    assert(compress_string("qwerruiop") == "qwer2uiop")
    print "=== Success ==="

    print "Testing strings with no repeats..."
    assert(compress_string("ababababababa") == "ababababababa")
    assert(compress_string("asdfghjkl") == "asdfghjkl")
    print "=== Success ==="

    print "Testing strings with large repeats..."
    assert(compress_string("a" * 9999) == "a9999")
    assert(compress_string("z" * 189 + "y" * 57480 + "a" * 10) == "z189y57480a10")
    print "=== Success ==="


if __name__ == "__main__":
    test_compress_string()
