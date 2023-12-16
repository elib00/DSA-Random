#include <iostream>
#include <string>
#include "tree_node.h"
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

        int removeNode(TreeNode *n){
            int return_val = n->val;

            TreeNode *parent = n->parent;

            TreeNode *new_node = nullptr;
            if(n->left){
                new_node = n->left;
            }

            if(n->right){
                new_node = n->right;
            }

            if(!new_node){
                if(parent == nullptr){
                    root = nullptr;
                }else{
                    if(parent->left == n){
                        parent->left = nullptr; 
                    }else if(parent->right == n){
                        parent->right = nullptr;
                    }
                }
            }else{
                if(parent == nullptr){
                    new_node->parent = nullptr;
                    root = new_node;
                }else{
                    if(parent->left == n){
                        parent->left = new_node;
                        new_node->parent = parent;
                    }else if(parent->right == n){
                        parent->right = new_node;
                        new_node->parent = parent;
                    }
                }
            }
            

            free(n);
            size--;
            return return_val;
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
                return root;
            }

            TreeNode *curr = root;
            while(curr){
                if(val < curr->val){
                    if(curr->left){
                        curr = curr->left;
                    }else{
                        TreeNode *n = addLeft(curr, val);
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
                        TreeNode *n = addRight(curr, val);
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

        bool removeNodeBST(int val){
            int smallest_value;

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
            if(!curr) return false; //wala jud nakit-an ang value
            
            cout << "value nga nakit-an: " << curr->val << endl;

            //get the smallest value at the right of the tree (ang smallest value kay siya gihapon ang
            //biggest value sa BST since naa man shas right amazingg...
           
            if(curr->left && curr->right){  //if naa shay children
                TreeNode *right_subtree_anchor = curr->right;
                cout << "value sa right before loop: " <<curr->right->val << endl;
                //para makuha ang least na value, always go down sa left
                while(right_subtree_anchor->left){
                    right_subtree_anchor = right_subtree_anchor->left;
                }

                smallest_value = removeNode(right_subtree_anchor);
                curr->val = smallest_value;
            }else{ // wa shay children, maremove ra sha dayon
                removeNode(curr);
            }

            return true;
        }

        TreeNode *convertPreorder(int *array, int start, int end, TreeNode *parent){
            if(start > end) return nullptr;

            TreeNode *n = new TreeNode();
            n->val = array[start];
            n->parent = parent;

            int i = start + 1;
            while(i <= end && array[start] > array[i]){
                i++;
            }

            n->left = convertPreorder(array, start + 1, i - 1, n);
            n->right = convertPreorder(array, i, end, n);
            return n;
        }




};