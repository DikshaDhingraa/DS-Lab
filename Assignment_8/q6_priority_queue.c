// q6_priority_queue.c - Priority queue using a max-heap (highest priority value is served first)
#include <stdio.h>
#define MAX 100

int heap[MAX];
int size = 0;

void swap(int* a, int* b) { int t = *a; *a = *b; *b = t; }

void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[(i - 1) / 2], &heap[i]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(int i) {
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < size && heap[l] > heap[largest]) largest = l;
    if (r < size && heap[r] > heap[largest]) largest = r;
    if (largest != i) { swap(&heap[i], &heap[largest]); heapifyDown(largest); }
}

void enqueue(int v) {
    if (size == MAX) { printf("Queue is full.\n"); return; }
    heap[size] = v;
    heapifyUp(size);
    size++;
}

int dequeue() {          // removes and returns highest priority element
    int top;
    if (size == 0) { printf("Queue is empty.\n"); return -1; }
    top = heap[0];
    heap[0] = heap[--size];
    heapifyDown(0);
    return top;
}

void peek() {
    if (size == 0) printf("Queue is empty.\n");
    else printf("Highest priority element = %d\n", heap[0]);
}

void display() {
    int i;
    if (size == 0) { printf("Queue is empty.\n"); return; }
    printf("Heap array: ");
    for (i = 0; i < size; i++) printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    int ch, v;
    do {
        printf("\n--- Priority Queue (Max Heap) ---\n1. Enqueue\n2. Dequeue\n"
               "3. Peek\n4. Display\n0. Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Value: "); scanf("%d", &v); enqueue(v); break;
            case 2: v = dequeue(); if (v != -1) printf("Dequeued: %d\n", v); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 0: printf("Bye!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (ch != 0);
    return 0;
}
