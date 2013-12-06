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
			//thislow �Ǹö����������ʼidx
			low=thislow;
		}
		if(sum<0)
		{
			sum=0;
			//���¸ö����������ʼidx
			thislow=i+1;
		}
	}
	//���max<0 ��˵������ȫ�� ��ʱmax�϶��������������Ǹ��� �ҵ������¶�Ӧidx����
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