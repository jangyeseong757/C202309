#include <stdio.h>

int hapf(int value);

void main()
{
	printf("1���� 10������ ���� %d\n", hapf(10));
	printf("1���� 100������ ���� %d\n", hapf(100));
	printf("1���� 1000������ ���� %d\n", hapf(1000));
}

int hapf(int value) //�Լ����� hapf��� �Լ��̰� value �� �Ű������̴�
{
	int i;
	int hap = 0;
	i = 1;
	while (i <= value) {
		hap = hap + i;
		i = i + 1;
		// i���� value������������ Ŀ����(hapf(10.100,1000)ó�� 10���� Ŀ���� �״����� 100 �� �Ŀ��� value ���� 1000�̵�
		// �׸��� ������ hap���� hap+i(���� �հ� ���ο� ���� ����)�� �Ǿ� 
		//���� ���� ���� ������ �ȴ�
	}
	return hap;

	//�������� hap(��)�� ���
}


