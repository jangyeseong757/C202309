#include <stdio.h>
#define STUDENTS 5

#include <stdio.h>
#define STUDENTS 5 //�л� ���� 5�� 
void classifyStudents(int scores[], char targetGrade) { //�Լ� ����
	printf("�л� ���� �з�:\n");
	char grade = ' ';
	for (int i = 0; i < STUDENTS; i++) { //i���� 0���� ������ students ���� �Ǳ������� �����ϰ� �Ǵ°� for������ �ڵ�
		if (scores[i] >= 90) { // i���� �����Ǹ� score���� �������� 90�̻��̸�  A 
			grade = 'A';
		}
		else if (scores[i] >= 80) { //90���ٴ� �۰� 80�̻��̸� B
			grade = 'B';
		}
		else if (scores[i] >= 70) {  //70�̻� 80�̸��̸� C
			grade = 'C';
		}
		else if (scores[i] >= 60) { //60�̻��̰� 70�̸��̸� D
			grade = 'D';
		}
		else {             //�� ���� ����  F�� �ش�
			grade = 'F';
		}
		if (targetGrade == grade) {
			printf("%d �л��� %c������ �޾ҽ��ϴ�", i + 1, targetGrade);
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
		printf("�л� %d�� ������ �԰��ϼ���:", i + 1);
		scanf_s("%d", &scores[i]);
	}

	char ch = getchar();
	char target;
	printf("Ư�� ����(A,B,C,D,F)�� �Է��Ͻÿ�:");
	scanf_s("%c", &target, 1);

	classifyStudents(scores, target);

	int sum = sumScores(scores);
	double average = averageScores(scores);
	printf("�л��� ������ �� ���� %d�̰�,��հ��� %1f�Դϴ�. \n", sum, average);
	printRanks(scores);
	return 0;

}