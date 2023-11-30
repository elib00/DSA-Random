#include <iostream>
#include "tree_node.h"
#include <queue>
#include <string>
#include <climits>
using namespace std;

class BinaryTree {
    TreeNode *root;
    int size;

    TreeNode *createNode(TreeNode *parent, int val){
        TreeNode *n = new TreeNode();
        n->val = val;
        n->parent = parent;
        return n;
    }

    void preorderTraversal(TreeNode *node){
        if(!node) return;
        cout << node->val << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    void breadthFirstTraversal(TreeNode *node){
        queue<TreeNode*> q;
        q.push(node);

        while(!q.empty()){
            int len = q.size();
            for(int i = 0; i < len; i++){
                TreeNode *temp = q.front();
                q.pop();
                if(temp){
                    cout << temp->val << " ";
                    if(temp->left) q.push(temp->left);
                    if(temp->right) q.push(temp->right);
                }
            }

            cout << endl;
        }
    }

    public:
        BinaryTree(){
            root = nullptr;
            size = 0;
        }

        TreeNode *addRoot(int val){
            TreeNode *n = new TreeNode();
            n->val = val;
            n->parent = nullptr;
            root = n;
            size++;
            return n;
        }

        TreeNode *accessLeft(TreeNode *node){
            return node->left;
        }

        TreeNode *accessRight(TreeNode *node){
            return node->right;
        }

        TreeNode *addLeft(TreeNode *node, int val){
            TreeNode *n = createNode(node, val);
            node->left = n;
            size++;
            return n;
        }

        TreeNode *addRight(TreeNode *node, int val){
            TreeNode *n = createNode(node, val);
            node->right = n;
            size++;
            return n;
        }

        TreeNode *getRoot(){
            return root;
        }


        void constructTree(TreeNode *node){
            TreeNode *left = nullptr;
            TreeNode *right = nullptr;

            int choice;
            cout << "Do you want to add left of " << node->val << "?: ";
            cin >> choice;

            if(choice){
                int left_val;
                cout << "Enter left value of " << node->val << ": ";
                cin >> left_val;
                TreeNode *left_subtree = addLeft(node, left_val);
                constructTree(left_subtree);
            }else{
                cout << endl;
            }

            cout << "Do you want to add right of " << node->val << "?: ";
            cin >> choice;

            if(choice){
                int right_val;
                cout << "Enter right value of " << node->val << ": ";
                cin >> right_val;
                TreeNode *right_subtree = addRight(node, right_val);
                constructTree(right_subtree);
            }else{
                cout << endl;
            }

            return;

        }

        //traversals
        void preorderTraversal(){
            preorderTraversal(root);
        }

        void breadthFirstTraversal(){
            breadthFirstTraversal(root);    
        }

        //bst operations
        TreeNode *insert(int val){
            if(!root){
                root = addRoot(val);
                size++;
                return root;
            }

            TreeNode *curr = root;
            while(curr){
                if(val < curr->val){
                    if(curr->left){
                        curr = curr->left;
                    }else{
                        size++;
                        TreeNode *n = createNode(curr, val);
                        curr->left = n;
                        cout << "parent of subtree: " << curr->val << endl;
                        cout << "left of " << curr->val << ": ";
                        (curr->left) ? cout << curr->left->val << endl : cout << "no left child" << endl;
                        cout << "right of " << curr->val << ": ";
                        (curr->right) ? cout << curr->right->val << endl : cout << "no right child" << endl;
                        return n;
                    }
                }else if(val > curr->val){
                    if(curr->right){
                        curr = curr->right;
                    }else{
                        size++;
                        TreeNode *n = createNode(curr, val);
                              curr->right = n;
                        cout << "parent of subtree: " << curr->val << endl;
                        cout << "left of " << curr->val << ": ";
                        (curr->left) ? cout << curr->left->val << endl : cout << "no left child" << endl;
                        cout << "right of " << curr->val << ": ";
                        (curr->right) ? cout << curr->right->val << endl : cout << "no right child" << endl;
                        return n;
                    }
                }
            }
        }

        int *remove(int val){
            int return_val;

            TreeNode *curr = getRoot();
            while(curr){
                if(val == curr->val){
                    break;
                }else if(val < curr->val){
                    curr = curr->left;
                }else if(val > curr->val){
                    curr = curr->right;
                }
            }

            //check if nakit-an ba ang value
            if(!curr) return INT_MIN; //wala jud nakit-an ang value

            //get the smallest value at the right of the tree (ang smallest value kay siya gihapon ang
            //biggest value sa BST since naa man shas right amazingg...
           
            if(curr->left && curr->right){  //if naa shay children
                node *right_subtree_anchor = curr->right;
                //para makuha ang least na value, always go down sa left
                while(right_subtree_anchor->left){
                    right_subtree_anchor = right_subtree_anchor->left;
                }

            }else{ // wa shay children, maremove ra sha dayon
                int 
            }


        }




};