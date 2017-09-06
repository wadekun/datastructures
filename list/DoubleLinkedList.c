// 双向链表
//
// Created by liangck on 2017/9/5.
//

#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

/************** *******************************
 循环链表
**********************************************/

/****** 节点类型 ********/
typedef struct DlNode {
    DataType data; // 存储的数据
    struct node *prior, *next; // 指向后继的指针
}DlNode, *DLinkedList;

/**
 * 初始化循环列表
 * @return
 */
DLinkedList InitList();

/**
 * 获取链表长度
 * @param L
 * @return
 */
int ListLength(DLinkedList L);

/**
 * 插入元素
 * @param L
 * @param i
 * @param data
 */
void InsertList(DLinkedList L, int i, DataType data);

/**
 * 获取元素位置
 * @param L
 * @param data
 * @return
 */
int LocateNode(DLinkedList L, DataType data);

/**
 * 删除元素
 * @param L
 * @param i
 */
void DeleteList(DLinkedList L, int i);

/**
 * 获取指定位置元素
 * @param L
 * @param i
 * @return
 */
DataType GetNode(DLinkedList L, int i);

/**
 * 打印链表
 * @param L
 */
void PrintList(DLinkedList L);


DLinkedList InitList() {
    DlNode *h = (DlNode *)malloc(sizeof(DLinkedList)); // 头结点
    h->next = h->prior = h;

    return h;
}

int ListLength(DLinkedList L) {
    DlNode *node = L->next;
    int i = 0;

    while (node != L) {
        i++;

        node = node->next;
    }

    return i;
}

void InsertList(DLinkedList L, int i, DataType data) {
    if (i <= 0 || i > i + 1) {
        printf("position error: %d", i);
        return;
    }

    DlNode *p = L;
    int j = 0;
    while (j < i - 1) {
        j++;
        p = p->next;
    }

    DlNode *s = (DlNode*)malloc(sizeof(DlNode));
    s->data = data;

    DlNode *t = p->next;

    s->prior = p;
    p->next = s;
    s->next = t;
    t->prior = s;
}

int LocateNode(DLinkedList L, DataType data) {
    int j = 0;
    DlNode *t = L;
    while ((t = t->next) != L) {
        j++;
        if (t->data == data) {
            return j;
        }
    }

    return 0;
}

void DeleteList(DLinkedList L, int i) {
    if (i <= 0 || i > ListLength(L)) {
        printf("position error: %d", i);
        return;
    }

    int j = 0;
    DlNode *t = L;
    while (j < i - 1) { // 定位到 i-1 的位置
        j++;
        t = t->next;
    }

    DlNode *s = t->next; // 待删除节点
    t->next = s->next;
    ((DlNode*)s->next)->prior = t;

    s->prior = NULL;
    s->next = NULL;
    free(s);
}

DataType GetNode(DLinkedList L, int i) {
    if (i <= 0 || i > ListLength(L)) {
        printf("position error: %d \n", i);
        return NULL;
    }

    int j = 0;
    DlNode *p = L;
    while (j++ < i) {
        p = p->next;
    }

    return p->data;
}

void PrintList(DLinkedList L) {
    DlNode *p = L;
    while ((p = p->next) != L) {
        printf("%d\n", p->data);
    }
}

int main() {
    // 1. 初始化单向链表
    DLinkedList L = InitList();

    // 2. 添加元素
    InsertList(L, 1, 1);
    InsertList(L, 2, 2);
    InsertList(L, 3, 3);
    InsertList(L, 4, 4);
    InsertList(L, 5, 5);
    InsertList(L, 6, 6);

    // 3. 显示表长
    printf("List length : %d \n", ListLength(L)); // 6

    // 4. 元素寻址
    printf("%d's position is %d \n", 3, LocateNode(L, 3)); // 3

    // 5. 查找
    printf("position %d is %d \n", 4, GetNode(L, 4)); // 4

    // 6. 删除
    DeleteList(L, 4); //

    // 7. 打印链表
    PrintList(L); // 1, 2, 3, 5, 6

    return 0;
}