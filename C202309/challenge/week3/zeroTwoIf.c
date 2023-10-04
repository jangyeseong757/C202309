
#include <stdio.h>

int main() {
	int num;

	printf("숫자를 입력하시오: ");
	//""안의 말 출력

	scanf_s("%d", &num);
	//num을 정수로 입력받음

	if (num == 0) {
		printf("zero");
	}
	else if (num == 1) {
		printf("one");
	}
	else if (num == 2) {
		printf("two");
	}
	else {
		printf("not 0~2");
	}
	//num값에 따라 경우의 수가 나뉘게되고
	//0~2값이 아니면 else를 출력
}  
=======
