// 线性表顺序结构存储
//
// 时间复杂度：
//    插入：O(n)
//    删除：O(n)
//    遍历：O(n)
//
// Created by liangck on 2017/7/23.

#include <stdio.h>
#include <stdlib.h>

#define ListSize 100 // 表空间的大小应根据实际需要来定义，这里假设为100
typedef int DataType; // DataType 的类型可以根据实际情况而定，这里假设为int
typedef struct {
    DataType data[ListSize]; // 线性数组用来存放表节点
    int length;        // 线性表当前表长（已存储数据个数）
}SeqList;

// 构造一个空栈
SeqList * InitList();

// 获取表长
int ListLength(SeqList * l);

// 获取i位置的元素 1 <= i <= ListLength(l)
DataType GetNode(SeqList * l, int i);

// 获取元素x的位置
int LocateNode(SeqList * l, DataType x);

// 在表l的第i位置前插入x
void InsertList(SeqList * l, int i, DataType x);

// 删除位置i处的元素
void DeleteList(SeqList * l, int i);

SeqList * InitList() {
    SeqList * temp = (SeqList *)malloc(sizeof(SeqList)); // init memory space
    temp->length=0; // init data length

    // init data array
    for (int i = 0; i < ListSize; ++i) {
        temp->data[i] = 0;
    }

    return temp;
}

int ListLength(SeqList * l) {
    return l->length;
}

DataType GetNode(SeqList * l, int i) {
    return l->data[i-1];
}

int LocateNode(SeqList * l, DataType x) {
    if (l->length == 0) { // the data is empty
        return 0;
    }

    for (int i = 0; i < l->length; ++i) {
        if (l->data[i] == x) { // find node and return the position
            return i + 1;
        }
    }

    return 0; // can't find the node x
}

void DeleteList(SeqList * l, int i) {
    if (l->length == 0) {
        printf("the SeqList is empty! \n");
        return;
    }

    if (i < 1 || i > l->length) {
        printf("position error. with position: [%d], data length: [%d]", i, l->length);
        return;
    }

    for (int j = i-1; j < l->length; ++j) {
        l->data[j]=l->data[j+1];
    }

    l->length--; // resize list
}

void InsertList(SeqList * l, int i, DataType x) {
    // valid position
    if (i < 1 || i > l->length + 1) {
        printf("position error! position:[%d], seq length:[%d]\n", i, l->length);
        return;
    }

    if (l->length >= ListSize) {
        printf("list overflow! \n");
        return;
    }

    for (int j = l->length-1; j >= i - 1; j--) { // 倒序遍历至i位置
        l->data[j+1]=l->data[j]; // 元素后移
    }

    // put data and resize
    l->data[i-1] = x;
    l->length++;
}

// main method
int main() {
    // 1. init
    SeqList * seq = InitList();

    // 2. insert data
    InsertList(seq, 1, 1); // {1}
    InsertList(seq, 2, 2); // {1, 2}
    InsertList(seq, 3, 3); // {1, 2, 3}
    // 3. show size

    printf("the SeqList's size: %d \n", ListLength(seq)); // 3

    // 4. get node

    printf("the node at position %d is %d \n", 2, GetNode(seq, 2)); // 2

    // 5. locate node

    InsertList(seq, 4, 2); // {1, 2, 3, 2}

    printf("the position of node 2 is %d \n", LocateNode(seq, 2)); // 2

    // 6. delete node

    DeleteList(seq, 3); // {1, 2, 2}

    // for each
    for (int i = 0; i < seq->length; ++i) {
        printf("seq data[%d]: %d \n", i, seq->data[i]);
    }

    return 0;
}