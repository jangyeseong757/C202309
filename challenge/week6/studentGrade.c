#include <stdio.h>
#define STUDENTS 5

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
		else {             //그 외의 값은  F를 준다
			grade = 'F';
		}
		if (targetGrade == grade) {
			printf("%d 학생은 %c점수를 받았습니다", i + 1, targetGrade);
		}
	}
}

int sumScores(int scores[]) {
	int total = 0;
	for (int i = 0; i < STUDENTS; i++) {
		total += scores[i];
	}
	return total;

}

double averageScores(int scores[]) {

}
void printRanks(int scores[]) {

}

int main() {
	int scores[STUDENTS];

	for (int i = 0; i < STUDENTS; i++) {
		printf("학생 %d의 성적을 입격하세요:", i + 1);
		scanf_s("%d", &scores[i]);
	}

	char ch = getchar();
	char target;
	printf("특정 점수(A,B,C,D,F)를 입력하시오:");
	scanf_s("%c", &target, 1);

	classifyStudents(scores, target);

	int sum = sumScores(scores);
	double average = averageScores(scores);
	printf("학생들 점수의 총 합은 %d이고,평균값은 %1f입니다. \n", sum, average);
	printRanks(scores);
	return 0;

}