#include<stdio.h>
int main() {
	int i = -1; //i라는 변수에 -1값을 할당한다
	do {
		printf("%d Hello World! \n", i = i + 2); //do while 문 임으로 무조건 한번은 식행 하게 된다 그리고 i값은 2씩 추가가 되게 된다.
 }
		while ( i < 9); //i값이 1이 된 상태이니 조건을 만족한다 그러니 위로 가서 문장을 수행하여 9이전까지 문장 수행을 하는 코드이다
		return 0;
		
	
} 