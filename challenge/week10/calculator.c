#include<stdio.h>

void summation(double *value1, double*value2, double*value3);
void subtraction(double* value1, double* value2, double* value3);
void multification(double* value1, double* value2, double* value3);
void division(double* value1, double* value2, double* value3);


int main()
{
	double a = 2, b = 3;
	double result;
	summation(&a, &b, &result); //�Լ��� �Ű������� ������ ����� �޾����� ������ �տ� &�� �����ش� 
	printf("%.0lf+%.0lf=%.2lf\n", a, b, result);

	subtraction(&a, &b, &result);
	printf("%.0lf-%.0lf=%.2lf\n", a, b, result);


	multification(&a, &b, &result);
	printf("%.0lf*%.0lf=%.2lf\n", a, b, result);

	division(&a, &b, &result);
	printf("%.0lf/%.0lf=%.2lf\n", a, b, result);
}

void summation(double* value1, double*value2, double*value3) //�����͸� ������ �޴´�

{
	*value3 = *value1 + *value2; //���� value�鿡�� �ּҰ� �� �������� �������� ���ؼ� ���� �������ش�

}

void subtraction(double* value1, double* value2, double* value3)

{
	*value3 = *value1 - *value2;

}

void multification(double* value1, double* value2, double* value3)

{
	*value3 = *value1 * *value2;

}

void division(double* value1, double* value2, double* value3)

{
	*value3 = *value1 / *value2;

}