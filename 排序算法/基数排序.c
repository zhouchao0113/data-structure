#include<iostream>

using namespace std;

int maxbit(int *num, int size)
{
	int max = num[0];
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (num[i] > max) max = num[i];
	}

	while (max % 10 != 0)
	{
		max = max / 10;
		count++;
	}

	return count;
}

void radixsort(int *num, int size)
{
	int count[10];
	int *tempnum = (int *)malloc(size * sizeof(tempnum));

	int max = maxbit(num, size);
	int radix = 1;
	for (int i = 0; i < max; i++)
	{
		for (int i = 0; i < 10; i++) count[i] = 0;

		for (int i = 0; i < size; i++) count[(num[i] / radix) % 10] ++;

		for (int i = 1; i < 10; i++) count[i] = count[i] + count[i - 1];

		for (int i = size - 1; i >= 0; i--)
		{
			tempnum[count[(num[i] / radix) % 10] - 1] = num[i];
			count[(num[i] / radix) % 10] --;
		}

		for (int i = 0; i < size; i++) num[i] = tempnum[i];

		radix *= 10;
	}

	free(tempnum);
}

int main()
{
	int num[5] = { 2,14,22,33,111 };
	radixsort(num, 5);
	for (int i = 0; i < 5; i++)
	{
		cout << num[i] << " ";
	}
	cout << endl;

	system("pause");
	return  0;
}
