// Simple binary search tree class for integers

#ifndef BST_H
#define BST_H

struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};


class Bst {
 public:
    Bst();
    ~Bst();
    void Insert(int val);
    void Remove(int val);
    BstNode* Find(int val);
    BstNode* GetRoot();

 private:
    BstNode* root_;

    void DeleteRecursive(BstNode* node);
};

#endif // BST_H
