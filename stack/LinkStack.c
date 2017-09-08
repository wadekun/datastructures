// 链表栈
//
// Created by liangck on 2017/9/8.
//

#include <stdio.h>
#include <stdlib.h>

typedef char DataType;  // 栈数据类型

typedef struct stackNode{
    DataType data;
    struct stackNode *next;
}StackNode, *LinkStack;

/**
 * 初始化空栈
 * @return
 */
LinkStack InitStack();

/**
 * 判断栈空
 * @param stack
 * @return
 */
int StackEmpty(LinkStack stack);

/**
 * 入栈
 * @param s
 * @param data
 */
LinkStack Push(LinkStack s, DataType data);

/**
 * 出栈
 * @param s
 * @return
 */
LinkStack Pop(LinkStack s, DataType *x);

/**
 * 获取栈顶元素
 * @param s
 * @return
 */
DataType GetTop(LinkStack s);

/**
 * 打印栈
 * @param s
 */
void PrintStack(LinkStack s);


// ********************* implements *********************

LinkStack InitStack() {
    return NULL;
}

int StackEmpty(LinkStack stack) {
    return stack == NULL;
}

LinkStack Push(LinkStack s, DataType data) {
    StackNode *node = (StackNode*) malloc(sizeof(StackNode));

    if (node) {
        node->data = data;
        node->next = s;
        s = node;
    }

    return s;
}

LinkStack Pop(LinkStack s, DataType *x) {
    if (StackEmpty(s)) {
        printf("the Stack is Empty! /n");
        exit(1);
    }

    StackNode *p = s;
    *x = p->data;
    s = p->next;
    free(p);

    return s;
}

DataType GetTop(LinkStack s) {
    if (StackEmpty(s)) {
        printf("the Stack is Empty! /n");
        return NULL;
    }

    return s->data;
}

void PrintStack(LinkStack s) {
    if (s == NULL) {
        printf("Stack is Empty");
        return;
    }

    StackNode *p = s;
    while (p != NULL) {
        printf("%c\n", p->data);
        p = p->next;
    }
}

int main() {

    // 1. 初始化栈
    LinkStack *s = InitStack();
//    PrintStack(s);
    // 2. 压栈

    s = Push(s, 'a');
//    PrintStack(s);

    s = Push(s, 'b');
//    PrintStack(s);

    s = Push(s, 'c');
//    PrintStack(s);

    s = Push(s, 'd');
//    PrintStack(s);

    s = Push(s, 'e');
//    PrintStack(s);

    s = Push(s, 'f');
//    PrintStack(s);

    printf("print Stack: \n");
    PrintStack(s);
    // 3. 出栈
    char a, b, c;

    s = Pop(s, &a);

    printf("pop stack: %c \n", a); // f
    printf("print Stack: \n");
    PrintStack(s);

    s = Pop(s, &b);
    printf("pop stack: %c \n", b); // e

    s = Pop(s, &c);
    printf("pop stack: %c \n", c); // d

    // 4. 获取栈顶元素
    printf("get stack top: %c \n", GetTop(s)); // c

    // 5. 打印栈
    printf("#########Print Stack: \n");
    PrintStack(s); // c, b, a


    return 0;
}