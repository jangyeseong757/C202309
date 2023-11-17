#include <stdio.h>
#define STUDENTS 5 

void classifyStudents(int* scores, char targetGrade) {
    printf("�л� ���� �з�:\n");
    char grade = ' ';
    for (int i = 0; i < STUDENTS; i++) {
        if (*(scores + i) >= 90) {
            grade = 'A';
        }
        else if (*(scores + i) >= 80) {
            grade = 'B';
        }
        else if (*(scores + i) >= 70) {
            grade = 'C';
        }
        else if (*(scores + i) >= 60) {
            grade = 'D';
        }
        else {
            grade = 'F';
        }
        if (targetGrade == grade) {
            printf("%d �л��� %c ������ �޾ҽ��ϴ�\n", i + 1, targetGrade);
        }
    }
}

int sumScores(int* scores) {
    int total = 0;
    for (int i = 0; i < STUDENTS; i++) {
        total += *(scores + i);
    }
    return total;
}

double averageScores(int* scores) {
    int sum = sumScores(scores);
    double average = (double)sum / (double)STUDENTS;
    return average;
}

void printRanks(int* scores) {
    int ranks[STUDENTS];
    for (int i = 0; i < STUDENTS; i++) {
        ranks[i] = 1;
        for (int j = 0; j < STUDENTS; j++) {
            if (*(scores + j) > *(scores + i)) {
                ranks[i]++;
            }
        }
        printf("%d �л��� ������ %d�Դϴ�.\n", i + 1, ranks[i]);
    }
}

int main() {
    int scores[STUDENTS];

    for (int i = 0; i < STUDENTS; i++) {
        printf("�л� %d�� ������ �Է��ϼ���: ", i + 1);
        scanf_s("%d", &scores[i]);
    }

    char ch = getchar();

    char target;
    printf("Ư�� ����(A,B,C,D,F)�� �Է��Ͻÿ�: ");
    scanf_s(" %c", &target); 

    classifyStudents(scores, target);

    int sum = sumScores(scores);
    double average = averageScores(scores);
    printf("�л��� ������ �� ���� %d�̰�, ��հ��� %.1f�Դϴ�. \n", sum, average);
    printRanks(scores);
    return 0;
}
