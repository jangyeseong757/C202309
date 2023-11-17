#include<stdio.h>

void summation(double *value1, double*value2, double*value3);
void subtraction(double* value1, double* value2, double* value3);
void multification(double* value1, double* value2, double* value3);
void division(double* value1, double* value2, double* value3);


int main()
{
	double a = 2, b = 3;
	double result;
	summation(&a, &b, &result); //함수의 매개변수를 포인터 편수로 받았으니 변수들 앞에 &를 적어준다 
	printf("%.0lf+%.0lf=%.2lf\n", a, b, result);

	subtraction(&a, &b, &result);
	printf("%.0lf-%.0lf=%.2lf\n", a, b, result);


	multification(&a, &b, &result);
	printf("%.0lf*%.0lf=%.2lf\n", a, b, result);

	division(&a, &b, &result);
	printf("%.0lf/%.0lf=%.2lf\n", a, b, result);
}

void summation(double* value1, double*value2, double*value3) //포인터를 변수로 받는다

{
	*value3 = *value1 + *value2; //현재 value들에는 주소가 들어가 있음으로 역참조를 통해서 값을 연산해준다

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