#include <stdio.h>

#define MAX_STUDENTS 30

// 학생 정보를 담을 구조체 정의
typedef struct {
    char name[50];  // 학생 이름
    int score;      // 학생 점수
} Student;

// 특정 학점을 기준으로 학생을 분류하는 함수
void classifyStudents(Student students[], int numStudents, char targetGrade) {
    printf("학생 성적 분류:\n");
    char grade = ' '; // 학점을 저장할 변수
    for (int i = 0; i < numStudents; i++) {
        // 점수에 따라 학점 결정
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
        // 입력된 학점과 일치하는 학생 정보 출력
        if (targetGrade == grade) {
            printf("%s 학생은 %c 점수를 받았습니다\n", students[i].name, targetGrade);
        }
    }
}

// 학생들의 총 점수를 계산하는 함수
int sumScores(Student students[], int numStudents) {
    int total = 0;
    for (int i = 0; i < numStudents; i++) {
        total += students[i].score; // 학생 점수를 더함
    }
    return total; // 총 합 반환
}

// 학생들의 평균 점수를 계산하는 함수
double averageScores(Student students[], int numStudents) {
    int sum = sumScores(students, numStudents); // 학생 점수 총합
    double average = (double)sum / (double)numStudents; // 평균 계산
    return average; // 평균 반환
}

// 학생들의 점수에 따라 순위를 출력하는 함수
void printRanks(Student students[], int numStudents) {
    int ranks[MAX_STUDENTS]; // 순위를 저장할 배열
    for (int i = 0; i < numStudents; i++) {
        ranks[i] = 1; // 초기 순위 설정
        for (int j = 0; j < numStudents; j++) {
            if (students[j].score > students[i].score) {
                ranks[i]++; // 현재 학생보다 점수가 높으면 순위 증가
            }
        }
        printf("%s 학생의 순위는 %d입니다.\n", students[i].name, ranks[i]); // 순위 출력
    }
}

int main() {
    int numStudents;
    printf("학생 수를 입력하세요 (최대 %d명): ", MAX_STUDENTS);
    scanf_s("%d", &numStudents);
    getchar(); // 개행 문자 처리

    if (numStudents <= 0 || numStudents > MAX_STUDENTS) {
        printf("유효하지 않은 학생 수입니다.\n");
        return 1;
    }

    Student students[MAX_STUDENTS]; // 학생 정보를 담을 배열

    // 학생 정보 입력
    for (int i = 0; i < numStudents; i++) {
        printf("학생 %d의 이름을 입력하세요: ", i + 1);
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0'; // 개행 문자 제거

        printf("학생 %d의 성적을 입력하세요: ", i + 1);
        scanf_s("%d", &students[i].score);
        getchar(); // 개행 문자 처리
    }

    char targetGrade;
    printf("특정 점수(A, B, C, D, F)를 입력하시오: ");
    scanf_s(" %c", &targetGrade);

    classifyStudents(students, numStudents, targetGrade); // 학점별 학생 분류 출력

    int sum = sumScores(students, numStudents); // 학생 점수 총합 계산
    double average = averageScores(students, numStudents); // 학생 점수 평균 계산
    printf("학생들 점수의 총 합은 %d이고, 평균값은 %.1f입니다. \n", sum, average); // 총 합과 평균 출력
    printRanks(students, numStudents); // 학생 순위 출력

    return 0;
}
