#include <stdio.h>

int main() {
	int choice;
	//choice��� ���� ����

	printf("1. ���� ���� \n");
	printf("2. ���� ���� �ݱ�\n");
	printf("3. ����\n");
	//����Ʈ �� �����
	scanf_s("%d", &choice);
	//choice��� ���� ������ �Է¹�����

	if (choice == 1) {
		printf("������ �����մϴ�. \n");
	}
	else if (choice == 2) {
		printf("���� ���� �ݽ��ϴ�.\n");
	}
	else if (choice == 3) {
		printf("�����մϴ�.\n");
	}
	else {
		printf("�߸� �Է��ϼ̽��ϴ�.");
	}
	//choice���� ���� ����� ������ ������ �ȴ�
}