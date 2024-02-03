#include "../../list.h"
#include "doubly_node.h"
#include <stdexcept>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

class DoublyLL : public List {
    int _size;
    node *head;
    node *tail;

    node *createNode(int value){
        node *newNode = (node*) calloc(1, sizeof(node));
        newNode->data = value;
        return newNode;
    }

    void addBetween(int value, node *predecessor, node *successor){
        node *newNode = createNode(value);
        newNode->prev = predecessor;
        newNode->next = successor;
        predecessor->next = newNode;
        successor->prev = newNode;
        _size++;
        return;
    }

    void *removeNode(node *n){
        node *predecessor = n->prev;
        node *successor = n->next;
        predecessor->next = successor;
        successor->prev = predecessor;
        _size--;
        free(n);
    }

    public:
        DoublyLL(){
            //sentinel-based (dummy) implementation
            _size = 0;
            head = (node*) calloc(1, sizeof(node));
            tail = (node*) calloc(1, sizeof(node));
            head->next = tail;
            tail->prev = head;
        }

        //insert an element in the list
        void insert(int value){
            if(head->next == tail){
                addBetween(value, head, tail);
            }else{
                addBetween(value, tail->prev, tail);
            }
        }

        //remove the first occurrence of an element and return its position, return -1 if it was not found
        int remove(int value){
            int ctr = 1;
            node *curr = head->next;
            while(curr != tail){
                if(curr->data == value){
                    removeNode(curr);
                    free(curr);
                    return ctr;
                }
                ctr++;
                curr = curr->next;
            }

            return -1;
        }

        //get the element at the specified position
        //pos 1 refers to the first element and so on
        int get(int pos){
            if(pos <= 0 || pos >= _size + 1){
                throw logic_error("Invalid position. Position out of bounds.");
            }

            int ctr = 1;
            node *curr = head->next;
            while(curr != tail){
                if(ctr == pos){
                    return curr->data; 
                } 

                curr = curr->next;
                ctr++;
            }
        }

        int search(int value){
            int ctr = 1;
            node *curr = head->next;
            while(curr != tail){
                if(curr->data == value){
                    return ctr;
                }

                curr = curr->next;
                ctr++;
            }

            return -1;
        }

        void print(){
            node *curr = nullptr;

            cout << "FROM HEAD: ";
            curr = head->next;
            if(_size == 0){
                cout << "(none)" << endl;
            }else{
                while(curr != tail){
                    cout << curr->data;
                    if(curr->next != tail){
                        cout << " -> ";
                    }else{
                        cout << endl;
                    }

                    curr = curr->next;
                }
            }

            cout << "FROM TAIL: ";
            curr = tail->prev;
            if(_size == 0){
                cout << "(none)" << endl;
            }else{
                while(curr != head){
                    cout << curr->data;
                    if(curr->prev != head){
                        cout << " <- ";
                    }else{
                        cout << endl;
                    }

                    curr = curr->prev;
                }
            }

            return;
        }

        int size(){
            return _size;
        }

        bool isEmpty(){
            return _size == 0;
        }

        void addAt(int value, int pos){
            if(pos <= 0 || pos >= _size + 1){
                throw logic_error("Invalid position. Position out of bounds.");
            }

            node *curr = nullptr;

            //traverse from the head
            if(pos <= ceil(_size / 2.0)){
                curr = head;
                for(int i = 1; i <= pos; i++){
                    curr = curr->next;
                }
            }else{
                // 1 2 3 4
                curr = tail;
                for(int i = _size; i >= pos; i--){
                    curr = curr->prev;
                }
            }

            addBetween(value, curr->prev, curr);
            return;
        }

        int removeAt(int pos){
            if(pos <= 0 || pos >= _size + 1){
                throw logic_error("Invalid position. Position out of bounds.");
            }

            node *curr = nullptr;

            if(pos <= ceil(_size / 2.0)){
                curr = head;
                for(int i = 1; i <= pos; i++){
                    curr = curr->next;
                }
            }else{
                curr = tail;
                for(int i = _size; i >= pos; i--){
                    curr = curr->prev;
                }
            }

            int value = curr->data;
            removeNode(curr);
            return value;
        }

        //doubly LL operations
        void addHead(int value){
            addBetween(value, head, head->next);
        }

        void addTail(int value){
            addBetween(value, tail->prev, tail);
        }

        int removeHead(){
            node *temp = head->next;
            int val;
            if(temp != tail){
                node *predecessor = head;
                node *successor = head->next->next;
                predecessor->next = successor;
                successor->prev = predecessor;
                val = temp->data;
            }else{
                return -1;
            }

            free(temp);
            _size--;
            return val;
        }

        int removeTail(){
            node *temp = tail->prev;
            int val;
            if(temp != head){
                tail->prev = tail->prev->prev;
                val = temp->data;
            }else{
                return -1;
            }

            free(temp);
            _size--;
            return val;
        }

        int getHead(){
            if(head->next == tail){
                return -1;
            }

            return head->next->data;
        }
};