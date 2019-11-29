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
Graph  CreateGraph(int Size)
{
	Graph graph = (Graph)malloc(sizeof(struct GNode));
	graph->Ne = 0;
	graph->Nv = Size;
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
