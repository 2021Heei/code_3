#include "SList.h"


int main() {
	SLTNode head1;
	SLTNode head2;
	head1.next = NULL;
	head2.next = NULL;
	SLTNode* str1 = &head1;
	SLTNode* str2 = &head2;
	char *s1 = "loading";
	char *s2 = "be";
	char* s11 = s1;
	char* s22 = s2;
	while (*s11) {
		SListPushBack(&(str1->next), *s11);
		++s11;
	}
	while (*s22) {
		SListPushBack(&(str2->next), *s22);
		++s22;
	}
	SLTNode* tail1 = str1;
	while (tail1) {
		if (tail1->data == 'i') {
			break;
		}
		tail1 = tail1->next;
	}
	SLTNode* tail2 = str2;
	while (tail2->next) {
		tail2 = tail2->next;
	}
	tail2->next = tail1;

	SListPrint(str1->next);
	SListPrint(str2->next);

	SLTNode* ret = ListIntersection(str1, str2);
	if (ret != NULL) {
		SListPrint(ret);
	}

	return 0;
}