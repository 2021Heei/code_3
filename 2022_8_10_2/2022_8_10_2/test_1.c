//���Բ���
//��̬ͨѶ¼
#include "contact.h"

enum option {
	EXIT,
	ADD,
	DELETE,
	CHECK,
	MODIFY,
	DISPLAY,
	SORT,
};
int main() {
	Contact Peo;
	int input = 0;

	InitContact(&Peo);

	do {
		menu();
		printf("���������ѡ��>");
		scanf("%d", &input);
		switch (input) {
		case ADD:
			//add
			AddContact(&Peo);
			break;
		case DELETE:
			//ɾ
			DelContact(&Peo);
			break;
		case CHECK:
			//��
			CheckContact(&Peo);
			break;
		case MODIFY:
			//��
			ModifyContact(&Peo);
			break;
		case DISPLAY:
			//��ӡ
			DisplayContact(&Peo);
			break;
		case SORT:
			//����
			sort(&Peo);
			break;
		case EXIT:
			//����ͨѶ¼���˳�
			DestroyContact(&Peo);
			printf("�����˳�!\n");
			break;
		default:
			//����
			printf("�����������������!\n");
			break;
		}
	} while (input);
	return 0;
}
