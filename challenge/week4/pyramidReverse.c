#include <stdio.h>

int main()

{
	int floor;//floor ��� ������ ���� �Ѵ�
	printf("������ �װڽ��ϱ�?(5~100)"); // ������ �װڽ��ϱ�? ��� ���� ���
	scanf_s("%d", &floor); //floor ��� ���� �Է¹����� �ִ�

	for (int i = floor; i > 0; i--) { //i�� �����ϴµ� �� i���� floor���� ���� �����̴� �׸��� i�� 0���� ũ�� 1�� i���� ���� �ȴ�.
		for (int j = 0; j < floor - i; j++) {
			printf("S");
		}
		for (int k = 0; k < i * 2 - 1; k++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}