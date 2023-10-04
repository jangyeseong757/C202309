#include <stdio.h>

int main()
{
	int x = 4;
	int y = 2;
	int z;
	//x y z 변수설정후에 x 와 y에는 
	//각각 4 와 2를 넣는다

	z = x + y;
	printf("z=x+y=%d\n", z);
	//z값이 x와 y의 합으로 되어있고 z를 출력
	z = x - y;
	printf("z=x-y=%d\n", z);
	//z값이 x와 y의 차로 되어있고 z를 출력
	z = x * y;
	printf("z=x*y=%d\n", z);
	//z값이 x와 y의 곱으로 되어있고 z를 출력
	z = x / y;
	printf("z=x/y=%d\n", z);
	//z값이 x와 y를 나눈값으로 되어있고 z를 출력

}