#include "../list.h"
#include "node.h"
#include <cstdlib>
#include <iostream>

using namespace std;

class SinglyLL : public List {
    int size;
    node *head;
    node *tail;

    node *createNode(int value){
        node *newNode = (node*) calloc(1, sizeof(node));
        newNode->data = value;
        newNode->next = nullptr;
        return newNode;
    }

    public:
        SinglyLL(){
            size = 0;
            head = nullptr;
            tail = nullptr;
        }

        //list operations
        int search(int value){
            node *curr = head;
            int ctr = 0;

            while(curr){
                if(curr->data == value){
                    return ctr;
                }

                curr = curr->next;
                ctr++;
            }

            return -1;
        }

        void insert(int value){
            if(head == nullptr){
                addHead(value);
            }else{
                addTail(value);
            }
        }

        // 1 2 3 4 5 
        int get(int pos){
            if(pos < 0 || pos >= size){
                return -1;
            }

            node *curr = head;
            int ctr = 0;
            while(curr){
                if(ctr == pos){
                    return curr->data;
                }
                curr = curr->next;
                ctr++;
            }
        }

        int remove(int value){
            node *curr = head;
            node *prev = nullptr;
            int ctr = 0;
            while(curr){
                if(curr->data == value){
                    if(curr == head){
                        head = head->next;
                    }else{
                        prev->next = curr->next;
                    }

                    size--;
                    return ctr;
                }
                
                prev = curr;
                curr = curr->next;
                ctr++;
            }
            return -1;
        }

        void print(){
            if(size == 0){
                cout << "Empty" << endl;
            }else{
                node *curr = head;
                cout << "Elements: ";
                while(curr){
                    cout << curr->data << " ";
                    curr = curr->next;
                }

                cout << endl;
            }
           
            return;
        }

        //linked list utility operations
        node *addHead(int value){
            node *newNode = createNode(value);
            newNode->next = head;
            if(head == nullptr){
                tail = newNode;
            }
            head = newNode;
            size++;
            return newNode;
        }

        node *addTail(int value){
            node *newNode = createNode(value);
            if(tail == nullptr){
                head = newNode;
            }else{
                tail->next = newNode;
            }

            tail = newNode;
            size++;
            return newNode;
        }



};