#include "SList.h"

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	SLTNode* phead = NULL;
	for (int i = 1; i <= n; ++i) {
		SListPushBack(&phead, i);
	}
	SListPrint(phead);
	SLTNode* tail = SListFind(phead, n);
	assert(tail);
	tail->next = phead;
	int i = 1;
	while (phead->next != phead) {
		phead = phead->next;
		++i;
		if (i == m) {
			i = 1;
			SLTNode* tail = NULL;
			while (tail->next != phead) {
				tail = tail->next;
				assert(tail);
			}
			tail->next = phead->next;
			free(phead);
			phead = tail->next;
		}
	}
	printf("%d\n", phead->data);
	return 0;
}