#include <stdio.h>

int main() {
    int floor; //floor ��� ���� ����
    printf("�� ���� �װڽ��ϱ�? (5~100) ");
    scanf_s("%d", &floor); //  floor   �� �Է� ����

    for (int i = 0; i < floor; i++) { // i���� 0���� floor �� ������ ����
        for (int j = 0; j < floor - 1 - i; j++) { //j���� 0���� floor-1-i������ ����
            printf("S"); //S���
        }
        for (int k = 0; k < i * 2 + 1; k++) { //k���� 0����  i * 2 + 1 ���� ����
            printf("*");// *���
        }
        printf("\n");
    }
    return 0;
}