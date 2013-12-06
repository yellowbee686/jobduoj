#include <cstdio>
using namespace std;
const int MAX=75;
long long ret[MAX];
long long climbStairs(int n) {	
		if(n>2)
		{
			for(int i=3;i<=n;++i)
				ret[i]=ret[i-1]+ret[i-2];
		}
		return ret[n];
}
int main()
{
	int n;
	long long ans;
	ret[0]=0;
	ret[1]=1;
	ret[2]=2;
	while(scanf("%d",&n)!=EOF)
	{
		ans=climbStairs(n);
		printf("%ld\n",ans);
	}
	return 0;
}