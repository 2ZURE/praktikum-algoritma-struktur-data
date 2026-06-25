#include <iostream>
#include "single_linked_list.h"

using namespace std;

int main() {

    int n, k;
    cin >> n >> k;
    int awal = k;
    SingleLinkedList list;
    list.init();

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        list.add_back(x);
    }

    int pos = 0;

    while (list.size > 1) {
        pos = (pos + k - 1) % list.size;
        int val = list.get(pos);
        list.delete_idx(pos);
        if (val % 2 == 0) {
            k++;
        } else {
            k--;
        }
        if (k <= 0) {
            k = awal;
        }
        if (pos >= list.size) {
            pos = 0;
        }
    }
    cout << list.get(0) << endl;
    return 0;
}