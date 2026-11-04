// q1a_dll_menu.c - Menu driven program: Doubly Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* head = NULL;

struct Node* newNode(int v) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = v;
    n->prev = n->next = NULL;
    return n;
}

struct Node* findNode(int key) {
    struct Node* t = head;
    while (t && t->data != key) t = t->next;
    return t;
}

void insertFirst(int v) {
    struct Node* n = newNode(v);
    n->next = head;
    if (head) head->prev = n;
    head = n;
}

void insertLast(int v) {
    struct Node* n = newNode(v);
    if (!head) { head = n; return; }
    struct Node* t = head;
    while (t->next) t = t->next;
    t->next = n;
    n->prev = t;
}

void insertAfter(int key, int v) {
    struct Node* p = findNode(key);
    if (!p) { printf("Node %d not found.\n", key); return; }
    struct Node* n = newNode(v);
    n->next = p->next;
    n->prev = p;
    if (p->next) p->next->prev = n;
    p->next = n;
}

void insertBefore(int key, int v) {
    struct Node* p = findNode(key);
    if (!p) { printf("Node %d not found.\n", key); return; }
    if (p == head) { insertFirst(v); return; }
    struct Node* n = newNode(v);
    n->prev = p->prev;
    n->next = p;
    p->prev->next = n;
    p->prev = n;
}

void deleteNode(int key) {
    struct Node* p = findNode(key);
    if (!p) { printf("Node %d not found.\n", key); return; }
    if (p->prev) p->prev->next = p->next;
    else head = p->next;
    if (p->next) p->next->prev = p->prev;
    free(p);
    printf("Node %d deleted.\n", key);
}

void searchNode(int key) {
    int pos = 1;
    struct Node* t;
    for (t = head; t; t = t->next, pos++)
        if (t->data == key) { printf("%d found at position %d.\n", key, pos); return; }
    printf("%d not found.\n", key);
}

void display() {
    struct Node* t;
    if (!head) { printf("List is empty.\n"); return; }
    for (t = head; t; t = t->next) printf("%d%s", t->data, t->next ? " <-> " : "\n");
}

int main() {
    int ch, v, k;
    do {
        printf("\n--- Doubly Linked List ---\n"
               "1. Insert at first\n2. Insert at last\n3. Insert after a node\n"
               "4. Insert before a node\n5. Delete a node\n6. Search a node\n"
               "7. Display\n0. Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Value: "); scanf("%d", &v); insertFirst(v); break;
            case 2: printf("Value: "); scanf("%d", &v); insertLast(v); break;
            case 3: printf("After which node: "); scanf("%d", &k); printf("Value: "); scanf("%d", &v); insertAfter(k, v); break;
            case 4: printf("Before which node: "); scanf("%d", &k); printf("Value: "); scanf("%d", &v); insertBefore(k, v); break;
            case 5: printf("Node to delete: "); scanf("%d", &k); deleteNode(k); break;
            case 6: printf("Node to search: "); scanf("%d", &k); searchNode(k); break;
            case 7: display(); break;
            case 0: printf("Bye!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (ch != 0);
    return 0;
}
