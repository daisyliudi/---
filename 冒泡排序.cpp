#include<iostream>
using namespace std;

void BubbleSort(int R[], int n)
{
	int i, j, flag;
	int temp;
	for (i = n; i >= 2; --i)//一共需要扫描n-1次
	{
		flag = 0;//标志位，当flag不为0表明上一次交换了
		for (j = 2; j <= i;++j)//从第二个开始和自己前面的比较，如果逆序就交换，第1次扫描扫描到最后一位n，第二次到倒数第二位
			if (R[j - 1] > R[j])
			{
			temp = R[j];
			R[j] = R[j - 1];
			R[j - 1] = temp;
			flag = 1;
			}
		if (flag == 0)
			return;

	}
}
