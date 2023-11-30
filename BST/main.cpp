#include <iostream>
#include "binary_tree.h"
using namespace std;

int main(void){
    BinaryTree *tree = new BinaryTree();
    int val;
    cout << "Enter the root of the binary tree: ";
    cin >> val;
    tree->addRoot(val);
    // tree->constructTree(root);
    // tree->preorderTraversal();
    int choice;
    while(true){
        cout << "Do you want to insert a node in the binary tree [yes - 1 / no - 0]? ";
        cin >> choice;
        if(choice == 0) break;
        int val;
        cout << "Enter value of node to insert: ";
        cin >> val;
        tree->insert(val);
        cout << endl;
    }

  
    tree->breadthFirstTraversal();

    return 0;
}