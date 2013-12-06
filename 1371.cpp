/*
使用STL中的最大堆来维护k个数 但是会超时 可直接排序再输出最小的k个数却不会超时...
*/
#include <cstdio>
#include <set>
#include <functional>
using namespace std;
const int MAX=200000;
int a[MAX];
typedef multiset<int,greater<int> > maxheap;

int main()
{	
	int n,k,tmp;
	maxheap knums;
	maxheap::iterator it;
	while (scanf("%d%d",&n,&k)!=EOF)
	{
		knums.clear();
		for (int i=0;i<n;++i)
		{
			scanf("%d",&tmp);
			if (knums.size()<k)
			{
				knums.insert(tmp);
			} 
			else
			{
				it=knums.begin();
				if(*it>tmp)
				{
					knums.erase(it);
					knums.insert(tmp);
				}
			}
		}
		for (maxheap::reverse_iterator rit=knums.rbegin();rit!=knums.rend();++rit)
		{
			if(rit==knums.rbegin())
				printf("%d",*rit);
			else
				printf(" %d",*rit);
		}
		printf("\n");
	}
	return 0;
}