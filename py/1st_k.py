"""
Given a sorted list, find the first occurance of k.
"""

def find_first(l, k):
    """ Assumes that 'l' is a list of integars and is sorted """

    # Input checks
    if len(l) is 0:
        return -1

    # Initialize binary search params
    result = -1
    upper = len(l) - 1
    lower = 0

    # Search loop
    while lower <= upper:
        # Calculate middle index
        mid = lower + ((upper - lower)/2)

        # Check if possible solution
        if l[mid] == k:
            result = mid

        # Binary search
        if l[mid] >= k:
            upper = mid - 1
        else:
            lower = mid + 1

    return result

def test_find_first():
    print "Testing find 1st k..."

    # Test empty list
    assert(find_first([], 0) == -1)

    # Test k is not in list
    assert(find_first(range(100), -1) == -1)
    assert(find_first(range(-100, 100), 100) == -1)

    # Test single k at boundaries
    assert(find_first(range(1000), 999) == 999)
    assert(find_first(range(10, 9001), 10) == 0)

    # Test large number of repeast at various positions
    test_list = range(100) + ([100] * 1000) + range(101, 100)
    assert(find_first(test_list, 100) == 100)

    test_list = range(-1000, 0) + ([0] * 997) + range(101, 100)
    assert(find_first(test_list, 0) == 1000)

    print "=== Success ==="


if __name__ == "__main__":
    test_find_first()
