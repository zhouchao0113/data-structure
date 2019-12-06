/****图的临接矩阵表示法****/
#define MaxSize 100
#define Infinity 65535;

//定义边结点
typedef struct ENode {
	int v1, v2;//边
	int weight;//权重
}*PtrToENode;
typedef PtrToENode Edge;

//定义图结点
typedef struct GNode {
	int Nv;//顶点数
	int Ne;//结点数
	int G[MaxSize][MaxSize];//临接矩阵
} *PtrToGNode;
typedef PtrToGNode MGraph;

//创建图
MGraph  CreateGraph(int VertexNum)
{
	Graph graph = (Graph)malloc(sizeof(struct GNode));
	graph->Ne = 0;
	graph->Nv = VertexNum;
	for (int i = 0; i < graph->Nv; i++)
	{
		for (int j = 0; j < graph->Nv; j++)
		{
			graph->G[i][j] = Infinity;
		}
	}
	return graph;
}

//将边插入图
void InsertEdge(MGraph graph, Edge edge)
{
	graph->G[edge->v1][edge->v2] = edge->weight;
	graph->G[edge->v2][edge->v1] = edge->weight;
}

//队列定义
typedef struct Node {
	int front, rear;
	int *data;
	int maxsize;
}*PtrToNode;
typedef PtrToNode Queue;

//队列创建
Queue CreateQueue(int size)
{
	Queue q = (Queue)malloc(sizeof(struct Node));
	q->maxsize = size;
	q->front = q->rear = 0;
	q->data = (int *)malloc(sizeof(int));
}

//判断满
bool isFull(Queue q)
{
	return (q->rear + 1) % q->maxsize == q->front;
}

//队列插入
void InsertQ(Queue q, int x)
{
	if (isFull(q))
	{
		printf("full");
	}
	else
	{
		q->rear = (q->rear + 1) % q->maxsize;
		q->data[q->rear] = x;
	}
}

//判断空
bool isEmpty(Queue q)
{
	return q->rear == q->front;
}

//队列删除
int DeleteQ(Queue q)
{
	if (isEmpty(q))
	{
		printf("empty");
		return 0;
	}
	else
	{
		int temp = q->data[q->rear];
		q->rear = (q->rear + 1) % q->maxsize;
		return temp;
	}
	
}

//判断有没有边
bool isEdge(MGraph graph, int v1, int v2)
{
	return graph->G[v1][v2] > Inifity ? true : false;
}

//BFS
void BFS(MGraph graph, int s, int *visited)
{
	Queue q = CreateQueue(MaxNum);
	visited[s] = true;
	InsertQ(q, s);
	int v1, v2;
	while (!isEmpty(q))
	{
		v1 = DeleteQ(q);
		for (v2= 0; v2 < graph->Nv; v2++)
		{
			if (!visited[v2] && isEdge(graph, v1, v2))
			{
				visited[v2] = true;
				InsertQ(q, v2);
			}
		}
	}

}
