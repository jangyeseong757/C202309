#include <stdio.h>
#define MAX_TASKS 10
#define CHAR_NUM 100
#include <string.h>

int main() {
	char tasks[MAX_TASKS][CHAR_NUM] = { "" }; // 할 일 목록을 저장하기 위한 2차원 배열
	int taskCount = 0; // 할 일의 수를 저장하기 위한 변수

	printf("TODO 리스트 시작! \n");

	while (1) {
		int choice = -1; // 사용자 입력 메뉴를 저장하기 위한 변수

		// 사용자에게 메뉴를 출력하고, 메뉴를 입력받기
		printf("------------------\n");
		printf("메뉴를 입력해주세요.\n");;
		printf("1. 할 일 추가\n2. 할 일 삭제\n3. 목록 보기\n4. 종료\n5.할 일 수정\n");
		printf("현재 할 일 수 = %d\n", taskCount);
		printf("------------------\n");
		scanf_s("%d", &choice);

		int terminate = 0; // 종료를 위한 flag
		int delIndex = -1;  // 할 일 삭제를 위한 index 저장 변수
		int changeIndex = -1; // 할 일 수정을 위한 index 저장 변수
		int modifyIndex = -1;
		char ch; // 할 일 수정시 버퍼를 받기 위한 문자 변수

		// 입력에 따른 기능 수행
		switch (choice) {
		case 1:
			printf("할 일을 입력하세요 (공백 없이 입력하세요): "); //사용자가 1을 입력하면 이런 문장이 출력이 된다.
			scanf_s("%s", tasks[taskCount], (int)sizeof(tasks[taskCount]));// 현재 tasks가 0 임으로 tasks 라는 2차원 배열의 1번째 줄에 입력받은 값을 저장
			printf("할 일 ""%s""가 저장되었습니다\n\n", tasks[taskCount]);
			taskCount++; //할일을 입력했으므로 taskCount가 1 추가 된다
			break;
		case 2:
			// 할 일 삭제하는 코드 블록 
			printf("삭제할 할 일의 번호를 입력해주세요. (1부터 시작):");
			scanf_s("%d", &delIndex);//입력받은 변수를 delIndex에 저장
			if (delIndex > taskCount || delIndex <= 0) { //delIndex라는 값이 taskCount보다 크면 아직 저장 되지 않은 일에 대한 삭제이고 0보다 작을수는 없으므로
				//저 둘중 하나라도 True가 나오면 아래의 printf문의 문장을 출력한다
				printf("삭제 범위가 벗어났습니다.\n");
			}
			else {
				printf("%d. %s : 할 일을 삭제합니다.\n", delIndex, tasks[delIndex - 1]); //delIndex 즉 삭제하고 싶은 번호가 1이라고 하면 그거는 tasks[0]에 저장되어
				//있으므로 tasks[delIndex - 1] 값을 반환한다
				strcpy_s(tasks[delIndex - 1], sizeof(tasks[delIndex - 1]), "");// tasks[delIndex - 1] 자리에 ""인 공백을 넣는다

				for (int i = delIndex; i < taskCount + 1; i++) {
					strcpy_s(tasks[i - 1], sizeof(tasks[i]), tasks[i]); //반복문을 통해서 뒤에 있는 문자열을 한자리 앞으로 옮겨준다
				}
				taskCount -= 1; //할 일이 하나 삭제되었음으로 -1을 해준다
			}
			break;
		case 3:
			printf("할 일 목록\n");
			for (int i = 0; i < taskCount; i++) { //taskCount가 3이라한다면 
				printf("%d. %s \n", i + 1, tasks[i]);//1 ,tasks[0]이 출력 되고 ~~3,tasks[2] 까지 되어 3개의 목록을 다 보여주게 된다
			}
			printf("\n");
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
		if (taskCount == 10) { //taskCount가 10개가 되면 할일이 끝났다 하고 빠져나온다
			printf("할 일이 %d개로 다 찼습니다.", taskCount);
			break;
		}

	

	}
	return 0;
}