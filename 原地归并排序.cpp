#include<iostream>
using namespace std;
void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void reverse(int A[], int len)//将长度为len的数组逆序
{
	int i = 0,j = len - 1;
	while (i < j)
	{
		Swap(A[i], A[j]);
		i++;
		j--;

	}

}
void exchange(int A[], int len, int i)//将含有n个元素的数组向左循环移位i个位置
{
	reverse(A, i);
	reverse(A + i, len- i);
	reverse(A, len);

}
//将两个有序部分归并
void Merge(int A[], int start, int mid, int end)
{
	int i = start, j = mid, k = end;
	while (i < j&&j <= k)
	{
		int step = 0;
		while(i < j&&A[i] <=A[j])
			i++;
		while (j <= k&&A[j] <= A[i])//当j大于k时也会停止
		{
			j++;
			step++;
		}
		exchange(A + i, j - i, j - i - step);//为什么是j-i，找到j，是j之前的数，所以j-1-i+1，而step，记录下第二次的步数，然后总数减
		i = i + step;
	}
}
void MergeSort(int A[], int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		MergeSort(A, start, mid);
		MergeSort(A, mid + 1, end);
		Merge(A, start, mid + 1, end);
	}
}
