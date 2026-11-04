// q2_cll_display.c - Display circular linked list, repeating head value at the end
// Input: 20 -> 100 -> 40 -> 80 -> 60     Output: 20 100 40 80 60 20
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

void display(struct Node* head) {
    struct Node* t = head;
    if (!head) { printf("List is empty.\n"); return; }
    do {
        printf("%d ", t->data);
        t = t->next;
    } while (t != head);
    printf("%d\n", head->data);   // repeat head value
}

int main() {
    struct Node* head = NULL;
    int vals[] = {20, 100, 40, 80, 60};
    int i;
    for (i = 0; i < 5; i++) head = insertLast(head, vals[i]);
    printf("Output: ");
    display(head);
    return 0;
}
