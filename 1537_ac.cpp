//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<cmath>
//using namespace std;
//int a[10010];
//int n,k;
//int dp[2][10010];
//int mm[10010];
//void init(int f)
//{
//    mm[1]=dp[f][1]-a[1];
//    for(int i=2;i<=n;i++)
//    {
//        mm[i]=max(mm[i-1],dp[f][i]-a[i]);
//    }
//}
//int DP()
//{
//    memset(dp,0,sizeof(dp));
//    int flag=0,f;
//    for(int i=1;i<=k;i++)
//    {
//        f=flag;
//        flag^=1;
//        init(f);
//        for(int j=2;j<=n;j++)
//        {
//            dp[flag][j]=max(dp[flag][j-1],mm[j-1]+a[j]);
//        }
//    }
//    return dp[flag][n];
//}
//int main()
//{
//    while(~scanf("%d%d",&n,&k))
//    {
//        for(int i=1;i<=n;i++)
//        {
//            scanf("%d",&a[i]);
//        }
//        printf("%d\n",DP());
//    }
//}