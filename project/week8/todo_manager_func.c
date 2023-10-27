#include <stdio.h>
#define MAX_TASKS 10
#define CHAR_NUM 100
#include <string.h>

char tasks[MAX_TASKS][CHAR_NUM] = { "" }; // �� �� ����� �����ϱ� ���� 2���� �迭
int taskCount = 0; // �� ���� ���� �����ϱ� ���� ����


void addTask(char task[]) { //task��� ������ �Ű������� ����Ѵ�
	printf("�� ���� �Է��ϼ��� (���� ���� �Է��ϼ���): ");
	scanf_s("%s", task, (int)sizeof(task));//�Է¹��� ���� task�� �ִ´�
	strcpy_s(tasks[taskCount], sizeof(tasks[taskCount]), task);// task�� �ִ� ���� tasks[taskCount]�� �ִ� �Լ��� �������
	printf("�� �� ""%s""�� ����Ǿ����ϴ�\n\n", task);
}

void delTask(int delIndex, int taskCount) { //�Ű������� 2���� �����Ѵ�

	printf("%d. %s : �� ���� �����մϴ�.\n", delIndex, tasks[delIndex - 1]); 


	for (int i = delIndex; i < taskCount + 1; i++) { //i�� �����ϰ� ���� ��ȣ�� �ִ´�
		strcpy_s(tasks[i - 1], sizeof(tasks[i]), tasks[i]); //tasks[i]��°�� �ִ� ���� task[i-1]�� �ִ� �Լ��� �ϼ���Ų��. for���� ���� ������ �� �ڿ��ִ� ����
	} //��ĭ ���ܿ��� �ȴ�
}

void printTask(int taskCount) {
	for (int i = 0; i < taskCount; i++) { //����� �����ִ� �Լ��� 3��° ���� task[2]�� ����Ǿ��ֱ� ������ �տ� ��ȣ�� +i�� ���־� ���� �����ְ� �ȴ�
		printf("%d. %s \n", i + 1, tasks[i]);
	}
	printf("\n");
}

int main() {
	printf("TODO ����Ʈ ����! \n");

	while (1) {
		int choice = -1; // ����� �Է� �޴��� �����ϱ� ���� ����

		// ����ڿ��� �޴��� ����ϰ�, �޴��� �Է¹ޱ�
		printf("------------------\n");
		printf("�޴��� �Է����ּ���.\n");
		printf("1. �� �� �߰�\n2. �� �� ����\n3. ��� ����\n4. ����\n5.�� �� ����\n");
		printf("���� �� �� �� = %d\n", taskCount);
		printf("------------------\n");
		scanf_s("%d", &choice);

		int terminate = 0;
		int delIndex = -1; // �� �� ������ ���� �ε���

		int modifyIndex = -1; // �� �� ������ ���� �ε���
		char ch;

		// �Է¿� ���� ��� ����
		switch (choice) {
		case 1:
			addTask(tasks[taskCount]); //addTask�Լ��� ����ϴµ� task[taskCount]�� �Ű� ���� ������ �Ͽ� �Լ��� �۵��ȴ�
			taskCount++; //�� �� �߰��� taskCOunt���� +1�� �ȴ�
			break;
		case 2:
			printf("������ �� ���� ��ȣ�� �Է����ּ���. (1���� ����):");
			scanf_s("%d", &delIndex); //�����ϰ� ���� ��ȣ�� �Է� ������ delIndex�� ������ �ȴ�
			if (delIndex > taskCount || delIndex <= 0) {  //delIndex�� taskCount���� ũ�ų� �Ǵ� <=0�� ���� ������ ���������� ����� �˷��ش�
				printf("���� ������ ������ϴ�.\n");
			}
			else {
				delTask(delIndex, taskCount); //�� �̿��� ���� delIndex�� taskCount�� �Ű������� �ϴ� �ռ� ������ delTask �Լ��� ������ش�
				taskCount -= 1; //����� ���� �Ǿ������� taskCount ���� 1 ���ش�
			}
			break;
		case 3:
			printf("�� �� ���\n");
			printTask(taskCount); //����� ���� ���� �ռ� ������ printTask�Լ��� taskCount�� �Ű������� �Ͽ��� ������ش�
			break;
		case 4:
			terminate = 1; //4���� ������ �Ǹ� terminae���� 1�� �ǰ� �ǰ� switch���� ���������� �ȴ�
			break;
		case 5:
			printf("������ �� ���� ��ȣ�� �Է����ּ���. (1���� ����): ");
			scanf_s("%d", &modifyIndex); //����ڰ� �����ϰ��� �ϴ� ��ȣ�� modifyIndex ������ ����
			ch = getchar();
			printf("���ο� �� ���� �Է����ּ���");
			scanf_s("%s", tasks[modifyIndex - 1], (int)sizeof(tasks[modifyIndex - 1])); //���� �Է¹��� ���� ������ �ش�
			printf("���ο� �� ���� �߰��Ǿ����ϴ�: %d. %s\n", modifyIndex, tasks[modifyIndex - 1]);
			break;
		default:
			printf("�߸��� �����Դϴ�. �ٽ� �����ϼ���.\n");
		}

		if (terminate == 1) {
			printf("���Ḧ �����ϼ̽��ϴ�. ���α׷��� �����մϴ�.\n");
			break; //4���� ������ �Ǹ� break�� switch���� ���� ������ ����� ���� �Ǵµ� ���⼭�� ���� ������ ����ϰ� while ���� �������� ���α׷��� ����ȴ�
		}
		if (taskCount == 10) { //taskCount�� 10���� �Ǹ� ������ �� á�ٰ� �˷��ְ� while���� ���� ���´�
			printf("�� ���� %d���� �� á���ϴ�.", taskCount);
			break;
		}



	}
	return 0;
}