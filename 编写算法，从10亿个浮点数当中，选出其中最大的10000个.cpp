典型的Top K问题，用堆是最典型的思路。建10000个数的小顶堆，然后将10亿个数依次读取，大于堆顶，则替换堆顶，做一次堆调整。
结束之后，小顶堆中存放的数即为所求。代码如下(为了方便，这里直接使用了STL容器)：

#include "stdafx.h"  
#include <vector>  
#include <iostream>  
#include <algorithm>  
#include <functional> // for greater<>  
using namespace std;  
int _tmain(int argc, _TCHAR* argv[])  
{  
  vector<float> bigs(10000,0);  
  vector<float>::iterator it;  
  // Init vector data  
  for (it = bigs.begin(); it != bigs.end(); it++)  
  {  
    *it = (float)rand()/7; // random values;  
  }  
  cout << bigs.size() << endl;  
  make_heap(bigs.begin(),bigs.end(), greater<float>()); // The first one is the smallest one!  
  float ff;  
  for (int i = 0; i < 1000000000; i++)  
  {  
    ff = (float) rand() / 7;  
    if (ff > bigs.front()) // replace the first one ?  
    {  
      // set the smallest one to the end!  
      pop_heap(bigs.begin(), bigs.end(), greater<float>());   
      // remove the last/smallest one  
      bigs.pop_back();   
      // add to the last one  
      bigs.push_back(ff);   
      // mask heap again, the first one is still the smallest one  
      push_heap(bigs.begin(),bigs.end(),greater<float>());  
    }  
  }  
  // sort by ascent  
  sort_heap(bigs.begin(), bigs.end(), greater<float>());   
  return 0;  
}
