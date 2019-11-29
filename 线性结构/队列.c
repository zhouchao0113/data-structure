#include <iostream>

using namespace std;

//定义队列
typedef struct Node {
	int *data;
	int Front, Rear;
	int MaxSize;
} *Queue;

//创建队列
Queue CreatQueue(int MaxSize)
{
	Queue queue = (Queue)malloc(sizeof(struct Node));
	queue->data = (int *)malloc(MaxSize * sizeof(int));
	queue->Front = queue->Rear = 0;
	queue->MaxSize = MaxSize;
	
	return queue;
}

//判断队列是否已满
bool isFull(Queue queue)
{
	return (queue->Rear + 1) % queue->MaxSize == queue->Front;
}

//向队列加入元素
void AddQ(Queue queue, int item)
{
	if (isFull(queue))
	{
		printf("队列已满");
	}
	else
	{
		queue->Rear = (queue->Rear + 1) % queue->MaxSize;
		queue->data[queue->Rear] = item;
	}
}

//判断队列是否已空
bool isEmpty(Queue queue)
{
	return queue->Front == queue->Rear;
}

//删除队列中的元素
int DeleteQ(Queue queue)
{
	if (isEmpty(queue))
	{
		printf("队列已空");
	}
	else 
	{
		queue->Front = (queue->Front + 1) % queue->MaxSize;
		return queue->data[queue->Front];
	}
}

int main()
{
	Queue queue = CreatQueue(4);
	AddQ(queue, 1);
	AddQ(queue, 2);
	AddQ(queue, 3);
	while (!isEmpty(queue))
	{
		cout << DeleteQ(queue) << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
