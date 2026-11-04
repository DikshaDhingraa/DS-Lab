// q5_heapsort.c - Heapsort (increasing / decreasing order)
#include <stdio.h>

void swap(int* a, int* b) { int t = *a; *a = *b; *b = t; }

// Max-heap heapify (used for increasing order)
void maxHeapify(int a[], int n, int i) {
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;
    if (largest != i) { swap(&a[i], &a[largest]); maxHeapify(a, n, largest); }
}

// Min-heap heapify (used for decreasing order)
void minHeapify(int a[], int n, int i) {
    int smallest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && a[l] < a[smallest]) smallest = l;
    if (r < n && a[r] < a[smallest]) smallest = r;
    if (smallest != i) { swap(&a[i], &a[smallest]); minHeapify(a, n, smallest); }
}

void heapSortIncreasing(int a[], int n) {
    int i;
    for (i = n / 2 - 1; i >= 0; i--) maxHeapify(a, n, i);   // build max heap
    for (i = n - 1; i > 0; i--) {
        swap(&a[0], &a[i]);          // move largest to the end
        maxHeapify(a, i, 0);
    }
}

void heapSortDecreasing(int a[], int n) {
    int i;
    for (i = n / 2 - 1; i >= 0; i--) minHeapify(a, n, i);   // build min heap
    for (i = n - 1; i > 0; i--) {
        swap(&a[0], &a[i]);          // move smallest to the end
        minHeapify(a, i, 0);
    }
}

void printArray(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int n, i, ch;
    int a[100], b[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) { scanf("%d", &a[i]); b[i] = a[i]; }

    printf("1. Increasing order\n2. Decreasing order\nEnter choice: ");
    scanf("%d", &ch);
    if (ch == 1) { heapSortIncreasing(a, n); printf("Sorted (increasing): "); printArray(a, n); }
    else if (ch == 2) { heapSortDecreasing(b, n); printf("Sorted (decreasing): "); printArray(b, n); }
    else printf("Invalid choice.\n");
    return 0;
}
