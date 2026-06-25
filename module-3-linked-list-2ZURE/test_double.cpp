#include <iostream>
#include "double_linked_list.h"

using namespace std;

int main() {

    DoubleLinkedList list;

    list.init();

    cout << "ADD BACK\n";
    list.add_back('A');
    list.add_back('B');
    list.add_back('C');
    list.display();

    cout << "\nADD FRONT\n";
    list.add_front('X');
    list.display();

    cout << "\nADD IDX\n";
    list.add_idx('Z', 2);
    list.display();

    cout << "\nGET IDX 2\n";
    cout << list.get(2) << endl;

    cout << "\nSET IDX 2\n";
    list.set('Y', 2);
    list.display();

    cout << "\nDELETE FRONT\n";
    list.delete_front();
    list.display();

    cout << "\nDELETE BACK\n";
    list.delete_back();
    list.display();

    cout << "\nDELETE IDX 1\n";
    list.delete_idx(1);
    list.display();

    cout << "\nCLEAR\n";
    list.clear();
    list.display();

    return 0;
}