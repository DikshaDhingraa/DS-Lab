// q1b_cll_menu.c - Menu driven program: Circular Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* newNode(int v) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = v;
    n->next = NULL;
    return n;
}

struct Node* getLast() {
    struct Node* t = head;
    if (!head) return NULL;
    while (t->next != head) t = t->next;
    return t;
}

struct Node* findNode(int key) {
    struct Node* t = head;
    if (!head) return NULL;
    do {
        if (t->data == key) return t;
        t = t->next;
    } while (t != head);
    return NULL;
}

void insertFirst(int v) {
    struct Node* n = newNode(v);
    if (!head) { n->next = n; head = n; return; }
    struct Node* last = getLast();
    n->next = head;
    last->next = n;
    head = n;
}

void insertLast(int v) {
    struct Node* n = newNode(v);
    if (!head) { n->next = n; head = n; return; }
    struct Node* last = getLast();
    last->next = n;
    n->next = head;
}

void insertAfter(int key, int v) {
    struct Node* p = findNode(key);
    if (!p) { printf("Node %d not found.\n", key); return; }
    struct Node* n = newNode(v);
    n->next = p->next;
    p->next = n;
}

void insertBefore(int key, int v) {
    struct Node *p = findNode(key), *prev;
    if (!p) { printf("Node %d not found.\n", key); return; }
    if (p == head) { insertFirst(v); return; }
    prev = head;
    while (prev->next != p) prev = prev->next;
    struct Node* n = newNode(v);
    n->next = p;
    prev->next = n;
}

void deleteNode(int key) {
    struct Node *p, *prev;
    if (!head) { printf("List is empty.\n"); return; }
    p = findNode(key);
    if (!p) { printf("Node %d not found.\n", key); return; }
    if (p == head && p->next == head) {
        free(p);
        head = NULL;
    } else {
        prev = head;
        while (prev->next != p) prev = prev->next;   // for head, prev becomes last node
        prev->next = p->next;
        if (p == head) head = p->next;
        free(p);
    }
    printf("Node %d deleted.\n", key);
}

void searchNode(int key) {
    int pos = 1;
    struct Node* t = head;
    if (!head) { printf("List is empty.\n"); return; }
    do {
        if (t->data == key) { printf("%d found at position %d.\n", key, pos); return; }
        t = t->next;
        pos++;
    } while (t != head);
    printf("%d not found.\n", key);
}

void display() {
    struct Node* t = head;
    if (!head) { printf("List is empty.\n"); return; }
    do {
        printf("%d -> ", t->data);
        t = t->next;
    } while (t != head);
    printf("(back to head %d)\n", head->data);
}

int main() {
    int ch, v, k;
    do {
        printf("\n--- Circular Linked List ---\n"
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
