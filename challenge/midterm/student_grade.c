#include <stdio.h>
#define STUDENTS 5
#define SUBJECTS 3
#define CHARNUM 20

void printStudentResults(double studentScores[][3], char studentNames[][20]);
void printSubjectResults(double studentScores[][3], char subjectNames[][20]);

int main() {
    char subjectNames[SUBJECTS][CHARNUM] = { "퀴즈", "중간고사", "기말고사" };
    char studentNames[STUDENTS][CHARNUM] = { "" }; // 학생 이름이 저장될 배열
    double studentScores[STUDENTS][SUBJECTS] = { 0.0 }; // 학생의 시험 별 성적이 점수가 저장될 배열
    printf("학생 %d명의 이름의 입력을 시작합니다. \n", STUDENTS);

    // TODO 1.1: 학생 이름을 입력받는 코드 블록 작성
    for (int i = 0; i < 5; i++) {
        scanf_s("%s", studentNames[i], (int)sizeof(studentNames[i]));
    }

    // 입력된 학생 이름이 잘 저장되었는지 확인하는 코드 블록
    printf("학생 이름이 모두 입력되었습니다. \n");
    printf("입력된 학생 이름은 다음과 같습니다. \n");
    for (int i = 0; i < STUDENTS; i++) {
        printf("%s", studentNames[i]);
        if (i != STUDENTS - 1) {
            printf(", ");
        }
    }
    printf("\n");
    printf("--------------------\n");
    printf("각 학생의 %s, %s, %s 점수를 차례대로 입력해주세요. (띄어쓰기 구분)\n ", subjectNames[0], subjectNames[1], subjectNames[2]);

    // TODO 1.2: 학생들의 시험 별 점수를 입력받는 코드 블록 작성
    for (int i = 0; i < 5; i++) {

        printf("%s의 성적:", studentNames[i]);
        scanf_s("%lf", &studentScores[i][0]);
        scanf_s("%lf", &studentScores[i][1]);
        scanf_s("%lf", &studentScores[i][2]);
    }


    printf("학생들의 시험 점수가 모두 입력 되었습니다.\n");
    printf("--------------------\n");
    printf("학생 별 성적은 다음과 같습니다 \n");

    // TODO 1.3: 학생 별 평균 점수를 출력하는 코드 블록 작성 >> 이후 함수화
    printStudentResults(studentScores, studentNames);   //함수를 호출 한다

    printf("--------------------\n");
    printf("과목 별 평균 점수는 아래와 같습니다. \n");

    // TODO 1.4: 과목 별 평균 점수를 출력하는 코드 블록 작성 >> 이후 함수화
    printSubjectResults(studentScores, subjectNames);  //함수 호출

    printf("프로그램을 종료합니다. ");
    return 0;
}

void printStudentResults(double studentScores[][3], char studentNames[][20]) { //배열의 크기를 알려준다
    for (int i = 0; i < 5; i++) { //studentScores에서 i값은 학생 j값은 과목을 의미하는 학생은 5명임으로 i값은 5보다 작게 과목은 3과목임으로 3보다 작다고 한다
        int total = 0;
        for (int j = 0; j < 3; j++) {
            total += studentScores[i][j];  //예를 들어 i가 0일때 j가 0이면 첫번째 학생의 첫번째 과목 점수가 토탈에 저장되고 그 후 j가 1 이 됨으로 첫번째 학생의 2번째 과목과 첫번쨰 과목의 합이 토탈에 저장된다
        }                                   //이후 3과목 모두의 합을 토탈에 저장한다.
        double finalScore = (double)total / 3;   //total/3을 하게 되면 3과목의 평균이 출력 되는 것이다.
        printf("\t%s의 평균 점수:%2lf\n", studentNames[i], finalScore);
    }
}

void printSubjectResults(double studentScores[][3], char subjectNames[][20]) {
    for (int j = 0; j < 3; j++) {  //이번에는 과목이 고정된 상태로 학생이 바뀌어 점수의 평균을 출력하기에 j가 앞으로 나오게 되었다.
        int total = 0;
        for (int i = 0; i < 5; i++) {   //j가 0이면 퀴즈라는 과목이 고정된 상태로 for문을 돌아 학생 1 학생 2...학생 5까지의 점수의 합이 토탈이라는 변수에 저장되게 된다
            total += studentScores[i][j];  
        }
        double subjectScore = (double)total / 5; //5명의 학생임으로 /5를 해주면 과목의 평균이 나오게 된다
        printf("\t%s의 평균 점수는 %.2lf 입니다.\n", subjectNames[j], subjectScore);
    }
}
