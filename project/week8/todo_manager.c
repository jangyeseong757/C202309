#include <stdio.h>
#define MAX_TASKS 10
#define CHAR_NUM 100
#include <string.h>

int main() {
	char tasks[MAX_TASKS][CHAR_NUM] = { "" }; // �� �� ����� �����ϱ� ���� 2���� �迭
	int taskCount = 0; // �� ���� ���� �����ϱ� ���� ����

	printf("TODO ����Ʈ ����! \n");

	while (1) {
		int choice = -1; // ����� �Է� �޴��� �����ϱ� ���� ����

		// ����ڿ��� �޴��� ����ϰ�, �޴��� �Է¹ޱ�
		printf("------------------\n");
		printf("�޴��� �Է����ּ���.\n");;
		printf("1. �� �� �߰�\n2. �� �� ����\n3. ��� ����\n4. ����\n5.�� �� ����\n");
		printf("���� �� �� �� = %d\n", taskCount);
		printf("------------------\n");
		scanf_s("%d", &choice);

		int terminate = 0; // ���Ḧ ���� flag
		int delIndex = -1;  // �� �� ������ ���� index ���� ����
		int changeIndex = -1; // �� �� ������ ���� index ���� ����
		int modifyIndex = -1;
		char ch; // �� �� ������ ���۸� �ޱ� ���� ���� ����

		// �Է¿� ���� ��� ����
		switch (choice) {
		case 1:
			printf("�� ���� �Է��ϼ��� (���� ���� �Է��ϼ���): "); //����ڰ� 1�� �Է��ϸ� �̷� ������ ����� �ȴ�.
			scanf_s("%s", tasks[taskCount], (int)sizeof(tasks[taskCount]));// ���� tasks�� 0 ������ tasks ��� 2���� �迭�� 1��° �ٿ� �Է¹��� ���� ����
			printf("�� �� ""%s""�� ����Ǿ����ϴ�\n\n", tasks[taskCount]);
			taskCount++; //������ �Է������Ƿ� taskCount�� 1 �߰� �ȴ�
			break;
		case 2:
			// �� �� �����ϴ� �ڵ� ��� 
			printf("������ �� ���� ��ȣ�� �Է����ּ���. (1���� ����):");
			scanf_s("%d", &delIndex);//�Է¹��� ������ delIndex�� ����
			if (delIndex > taskCount || delIndex <= 0) { //delIndex��� ���� taskCount���� ũ�� ���� ���� ���� ���� �Ͽ� ���� �����̰� 0���� �������� �����Ƿ�
				//�� ���� �ϳ��� True�� ������ �Ʒ��� printf���� ������ ����Ѵ�
				printf("���� ������ ������ϴ�.\n");
			}
			else {
				printf("%d. %s : �� ���� �����մϴ�.\n", delIndex, tasks[delIndex - 1]); //delIndex �� �����ϰ� ���� ��ȣ�� 1�̶�� �ϸ� �װŴ� tasks[0]�� ����Ǿ�
				//�����Ƿ� tasks[delIndex - 1] ���� ��ȯ�Ѵ�
				strcpy_s(tasks[delIndex - 1], sizeof(tasks[delIndex - 1]), "");// tasks[delIndex - 1] �ڸ��� ""�� ������ �ִ´�

				for (int i = delIndex; i < taskCount + 1; i++) {
					strcpy_s(tasks[i - 1], sizeof(tasks[i]), tasks[i]); //�ݺ����� ���ؼ� �ڿ� �ִ� ���ڿ��� ���ڸ� ������ �Ű��ش�
				}
				taskCount -= 1; //�� ���� �ϳ� �����Ǿ������� -1�� ���ش�
			}
			break;
		case 3:
			printf("�� �� ���\n");
			for (int i = 0; i < taskCount; i++) { //taskCount�� 3�̶��Ѵٸ� 
				printf("%d. %s \n", i + 1, tasks[i]);//1 ,tasks[0]�� ��� �ǰ� ~~3,tasks[2] ���� �Ǿ� 3���� ����� �� �����ְ� �ȴ�
			}
			printf("\n");
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
		if (taskCount == 10) { //taskCount�� 10���� �Ǹ� ������ ������ �ϰ� �������´�
			printf("�� ���� %d���� �� á���ϴ�.", taskCount);
			break;
		}

	

	}
	return 0;
}