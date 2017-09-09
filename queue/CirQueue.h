//
// Created by liangck on 2017/9/9.
//

#ifndef DATASTRUCTURES_CIRQUEUE_H
#define DATASTRUCTURES_CIRQUEUE_H

#define QueueSize 100
typedef char DataType;

typedef struct {
    DataType data[QueueSize];
    int front, rear;
}CirQueue;

/**
 * 初始化队列
 * @return
 */
CirQueue* InitQueue();

/**
 * 判断队列是否为空
 * @param q
 * @return
 */
int QueueEmpty(CirQueue *q);

/**
 * 判断队列满
 * @param q
 * @return
 */
int QueueFull(CirQueue *q);

/**
 * 入队
 * @param q
 * @param data
 */
void EnQueue(CirQueue *q, DataType data);

/**
 * 出队
 * @param q
 * @return
 */
DataType DeQueue(CirQueue *q);

/**
 * 取队列头
 * @param q
 * @return
 */
DataType GetFront(CirQueue *q);

#endif //DATASTRUCTURES_CIRQUEUE_H
