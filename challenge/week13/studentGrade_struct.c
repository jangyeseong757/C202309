#include <stdio.h>

#define MAX_STUDENTS 30

// �л� ������ ���� ����ü ����
typedef struct {
    char name[50];  // �л� �̸�
    int score;      // �л� ����
} Student;

// Ư�� ������ �������� �л��� �з��ϴ� �Լ�
void classifyStudents(Student students[], int numStudents, char targetGrade) {
    printf("�л� ���� �з�:\n");
    char grade = ' '; // ������ ������ ����
    for (int i = 0; i < numStudents; i++) {
        // ������ ���� ���� ����
        if (students[i].score >= 90) {
            grade = 'A';
        }
        else if (students[i].score >= 80) {
            grade = 'B';
        }
        else if (students[i].score >= 70) {
            grade = 'C';
        }
        else if (students[i].score >= 60) {
            grade = 'D';
        }
        else {
            grade = 'F';
        }
        // �Էµ� ������ ��ġ�ϴ� �л� ���� ���
        if (targetGrade == grade) {
            printf("%s �л��� %c ������ �޾ҽ��ϴ�\n", students[i].name, targetGrade);
        }
    }
}

// �л����� �� ������ ����ϴ� �Լ�
int sumScores(Student students[], int numStudents) {
    int total = 0;
    for (int i = 0; i < numStudents; i++) {
        total += students[i].score; // �л� ������ ����
    }
    return total; // �� �� ��ȯ
}

// �л����� ��� ������ ����ϴ� �Լ�
double averageScores(Student students[], int numStudents) {
    int sum = sumScores(students, numStudents); // �л� ���� ����
    double average = (double)sum / (double)numStudents; // ��� ���
    return average; // ��� ��ȯ
}

// �л����� ������ ���� ������ ����ϴ� �Լ�
void printRanks(Student students[], int numStudents) {
    int ranks[MAX_STUDENTS]; // ������ ������ �迭
    for (int i = 0; i < numStudents; i++) {
        ranks[i] = 1; // �ʱ� ���� ����
        for (int j = 0; j < numStudents; j++) {
            if (students[j].score > students[i].score) {
                ranks[i]++; // ���� �л����� ������ ������ ���� ����
            }
        }
        printf("%s �л��� ������ %d�Դϴ�.\n", students[i].name, ranks[i]); // ���� ���
    }
}

int main() {
    int numStudents;
    printf("�л� ���� �Է��ϼ��� (�ִ� %d��): ", MAX_STUDENTS);
    scanf_s("%d", &numStudents);
    getchar(); // ���� ���� ó��

    if (numStudents <= 0 || numStudents > MAX_STUDENTS) {
        printf("��ȿ���� ���� �л� ���Դϴ�.\n");
        return 1;
    }

    Student students[MAX_STUDENTS]; // �л� ������ ���� �迭

    // �л� ���� �Է�
    for (int i = 0; i < numStudents; i++) {
        printf("�л� %d�� �̸��� �Է��ϼ���: ", i + 1);
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0'; // ���� ���� ����

        printf("�л� %d�� ������ �Է��ϼ���: ", i + 1);
        scanf_s("%d", &students[i].score);
        getchar(); // ���� ���� ó��
    }

    char targetGrade;
    printf("Ư�� ����(A, B, C, D, F)�� �Է��Ͻÿ�: ");
    scanf_s(" %c", &targetGrade);

    classifyStudents(students, numStudents, targetGrade); // ������ �л� �з� ���

    int sum = sumScores(students, numStudents); // �л� ���� ���� ���
    double average = averageScores(students, numStudents); // �л� ���� ��� ���
    printf("�л��� ������ �� ���� %d�̰�, ��հ��� %.1f�Դϴ�. \n", sum, average); // �� �հ� ��� ���
    printRanks(students, numStudents); // �л� ���� ���

    return 0;
}
