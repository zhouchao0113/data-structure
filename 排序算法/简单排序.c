#include <iostream>
using namespace std;

typedef int ElementType;

void Buble_sort(ElementType element[], int N);
void Insertion_sort(ElementType element[], int N);

int main()
{
	ElementType element[5] = { 2, 3, 9 , 4, 1 };
	Buble_sort(element, 5);
	for (int i = 0; i < 5; i++)
	{
		cout << element[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}

void swap(ElementType &a,ElementType &b)
{
	ElementType temp;
	temp = a;
	a = b;
	b = temp;
}

//冒泡排序
void Buble_sort(ElementType element[], int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - i - 1; j++)
		{
			if (element[j] > element[j + 1])
			{
				swap(element[j],element[j+1]);
			}
		}
	}
}

//插入排序
void Insertion_sort(ElementType element[], int N)
{
	ElementType temp;
	int i = 0;
	int j = 0;
	for (i = 1; i < N; i++) //（从第2个数开始）
	{
		temp = element[i]; //插入数为temp
		for (j = i; j > 0 && element[j - 1] > temp; j--) //上一个元素小于新插入的元素
		{
			element[j] = element[j - 1];
		}
		element[j] = temp;

	}

}
