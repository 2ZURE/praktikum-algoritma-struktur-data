#include "queue.h"

void init(Queue* q) {
    q->front = q->data;
    q->rear = q->data;
}

bool isEmpty(const Queue* q) {
    return q->front == q->rear;
}

bool isFull(const Queue* q) {
    return q->rear == q->data + MAX;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) throw "Queue overflow";
    *(q->rear) = value;
    q->rear++;
}

void dequeue(Queue* q) {
    if (isEmpty(q)) throw "Queue underflow";
    q->front++;
}

int front(const Queue* q) {
    if (isEmpty(q)) throw "Queue kosong";
    return *(q->front);
}

int back(const Queue* q) {
    if (isEmpty(q)) throw "Queue kosong";
    return *(q->rear - 1);
}