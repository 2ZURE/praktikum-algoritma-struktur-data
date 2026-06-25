#include "single_linked_list.h"
#include <iostream>
#include <stdexcept>

using namespace std;

void SingleLinkedList::init() {

    head = nullptr;
    tail = nullptr;
    size = 0;
}

bool SingleLinkedList::is_empty() {

    return head == nullptr;
}

void SingleLinkedList::add_front(int val) {

    Node* baru = new Node;
    baru->data = val;

    if (is_empty()) {
        head = baru;
        tail = baru;
        tail->next = head;
    } else {
        baru->next = head;
        head = baru;
        tail->next = head;
    }

    size++;
}

void SingleLinkedList::add_back(int val) {

    Node* baru = new Node;
    baru->data = val;

    if (is_empty()) {
        head = baru;
        tail = baru;
        tail->next = head;
    } else {
        tail->next = baru;
        tail = baru;
        tail->next = head;
    }

    size++;
}

void SingleLinkedList::add_idx(int val, int idx) {

    if (idx < 0 || idx > size) {
        throw out_of_range("Index di luar batas");
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
    for (int i = 0; i < idx - 1; i++) {
        bantu = bantu->next;
    }
    baru->next = bantu->next;
    bantu->next = baru;
    tail->next = head;
    size++;
}

void SingleLinkedList::delete_front() {

    if (is_empty()) {
        throw out_of_range("List kosong");
    }

    if (size == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        Node* hapus = head;
        head = head->next;
        tail->next = head;
        delete hapus;
    }
    size--;
}

void SingleLinkedList::delete_back() {

    if (is_empty()) {
        throw out_of_range("List kosong");
    }

    if (size == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;

    } else {
        Node* bantu = head;
        while (bantu->next != tail) {
            bantu = bantu->next;
        }
        delete tail;
        tail = bantu;
        tail->next = head;
    }
    size--;
}

void SingleLinkedList::delete_idx(int idx) {

    if (idx < 0 || idx >= size) {
        throw out_of_range("Index di luar batas");
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
    for (int i = 0; i < idx - 1; i++) {
        bantu = bantu->next;
    }
    Node* hapus = bantu->next;
    bantu->next = hapus->next;
    tail->next = head;
    delete hapus;
    size--;
}

void SingleLinkedList::display() {

    if (is_empty()) {
        cout << "List kosong\n";
        return;
    }

    Node* bantu = head;
    for (int i = 0; i < size; i++) {
        cout << bantu->data << " ";
        bantu = bantu->next;
    }
    cout << endl;
}

int SingleLinkedList::get(int idx) {

    if (idx < 0 || idx >= size) {
        throw out_of_range("Index di luar batas");
    }
    Node* bantu = head;
    for (int i = 0; i < idx; i++) {
        bantu = bantu->next;
    }
    return bantu->data;
}

void SingleLinkedList::set(int val, int idx) {

    if (idx < 0 || idx >= size) {
        throw out_of_range("Index di luar batas");
    }
    Node* bantu = head;
    for (int i = 0; i < idx; i++) {
        bantu = bantu->next;
    }
    bantu->data = val;
}

void SingleLinkedList::clear() {

    while (size > 0) {
        delete_front();
    }
    head = nullptr;
    tail = nullptr;
}