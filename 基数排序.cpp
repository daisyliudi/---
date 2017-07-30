#include<iostream>
#include<vector>
using namespace std;
int GetNumInPos(int num, int pos)
{
	int temp;
	for (int i = 1; i <= (pos - 1); i++)
		temp *= 10;
	return (num / temp) % 10;
}
/***************************************************
*函数名称:RadixSort
*参数说明:ivec为无序数组
*基数排序
****************************************************/
#define RADIX_10 10//整型排序
#define KEYNUM_31 10//关键字个数，这里为整型位数

vector<int>& RadixSort(vector<int> &OriginData,int DataNum)
{
	vector<vector<int> > SpaceForSort(10,vector<int>(DataNum+1,0));//多出来的那位用来存储当前位数组的个数
	for (int pos = 1; pos <= KEYNUM_31; pos++)
	{
		for (int i = 0; i < DataNum; i++)//分配过程
		{
			int num = GetNumInPos(OriginData[i], pos);
			int index = ++SpaceForSort[num][0];
			SpaceForSort[num][index] = OriginData[i];

		}
		for (int i = 0,j=0; i < RADIX_10; i++)
		{
			for (int k = 1; k <= SpaceForSort[i][0]; k++)
				OriginData[j++] = SpaceForSort[i][k];
			SpaceForSort[i][0] = 0;//复位
		}

	}
	

}
