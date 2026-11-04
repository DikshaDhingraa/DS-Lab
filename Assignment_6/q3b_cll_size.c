// q3b_cll_size.c - Size of a circular linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertLast(struct Node* head, int v) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = v;
    if (!head) { n->next = n; return n; }
    struct Node* t = head;
    while (t->next != head) t = t->next;
    t->next = n;
    n->next = head;
    return head;
}

int size(struct Node* head) {
    int count = 0;
    struct Node* t = head;
    if (!head) return 0;
    do {
        count++;
        t = t->next;
    } while (t != head);
    return count;
}

int main() {
    struct Node* head = NULL;
    int vals[] = {20, 100, 40, 80, 60};
    int i;
    for (i = 0; i < 5; i++) head = insertLast(head, vals[i]);
    printf("Size of Circular Linked List = %d\n", size(head));
    return 0;
}
