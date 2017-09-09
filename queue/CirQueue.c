// 循环队列
//
// Created by liangck on 2017/9/9.
//

#include <stdio.h>
#include <stdlib.h>
#include "CirQueue.h"


CirQueue* InitQueue() {
    CirQueue *q = (CirQueue*)malloc(sizeof(CirQueue));

//    for (int i = 0; i < QueueSize; ++i) {
//        q->data[i] = 0;
//    }

    q->front = q->rear = 0;

    return q;
}

int QueueEmpty(CirQueue *q) {
    return q->rear == q->front;
}

int QueueFull(CirQueue *q) {
    return (q->rear + 1) % QueueSize == q->front;
}

void EnQueue(CirQueue *q, DataType data) {
    if (QueueFull(q)) {
        printf("Queue Overflow \n");
        return;
    }

    q->data[q->rear] = data;
    q->rear = (q->rear + 1) % QueueSize; // 循环意义下的加1
}

DataType DeQueue(CirQueue *q) {
    if (QueueEmpty(q)) {
        printf("Queue is Empty \n");
        return NULL;
    }

    DataType d = q->data[q->front];
    q->front = (q->front + 1) % QueueSize;

    return d;
}

DataType GetFront(CirQueue *q) {
    if (QueueEmpty(q)) {
        printf("Queue is Empty \n");
        return NULL;
    }

    return q->data[q->front];
}

int main() {

//    1. 初始化空队列
    CirQueue *q = InitQueue();

//    2. 入队列
    EnQueue(q, 'a');
    EnQueue(q, 'b');
    EnQueue(q, 'c');
    EnQueue(q, 'd');
    EnQueue(q, 'e');
    EnQueue(q, 'f');
//    3. 出队列
    printf("dequeue : %c \n", DeQueue(q)); // a
    printf("dequeue : %c \n", DeQueue(q)); // b
    printf("dequeue : %c \n", DeQueue(q)); // c
//    4. 取队头
    printf("Get Queue Head: %c \n", GetFront(q)); // c

//    5. 出队列至空
    printf("dequeue : %c \n", DeQueue(q)); // d
    printf("dequeue : %c \n", DeQueue(q)); // e
    printf("dequeue : %c \n", DeQueue(q)); // f
    printf("dequeue : %c \n", DeQueue(q)); // Queue is Empty

//    6. 入队列至满
    printf("En Queue to Full");

    for (int i = 0; i < 100; ++i) {
        EnQueue(q, 'x');
    }

    EnQueue(q, 'x'); // Queue Overflow

    return 0;
}