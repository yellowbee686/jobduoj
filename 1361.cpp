/*
��תһ�仰�еĵ���˳�� ������Ŀ�е��ʼ���ܻ��ж���ո� ��Щ�ո�ҲҪ��ת
��ת����Ŀ������stackȥʵ�� ����
_ _abc_ _ _xxx?_ _
�����������
_ _ xxx?_ _ _ abc_ _ 
����ֱ��cin>>s���Կո��\nΪ����������һ������ ����޷��жϳ��Ƿ�һ�е���ĩβ ���ǻ�ֱ�Ӽ���������һ�е��״�
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
	string s,tmp;
	stack<string> ss;
	while(getline(cin,s))
	{
		for(int i=0;i<s.size();++i)
		{
			if (s[i]==' ')
			{
				ss.push(tmp);
				tmp.clear();
				ss.push(" ");
			} 
			else
			{
				tmp+=s[i];
			}
		}
		//��Ҫ�������һ��
		ss.push(tmp);
		tmp.clear();
		while(!ss.empty())
		{
			cout<<ss.top();
			ss.pop();
		}
		cout<<endl;
	}
	return 0;
}