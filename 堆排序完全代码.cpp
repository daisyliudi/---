#include<iostream>
using namespace std;
//建立大根堆，注意A[0]不存储元素，实际存储从A[1]开始存储

void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = a;
}
void BuildMaxHeap(int A[], int len)
{
	for (int i = len / 2; i > 0; i--)//从i=[len/2]-1反复调整堆
		AdjustDown(A, i, len);

}
void AdjustDown(int A[], int k, int len)
{
	//将元素k向下进行调整
	A[0] = A[k]; // A[0]暂存k的值
	for (int i = 2 * k; i <= len; i *= 2)
	{
		if (i < len&&A[i] < A[i + 1])
			i++;
		if (A[0]>A[i])
			break;//不需要进行调整
		else
		{
			A[k] = A[i];
			k = i;
		}
	}
	A[k] = A[0];//将被筛选结点的值放入最终位置

}
//堆除了可以删除元素之外，还可以增加元素，增加元素是把元素增加到堆的末尾，然后从下到上调整堆
void AdjustUp(int A[], int k)
//参数k为向上调整的结点也为堆的元素个数
{
   A[0] = A[k];
   int i = k / 2;//i此时为双亲结点，若大于双亲结点，则将双亲结点下调
   while (i > 0 && A[i] < A[0])
   {
	   A[k] = A[i];
	   k = i;
	   i = k / 2;//继续向上进行比较
   }
	   A[k] = A[0];


}


void HeapSort(int A[], int len)
{
	BuildMaxHeap(A, len);
	for (int i = len; i > 1; i--)
	{
		Swap(A[i], A[1]);
		AdjustDown(A, 1, i - 1);
	}
}
