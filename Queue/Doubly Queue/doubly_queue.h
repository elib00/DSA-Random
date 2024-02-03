#include "../queue.h"
#include "../../List/Linked List/DoublyLL/doubly_linked_list.h"
#include <cstdlib>

class DoublyQueue : public Queue{
    DoublyLL *list;

    public:
        DoublyQueue(){
            list = new DoublyLL();
        }

        void enqueue(int value){
            list->addTail(value);
        }

        int dequeue(){
            int res = list->removeHead();
            if(res == -1){
                throw logic_error("Queue is empty. Cannot remove any element.");
            }

            return res;
        }

        int first(){
            int res = list->getHead();
            if(res == -1){
                throw logic_error("Queue is empty. Cannot get first element.");
            }

            return res;
        }

        int size(){
            return list->size();
        }

        bool isEmpty(){
            return size() == 0;
        }

        void print(){
            list->print();
        }
};