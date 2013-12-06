#include <cstdio>
const int MAX=100000;
class Calculer
{
private:
	static long long sum;
	static int c;
public:
	Calculer()
	{
		c++;
		sum+=c;
	}
	static void reset()
	{
		sum=0;
		c=0;
	}
	static long long getSum()
	{
		return sum;
	}
};
//对于static变量要显式声明
int Calculer::c=0;
long long Calculer::sum=0;
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		Calculer::reset();
		Calculer *p=new Calculer[n]();
		delete []p;
		long long ans=Calculer::getSum();
		printf("%ld\n",ans);
	}
	return 0;
}