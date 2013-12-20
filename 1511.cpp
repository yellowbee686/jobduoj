/*
��β��ͷ��ӡ���� ���˳����Ŀռ�һ����Ťת Ҳ����ʹ��ջ��ʵ��
*/
#include <cstdio>

struct ListNode {
	int val;
	ListNode *pNext;
	ListNode(int x) : val(x), pNext(NULL) {}
};

ListNode * reverseList(ListNode *head) {
	ListNode *ret = NULL;
	ListNode *lst = head,*now,*next;
	if (lst != NULL) {
		now = lst->pNext;
		lst->pNext = NULL;
		while (now != NULL) {
			next = now->pNext;
			now->pNext = lst;
			lst = now;
			now = next;
		}
		ret = lst;
	}
	return ret;
}

int main() {
	ListNode *head = NULL,*lst = NULL;
	int tmp;
	while (scanf("%d",&tmp) && tmp != -1) {
		ListNode *node = new ListNode(tmp);
		if (lst == NULL) {
			head = node;
			lst = node;
		}
		else {
			lst->pNext =node;
			lst = node;
		}
	}
	ListNode *rHead = reverseList(head);
	while (rHead!=NULL) {
		printf("%d\n",rHead->val);
		rHead = rHead->pNext;
	}
	return 0;
}