#include <iostream>
#include "doubly_linked_list.h"

using namespace std;

int main(void){
    char op;
    int num;
    int pos;
    int res;

    List *list = new DoublyLL();

    do {
        cout << "Enter operation: ";
        cin >> op;

        switch(op){
            case 'a':
                cin >> num;
                list->insert(num);
                cout << "Added " << num << endl;
                break;
            case 'r':
                cin >> num;
                res = list->remove(num);
                if(res != -1){
                    cout << "Removed " << num << " at position " << res << endl;
                }else{
                    cout << "Removal unsuccessful. Element not found." << endl;
                }
                break;
            case 'g':
                cin >> pos;
                try{
                    cout << "Got " << list->get(pos) << "  at position " << pos << endl;
                }catch(const exception &e){
                    cout << e.what() << endl;
                }
                break;
            case 's':
                cin >> num;
                res = list->search(num);
                if(res != -1){
                    cout << "Found " << num << " at position " << res << endl;
                }else{
                    cout << "Search failed. Element not found." << endl;
                }
                break;
            case 'p':
                list->print();
                break;
            case 'l':
                cout << "Size: " << list->size() << endl;
                break;
            case 'e':
                cout << "Empty? " << list->isEmpty() << endl;
                break;
            case '@':
                cin >> num;
                cin >> pos;
                try {
                    list->addAt(num, pos);
                    cout << "Added " << num << " at position " << pos << endl;
                }catch(const exception &e){
                    cout << e.what() << endl;
                }
                break;
            case '-':
                cin >> pos;
                try{
                    cout << "Removed " << list->removeAt(pos) << " at position " << pos << endl;
                }catch(const exception &e){
                    cout << e.what() << endl;
                }
                break;
            case 'c':
                
        }
    }while(op != 'x');

    cout << "Exiting..." << endl;
    return 0;
}