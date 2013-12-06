#include <cstdio>
const int MAX=1000000;
int a[MAX];
void findTwo(int n, int k)
{
	int low=0,up=n-1;
	int sum=a[low]+a[up];
	bool flag=true;
	while (sum!=k)
	{
		if(sum>k)
			up--;
		else
			low++;
		sum=a[low]+a[up];
		if(low>=up)
		{
			flag=false;
			break;
		}
	}
	if(flag)
		printf("%d %d\n",a[low],a[up]);
	else
		printf("-1 -1\n");
}

int main()
{
	int n,k;	
	while (scanf("%d%d",&n,&k)!=EOF)
	{
		for(int i=0;i<n;++i)
			scanf("%d",&a[i]);
		findTwo(n,k);
	}	
	return 0;
}