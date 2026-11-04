// q4_dll_palindrome.c - Check if a doubly linked list of characters is a palindrome
#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node *prev, *next;
};

struct Node* insertLast(struct Node* head, char c) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = c;
    n->next = NULL;
    n->prev = NULL;
    if (!head) return n;
    struct Node* t = head;
    while (t->next) t = t->next;
    t->next = n;
    n->prev = t;
    return head;
}

// compare from both ends, moving inwards
int isPalindrome(struct Node* head) {
    struct Node* tail = head;
    if (!head) return 1;
    while (tail->next) tail = tail->next;
    while (head != tail && tail->next != head) {
        if (head->data != tail->data) return 0;
        head = head->next;
        tail = tail->prev;
    }
    return 1;
}

int main() {
    char word[100];
    struct Node* head = NULL;
    int i;
    printf("Enter characters (no spaces): ");
    scanf("%99s", word);
    for (i = 0; word[i] != '\0'; i++) head = insertLast(head, word[i]);
    printf("%s\n", isPalindrome(head) ? "True" : "False");
    return 0;
}
