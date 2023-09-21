#include <stdio.h>

int main() {
	int choice;
	//choice라는 변수 만듬

	printf("1. 파일 저장 \n");
	printf("2. 저장 없이 닫기\n");
	printf("3. 종료\n");
	//프린트 할 내용들
	scanf_s("%d", &choice);
	//choice라는 값을 정수로 입력받을것

	if (choice == 1) {
		printf("파일을 저장합니다. \n");
	}
	else if (choice == 2) {
		printf("저장 없이 닫습니다.\n");
	}
	else if (choice == 3) {
		printf("종료합니다.\n");
	}
	else {
		printf("잘못 입력하셨습니다.");
	}
	//choice값에 따라 경우의 수들이 나뉘게 된다
}