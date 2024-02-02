#include <iostream>
#include "singly_linked_list.h"

using namespace std;

int main(void){
    char op;
    int val;
    int pos;
    int res;

    List *list = new SinglyLL();

    do{
        cout << "Enter operation: ";
        cin >> op;

        switch(op){
            case 'a':
                cin >> val;
                list->insert(val);
                cout << "Added " << val << endl;
                break;
            case 'r':
                cin >> val;
                res = list->remove(val);
                if(res == -1){
                    cout << "Element not found. Removal unsuccessful." << endl;
                }else{
                    cout << "Removed " << val << " at pos " << res << endl;
                }
                break;
            case 's':
                cin >> val;
                res = list->search(val);
                if(res == -1){
                    cout << "Element not found. Search unsuccessful." << endl;
                }else{
                    cout << "Found " << val <<  " at position " <<  res << endl;
                }
           
                break;
            case 'g':
                cin >> pos;
                res = list->get(pos);
                if(res == -1){
                    cout << "Invalid position. Retrieval unsuccessful." << endl;
                }else{
                    cout << "Got " << res << endl;
                }
                break;
            case 'p':
                list->print();
                break;
        }
    }while(op != 'x');


    cout << "Program exited." << endl;
    return 0;
}