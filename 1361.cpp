/*
翻转一句话中的单词顺序 而且题目中单词间可能会有多个空格 这些空格也要翻转
翻转的题目可以用stack去实现 例如
_ _abc_ _ _xxx?_ _
则输出，如下
_ _ xxx?_ _ _ abc_ _ 
而且直接cin>>s是以空格或\n为结束符输入一个单词 因此无法判断出是否一行到了末尾 而是会直接继续读入下一行的首词
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
		//不要忘了最后一个
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