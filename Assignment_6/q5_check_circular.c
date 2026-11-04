// q5_check_circular.c - Check if a linked list is a Circular Linked List or not
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int v) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = v;
    n->next = NULL;
    return n;
}

// Walk from head->next: if we come back to head it is circular, if we hit NULL it is not
int isCircular(struct Node* head) {
    struct Node* t;
    if (!head) return 1;
    t = head->next;
    while (t && t != head) t = t->next;
    return t == head;
}

int main() {
    // 2 -> 4 -> 6 -> 7 -> 5
    struct Node *a = newNode(2), *b = newNode(4), *c = newNode(6), *d = newNode(7), *e = newNode(5);
    a->next = b; b->next = c; c->next = d; d->next = e;

    printf("Normal list (5 points to NULL): %s\n", isCircular(a) ? "True" : "False");

    e->next = a;   // make it circular
    printf("Circular list (5 points to 2) : %s\n", isCircular(a) ? "True" : "False");
    return 0;
}
