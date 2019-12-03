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
	int Graph[MaxSize][MaxSize];//临接矩阵
} *PtrToGNode;
typedef PtrToGNode Graph;

//创建图
Graph  CreateGraph(int VertexNum)
{
	Graph graph = (Graph)malloc(sizeof(struct GNode));
	graph->Ne = 0;
	graph->Nv = VertexNum;
	for (int i = 0; i < graph->Nv; i++)
	{
		for (int j = 0; j < graph->Nv; j++)
		{
			graph->Graph[i][j] = Infinity;
		}
	}
	return graph;
}

//将边插入图
void InsertEdge(Graph graph, Edge edge)
{
	graph->Graph[edge->v1][edge->v2] = edge->weight;
	graph->Graph[edge->v2][edge->v1] = edge->weight;
}



/*****图的邻接表表示****/
#define MaxSize 100
//定义边结点
typedef struct ENode {
	int v1, v2;//结点
	int weight;//权重
}*PtrToENode;
typedef PtrToENode Edge;

//定义邻接点
typedef struct AdjVNode {
	int AdjV;//邻接点
	int weight;//边权重
	struct AdjVNode *next;//下一个邻接点
}*PtrToAdjVNode;

//定义表头结点
typedef struct VNode {
	PtrToAdjVNode first;//头指针
	int data;//结点数据
}AdjList[MaxSize];

//定义图结点
typedef struct GNode {
	int Ne;//边数量
	int Nv;//顶点数量
	AdjList graph;
}*PtrToGNode;
typedef PtrToGNode Graph;

//初始化图
Graph CreateGraph(int VertexNum)
{
	Graph graph = (Graph)malloc(sizeof(struct GNode));
	graph->Nv = VertexNum;
	graph->Ne = 0;
	for (int i = 0; i < VertexNum; i++) graph->graph[i].first = NULL;
}

//插入边
void InsertEdge(Graph graph, Edge edge)
{
	//新建邻接点
	PtrToAdjVNode Node = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	Node->AdjV = edge->v2;
	Node->weight = edge->weight;
	//将v1插入v2
	Node->next = graph->graph[edge->v1].first;
	graph->graph[edge->v1].first = Node->next;

	//新建邻接点
	PtrToAdjVNode Node2 = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	Node2->AdjV = edge->v1;
	Node2->weight = edge->weight;

	Node->next = graph->graph[edge->v2].first;
	graph->graph[edge->v2].first = Node->next;
}

//深度优先遍历
void DFS(LGraph graph, int v,int *visited)
{
	PtrToAdjNode *Node;
	visited[v] = true;

	for (Node = graph->G[v].first; Node; Node = Node->next)
	{
		if (!visited[Node->AdjV])
		{
			DFS(graph, Node->AdjV, visited);
		}
	}
}
