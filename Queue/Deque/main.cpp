#include <iostream>
#include "deque.h"

int main(void){
    char op;
    int num;

    Deque *deque = new Deque();
    do{
        cout << "Enter operation: ";
        cin >> op;
        switch(op){
            case 'e': // add to the end of the deque
                cin >> num;
                deque->enqueue(num);
                cout << "Added " << num << endl;
                break;
            case 'd': //remove the first element
                try {
                    cout << "Removed " << deque->dequeue() << endl;
                }catch(const exception &e){
                    cout << e.what() << endl;
                }
                break; 
            case '@': // add to the front of the deque
                cin >> num;
                deque->addFront(num);
                cout << "Added " << num << endl;
                break;
            case '-':
                try{
                    cout << "Removed " << deque->removeRear() << " from the back of the deque" << endl;
                }catch(const exception &e){
                    cout << e.what() << endl;
                }
                break; 
            case 'f': //access the front of the deque
                try{
                    cout << "Front : " << deque->front() << endl;
                }catch(const exception &e){
                    cout << e.what() << endl;
                }
                break;
            case 'r':
                try{
                    cout << "Rear: " << deque->rear() << endl;
                }catch(const exception &e){
                    cout << e.what() << endl;
                }
                break;
            case 's': // get the current size of the deque
                cout << "Size: " << deque->size() << endl;
                break;
            case '?': // check if the deque is empty
                cout << "Empty? " << deque->isEmpty() << endl;
                break;
            case 'p': //print the contents of the deque (for checking and debugging purposes only)
                deque->print();
                break;         
        }

    }while(op != 'x');

    cout << "Exiting..." << endl;

    return 0;
}