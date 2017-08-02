// Class with get max method

#include <cassert>
#include <iostream>
#include <stack>

// Stack class with a GetMax method that returns the maximum value on the stack
class MaxStack {
 public:
    void Push(int val) {
        // Handle max updates
        if (val_stack_.empty()) {
            // First item in the stack
            max_.val = val;
            max_.cnt = 1;
        } else if (val > max_.val) {
            // New max value
            max_stack_.push(max_);
            max_.val = val;
            max_.cnt = 1;
        } else {
            // Increment max count
            ++max_.cnt;
        }

        // Push value onto stack
        val_stack_.push(val);
    }

    int Pop() {
        // Check if stack is empty
        if (val_stack_.empty()) {
            throw std::length_error("Stack is empty!");
        }

        // Store result and pop from stack
        int res = val_stack_.top();
        val_stack_.pop();

        // Handle max updates
        if (max_.cnt <= 1 && !max_stack_.empty()) {
            // Set max to item on top of max stack and pop it
            max_ = max_stack_.top();
            max_stack_.pop();
        } else {
            // Decrement max count
            --max_.cnt;
        }

        // Return result
        return res;
    }

    int GetMax() {
        if (val_stack_.empty()) {
            throw std::length_error("Stack is empty!");
        }

        return max_.val;
    }

    bool Empty() {
        return val_stack_.empty();
    }

 private:
    struct MaxPair {
        int val;
        int cnt;
    };

    MaxPair max_;
    std::stack<MaxPair> max_stack_;
    std::stack<int> val_stack_;
};


void TestMaxStack() {
    MaxStack test_stack;

    // Test edge cases
    std::cout << "Testing empty stack..." << std::endl;
    try {
        test_stack.Pop();
        std::cout << "  Error: pop succeeded on empty stack!" << std::endl;
    } catch (std::length_error) {
        // Do nothing
    }
    try {
        test_stack.GetMax();
        std::cout << "  Error: GetMax succeeded on empty stack!" << std::endl;
    } catch (std::length_error) {
        // Do nothing
    }
    std::cout << "  Success" << std::endl;

    // Test single element
    std::cout << "Testing single element..." << std::endl;
    test_stack.Push(10);
    assert(test_stack.GetMax() == 10);
    assert(test_stack.Pop() == 10);

    // Check edge cases again
    try {
        test_stack.Pop();
        std::cout << "  Error: pop succeeded on empty stack!" << std::endl;
    } catch (std::length_error) {
        // Do nothing
    }
    try {
        test_stack.GetMax();
        std::cout << "  Error: GetMax succeeded on empty stack!" << std::endl;
    } catch (std::length_error) {
        // Do nothing
    }
    std::cout << "  Success" << std::endl;

    // Test incrementing values
    std::cout << "Testing incrementing values..." << std::endl;
    for (int i = 0; i < 15; ++i) {
        test_stack.Push(i);
    }
    for (int i = 0; i < 15; ++i) {
        assert(test_stack.GetMax() == 15 - i - 1);
        assert(test_stack.Pop() == 15 - i - 1);
    }
    std::cout << "  Success" << std::endl;

    // Test decrementing values
    std::cout << "Testing decrementing values..." << std::endl;
    for (int i = 15; i >= 0; --i) {
        test_stack.Push(i);
    }
    for (int i = 15; i >= 0; --i) {
        assert(test_stack.GetMax() == 15);
        assert(test_stack.Pop() == 15 - i);
    }
    std::cout << "  Success" << std::endl;

    // Test mixed values
    std::cout << "Testing mixed values..." << std::endl;
    test_stack.Push(20);
    test_stack.Push(10);
    test_stack.Push(15);
    test_stack.Push(21);
    test_stack.Push(1);
    test_stack.Push(9);
    test_stack.Push(200);
    test_stack.Push(201);

    assert(test_stack.GetMax() == 201);
    assert(test_stack.Pop() == 201);
    assert(test_stack.GetMax() == 200);
    assert(test_stack.Pop() == 200);
    assert(test_stack.GetMax() == 21);
    assert(test_stack.Pop() == 9);
    assert(test_stack.GetMax() == 21);
    assert(test_stack.Pop() == 1);
    assert(test_stack.GetMax() == 21);
    assert(test_stack.Pop() == 21);
    assert(test_stack.GetMax() == 20);
    assert(test_stack.Pop() == 15);
    assert(test_stack.GetMax() == 20);
    assert(test_stack.Pop() == 10);
    assert(test_stack.GetMax() == 20);
    assert(test_stack.Pop() == 20);
    std::cout << "  Success" << std::endl;
}


int main() {
    TestMaxStack();
}
