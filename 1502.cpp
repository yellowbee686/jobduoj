#include<stdio.h>
#define inf 0x7FFFFF
int a[501];
int m,kk;
int check(int x)
{
	int i;
	int s=0;
	int cnt=0;
	for(i=1;i<=m;)
	{
		if(s+a[i]>x)
		{
			cnt++;
			s=0;
		}
		else 
		{
			s+=a[i];
			i++;
		}
	}
	cnt++;
	if(cnt<=kk)
		return 1;
	return 0;
}
int main()
{
	int ca;
	while(scanf("%d",&ca)!=EOF)
	{
		while(ca--)
		{
			int i,j,k;
			scanf("%d%d",&m,&kk);
			int l,r;
			l=r=0;
			for(i=1;i<=m;i++)
			{
				scanf("%d",a+i);
				r+=a[i];
				if(l<a[i])
					l=a[i];
			}
			while(l<r)
			{
				int mid=(l+r)/2;
				if(check(mid))
					r=mid;
				else 
					l=mid+1;
			}
			printf("%d\n",l);
		}
	}
	return 0;
}