// 栈的顺序表示
//
// Created by liangck on 2017/9/7.
//

#include <stdio.h>
#include <stdlib.h>

#define StackSize 100   // 栈空间大小
typedef char DataType;  // 栈数据类型

typedef struct {
    DataType data[StackSize];  // 用数据存放栈数据
    int top;                   // 栈顶指针
}SeqStack;


/**
 * 初始化栈
 * @return
 */
SeqStack* InitStack();

/**
 * 栈是否空
 * @param s
 * @return
 */
int StackEmpty(SeqStack *s);

/**
 * 判断栈满
 * @param s
 * @return
 */
int StackFull(SeqStack *s);

/**
 * 进栈
 * @param s
 */
void Push(SeqStack *s, DataType data);

/**
 * 出栈
 * @param s
 */
DataType Pop(SeqStack *s);

/**
 * 取栈顶元素
 * @param s
 * @return
 */
DataType GetTop(SeqStack *s);

/**
 * 打印栈元素
 * @param s
 */
void PrintStack(SeqStack *s);

// ********************* implements **********************

SeqStack* InitStack() {
    SeqStack *s = (SeqStack*) malloc(sizeof(SeqStack)); // 申请内存

    s->top = -1; // 栈顶指向-1

    for (int i = 0; i < StackSize; ++i) { // 栈内元素赋初值
        s->data[i] = 0;
    }

    return s;
}

int StackEmpty(SeqStack *s) {
    return s->top == -1;
}

int StackFull(SeqStack *s) {
    return s->top == StackSize - 1;
}

void Push(SeqStack *s, DataType data) {
    if (StackFull(s)) {
        printf("stack overflow \n");
    } else {
        s->top = s->top + 1;
        s->data[s->top] = data;
    }
}

DataType Pop(SeqStack *s) {
    if (StackEmpty(s)) {
        printf("stack is Empty \n");
    } else {
        return s->data[s->top--];
    }
}

DataType GetTop(SeqStack *s) {
    if (StackEmpty(s)) {
        printf("stack is Empty \n");
    } else {
        return s->data[s->top];
    }
}

void PrintStack(SeqStack *s) {
    if (StackEmpty(s)) {
        printf("stack is Empty \n");
        return;
    }

    int j = s->top;
    while (j >= 0) {
        printf("%d: %c \n", j, s->data[j--]);
    }
}

int main() {
    // 1. 初始化栈
    SeqStack *s = InitStack();
    // 2. 压栈
    Pop(s); // stack is Empty

    Push(s, 'a');
    Push(s, 'b');
    Push(s, 'c');
    Push(s, 'd');
    Push(s, 'e');
    Push(s, 'f');

    // 3. 出栈
    printf("pop stack: %c \n", Pop(s)); // f
    printf("pop stack: %c \n", Pop(s)); // e
    printf("pop stack: %c \n", Pop(s)); // d

    // 4. 获取栈顶元素
    printf("get stack top: %c \n", GetTop(s)); // c

    // 5. 打印栈
    printf("#########Print Stack: \n");
    PrintStack(s); // c, b, a

    // Push至满
    printf("####################压满栈： \n");
    for (int i = 0; i < 100 - 3; ++i) {
        Push(s, 'x');
    }

    Push(s, 'x'); // overflow
}
