/*
当输入的元素是 n 个 0 到 k 之间的整数时，它的运行时间是 Θ(n + k)。计数排序不是比较排序，排序的速度快于任何比较排序算法。

由于用来计数的数组C的长度取决于待排序数组中数据的范围（等于待排序数组的最大值与最小值的差加上1），这使得计数排序对于数据范围很大的数组，需要大量内存。计数排序是用来排序0到100之间的数字的最好的算法，但是它不适合按字母顺序排序人名。但是，计数排序可以用在基数排序中的算法来排序数据范围很大的数组。

算法的步骤如下：

找出待排序的数组中最大和最小的元素
统计数组中每个值为i的元素出现的次数，存入数组C的第i项
对所有的计数累加（从C中的第一个元素开始，每一项和前一项相加）
反向填充目标数组：将每个元素i放在新数组的第C(i)项，每放一个元素就将C(i)减去1
*/
/*计数排序的基本思想为一组数在排序之前先统计这组数中其他数小于这个数的个数，则可以确定这个数的位置。
例如要排序的数为 7 4 2 1 5 3 1 5；则比7小的有7个数，所有7应该在排序好的数列的第八位，同理3在第四位，
对于重复的数字，1在1位和2位（暂且认为第一个1比第二个1小），5和1一样位于6位和7位
*/

#include<iostream>
#include<vector>
#define NUM_RANGE 100//预定义数据范围上限，即k的值
using namespace std;
vector<int>& counting_sort(vector<int> oriData)
{
	int len = oriData.size();
	vector<int> sortedData;
	vector<int> countData;
	//初始化统计数组元素值为0；
	for (int k = 0; k < NUM_RANGE; k++)
		countData[k] = 0;
	//统计数组中，每个元素出现的次数
	for (int i = 0; i < len; i++)
		countData[oriData[i]]++;
	//统计数组计数，每项存前N项和
	for (int k = 1; k < NUM_RANGE; k++)
		countData[k] += countData[k - 1];
	//将计数排序结果转化为数组元素的真实排序结果
	for (int j = len - 1; j >= 0; j++)
	{
		int elem = oriData[j];//取出来最后一个元素
		int index = countData[elem] - 1;//待排序的元素在有序数组的序号
		sortedData[index] = elem;//将元素存入排好序的数组中
		countData[elem]--;//修正排序结果，已经排好了一个元素
	}
	return sortedData;
}
