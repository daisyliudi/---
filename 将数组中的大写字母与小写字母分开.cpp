//一个数组中存储有且仅有大写和小写字母，编写一个函数对数组内的字母重新排列，让小写字母在所有大写字母之前
//类似于快排的partition函数
#include<iostream>
using namespace std;
bool isUpper(char a)
{
	if (a >= 'A'&&a <= 'Z')
		return true;
	return false;

}
bool isLower(char a)
{
	if (a >= 'a'&&a <= 'z')
		return true;
}
void partition(char A[], int start, int end)
{
	while (start < end)
	{
		while (start < end&&isUpper(A[end])) end--;
		while (start < end&&isLower(A[start])) start++;
		char temp = A[end];
		A[end] = A[start];
		A[start] = temp;
	}
}
