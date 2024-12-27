#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура узла
typedef struct Node {
    char value[50];
    int priority;
    struct Node* next;
} Node;

// Функции для Priority Queue
typedef struct PriorityQueue {
    Node* head;
} PriorityQueue;

PriorityQueue* createPriorityQueue() {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->head = NULL;
    return pq;
}

void add(PriorityQueue* pq, const char* value, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->value, value);
    newNode->priority = priority;
    newNode->next = NULL;

    if (pq->head == NULL || pq->head->priority < priority) {
        newNode->next = pq->head;
        pq->head = newNode;
    } else {
        Node* current = pq->head;
        while (current->next != NULL && current->next->priority >= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void removePriority(PriorityQueue* pq) {
    if (pq->head == NULL) {
        printf("Очередь пуста\n");
        return;
    }
    Node* removed = pq->head;
    pq->head = pq->head->next;
    free(removed);
}

void displayPriorityQueue(PriorityQueue* pq) {
    Node* current = pq->head;
    if (!current) {
        printf("Очередь пуста\n");
        return;
    }
    while (current) {
        printf("%s (priority %d) -> ", current->value, current->priority);
        current = current->next;
    }
    printf("None\n");
}

// Функции для Queue
typedef struct Queue {
    Node* head;
    Node* tail;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

void enqueue(Queue* queue, const char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->value, value);
    newNode->priority = 0;
    newNode->next = NULL;

    if (queue->tail) {
        queue->tail->next = newNode;
    }
    queue->tail = newNode;
    if (queue->head == NULL) {
        queue->head = newNode;
    }
}

void dequeue(Queue* queue) {
    if (queue->head == NULL) {
        printf("Очередь пуста\n");
        return;
    }
    Node* removed = queue->head;
    queue->head = queue->head->next;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    free(removed);
}

void displayQueue(Queue* queue) {
    Node* current = queue->head;
    if (!current) {
        printf("Очередь пуста\n");
        return;
    }
    while (current) {
        printf("%s -> ", current->value);
        current = current->next;
    }
    printf("None\n");
}

// Функции для Stack
typedef struct Stack {
    Node* head;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->head = NULL;
    return stack;
}

void push(Stack* stack, const char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->value, value);
    newNode->priority = 0;
    newNode->next = stack->head;
    stack->head = newNode;
}

void pop(Stack* stack) {
    if (stack->head == NULL) {
        printf("Стек пуст\n");
        return;
    }
    Node* removed = stack->head;
    stack->head = stack->head->next;
    free(removed);
}

void displayStack(Stack* stack) {
    Node* current = stack->head;
    if (!current) {
        printf("Стек пуст\n");
        return;
    }
    while (current) {
        printf("%s -> ", current->value);
        current = current->next;
    }
    printf("None\n");
}

int main() {
    // Тестирование PriorityQueue
    printf("--- Priority Queue ---\n");
    PriorityQueue* priorityQueue = createPriorityQueue();
    add(priorityQueue, "Task1", 1);
    add(priorityQueue, "Task2", 3);
    add(priorityQueue, "Task3", 2);
    displayPriorityQueue(priorityQueue);
    removePriority(priorityQueue);
    displayPriorityQueue(priorityQueue);

    // Тестирование Queue
    printf("--- Queue ---\n");
    Queue* queue = createQueue();
    enqueue(queue, "Item1");
    enqueue(queue, "Item2");
    enqueue(queue, "Item3");
    displayQueue(queue);
    dequeue(queue);
    displayQueue(queue);

    // Тестирование Stack
    printf("--- Stack ---\n");
    Stack* stack = createStack();
    push(stack, "Element1");
    push(stack, "Element2");
    push(stack, "Element3");
    displayStack(stack);
    pop(stack);
    displayStack(stack);

    return 0;
}
