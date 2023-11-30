#include <iostream>
#include "tree_node.h"

class BinaryTree {
    TreeNode *root;
    int size;

    TreeNode *create_node(int val, TreeNode *parent){
        TreeNode *n = new TreeNode();
        n->val = val;
        n->parent = parent;
        return n;
    }

    public:
        BinaryTree(){
            root = nullptr;
            size = 0;
        }

};