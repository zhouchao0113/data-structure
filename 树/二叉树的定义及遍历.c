#include <iostream>

using namespace std;

//定义
typedef struct Node {
	int data;//数据
	struct Node *left;//左子树
	struct Node *right;//右子树
}*PtrToNode;
typedef PtrToNode BinTree;

//创建
BinTree CreatBinTree()
{
	PtrToNode Node = (PtrToNode)malloc(sizeof(struct Node));
	Node->left = NULL;
	Node->right = NULL;
	return 0;
}

////插入
//void InsertBinTree(BinTree bt, int x)
//{
//
//}

//判断是否空
bool isEmpty(BinTree bt)
{
	return bt == NULL;
}

//先序遍历
void PreOrderTraversal(BinTree bt)
{
	if (bt)
	{
		printf("%d ", bt->data);
		PreOrderTraversal(bt->left);
		PreOrderTraversal(bt->right);
	}
}

//中序遍历
void InOrderTraversal(BinTree bt)
{
	if (bt)
	{
		InOrderTraversal(bt->left);
		printf("%d ", bt->data);
		InOrderTraversal(bt->right);
	}
}

//后序遍历
void PostOrderTraversal(BinTree bt)
{
	if (bt)
	{
		PostOrderTraversal(bt->left);
		PostOrderTraversal(bt->right);
		printf("%d ", bt->data);
	}
}

//定义队列结点
typedef struct QNode {
	PtrToNode *data;
	int front, rear;
	int MaxSize;
}*PtrToQNode;
typedef PtrToQNode Queue;

//创建队列
Queue CreateQ(int size)
{
	Queue q = (Queue)malloc(sizeof(struct QNode));
	q->data = (PtrToNode *)malloc(size * sizeof(PtrToQNode));
	q->MaxSize = size;
	q->front = q->rear = 0;
	return q;
}

//判断队列是否已满
bool isFull(Queue q)
{
	return (q->rear + 1) % q->MaxSize == q->front;
}

//插入
void AddQ(Queue q, PtrToNode x)
{
	if (isFull(q))
	{
		printf("full");
	}
	else
	{
		q->rear = (q->rear + 1) % q->MaxSize;
		q->data[q->rear] = x;
	}
}

//判断队列是否已空
bool isEmpty(Queue q)
{
	return q->front == q->rear;
}

//删除
PtrToNode DeleteQ(Queue q)
{
	if (isEmpty(q))
	{
		printf("empty");
		return 0;
	}
	else
	{
		PtrToNode temp = q->data[q->rear];
		q->rear = (q->rear - 1) % q->MaxSize;
	}
}

//层次遍历
void LevelOrderTraversal(BinTree bt)
{
	if (!bt) return;
	Queue q = CreateQ(10);
	PtrToNode Node;
	AddQ(q, bt);
	while (!isEmpty(q))
	{
		Node = DeleteQ(q);
		printf("%d ", Node->data);
		if (Node->left) AddQ(q, Node->left);
		if (Node->right) AddQ(q, Node->right);
	}

}

int main()
{

	system("pause");
	return 0;
}
