#include <stdio.h>

int main()
{
	int x = 4;
	int y = 2;
	int z;
	//x y z ���������Ŀ� x �� y���� 
	//���� 4 �� 2�� �ִ´�

	z = x + y;
	printf("z=x+y=%d\n", z);
	//z���� x�� y�� ������ �Ǿ��ְ� z�� ���
	z = x - y;
	printf("z=x-y=%d\n", z);
	//z���� x�� y�� ���� �Ǿ��ְ� z�� ���
	z = x * y;
	printf("z=x*y=%d\n", z);
	//z���� x�� y�� ������ �Ǿ��ְ� z�� ���
	z = x / y;
	printf("z=x/y=%d\n", z);
	//z���� x�� y�� ���������� �Ǿ��ְ� z�� ���

}