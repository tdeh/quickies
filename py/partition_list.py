"""
Partition a list of integers such that all elements less than the pivot appear
before the pivot and all elements greater than the pivot appear after.
"""

def partition(l, pivot):
    """
    Assumes that 'l' is a list of integers.
    """
    # Write index pointing to place in list to swap
    write_idx = 0

    # Move elements that are less than pivot
    idx = len(l) - 1
    while write_idx < idx:
        if l[write_idx] < pivot:
            # Element at write_idx is less than pivot; keep moving
            write_idx += 1
        elif l[idx] >= pivot:
            # Element at idx is greater than or equal to pivot; keep moving
            idx -= 1
        else:
            # Swap elements at write_idx and idx
            temp = l[idx]
            l[idx] = l[write_idx]
            l[write_idx] = temp

            # Increment write_idx and decrement idx
            write_idx += 1
            idx -= 1

    # Move elements that are equal to pivot
    idx = len(l) - 1
    while write_idx < idx:
        if l[write_idx] <= pivot:
            # Element at write_idx is equal to pivot; keep moving
            write_idx += 1
        elif l[idx] > pivot:
            # Element at idx is greater than pivot; keep moving
            idx -= 1
        else:
            # Swap elements at write_idx and idx
            temp = l[idx]
            l[idx] = l[write_idx]
            l[write_idx] = temp

            # Increment write_idx and decrement idx
            write_idx += 1
            idx -= 1


def test_partition():
    print "Testing empty list..."
    l = []
    partition(l, 1)
    assert(l == [])
    print "=== Success ==="

    print "Testing single element list..."
    l = [1]
    partition(l, 1)
    assert(l == [1])
    print "=== Success ==="

    print "Testing pivot is smallest element..."
    l = [1, 1, 2, 3, 4, 6, 10, 9, 2, 1, 6, 1]
    partition(l, 1)
    assert(l == [1, 1, 1, 1, 4, 6, 10, 9, 2, 3, 6, 2])
    print "=== Success ==="

    print "Testing pivot is largest element..."
    l = [1, 1, 2, 3, 4, 6, 10, 9, 2, 1, 6, 1]
    partition(l, 10)
    assert(l == [1, 1, 2, 3, 4, 6, 1, 9, 2, 1, 6, 10])
    print "=== Success ==="

    print "Testing pivot is ~median..."
    l = [-19, 94, 0, 42, -83, 6, 19, -32, 59, 42, -109, 38, 109, 290]
    partition(l, 42)
    assert(l == [-19, 38, 0, -109, -83, 6, 19, -32, 42, 42, 59, 94, 109, 290])
    print "=== Success ==="


if __name__ == "__main__":
    test_partition()
