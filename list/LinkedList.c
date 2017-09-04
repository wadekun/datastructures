// 链表
//
// Created by liangck on 2017/9/3.
//

#include <stdio.h>
#include <stdlib.h>

typedef char DataType;

/************** *******************************
 单向链表
**********************************************/

/****** 节点类型 ********/
typedef struct node {
    DataType data; // 存储的数据
    struct node * next; // 指向后继的指针
}ListNode, * LinkedList;

// 初始化链表（只有头节点）
LinkedList initLinkedList();

// 头插法
LinkedList createLinkedListH();

// 尾插法
LinkedList createLinkedListT();

// 查找元素
ListNode * GetNode(LinkedList L, DataType i);

// 查询位置
int LocateNode(LinkedList L, DataType data);

// 插入元素
void InsertList(LinkedList L, int i, DataType data);

// 删除元素
void DeleteList(LinkedList L, int i);

// init an empty linkedList
LinkedList initLinkedList() {
    LinkedList head = (LinkedList) malloc(sizeof(LinkedList));
    head->next=NULL;

    return head;
}

// 头插法 创建单向链表
LinkedList createLinkedListH() {
    LinkedList head = (LinkedList) malloc(sizeof(LinkedList)); // 头结点
    head->next = NULL;

    ListNode * p;
    char ch;
    while ((ch = getchar()) != '\n') {
        p = (LinkedList) malloc(sizeof(LinkedList));
        p->data = ch;

        // 把新节点p放入头节点后面
        p->next = head->next;
        head->next = p;
    }

    return head;
}

// 尾插法 创建单向链表
LinkedList createLinkedListT() {
    LinkedList head = (LinkedList) malloc(sizeof(LinkedList)); // 头结点
    head->next = NULL;

    ListNode * t = head; // 临时节点，指向链表尾部
    ListNode * p;
    char ch;
    while ((ch = getchar()) != '\n') {
        p = (LinkedList) malloc(sizeof(LinkedList));
        p->data = ch;

        t->next = p;   // 新节点链入当前尾节点尾部
        p->next = NULL; // 新节点next置空
        t = p; // 将新节点置为尾节点
    }

    return head;
}

// 打印链表
void printLinkedList(LinkedList L) {
//    if (L->next == NULL)
//        printf("the LinkedList is Empty! \n");

    ListNode * node = L;
    while ((node = node->next) != NULL) {
        printf("%c \n", node->data);
    }
}

ListNode * GetNode(LinkedList L, DataType i) {
    if (i <= 0) {
        printf("position error");
        return NULL;
    }

    if (L->next == NULL) {
        printf("the List is Empty !\n");
        return NULL;
    }

    ListNode * node = L;
    int j = 0;
    while ((node = node->next) != NULL) {
        j++;
        if (j == i) {
            return node->data;
        }
    }

    printf("position %d not found !", i);
    return NULL;
}

int LocateNode(LinkedList L, DataType data) {
    if (L->next == NULL) { // List is Empty
        printf("the List is Empty !\n");
        return -1;
    }

    ListNode * node = L;
    int j = 0;
    while ((node = node->next) != NULL) {
        j++;
        if (node->data == data) {
            return j;
        }
    }

    printf("the element %d not found ", (char)data);
    return -1;
}

void InsertList(LinkedList L, int i, DataType data) {

    if (i <= 0) {
        printf("position = %d error, must be grater than 1.", i);
        return;
    }

    ListNode * node = L;
    int j = 0;
    while (j++ < i - 1 ) {
        node = node->next;
        if (node == NULL) { // 在小于i的位置不可能出现node为空的情况
            printf("position: %d ERROR!", i);
            return;
        }
    }

    ListNode * temp = (ListNode *) malloc(sizeof(ListNode));
    temp->data = data;

    temp->next = node->next; // 将该节点链入链表中
    node->next = temp;
}

void DeleteList(LinkedList L, int i) {
    if (i <= 0) {
        printf("position = %d error, must be >= 1.", i);
        return;
    }

    ListNode * node = L;
    int j = 0;
    while (j++ < i - 1 ) {
        node = node->next;
        if (node == NULL) { // 在小于i的位置不可能出现node为空的情况
            printf("position: %d ERROR!", i);
            return;
        }
    }

    ListNode * tmp = node->next; // 取出后继
    node->next = node->next->next; // 将当前节点后继指向后继的后继
//    tmp->next = NULL; // 原后继的节点(即待删除节点)后继置空
//    tmp->data = NULL; // 元素置空,
    free(tmp); // 回收内存
}

int main() {
    // 1. 测试头插法
//    printf("头插法，请输入链表元素（按回车结束）： ");
//    LinkedList L = createLinkedListH(); // 依次输入：a, b, c, d, e, f , 回车
//    printf("开始打印元素 \n");
//    printLinkedList(L); // f, e, d, c, b, a

    // 2. 测试尾插法
    printf("尾插法，请输入链表元素（按回车结束）：");
    LinkedList LT = createLinkedListT(); // 依次输入：a, b, c, d, e, f, 回车
    printf("开始打印元素 \n");
    printLinkedList(LT);
//    printf("%c", LT->next->data);

    // 3. 根据索引查找
    printf("Getnode int position %d : %c \n", 3, GetNode(LT, 3)); // c

    // 4. 查找元素位置
    printf("LocateNode position %c : %d \n", '3', LocateNode(LT, 'c')); // 3

    printLinkedList(LT);

    // 5. 插入元素
    printf("插入元素， position： %d, data: %c \n", 3, 'x');
    InsertList(LT, 3, 'x'); // a, b, x, c, d, e, f,
    printLinkedList(LT);

    // 6. 删除元素
    printf("删除元素， position：%d \n", 4);
    DeleteList(LT, 4);
    printLinkedList(LT); // a, b, x, d, e, f,
}