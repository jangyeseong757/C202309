#include <stdio.h>

long hapf(int value);

void main()
{
	printf("1���� 2������ ���� %d\n", multi(2));  //2
	printf("1���� 3������ ���� %d\n", multi(3));  //6
	printf("1���� 5������ ���� %d\n", multi(5)); //120
}

long multi(int value) //�Լ����� multi��� �Լ��̰� value �� �Ű������̴�
{
	int i; //i���� 1
	int multi = 1; //multi ���� 1
	for (i = 1; i <= value; i = i + 1) //i���� 1���� ������ value�� 2,3,5���� Ŀ���� �ȴ� �������  2�϶��� ó������ i�� 1������ multi���� 1*1 =1 �̵ǰ� ���� i���� 2�� �Ǿ� 
		//multi ���� 2*1=2 �� ���� return ���� ��ȯ�� �ȴ�
	{
		multi = multi * i;
	}
	return multi;
}