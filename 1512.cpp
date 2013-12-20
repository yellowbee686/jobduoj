#include <cstdio>
#include <stack>
using namespace std;

int main() {
	int n,tmp,front;
	scanf("%d",&n);
	char cmd[5];
	stack<int> inS,outS;
	while (n--) {
		scanf("%s",&cmd);
		front = -1;
		if (cmd[1]=='U') {
			scanf("%d",&tmp);
			inS.push(tmp);
		}
		else {
			if (outS.empty()) {
				while (!inS.empty()) {
					outS.push(inS.top());
					inS.pop();
				}
			} 
			if (!outS.empty()) {
				front = outS.top();
				outS.pop();
			}
			printf("%d\n",front);
		}
	}
	return 0;
}