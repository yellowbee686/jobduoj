#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 10000
struct project {
	int st;
	int ed;
	int val;
}pros[MAX],dp[MAX];

bool cmp(const project &a, const project &b) {
	if (a.ed!=b.ed) {
		return a.ed<b.ed;
	}
	else {
		return a.st<b.st;
	}
}

int main() {
	int n;
	while (scanf("%d",&n)!=EOF) {
		for (int i=0;i<n;++i) {
			scanf("%d%d%d",&pros[i].st,&pros[i].ed,&pros[i].val);
		}
		sort(pros,pros+n,cmp);
		dp[0].val=pros[0].val;
		dp[0].ed=pros[0].ed;
		for (int i=1;i<n;i++) {
			int tmp=pros[i].val;
			for (int j=i-1;j>=0;--j) {
				if (dp[j].ed<=pros[i].st) {
					tmp+=dp[j].val;
					break;
				}
			}
			if (tmp>dp[i-1].val) {
				dp[i].val=tmp;
				dp[i].ed=pros[i].ed;
			}
			else {
				dp[i].val=dp[i-1].val;
				dp[i].ed=dp[i-1].ed;
			}
		}
		printf("%d\n",dp[n-1].val);
	}
	return 0;
}