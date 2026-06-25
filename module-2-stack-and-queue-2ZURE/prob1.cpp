#include <iostream>
#include <sstream>
#include "stack.h"
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    string input;
    getline(cin, input);

    stringstream ss(input);
    string token;

    Stack s;
    init(&s);

    try {
        while (ss >> token) {
            // angka
            if (isdigit(token[0]) || token.size() > 1) {
                push(&s, stoi(token));
            } else {
                int b = peek(&s); pop(&s);
                int a = peek(&s); pop(&s);

                int hasil;

                if (token == "+") hasil = a + b;
                else if (token == "-") hasil = a - b;
                else if (token == "*") hasil = a * b;
                else if (token == "/") hasil = a / b;

                push(&s, hasil);
            }
        }

        cout << peek(&s) << endl;

    } catch (const char* err) {
        cout << err << endl;
    }

    return 0;
}