/*
类似于pat1053 比它还简单...
*/
#include <cstdio>
#include <vector>
using namespace std;
const int MAX=10005;
int w[MAX];
int a[MAX][2];

void findWay(int node, int weight, vector<int> v)
{
	weight-=w[node];
	v.push_back(node);
	int left=a[node][0], right=a[node][1];
	if (weight==0&&left==-1&&right==-1)
	{
		printf("A path is found:");
		for(int i=0;i<v.size();++i)
			printf(" %d",v[i]);
		printf("\n");
	} 
	else
	{
		if (left!=-1&&weight>0)		
			findWay(left,weight,v);
		if (right!=-1&&weight>0)		
			findWay(right,weight,v);
	}
}

int main()
{
	int n,k,tmp;
	while (scanf("%d%d",&n,&k)!=EOF)
	{
		for(int i=1;i<=n;++i)
		{
			scanf("%d%d%d",&w[i],&a[i][0],&a[i][1]);
			//题目中没说是BST 为了字典序输出要把小的放前 而且因为没有路径用-1表示 因此要验证两个都>0
			if (a[i][0]>0&&a[i][1]>0&&a[i][0]>a[i][1])
			{
				tmp=a[i][0];
				a[i][0]=a[i][1];
				a[i][1]=tmp;
			}
		}
		vector<int> v;
		printf("result:\n");
		findWay(1,k,v);
	}
	return 0;
}
