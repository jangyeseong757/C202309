#include <stdio.h>

int main()

{
	int floor;//floor 라는 변수를 정의 한다
	printf("몇층을 쌓겠습니까?(5~100)"); // 몇층을 쌓겠습니까? 라는 문장 출력
	scanf_s("%d", &floor); //floor 라는 값을 입력받을수 있다

	for (int i = floor; i > 0; i--) { //i를 정의하는데 이 i값은 floor값을 넣은 변수이다 그리고 i가 0보다 크면 1씩 i값이 감소 된다.

		for (int j = 0; j < floor - i; j++) {// j라는 변수 지정후 0 넣기 j값이 floor-i가 전까지 j값 증가
			printf("S");// for문 조건 만족하면 S값 출력
		}
		for (int k = 0; k < i * 2 - 1; k++) { //k라는 변수 지정후 k값은 i*2-1전까지 증가
			printf("*");//for문 조건 만족시키면 *모양 출력


		}
		printf("\n");
	}
	return 0;

}