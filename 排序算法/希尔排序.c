
//希尔排序
void shell_sort(ElementType element[], int N)
{
	int j = 0;
	for (int D = N / 2; D > 0; D = D / 2)
	{
		for (int i = D; i < N; i ++)
		{
			ElementType temp = element[i];
			for (j = i; j >= D&&element[j - D]>temp; j -= D)
			{
				element[j] = element[j - D];
			}
			element[j] = temp;
		}
	}
}

![Alt text](https://github.com/zhouchao0113/Sorting-Algorithm/blob/master/希尔排序.png)
