#include <cstdio>
using namespace std;
const int MAX=100000;
void maxSubArray(int A[], int n) {
	long long max=A[0];
	int low=0,up=0,thislow=0;
	long long sum=0;
	for(int i=0;i<n;++i)
	{
		sum+=A[i];
		if(sum>max)
		{
			max=sum;
			up=i;
			//thislow 是该段子数组的起始idx
			low=thislow;
		}
		if(sum<0)
		{
			sum=0;
			//更新该段子数组的起始idx
			thislow=i+1;
		}
	}
	//如果max<0 则说明数组全负 此时max肯定是数组中最大的那个数 找到并更新对应idx即可
	if(max<0)
	{
		for(int i=0;i<n;++i)
		{
			if(A[i]==max)
			{
				low=i;
				up=i;
				break;
			}
		}
	}
	//long long int specifier is lld
	printf("%lld %d %d\n",max,low,up);
}

int main()
{
	int a[MAX];
	int n;
	while(scanf("%d",&n)&&n)
	{
		for(int i=0;i<n;++i)
			scanf("%d",&a[i]);
		maxSubArray(a,n);
	}
	return 0;
}