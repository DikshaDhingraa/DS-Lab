// q3a_dll_size.c - Size of a doubly linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* insertLast(struct Node* head, int v) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = v;
    n->next = NULL;
    n->prev = NULL;
    if (!head) return n;
    struct Node* t = head;
    while (t->next) t = t->next;
    t->next = n;
    n->prev = t;
    return head;
}

int size(struct Node* head) {
    int count = 0;
    while (head) { count++; head = head->next; }
    return count;
}

int main() {
    struct Node* head = NULL;
    int vals[] = {10, 20, 30, 40, 50, 60};
    int i;
    for (i = 0; i < 6; i++) head = insertLast(head, vals[i]);
    printf("Size of Doubly Linked List = %d\n", size(head));
    return 0;
}
