#include <cstdio>
using namespace std;
struct ListNode {
	 int val;
	 ListNode *next;
	 ListNode(int x) : val(x), next(NULL) {}
};
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {     
	ListNode *tail=NULL;
	ListNode *l3=tail;
	int val;
	while(l1!=NULL&&l2!=NULL)
	{
		if(l1->val<=l2->val)
		{
			val=l1->val;
			l1=l1->next;
		}
		else
		{
			val=l2->val;
			l2=l2->next;
		}
		ListNode *one=new ListNode(val);
		if(tail==NULL)
		{
			tail=one;
			l3=one;
		}
		else
		{
			tail->next=one;
			tail=tail->next;
		}
	}
	if(l1!=NULL)
	{
		if(l3!=NULL)
			tail->next=l1;
		else
			l3=l1;
	}
	if(l2!=NULL)		
	{
		if(l3!=NULL)
			tail->next=l2;
		else
			l3=l2;
	}
	return l3;
}
int main()
{
	int n,m,val;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		ListNode *list1=NULL, *list2=NULL, *lst=NULL, *ans=NULL;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&val);
			ListNode *oneNode=new ListNode(val);
			if(!i) 
			{
				list1=oneNode;
				lst=oneNode;
			}
			else
			{
				lst->next=oneNode;
				lst=lst->next;
			}
		}
		for(int i=0;i<m;++i)
		{
			scanf("%d",&val);
			ListNode *oneNode=new ListNode(val);
			if(!i) 
			{
				list2=oneNode;
				lst=oneNode;
			}
			else
			{
				lst->next=oneNode;
				lst=lst->next;
			}
		}
		ans=mergeTwoLists(list1,list2);
		if(ans!=NULL)
		{
			while(ans!=NULL)
			{
				if(ans->next!=NULL)
					printf("%d ",ans->val);
				else
					printf("%d\n",ans->val);
				ans=ans->next;
			}
		}
		else
			printf("NULL\n");
	}
	return 0;
}