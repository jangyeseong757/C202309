#include <stdio.h>
#define STUDENTS 5
#define SUBJECTS 3
#define CHARNUM 20

void printStudentResults(double studentScores[][3], char studentNames[][20]);
void printSubjectResults(double studentScores[][3], char subjectNames[][20]);

int main() {
    char subjectNames[SUBJECTS][CHARNUM] = { "����", "�߰����", "�⸻���" };
    char studentNames[STUDENTS][CHARNUM] = { "" }; // �л� �̸��� ����� �迭
    double studentScores[STUDENTS][SUBJECTS] = { 0.0 }; // �л��� ���� �� ������ ������ ����� �迭
    printf("�л� %d���� �̸��� �Է��� �����մϴ�. \n", STUDENTS);

    // TODO 1.1: �л� �̸��� �Է¹޴� �ڵ� ��� �ۼ�
    for (int i = 0; i < 5; i++) {
        scanf_s("%s", studentNames[i], (int)sizeof(studentNames[i]));
    }

    // �Էµ� �л� �̸��� �� ����Ǿ����� Ȯ���ϴ� �ڵ� ���
    printf("�л� �̸��� ��� �ԷµǾ����ϴ�. \n");
    printf("�Էµ� �л� �̸��� ������ �����ϴ�. \n");
    for (int i = 0; i < STUDENTS; i++) {
        printf("%s", studentNames[i]);
        if (i != STUDENTS - 1) {
            printf(", ");
        }
    }
    printf("\n");
    printf("--------------------\n");
    printf("�� �л��� %s, %s, %s ������ ���ʴ�� �Է����ּ���. (���� ����)\n ", subjectNames[0], subjectNames[1], subjectNames[2]);

    // TODO 1.2: �л����� ���� �� ������ �Է¹޴� �ڵ� ��� �ۼ�
    for (int i = 0; i < 5; i++) {

        printf("%s�� ����:", studentNames[i]);
        scanf_s("%lf", &studentScores[i][0]);
        scanf_s("%lf", &studentScores[i][1]);
        scanf_s("%lf", &studentScores[i][2]);
    }


    printf("�л����� ���� ������ ��� �Է� �Ǿ����ϴ�.\n");
    printf("--------------------\n");
    printf("�л� �� ������ ������ �����ϴ� \n");

    // TODO 1.3: �л� �� ��� ������ ����ϴ� �ڵ� ��� �ۼ� >> ���� �Լ�ȭ
    printStudentResults(studentScores, studentNames);   //�Լ��� ȣ�� �Ѵ�

    printf("--------------------\n");
    printf("���� �� ��� ������ �Ʒ��� �����ϴ�. \n");

    // TODO 1.4: ���� �� ��� ������ ����ϴ� �ڵ� ��� �ۼ� >> ���� �Լ�ȭ
    printSubjectResults(studentScores, subjectNames);  //�Լ� ȣ��

    printf("���α׷��� �����մϴ�. ");
    return 0;
}

void printStudentResults(double studentScores[][3], char studentNames[][20]) { //�迭�� ũ�⸦ �˷��ش�
    for (int i = 0; i < 5; i++) { //studentScores���� i���� �л� j���� ������ �ǹ��ϴ� �л��� 5�������� i���� 5���� �۰� ������ 3���������� 3���� �۴ٰ� �Ѵ�
        int total = 0;
        for (int j = 0; j < 3; j++) {
            total += studentScores[i][j];  //���� ��� i�� 0�϶� j�� 0�̸� ù��° �л��� ù��° ���� ������ ��Ż�� ����ǰ� �� �� j�� 1 �� ������ ù��° �л��� 2��° ����� ù���� ������ ���� ��Ż�� ����ȴ�
        }                                   //���� 3���� ����� ���� ��Ż�� �����Ѵ�.
        double finalScore = (double)total / 3;   //total/3�� �ϰ� �Ǹ� 3������ ����� ��� �Ǵ� ���̴�.
        printf("\t%s�� ��� ����:%2lf\n", studentNames[i], finalScore);
    }
}

void printSubjectResults(double studentScores[][3], char subjectNames[][20]) {
    for (int j = 0; j < 3; j++) {  //�̹����� ������ ������ ���·� �л��� �ٲ�� ������ ����� ����ϱ⿡ j�� ������ ������ �Ǿ���.
        int total = 0;
        for (int i = 0; i < 5; i++) {   //j�� 0�̸� ������ ������ ������ ���·� for���� ���� �л� 1 �л� 2...�л� 5������ ������ ���� ��Ż�̶�� ������ ����ǰ� �ȴ�
            total += studentScores[i][j];  
        }
        double subjectScore = (double)total / 5; //5���� �л������� /5�� ���ָ� ������ ����� ������ �ȴ�
        printf("\t%s�� ��� ������ %.2lf �Դϴ�.\n", subjectNames[j], subjectScore);
    }
}
