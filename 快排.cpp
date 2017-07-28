#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int RandomInRange(int start, int end)
{
	int size = start - end + 1;
	return start + rand() % size;

}
int Partition(int data[], int start, int end)
{
	int index = RandomInRange(start, end);
	swap(&data[index], &data[end]);
	int small = start - 1;
	for (index = start; index < end; index++)
	{
		if (data[index] < data[end])
		{
			++small;
			if (small != index)
			{
				swap(&data[index], &data[small]);
			}
		}
	}

	++small;
	swap(&data[small], &data[end]);

	return small;

}
void QuickSort(int data[], int start, int end)
{
	if (start < end)
	{

		int index = Partition(data, start, end);
		QuickSort(data, start, index - 1);
		QuickSort(data, index + 1, end);
	}
}

int main()
{
	int data[] = { 5, 4, 3, 2, 1 };
	QuickSort(data, 0, 4);
	for (int i = 0; i < 5; i++)
		cout << data[i];
}
