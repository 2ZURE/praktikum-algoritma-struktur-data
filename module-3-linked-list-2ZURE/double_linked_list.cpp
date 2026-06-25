#include <iostream>
#include "double_linked_list.h"

using namespace std;

void DoubleLinkedList::init() {

    head = nullptr;
    tail = nullptr;
    size = 0;
}

bool DoubleLinkedList::is_empty() {

    return head == nullptr;
}

void DoubleLinkedList::add_front(char val) {

    Node* baru = new Node;
    baru->data = val;
    if (is_empty()) {
        head = baru;
        tail = baru;
        baru->next = head;
        baru->prev = tail;

    } else {
        baru->next = head;
        baru->prev = tail;
        head->prev = baru;
        tail->next = baru;
        head = baru;
        head->prev = tail;
        tail->next = head;
    }
    size++;
}

void DoubleLinkedList::add_back(char val) {

    Node* baru = new Node;
    baru->data = val;
    if (is_empty()) {
        head = baru;
        tail = baru;
        baru->next = head;
        baru->prev = tail;
    } else {
        baru->next = head;
        baru->prev = tail;
        tail->next = baru;
        tail = baru;
        head->prev = tail;
        tail->next = head;
    }
    size++;
}

void DoubleLinkedList::add_idx(char val, int idx) {

    if (idx < 0 || idx > size) {
        return;
    }

    if (idx == 0) {
        add_front(val);
        return;
    }

    if (idx == size) {
        add_back(val);
        return;
    }
    Node* baru = new Node;
    baru->data = val;
    Node* bantu = head;
    for (int i = 0; i < idx; i++) {
        bantu = bantu->next;
    }
    baru->next = bantu;
    baru->prev = bantu->prev;
    bantu->prev->next = baru;
    bantu->prev = baru;
    size++;
}

void DoubleLinkedList::delete_front() {

    if (is_empty()) {
        return;
    }
    if (size == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        Node* hapus = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        delete hapus;
    }
    size--;
}

void DoubleLinkedList::delete_back() {

    if (is_empty()) {
        return;
    }
    if (size == 1) {
        delete tail;
        head = nullptr;
        tail = nullptr;

    } else {
        Node* hapus = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        delete hapus;
    }
    size--;
}

void DoubleLinkedList::delete_idx(int idx) {

    if (idx < 0 || idx >= size) {
        return;
    }
    if (idx == 0) {
        delete_front();
        return;
    }
    if (idx == size - 1) {
        delete_back();
        return;
    }
    Node* bantu = head;
    for (int i = 0; i < idx; i++) {
        bantu = bantu->next;
    }
    bantu->prev->next = bantu->next;
    bantu->next->prev = bantu->prev;
    head->prev = tail;
    tail->next = head;
    delete bantu;
    size--;
}

void DoubleLinkedList::display() {

    if (is_empty()) {
        return;
    }
    Node* bantu = head;
    do {
        cout << bantu->data << " ";
        bantu = bantu->next;
    } while (bantu != head);
    cout << endl;
}

char DoubleLinkedList::get(int idx) {

    if (idx < 0 || idx >= size) {
        return '\0';
    }
    Node* bantu = head;
    for (int i = 0; i < idx; i++) {
        bantu = bantu->next;
    }
    return bantu->data;
}

void DoubleLinkedList::set(char val, int idx) {

    if (idx < 0 || idx >= size) {
        return;
    }
    Node* bantu = head;
    for (int i = 0; i < idx; i++) {
        bantu = bantu->next;
    }
    bantu->data = val;
}

void DoubleLinkedList::clear() {

    while (!is_empty()) {
        delete_front();
    }
}