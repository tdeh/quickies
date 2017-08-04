// Simple binary search tree class for integers

#include "bst.h"

Bst::Bst() {
    root_ = nullptr;
}

Bst::~Bst() {
    // Recursively delete starting at root
    DeleteRecursive(root_);
}

void Bst::Insert(int val) {
    // Check if empty
    if (root_ == nullptr) {
        // Empty tree; insert at root
        root_ = new BstNode {val, nullptr, nullptr};
        return;
    }

    // Not empty; traverse to find insertion point
    BstNode* node = root_;
    while (true) {
        if (val <= node->data) {
            // Check if we can insert on left child
            if (node->left == nullptr) {
                // Insert and return
                node->left = new BstNode {val, nullptr, nullptr};
                return;
            } else {
                // Traverse down left child
                node = node->left;
            }
        } else {
            // Check if we can insert on right child
            if (node->right == nullptr) {
                // Insert and return
                node->right = new BstNode {val, nullptr, nullptr};
                return;
            } else {
                // Traverse down right child
                node = node->right;
            }
        }
    }
}

BstNode* Bst::Find(int val) {
    BstNode* node = root_;

    // Traverse down tree
    while (node != nullptr) {
        if (node->data == val) {
            // Found the value; return the node
            return node;
        } else if (val <= node->data) {
            // Traverse down left child
            node = node->left;
        } else {
            // Traverse down right child
            node = node->right;
        }
    }
    return nullptr;
}

void Bst::Remove(int val) {
    // TODO
}

BstNode* Bst::GetRoot() {
    return root_;
}

void Bst::DeleteRecursive(BstNode* node) {
    if (node == nullptr) {
        // Base case; return
        return;
    } else {
        // Recursively delete left and right children
        DeleteRecursive(node->left);
        DeleteRecursive(node->right);

        // Delete this node
        delete node;
    }
}
