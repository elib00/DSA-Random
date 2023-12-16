#include "binary_tree.h"

class BinarySearchTree : public BinaryTree {
    virtual TreeNode *create() = 0;
    virtual TreeNode *insert(int) = 0;
    virtual TreeNode *remove(int) = 0;
    virtual TreeNode *search(int) = 0;
    virtual void inorder() = 0;
    virtual void preorder() = 0;
    virtual void postorder() = 0;
};