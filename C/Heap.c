// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_SIZE 100

// struct MinHeap {
//     int *heap;
//     int size;
//     int capacity;
// };

// struct MinHeap* createMinHeap(int capacity) {
//     struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
//     minHeap->capacity = capacity;
//     minHeap->size = 0;
//     minHeap->heap = (int*)malloc(capacity * sizeof(int));
//     return minHeap;
// }

// void swap(int *a, int *b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// void heapifyUp(struct MinHeap* minHeap, int index) {
//     int parent = (index - 1) / 2;
//     if (index && minHeap->heap[parent] > minHeap->heap[index]) {
//         swap(&minHeap->heap[parent], &minHeap->heap[index]);
//         heapifyUp(minHeap, parent);
//     }
// }

// void insert(struct MinHeap* minHeap, int value) {
//     if (minHeap->size == minHeap->capacity) {
//         printf("Heap is full, cannot insert.\n");
//         return;
//     }

//     minHeap->size++;
//     int index = minHeap->size - 1;
//     minHeap->heap[index] = value;
//     heapifyUp(minHeap, index);
// }

// void heapifyDown(struct MinHeap* minHeap, int index) {
//     int left = 2 * index + 1;
//     int right = 2 * index + 2;
//     int smallest = index;

//     if (left < minHeap->size && minHeap->heap[left] < minHeap->heap[smallest]) {
//         smallest = left;
//     }

//     if (right < minHeap->size && minHeap->heap[right] < minHeap->heap[smallest]) {
//         smallest = right;
//     }

//     if (smallest != index) {
//         swap(&minHeap->heap[smallest], &minHeap->heap[index]);
//         heapifyDown(minHeap, smallest);
//     }
// }

// int delete(struct MinHeap* minHeap) {
//     if (minHeap->size == 0) {
//         printf("Heap is empty, cannot delete.\n");
//         return -1;
//     }

//     if (minHeap->size == 1) {
//         minHeap->size--;
//         return minHeap->heap[0];
//     }

//     int deletedValue = minHeap->heap[0];
//     minHeap->heap[0] = minHeap->heap[minHeap->size - 1];
//     minHeap->size--;
//     heapifyDown(minHeap, 0);

//     return deletedValue;
// }

// int main() {
//     struct MinHeap* minHeap = createMinHeap(MAX_SIZE);

//     insert(minHeap, 10);
//     insert(minHeap, 5);
//     insert(minHeap, 15);
//     insert(minHeap, 8);
//     insert(minHeap, 3);

//     printf("Min heap after insertions: ");
//     for (int i = 0; i < minHeap->size; i++) {
//         printf("%d ", minHeap->heap[i]);
//     }
//     printf("\n");

//     int deletedValue = delete(minHeap);
//     printf("Deleted value from min heap: %d\n", deletedValue);

//     printf("Min heap after deletion: ");
//     for (int i = 0; i < minHeap->size; i++) {
//         printf("%d ", minHeap->heap[i]);
//     }
//     printf("\n");

//     free(minHeap->heap);
//     free(minHeap);

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_SIZE 100

// struct MaxHeap {
//     int *heap;
//     int size;
//     int capacity;
// };

// struct MaxHeap* createMaxHeap(int capacity) {
//     struct MaxHeap* maxHeap = (struct MaxHeap*)malloc(sizeof(struct MaxHeap));
//     maxHeap->capacity = capacity;
//     maxHeap->size = 0;
//     maxHeap->heap = (int*)malloc(capacity * sizeof(int));
//     return maxHeap;
// }

// void swap(int *a, int *b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// void heapifyUp(struct MaxHeap* maxHeap, int index) {
//     int parent = (index - 1) / 2;
//     if (index && maxHeap->heap[parent] < maxHeap->heap[index]) {
//         swap(&maxHeap->heap[parent], &maxHeap->heap[index]);
//         heapifyUp(maxHeap, parent);
//     }
// }

// void insert(struct MaxHeap* maxHeap, int value) {
//     if (maxHeap->size == maxHeap->capacity) {
//         printf("Heap is full, cannot insert.\n");
//         return;
//     }

//     maxHeap->size++;
//     int index = maxHeap->size - 1;
//     maxHeap->heap[index] = value;
//     heapifyUp(maxHeap, index);
// }

// void heapifyDown(struct MaxHeap* maxHeap, int index) {
//     int left = 2 * index + 1;
//     int right = 2 * index + 2;
//     int largest = index;

//     if (left < maxHeap->size && maxHeap->heap[left] > maxHeap->heap[largest]) {
//         largest = left;
//     }

//     if (right < maxHeap->size && maxHeap->heap[right] > maxHeap->heap[largest]) {
//         largest = right;
//     }

//     if (largest != index) {
//         swap(&maxHeap->heap[largest], &maxHeap->heap[index]);
//         heapifyDown(maxHeap, largest);
//     }
// }

// int delete(struct MaxHeap* maxHeap) {
//     if (maxHeap->size == 0) {
//         printf("Heap is empty, cannot delete.\n");
//         return -1;
//     }

//     if (maxHeap->size == 1) {
//         maxHeap->size--;
//         return maxHeap->heap[0];
//     }

//     int deletedValue = maxHeap->heap[0];
//     maxHeap->heap[0] = maxHeap->heap[maxHeap->size - 1];
//     maxHeap->size--;
//     heapifyDown(maxHeap, 0);

//     return deletedValue;
// }

// int main() {
//     struct MaxHeap* maxHeap = createMaxHeap(MAX_SIZE);

//     insert(maxHeap, 10);
//     insert(maxHeap, 5);
//     insert(maxHeap, 15);
//     insert(maxHeap, 8);
//     insert(maxHeap, 3);

//     printf("Max heap after insertions: ");
//     for (int i = 0; i < maxHeap->size; i++) {
//         printf("%d ", maxHeap->heap[i]);
//     }
//     printf("\n");

//     int deletedValue = delete(maxHeap);
//     printf("Deleted value from max heap: %d\n", deletedValue);

//     printf("Max heap after deletion: ");
//     for (int i = 0; i < maxHeap->size; i++) {
//         printf("%d ", maxHeap->heap[i]);
//     }
//     printf("\n");

//     free(maxHeap->heap);
//     free(maxHeap);

//     return 0;
// }


#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Heap sort
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}

