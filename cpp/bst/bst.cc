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
    BstNode* node;
    BstNode* parent = nullptr;

    // Find node
    while (node != nullptr) {
        if (node->data == val) {
            // Found the node
            return node;
        } else if (val <= node->data) {
            // Traverse down left child
            parent = node;
            node = node->left;
        } else {
            // Traverse down right child
            parent = node;
            node = node->right;
        }
    }

    // Check if node has children
    if (!node->left && !node->right) {
        // No children; trivial delete
        if (!parent) {
            // Node was root; set root to nullptr
            root_ = nullptr;
        } else if (node == parent->left) {
            // Node was left child; update parent->left
            parent->left = nullptr;
        } else {
            // Node was right child; update parent->right
            parent->right = nullptr;
        }
        delete node;
    } else if (!node->left) {
        // Only has left children
        if (!parent) {
            // Node was root; set root to left children
            root_ = node->left;
        } else if (node == parent->left) {
            // Node was left child; update parent->left
            parent->left = node->left;
        } else {
            // Node was right child; update parent->right
            parent->right = node->left;
        }
        delete node;
    } else if (!node->right) {
        // Only has right children
        if (!parent) {
            // Node was root; set root to right children
            root_ = node->right;
        } else if (node == parent->left) {
            // Node was left child; update parent->left
            parent->left = node->right;
        } else {
            // Node was right child; update parent->right
            parent->right = node->right;
        }
        delete node;
    } else {
        // Has left and right children; complex delete

        // Find inorder successor to node being deleted (smallest value in right subtree)
        BstNode* successor = node->right;
        BstNode* parent_successor = node;
        while (successor->left) {
            parent_successor = successor;
            successor = successor->left;
        }

        // Handle successor's right subtree if it exists
        if (successor->right) {
            parent_successor->left = successor->right;
        }

        // Replace node we're deleting with the successor
        successor->right = node->right;
        successor->left = node->left;
        delete node;
    }
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
