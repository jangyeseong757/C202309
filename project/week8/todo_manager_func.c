#include <stdio.h>
#define MAX_TASKS 10
#define CHAR_NUM 100
#include <string.h>

char tasks[MAX_TASKS][CHAR_NUM] = { "" }; // 할 일 목록을 저장하기 위한 2차원 배열
int taskCount = 0; // 할 일의 수를 저장하기 위한 변수


void addTask(char task[]) { //task라는 변수를 매개변수로 사용한다
	printf("할 일을 입력하세요 (공백 없이 입력하세요): ");
	scanf_s("%s", task, (int)sizeof(task));//입력받은 값을 task에 넣는다
	strcpy_s(tasks[taskCount], sizeof(tasks[taskCount]), task);// task에 있는 값을 tasks[taskCount]에 넣는 함수를 만들었다
	printf("할 일 ""%s""가 저장되었습니다\n\n", task);
}

void delTask(int delIndex, int taskCount) { //매개변수를 2개를 선언한다

	printf("%d. %s : 할 일을 삭제합니다.\n", delIndex, tasks[delIndex - 1]); 


	for (int i = delIndex; i < taskCount + 1; i++) { //i에 삭제하고 싶은 번호를 넣는다
		strcpy_s(tasks[i - 1], sizeof(tasks[i]), tasks[i]); //tasks[i]번째에 있는 값을 task[i-1]에 넣는 함수를 완성시킨다. for문을 통해 삭제된 값 뒤에있는 값을
	} //한칸 땡겨오게 된다
}

void printTask(int taskCount) {
	for (int i = 0; i < taskCount; i++) { //목록을 보여주는 함수로 3번째 값은 task[2]에 저장되어있기 때문에 앞에 번호는 +i를 해주어 쌍을 맞춰주게 된다
		printf("%d. %s \n", i + 1, tasks[i]);
	}
	printf("\n");
}

int main() {
	printf("TODO 리스트 시작! \n");

	while (1) {
		int choice = -1; // 사용자 입력 메뉴를 저장하기 위한 변수

		// 사용자에게 메뉴를 출력하고, 메뉴를 입력받기
		printf("------------------\n");
		printf("메뉴를 입력해주세요.\n");
		printf("1. 할 일 추가\n2. 할 일 삭제\n3. 목록 보기\n4. 종료\n5.할 일 수정\n");
		printf("현재 할 일 수 = %d\n", taskCount);
		printf("------------------\n");
		scanf_s("%d", &choice);

		int terminate = 0;
		int delIndex = -1; // 할 일 삭제를 위한 인덱스

		int modifyIndex = -1; // 할 일 수정을 위한 인덱스
		char ch;

		// 입력에 따른 기능 수행
		switch (choice) {
		case 1:
			addTask(tasks[taskCount]); //addTask함수를 사용하는데 task[taskCount]가 매개 변수 역할을 하여 함수가 작동된다
			taskCount++; //할 일 추가후 taskCOunt값이 +1이 된다
			break;
		case 2:
			printf("삭제할 할 일의 번호를 입력해주세요. (1부터 시작):");
			scanf_s("%d", &delIndex); //삭제하고 싶은 번호를 입력 받은후 delIndex에 저장이 된다
			if (delIndex > taskCount || delIndex <= 0) {  //delIndex가 taskCount보다 크거나 또는 <=0인 경우는 범위가 벗으남으로 벗어났다 알려준다
				printf("삭제 범위가 벗어났습니다.\n");
			}
			else {
				delTask(delIndex, taskCount); //그 이외의 경우는 delIndex와 taskCount를 매개변수로 하는 앞서 정의한 delTask 함수를 사용해준다
				taskCount -= 1; //사용후 삭제 되었음으로 taskCount 값은 1 빼준다
			}
			break;
		case 3:
			printf("할 일 목록\n");
			printTask(taskCount); //목록을 보기 위해 앞서 정의한 printTask함수를 taskCount를 매개변수로 하여금 사용해준다
			break;
		case 4:
			terminate = 1; //4번을 누르게 되면 terminae값이 1이 되게 되고 switch문을 빠져나가게 된다
			break;
		case 5:
			printf("수정할 할 일의 번호를 입력해주세요. (1부터 시작): ");
			scanf_s("%d", &modifyIndex); //사용자가 수정하고자 하는 번호를 modifyIndex 변수에 저장
			ch = getchar();
			printf("새로운 할 일을 입력해주세요");
			scanf_s("%s", tasks[modifyIndex - 1], (int)sizeof(tasks[modifyIndex - 1])); //새로 입력받은 값을 저장해 준다
			printf("새로운 할 일이 추가되었습니다: %d. %s\n", modifyIndex, tasks[modifyIndex - 1]);
			break;
		default:
			printf("잘못된 선택입니다. 다시 선택하세요.\n");
		}

		if (terminate == 1) {
			printf("종료를 선택하셨습니다. 프로그램을 종료합니다.\n");
			break; //4번을 누르게 되면 break로 switch문을 빠져 나오면 여기로 오게 되는데 여기서는 종료 문장을 출력하고 while 문을 빠져나와 프로그램이 종료된다
		}
		if (taskCount == 10) { //taskCount가 10개가 되면 할일이 다 찼다고 알려주고 while문을 빠져 나온다
			printf("할 일이 %d개로 다 찼습니다.", taskCount);
			break;
		}



	}
	return 0;
}