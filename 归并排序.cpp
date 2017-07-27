#include<iostream>
using namespace std;
//将有序数组a[]和b[]合并到c[]中
void Merge(int a[], int n, int b[], int m, int c[])
{
	int i, j,k;
	i = j = k = 0;
	while (i < n&&j < m)
	{
		if (a[i] < b[j])
			c[k++] = a[i++];
		else
			c[k++] = b[j++];
	}
	while (i < n)
		c[k++] = a[i++];
	while (j < m)
		c[k++] = b[j++];
}
//合并有序数列的效率是比较高的，可以达到O(n)

//归并排序，其的基本思路就是将数组分成二组A，B，如果这二组组内的数据都是有序的，
//那么就可以很方便的将这二组数据进行排序。如何让这二组组内数据有序了？

//可以将A，B组各自再分成二组。依次类推，当分出来的小组只有一个数据时，可以认为这个小组组内已经达到了有序，
//然后再合并相邻的二个小组就可以了。这样通过先递归的分解数列，再合并数列就完成了归并排序。
//将两个有序数列a[first...mid]和a[mid....last]合并
void Mergearray(int a[], int first, int mid, int last, int temp[])
{
	int i = first, j = mid + 1;
	int m = mid, n = last;
	int k = 0;
	while (i <= m&&j <= n)
	{
		if (a[i] < a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];

	}
	while (i <= m)
		temp[k++] = a[i++];
	while (j <= m)
		temp[k++] = a[j++];
	//最后元素个数是k个
	for (i = 0; i < k; i++)
		a[first + i] = temp[i];
}
void MergeSort(int a[], int first, int last, int temp[])
{
	//if(first==last)此时只有一个元素，已经排好序，什么也不用做
	if (first < last)
	{
		int mid = (first + last) / 2;
		MergeSort(a, first, mid, temp);//左边有序
		MergeSort(a, mid + 1, last, temp);//右边有序
		Mergearray(a, first, mid, last, temp);
	}
		  
}
bool MergeSortBegin(int a[], int n)
{
	int  *p = new int[n];
	if (p == NULL)
		return false;
	MergeSort(a, 0, n - 1, p);
	delete[] p;
	return true;

}
