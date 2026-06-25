#include <iostream>
#include "single_linked_list.h"

using namespace std;

int main() {

    SingleLinkedList list;

    list.init();

    cout << "ADD BACK\n";
    list.add_back(1);
    list.add_back(2);
    list.add_back(3);
    list.display();

    cout << "\nADD FRONT\n";
    list.add_front(10);
    list.display();

    cout << "\nADD IDX\n";
    list.add_idx(99, 2);
    list.display();

    cout << "\nGET IDX 2\n";
    cout << list.get(2) << endl;

    cout << "\nSET IDX 2\n";
    list.set(100, 2);
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