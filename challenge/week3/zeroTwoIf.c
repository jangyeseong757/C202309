
#include <stdio.h>

int main() {
	int num;

	printf("���ڸ� �Է��Ͻÿ�: ");
	//""���� �� ���

	scanf_s("%d", &num);
	//num�� ������ �Է¹���

	if (num == 0) {
		printf("zero");
	}
	else if (num == 1) {
		printf("one");
	}
	else if (num == 2) {
		printf("two");
	}
	else {
		printf("not 0~2");
	}
	//num���� ���� ����� ���� �����Եǰ�
	//0~2���� �ƴϸ� else�� ���
}  
=======
