#include <iostream>

using namespace std;

void swap(int *num, int a, int b)
{
	int temp = num[a];
	num[a] = num[b];
	num[b] = temp;
}

void quicksort(int *num, int left, int right)
{
	int i = left; int j = right + 1;
	int pivot = num[left];
	
	while (1)
	{
		if (i > right) break;
		while (num[++i] < pivot) {}

		if (j < left) break;
		while (num[--j] > pivot) {}

		if (i > j) break;

		swap(num, i, j);
	}
	swap(num, left, j);

	if (left < right)
	{
		quicksort(num, left, j - 1);
		quicksort(num, j + 1, right);
	}  
}

int main()
{
	int num[7] = { 5,8,9,3,1,5,45 };
	quicksort(num, 0, 6);
	
	for (int i = 0; i < 7; i++)
	{
		cout << num[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
