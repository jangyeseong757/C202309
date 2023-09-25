#include <stdio.h>
int main()
{
	int x = 4;
	int y = 2;
	int z;
	//x y z라는 변수 생성후 x y에는 각각 4와 2 넣기
	z = (x + y) * (x - y);
	printf("z=(x+y) * (x-y)=%d\n", z);
	//z값은 x의y의 합과 x와 y의 차의 곱으로 이루어짐
	//출력은 " " 안에 있는거 출력 후 z값 출력

	z= (x * y) * (x /y);
	printf("z=(x*y) * (x/y)=%d\n", z);
	//z값은 x의y의 곱과 x와 y의 나눗셈의 곱으로 이루어짐
	//출력은 " " 안에 있는거 출력 후 z값 출력

	z = x + y + 2004;
	printf("z=x+y+2004=%d\n" ,z);
	//z값은 x의y의 합과 2004라는 값의 합으로 이루어짐
	//출력은 " " 안에 있는거 출력 후 z값 출력
}