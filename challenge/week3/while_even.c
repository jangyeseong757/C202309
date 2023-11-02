#include<stdio.h>
int main() {
	int i = -1; //i값이 -1이 된다.
	while (i < 9) { //조건을 만족하면 아래 문장을 출력하게 된다.
		printf("%d Hello World! \n", i = i + 2); //조건을 만족함으로 아래문장을 출력하게 되고 i값은 1이 되어 다시 while문의 조건을 확인하러간후 조건이 맞으면 다시 헬로 월드를 출력하는 코드이다.
	}
}