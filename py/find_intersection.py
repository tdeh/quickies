"""
Find the intersection of two sorted arrays.
"""

def find_intersection(list_a, list_b):
    """
    Assumes that both lists are sorted.
    """
    # Initialize result list
    intersection = []

    # Initialize indecies for list_a and list_b
    idx_a = 0
    idx_b = 0

    # Loop while the two indecies are within their respective lists
    while idx_a < len(list_a) and idx_b < len(list_b):
        a = list_a[idx_a]
        b = list_b[idx_b]

        # If the two values match and the value is not already in the result,
        # add the value to the result; else advance the index referencing the
        # smaller number since we know the other list does not have a match
        if a == b and (len(intersection) == 0 or intersection[-1] != a):
           intersection.append(list_a[idx_a])
        elif a > b:
            idx_b += 1
        else:
            idx_a += 1

    return intersection


def test_find_intersection():
    print "Testing empty lists..."
    assert(find_intersection([], []) == [])
    assert(find_intersection([], [1,2,3]) == [])
    assert(find_intersection([1,2,3], []) == [])
    print "=== Success ==="

    print "Testing no intersection..."
    assert(find_intersection([1,2,3,4,5], [6,7,8,9,10]) == [])
    assert(find_intersection([1,3,5,7,9], [0,2,4,6,8]) == [])
    assert(find_intersection([1,2,3,7,8,9], [4,5,6,10,11,12]) == [])
    print "=== Success ==="

    print "Testing intersection with no repeats..."
    assert(find_intersection([0,1,2,3,7,8,9,10], [3,7,10]) == [3,7,10])
    assert(find_intersection([-222,-10,-5,1,7,43,107],
                             [-234,-32,-30,-10,0,14,34,43,999]) == [-10,43])
    print "=== Success ==="

    print "Testing intersection with repeats..."
    assert(find_intersection([-9,0,1,1,2,4,4,4,6,9,9,9,194,199],
                             [-10,-3,1,1,1,1,5,6,194,194,298]) == [1,6,194])
    print "=== Success ==="

    print "Testing large lists..."
    assert(find_intersection(range(10050), range(-100, 999)) == range(999))
    assert(find_intersection([-10]*999 + [0]*999 + [99]*999,
                             [-10]*999 + [1]*999 + [99]*999) == [-10, 99])
    print "=== Success ==="


if __name__ == "__main__":
    test_find_intersection()
