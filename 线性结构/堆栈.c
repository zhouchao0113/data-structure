#include<iostream>

using namespace std;

//定义节点结构
typedef struct Node {
	int data;
	struct Node *next;
} *PtrToNode;

//创建一个空栈
PtrToNode CreateStack()
{
	PtrToNode Node = (PtrToNode)malloc(sizeof(struct Node));
	Node->next = NULL;

	return Node;
}

//判断一个栈是否为空
bool IsEmpty(PtrToNode stack)
{
	if (stack->next != NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//将一个元素压入堆栈S
void Push(PtrToNode stack, int x)
{
	PtrToNode Node = (PtrToNode)malloc(sizeof(struct Node));
	Node->data = x;
	Node->next = stack->next;
	stack->next = Node;
}

//删除并返回堆栈S的栈顶元素
int Pop(PtrToNode stack)
{
	PtrToNode Node;
	int data;

	if (IsEmpty(stack))
	{
		printf("堆栈空");
		return 0;
	}
	else
	{
		Node = stack->next;
		data = Node->data;
		stack->next = Node->next;
		free(Node);
		return data;
	}
	
	

}

int main()
{
	PtrToNode stack = CreateStack();
	Push(stack, 1);
	Push(stack, 2);
	Push(stack, 3);
	while (stack->next != NULL)
	{
		printf("%d ", Pop(stack));
	}

	system("pause");
	return 0;
}
