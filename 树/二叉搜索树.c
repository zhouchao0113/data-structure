#include <iostream>

using namespace std;

//二叉搜索树：一棵二叉树，可以为空；如果不为空，满足以下性质：
//1. 非空左子树的所有键值小于其根结点的键值。
//2. 非空右子树的所有键值大于其根结点的键值。
//3. 左、右子树都是二叉搜索树。

//定义
typedef struct TNode {
	int data;
	struct TNode *left;
	struct TNode *right;
}*PtrToTNode;
typedef PtrToTNode BinTree;

//查找元素
PtrToTNode find(BinTree bst, int x)
{
	if (!bst) 
		return NULL;//没找到
	else if (x < bst->data)
		return find(bst->left, x);
	else if(x > bst->data)
		return find(bst->right, x);
	else
		return bst;
}

//查找最小元素
PtrToTNode findMin(BinTree bst) //最小元素一定是在树的最左分枝的端结点上
{
	if (!bst) 
		return NULL;
	else if (!bst->left)
		return bst;
	else
		return findMin(bst->left);
}

//查找最大元素
PtrToTNode findMax(BinTree bst)
{
	if (!bst)
		return NULL;
	else if (!bst->right)
		return bst;
	else
		return findMax(bst->right);
}

//插入
BinTree InserBT(BinTree bst, int x)
{
	if (!bst)
	{
		bst = (BinTree)malloc(sizeof(struct TNode));
		bst->data = x;
		bst->left = bst->right = NULL;
	}
	else if (x < bst->data)
	{
		bst->left = InserBT(bst->left, x);
	}
	else if (x > bst->data)
	{
		bst->right = InserBT(bst->right, x);
	}
	return bst;
}

//删除
BinTree Delete(BinTree bst, int x)
{
	if (!bst)
	{
		printf("failed");
		return NULL;
	}	
	else if (x < bst->data)
	{
		bst->left = Delete(bst->left, x);
	}
	else if (x > bst->data)
	{
		bst->right = Delete(bst->right, x);
	}
	else //找到了要删除的点
	{
		PtrToTNode Node;
		if (bst->left&&bst->right) //取右子树中的最小元素替代 或 取左子树中的最大元素替代
		{
			Node = findMin(bst->right); //取右子树中的最小元素替代
			bst->data = Node->data;
			bst->right = Delete(bst, Node->data);
		}
		else
		{
			if (!bst -> left)
			{
				Node = bst->right;
				bst = bst->right;
				free(Node);
			}
			else if (!bst->right)
			{
				Node = bst->left;
				bst = bst->left;
				free(Node);
			}
		}
	}
}


int main()
{
	BinTree bst = NULL;
	bst = InserBT(bst, 3);
	bst = InserBT(bst, 2);
	bst = InserBT(bst, 4);
	system("pause");
	return 0;
}
