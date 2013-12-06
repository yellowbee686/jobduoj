#include <cstdio>
using namespace std;
struct ListNode {
	 int val;
	 ListNode *next;
	 ListNode(int x) : val(x), next(NULL) {}
};

ListNode * endk(ListNode *head, int k)
{
	ListNode *ret=NULL, *tail=head;
	bool flag=true;
	if(head!=NULL&&k)
	{
		k--;
		while(k--)
		{
			if(tail->next!=NULL)
				tail=tail->next;
			else
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			ret=head;
			while(tail->next!=NULL)
			{
				ret=ret->next;
				tail=tail->next;
			}
		}
	}
	return ret;
}

int main()
{
	int n,k,val;
	ListNode *head=NULL, *lst=NULL, *ans=NULL;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		for(int i=0;i<n;++i)
		{
			scanf("%d",&val);
			ListNode *oneNode=new ListNode(val);
			if(!i) 
			{
				head=oneNode;
				lst=oneNode;
			}
			else
			{
				lst->next=oneNode;
				lst=lst->next;
			}
		}
		ans=endk(head,k);
		if(ans!=NULL)
			printf("%d\n",ans->val);
		else
			printf("NULL\n");
	}
	return 0;
}