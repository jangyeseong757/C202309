#include <stdio.h>

int main() {
    int floor; //floor 라는 변수 만듬
    printf("몇 층을 쌓겠습니까? (5~100) ");
    scanf_s("%d", &floor); //  floor   값 입력 받음

    for (int i = 0; i < floor; i++) { // i값은 0부터 floor 값 전까지 증가
        for (int j = 0; j < floor - 1 - i; j++) { //j값도 0부터 floor-1-i값까지 증가
            printf("S"); //S출력
        }
        for (int k = 0; k < i * 2 + 1; k++) { //k값도 0부터  i * 2 + 1 까지 증가
            printf("*");// *출력
        }
        printf("\n");
    }
    return 0;
}