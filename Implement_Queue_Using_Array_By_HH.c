#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int front, rear, size;
    unsigned capacity;
    int* array;
} Queue;
Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}
int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}
int isEmpty(Queue* queue) {
    return (queue->size == 0);
}
void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
    printf("%d enqueued to queue\n", item);
}
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}
int front(Queue* queue) {
    if (isEmpty(queue))
        return -1;
    return queue->array[queue->front];
}
int rear(Queue* queue) {
    if (isEmpty(queue))
        return -1;
    return queue->array[queue->rear];
}
int main() {
    Queue* queue = createQueue(MAX_SIZE);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    printf("Front element: %d\n", front(queue));
    printf("Rear element: %d\n", rear(queue));

    printf("Dequeued item: %d\n", dequeue(queue));
    printf("Front element after dequeue: %d\n", front(queue));
    return 0;
}
