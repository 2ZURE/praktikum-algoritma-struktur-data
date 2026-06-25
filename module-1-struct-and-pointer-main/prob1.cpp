#include <iostream>
#include "line.h"
using namespace std;

int main() {
    Line l;
    Point p;

    cin >> l.a >> l.b >> l.c >> p.x >> p.y;

    double value = gradient(&l, &p);
    string result = CheckPointPosition(value);

    cout << result << endl;

    return 0;
}