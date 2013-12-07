/*
�ݹ���֤ĳ�����Ƿ�ΪBST�ĺ������ ��Ҫע����ǵ�һ�����Ľڵ���<=3ʱ ����˳��Ϊ�� ���϶���BST
*/
#include <cstdio>
using namespace std;
const int MAX=10005;
int a[MAX];

bool ifPost(int low, int up)
{
	bool ret=true;
	int i,idx=up-1;
	if(up-low>2)
	{
		for (i=low;i<up;++i)
		{
			if(a[i]>a[up])
			{
				idx=i;
				break;
			}
		}
		for (i=i+1;i<up;++i)
		{
			if (a[i]<a[up])
			{
				ret=false;
				break;
			}
		}
		if(ret)
			ret=ifPost(low,idx-1)&&ifPost(idx,up-1);
	}
	return ret;
}

int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		for (int i=0;i<n;++i)	
			scanf("%d",&a[i]);	
		bool ans=ifPost(0, n-1);
		if(ans)
			printf("Yes\n");
		else
			printf("No\n");
	}	
	return 0;
}