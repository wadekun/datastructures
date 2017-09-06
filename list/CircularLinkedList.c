// 循环链表
//
//
// Created by liangck on 2017/9/4.
//
#include <stdlib.h>
#include <stdio.h>

typedef int DataType;

/************** *******************************
 循环链表
**********************************************/

/****** 节点类型 ********/
typedef struct node {
    DataType data; // 存储的数据
    struct node *next; // 指向后继的指针
}ListNode, *LinkedList;

/**
 * 初始化循环列表
 * @return
 */
LinkedList InitList();

/**
 * 获取链表长度
 * @param L
 * @return
 */
int ListLength(LinkedList L);

/**
 * 插入元素
 * @param L
 * @param i
 * @param data
 */
void InsertList(LinkedList L, int i, DataType data);

/**
 * 获取元素位置
 * @param L
 * @param data
 * @return
 */
int LocateNode(LinkedList L, DataType data);

/**
 * 删除元素
 * @param L
 * @param i
 */
void DeleteList(LinkedList L, int i);

/**
 * 获取指定位置元素
 * @param L
 * @param i
 * @return
 */
DataType GetNode(LinkedList L, int i);

/**
 * 打印链表
 * @param L
 */
void PrintList(LinkedList L);

LinkedList InitList() {
    LinkedList L = (LinkedList)malloc(sizeof(LinkedList));
    L->next = L;

    return L;
}

int ListLength(LinkedList L) {
    ListNode *node = L->next;
    int i = 0;

    while (node != L) {
        i++;

        node = node->next;
    }

    return i;
}

void InsertList(LinkedList L, int i, DataType data) {
    if (i <= 0 || i > ListLength(L) + 1) {
        printf("position error: %d", i);
    }

    int j = 0;
    ListNode *tmp = L;
    while (j < i - 1) {
        j++;
        tmp = tmp->next;
    }

    ListNode *n = (ListNode*) malloc(sizeof(ListNode));
    n->data = data;
    n->next = tmp->next;

    tmp->next = n;
}

int LocateNode(LinkedList L, DataType data) {
    int i = 0;
    ListNode *p = L;

    while ((p = p->next) != L) {
        i++;
        if (p->data == data) {
            return i;
        }
    }

    return 0;
}

void DeleteList(LinkedList L, int i) {
    if (i < 1 || i > ListLength(L) + 1) {
        printf("position error：%d \n" + i);
        return;
    }

    int j = 0;
    ListNode *p = L;

    while (j < i - 1) {
        j++;
        p = p->next;
    }

    ListNode *d = p->next;
    p->next = d->next;

    d->next = NULL;
    free(d);
}

void PrintList(LinkedList L) {
    ListNode *p = L;

    while ((p = p->next) != L) {
        printf("%c \n", p->data);
    }
}

DataType GetNode(LinkedList L, int i) {
    if (i < 1 || i > ListLength(L) + 1) {
        printf("position error：%d \n" + i);
        return NULL;
    }

    int j = 0;
    ListNode *p = L;

    while (j < i) {
        j++;
        p = p->next;
    }

    return p->data;
}

int main() {
    // 1. 初始化单向链表
    LinkedList L = InitList();

    // 2. 添加元素
    InsertList(L, 1, 'a');
    InsertList(L, 2, 'b');
    InsertList(L, 3, 'c');
    InsertList(L, 4, 'd');
    InsertList(L, 5, 'e');
    InsertList(L, 6, 'f');

    // 3. 显示表长
    printf("List length : %d \n", ListLength(L)); // 6

    // 4. 元素寻址
    printf("%c position is %d \n", 'c', LocateNode(L, 'c')); // 3

    // 5. 查找
    printf("position %d is %c \n", 4, GetNode(L, 4)); // d

    // 6. 删除
    DeleteList(L, 4); //

    // 7. 打印链表
    PrintList(L); // a, b, c, e, f
}