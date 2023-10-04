#include <stdio.h>

int hapf(int value);

void main()
{
	printf("1부터 10까지의 합은 %d\n", hapf(10));
	printf("1부터 100까지의 합은 %d\n", hapf(100));
	printf("1부터 1000까지의 합은 %d\n", hapf(1000));
}

int hapf(int value) //함수명은 hapf라는 함수이고 value 는 매개변수이다
{
	int i;
	int hap = 0;
	i = 1;
	while (i <= value) {
		hap = hap + i;
		i = i + 1;
		// i값이 value같아질때까지 커진다(hapf(10.100,1000)처럼 10까지 커지고 그다음은 100 그 후에는 value 값이 1000이됨
		// 그리고 기존에 hap값이 hap+i(기존 합과 새로운 값의 덧셈)가 되어 
		//점점 합의 값이 누적이 된다
	}
	return hap;

	//최종적인 hap(합)값 출력
}


