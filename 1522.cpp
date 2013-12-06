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
			//����ʱ��Ҫע�� ���op��Ϊchar ����Ҫ������һ�������Ե���һ�εĻس�
			//����������OJ�ϲ���ʱ����� ��˽�op��Ϊ�������ȵ�c�ַ���
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