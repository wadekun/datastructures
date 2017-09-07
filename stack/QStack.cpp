/**
 * author: jianggdong
 */

#include <stdio.h>
#include <stdlib.h>

#define StackSize 100

/*******************************************************************************
定义栈结构体，结构体包括一个用以只是栈顶top变量和一个用于存储数据的数组
*******************************************************************************/
typedef struct{
	int top;
	int stack[StackSize];
}qstack;

/*******************************************************************************
初始化栈，构造一个数组用以存储数据，将所有数据初始为零，栈顶top初始为零
*******************************************************************************/
qstack * Init_Stack();

/*******************************************************************************
判断栈是否为空，若为空返回True，否则返回False
*******************************************************************************/
bool Stack_Empty(qstack * temp);

/*******************************************************************************
判断栈是否为满，若满返回True，否则返回False
*******************************************************************************/
bool Stack_Full(qstack * temp);

/*******************************************************************************
向栈中压入数据n
*******************************************************************************/
void Push(qstack * temp, int n);

/*******************************************************************************
出栈操作
*******************************************************************************/
int Pop(qstack * temp);

/*******************************************************************************
从栈顶向栈底打印栈中所有数据
*******************************************************************************/
void Print_Stack(qstack * temp);

/*******************************************************************************
将一个序列倒置输出
*******************************************************************************/
void Reverse();

/*******************************************************************************
将一个压入栈中的序列按入栈次序输出
*******************************************************************************/
void Forward();

int main(){
	printf("Task 1: Reverse a number sequence\n\n");
	Reverse();
	printf("#####################################\n\n");
	printf("Task 2: Sequential output a number sequence\n\n");
	Forward();
	return 0;
}

qstack * Init_Stack(){
	//构造栈结构体
	qstack * temp = (qstack *)malloc(sizeof(qstack));

	//初始化栈顶变量
	temp->top = 0;

	//初始化数组元素
	for(int i = 0; i < StackSize; i++){
		temp->stack[i] = 0;
	}
	return temp;
}

bool Stack_Empty(qstack * temp){
	if(temp->top == 0)
		return true;

	else
		return false;
}

bool Stack_Full(qstack * temp){
	if(temp->top == StackSize - 1)
		return true;

	else
		return false;
}

void Push(qstack * temp, int n){
	//先判断栈是否满，满则不能压入
	if(Stack_Full(temp))
		printf("Error: Stack Full (n:%d)\n",n);

		//将数据n压入栈中
	else{
		temp->stack[temp->top] = n;
		++temp->top;
	}
}

int Pop(qstack * temp){
	//先判断栈是否空，若空不能出栈
	if(Stack_Empty(temp))
		printf("Error: Stack Empty\n");

		//取栈顶元素并做出栈操作
	else{
		--temp->top;
		return temp->stack[temp->top];
	}
}

void Print_Stack(qstack * temp){
	//先判断栈是否空，若空不能出栈
	if(Stack_Empty(temp))
		printf("Empty Stack");

		//从栈顶往栈底打印元素
	else{
		int n = temp->top;
		printf("top-> ");
		while(n != 0){
			printf("%d ",temp->stack[n-1]);
			--n;
		}
	}
}

void Reverse(){
	//初始化栈
	qstack * qs = Init_Stack();

	//向栈中压入十个数据
	printf("1.1 Push ten numbers in the stack:\n");
	for(int i = 0; i < 10; i++){
		Push(qs,i);
		printf("Push %d (stack):  ",i);
		Print_Stack(qs);
		printf("\n");
	}
	printf("\n*************************************\n\n");

	//将栈中所有数据出栈
	printf("1.2 Pop all numbers from the stack:\n");
	for(int i = 0; i < 10; i++){
		printf("Pop %d (stack):  ",Pop(qs));
		Print_Stack(qs);
		printf("\n");
	}
	printf("\n");
	free(qs);
}

void Forward(){
	//初始化栈
	qstack * qs1 = Init_Stack();
	qstack * qs2 = Init_Stack();

	//向栈1中压入十个数据
	printf("2.1 Push ten numbers in stack #1:\n");
	for(int i = 0; i < 10; i++){
		Push(qs1,i);
		printf("Push %d (stack #1):  ",i);
		Print_Stack(qs1);
		printf("\n");
	}
	printf("\n*************************************\n\n");

	//从栈1中出一个数据压入栈2
	printf("2.2 Pop a number from stack #1 and push it in stack #2:\n");
	for(int i = 0; i < 10; i++){
		int temp = Pop(qs1);
		printf("Pop %d (Stack #1):  ",temp);
		Print_Stack(qs1);
		Push(qs2,temp);
		if(i < 9)
			for(int j = 0; j < i; j++)
				printf("  ");
		else printf("             ");
		printf("Push %d (stack #2):  ",temp);
		Print_Stack(qs2);
		printf("\n");
	}
	printf("\n*************************************\n\n");

	//栈2中所有数据出栈
	printf("2.3 Pop all numbers from stack #2:\n");
	for(int i = 0; i < 10; i++){
		printf("Pop %d (stack):  ",Pop(qs2));
		Print_Stack(qs2);
		printf("\n");
	}
	printf("\n");
	free(qs1);
	free(qs2);
}
 
