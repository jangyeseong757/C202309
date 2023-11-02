#include <stdio.h>

long multi(int value);

int main()
{
	printf("1부터 2까지의 곱은 %d\n", multi(2));  //2
	printf("1부터 3까지의 곱은 %d\n", multi(3));  //6
	printf("1부터 5까지의 곱은 %d\n", multi(5)); //120
	return 0;
}

long multi(int value) //함수명은 multi라는 함수이고 value 는 매개변수이다
{
	int i; //i값은 1
	int mm = 1; //mm 값은 1
	for (i = 1; i <= value; i = i + 1) //i값이 1부터 시작해 value값 2,3,5까지 커지게 된다 예를들어  2일때는 처음에는 i가 1임으로 mm값이 1*1 =1 이되고 그후 i값이 2가 되어 
		//mm 값이 2*1=2 가 된후 return 으로 반환이 된다
	{
		mm = mm * i;
	}
	return mm;
}