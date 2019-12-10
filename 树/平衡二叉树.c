#include <iostream>

using namespace std;

//平衡二叉树
//空树、或者任一结点左、右子树高度差的绝对值不超过1
//https://blog.csdn.net/qq_24336773/article/details/81712866

//定义
typedef struct AVLNode {
	int data;//结点数据
	struct AVLNode *left;//左子树
	struct AVLNode *right;//右子树
	int height;//高度
}*PtrToAVLNode;
typedef PtrToAVLNode AVLTree;

//深度是从根节点数到它的叶节点，高度是从叶节点数到它的根节点
//二叉树的深度是从根节点开始（其深度为1）自顶向下逐层累加的；而二叉树高度是从叶节点开始（其高度为1）自底向上逐层累加的。
//空树的深度定义为-1

int getHeight(AVLTree t)
{
	if(!t) return 0;
	return t->height;
}

//得到两数的较大值
int Max(int a, int b)
{
	return a > b ? a : b;
}

//左单旋
AVLTree SingleLeftRotation(AVLTree A)
{
	AVLTree B = A->left;
	A->left = B->right;
	B->right = A;

	A->height = Max(getHeight(A->left), getHeight(A->right)) + 1;
	B->height = Max(getHeight(B->left), getHeight(B->right)) + 1;

	return B;
}

//右单旋
AVLTree SingleRightRotation(AVLTree A)
{
	AVLTree B = A->right;
	A->right = B->left;
	B->left = A;

	A->height = Max(getHeight(A->left), getHeight(A->right));
	B->height = Max(getHeight(B->left), getHeight(B->right));

	return B;
}

//左右双旋
AVLTree DoubleLeftRightRotation(AVLTree A)
{
	A->left = SingleRightRotation(A->left);
	return SingleLeftRotation(A);
}

//右左双旋
AVLTree DoubleRightLeftRotation(AVLTree A)
{
	A->right = SingleLeftRotation(A->right);
	return SingleRightRotation(A);
}

AVLTree Insert(AVLTree t, int x)
{
	if (!t)
	{
		t = (AVLTree)malloc(sizeof(struct AVLNode));
		t->data = x;
		t->left = t->right = NULL;
	}
	else if (x < t->data)
	{
		Insert(t->right, x);
		if (getHeight(t->left) - getHeight(t->right) == 2) //左子树高于右子树
		{
			if (x < t->left->data) //左单旋
			{
				t = SingleLeftRotation(t);
			}
			else //左右双旋
			{
				t = DoubleLeftRightRotation(t);
			}
		}
	}
	else if (x > t->data)
	{
		Insert(t->left, x);
		if (getHeight(t->right) - getHeight(t->left) == 2) //右子树高于左子树
		{
			if (x > t->right->data)
			{
				t = SingleRightRotation(t);
			}
			else //右左双旋
			{
				t = DoubleRightLeftRotation(t);
			}
		}
	}

	t->height = Max(getHeight(t->left), getHeight(t->right)) + 1;//更新树高

	return t;
}

int main()
{

	system("pause");
	return 0;
}
