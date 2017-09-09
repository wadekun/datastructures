// 链表队列
//
// Created by liangck on 2017/9/9.
//
#include <stdio.h>
#include <stdlib.h>

typedef char DataType; // 链表存储的数据类型

// 链表node
typedef struct qnode {
    DataType data;
    struct qnode *next;
} QueueNode;

// 链表
typedef struct {
    QueueNode *front;
    QueueNode *rear;
}LinkQueue;

// ************** 定义操作 ***************

/**
 * 初始化队列
 * @return
 */
LinkQueue* InitQueue();

/**
 * 判断队列是否为空
 * @param q
 * @return
 */
int QueueEmpty(LinkQueue *q);

/**
 * 入队
 * @param q
 * @param data
 */
void EnQueue(LinkQueue *q, DataType data);

/**
 * 出队
 * @param q
 * @return
 */
DataType DeQueue(LinkQueue *q);

/**
 * 取队列头
 * @param q
 * @return
 */
DataType GetFront(LinkQueue *q);

// ********************* 实现 ******************

LinkQueue* InitQueue() {
    LinkQueue *s = (LinkQueue*)malloc(sizeof(LinkQueue));

    s->front = s->rear = (QueueNode*)malloc(sizeof(QueueNode)); // 初始化时，头尾指针相同，栈为空

    s->front->next = s->rear->next = NULL; // 头尾指针的next指向空

    return s;
}

int QueueEmpty(LinkQueue *q) {
    return q->rear == q->front; // 头尾指针相同，栈为空
}

void EnQueue(LinkQueue *q, DataType data) {
    QueueNode *n = (QueueNode*)malloc(sizeof(QueueNode)); // 创建新节点
    n->data = data;
    n->next = NULL; // 新节点放入队尾，所以next指向空

    // 当前队尾next指向新节点（将新节点链入队列尾部）。
    // 第一次时，因为rear==front,所以front的next也指向新节点。
    q->rear->next = n;
    q->rear = n; // 更新尾指针值，指向新节点
}

DataType DeQueue(LinkQueue *q) {
    if (QueueEmpty(q)) {
        printf("Queue is Empty!\n");
        return NULL;
    }

    QueueNode *f = q->front; // 取出头结点
    DataType data = q->front->next->data; // 取出头结点数据

    free(f); // 回收头节点内存

    q->front = q->front->next; // 当前头指针向后移

    return data; // 返回数据
}

DataType GetFront(LinkQueue *q) {
    if (QueueEmpty(q)) {
        printf("Queue is Empty!\n");
        return NULL;
    }

    return q->front->next->data;
}

int main() {
//    1. 初始化空队列
    LinkQueue *q = InitQueue();

    printf("DeQueue: %c\n", DeQueue(q)); // 先测试取空队列数据
//    2. 入队列
    EnQueue(q, 'a');
    EnQueue(q, 'b');
    EnQueue(q, 'c');
    EnQueue(q, 'd');
    EnQueue(q, 'e');
    EnQueue(q, 'f');

//    3. 出队列
    printf("DeQueue: %c\n", DeQueue(q)); // a
    printf("DeQueue: %c\n", DeQueue(q)); // b
    printf("DeQueue: %c\n", DeQueue(q)); // c

//    4. 获取队列头
    printf("GetFront: %c \n", GetFront(q)); // d

//    5. 出队列至空
    printf("DeQueue: %c\n", DeQueue(q)); // d
    printf("DeQueue: %c\n", DeQueue(q)); // e
    printf("DeQueue: %c\n", DeQueue(q)); // f

    printf("DeQueue: %c\n", DeQueue(q)); // empty queue

    return 0;
}