#include <iostream>

using namespace std;

//有序数列归并
void Merge(int num[], int tempnum[], int left, int right, int rightend)
{
	int leftend = right - 1;

	int count = left;
	int templeft = left;
	while (left <= leftend&&right <= rightend)
	{
		if (num[left] < num[right])
		{
			tempnum[count++] = num[left++];
		}
		else
		{
			tempnum[count++] = num[right++];
		}
	}

	while (left <= leftend)
	{
		tempnum[count++] = num[left++];
	}
	while (right <= rightend)
	{
		tempnum[count++] = num[right++];
	}
	for (int i = 0; i < rightend - templeft + 1; i++)
	{
		num[templeft + i] = tempnum[templeft + i];
	}

}

//分组
void Msort(int num[], int tempnum[], int left, int rightend)
{
	int center;
	if (left < rightend)
	{
		center = (left + rightend) / 2;
		Msort(num, tempnum, left, center);//左递归
		Msort(num, tempnum, center+1, rightend);//左递归
		Merge(num, tempnum, left, center+1, rightend);
	}
}

//归并排序
void Merge_sort(int num[], int size)
{
	int *temp = (int *)malloc(size * sizeof(int));
	Msort(num, temp, 0, size - 1);

}

int main()
{
	int num[] = {5, 4, 3, 2,5,8,2};
	int tempnum[7];
	Merge_sort(num, 7);

	for (int i = 0; i < 7; i++)
	{
		cout << num[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
