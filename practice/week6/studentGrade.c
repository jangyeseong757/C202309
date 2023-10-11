#include <stdio.h>
#define STUDENTS 5 //학생 수는 5명 
void classifyStudents(int scores[], char targetGrade) { //함수 정의
	printf("학생 성적 분류:\n");
	char grade = ' ';
	for (int i = 0; i < STUDENTS; i++) { //i값은 0부터 시작해 students 값이 되기전까지 증가하게 되는걸 for문으로 코딩
		if (scores[i] >= 90) { // i값이 결정되면 score값이 정해지고 90이상이면  A 
			grade = 'A';
		}
		else if (scores[i] >= 80) { //90보다는 작고 80이상이면 B
			grade = 'B';
		}
		else if (scores[i] >= 70) {  //70이상 80미만이면 C
			grade = 'C';
		}
		else if (scores[i] >= 60) { //60이상이고 70미만이면 D
			grade = 'D';
		}
		else{             //그 외의 값은  F를 준다
			grade = 'F';
		}
			if (targetGrade == grade) {  
				printf("%d 학생은 %c점수를 받았습니다", i + 1, targetGrade); 
		}
	}
}
int main() {  
	int scores[STUDENTS]; //위에서 정의한 상수

	for (int i = 0; i < STUDENTS; i++) { //i값은 0으로 정의하고 i값이 students 값보다 작으면 1씩 증가
		printf("학생 %d의 성적을 입력하세요:", i + 1); 
		scanf_s("%d", &scores[i]); //학생의 성적은 정수로 입력받음
	}
	char ch = getchar(); 
	//버퍼 임시 저장 변수, 엔터지우기 위해

	char target; //문자형으로 정의
	printf("특정 점수 (A,B,C,D,F)를 입력하시오:");
	scanf_s("%c", &target, 1);
	classifyStudents(scores, target);
	return 0;
}