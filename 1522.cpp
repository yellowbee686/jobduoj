#include <cstdio>
#include <stack>
using namespace std;

class MyStack
{
private:
	stack<int> s;
	stack<int> mins;
public:
	void push(int k)
	{
		s.push(k);
		if (mins.empty()||!mins.empty()&&k<mins.top())
			mins.push(k);	
		else
			mins.push(mins.top());
	}
	int getMin()
	{
		return mins.top();
	}
	void pop()
	{	
		s.pop();		
		mins.pop();		
	}
	bool empty()
	{
		return s.empty();
	}
	int size()
	{
		return s.size();
	}
};

int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		MyStack ms;
		char op[2];
		int k;
		while (n--)
		{
			//输入时需要注意 如果op设为char 则需要先输入一次用来吃掉上一次的回车
			//但这样做在OJ上测试时会出错 因此将op设为单个长度的c字符串
			scanf("%s",op);
			if(op[0]=='s')
			{
				scanf("%d",&k);
				ms.push(k);
				printf("%d\n",ms.getMin());
			}
			else
			{	
				if(ms.empty())
					printf("NULL\n");
				else
				{
					ms.pop();
					if(!ms.empty())
						printf("%d\n",ms.getMin());
					else
						printf("NULL\n");
				}
			}
		}
	}
	return 0;
}