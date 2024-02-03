#include <iostream>
#include "doubly_queue.h"

int main(void){
    char op;
    int num;

    DoublyQueue *queue = new DoublyQueue();
    do{
        cout << "Enter operation: ";
        cin >> op;
        switch(op){
            case 'e':
                cin >> num;
                queue->enqueue(num);
                cout << "Added " << num << endl;
                break;
            case 'd':
                try {
                    cout << "Removed " << queue->dequeue() << endl;
                }catch(const exception &e){
                    cout << e.what() << endl;
                }
                break;
            case 'f':
                try{
                    cout << "First: " << queue->first() << endl;
                }catch(const exception &e){
                    cout << e.what() << endl;
                }
                break;
            case 's':
                cout << "Size: " << queue->size() << endl;
                break;
            case '?':
                cout << "Empty? " << queue->isEmpty() << endl;
                break;
            case 'p':
                queue->print();
                break;         
        }

    }while(op != 'x');

    cout << "Exiting..." << endl;

    return 0;
}