#include <stdio.h>
#define NUMCITY 3
#define NUMPEOPLE 2

char names[NUMPEOPLE][10]; // �տ��� define �� ����� �������� names �� cities ��� ������ �迭�� �����Ѵ�
char cities[NUMCITY][10];

void calculateTravelDays();

int main() {
	//����ڷκ��� ���� �̸� �Է¹ޱ�

	printf("%d���� ���ø��� ���ʴ�� �Է����ּ���. \n", NUMCITY);
	for (int i = 0; i < NUMCITY; i++) {  //NUMCITY�� 3������ �Է¹��� ���ð� ���� �λ� �����̶�� �ϸ� cities[0]���� ���ְ� ����
											//i���� 1�� ���� cities[1]���� �λ� cities[2]���� ������ ����
		scanf_s("%s", cities[i], (int)sizeof(cities[i]));
	}
	//����ڷκ��� ��� �̸� �ޱ�

	printf("%d���� ������ �̸��� ���ʴ�� �Է����ּ���. \n", NUMPEOPLE);
	for (int i = 0; i < NUMPEOPLE; i++) {    //NUMPEOPLE �� 2 ������  �Է¹��� �����ڰ� ö���� ����� �ϸ� names[0]���� ö�� names[1]���� ������ ���� ����
		scanf_s("%s", names[i], (int)sizeof(names[i]));
	}
	//�Լ�ȣ��
	calculateTravelDays();

	return 0;
}

void calculateTravelDays() { //caclulateTravelDays ��� �Լ��� �����
	int travelDays[NUMCITY][NUMPEOPLE]; //travelDays��� 2���� �迭�� �����
	//�� ���ÿ��� �� ����� ���� �� �� �Է¹ޱ�
	for (int i = 0; i < NUMCITY; i++) {
		for (int j = 0; j < NUMPEOPLE; j++) {
			printf("���� %s���� ���%s�� ���� �� ���� �Է��ϼ���: ", cities[i], names[j]); //i�� 0�̰� for���� ���ؼ� j�� 0������ cities[0]�� ���� names[0]�� ö�� ������ ���ֿ� ö���� �� ������ ����� �ȴ�
			scanf_s("%d", &travelDays[i][j]);//5��� ���ڸ� �Է��ϸ� tracelDays[0][0]�� 5��� ���ڰ� ���� �ȴ�
		} //�� ������ �ݺ��ϰ� �Ǹ� ö�� �� ���� ���� ���� �λ� ���￡ �� ���� ������ �� 6�� �Է��� ���� �Է��� ���ڰ� travelDays��� �迭�� 2�������� ���� �ȴ�.
	}

	//�� ���ú� �� �� �� �� ��� �� �� ��� �� ���
	for (int i = 0; i < NUMCITY; i++) {
		int totalDays = 0;  //totalDays�� �ʱ�ȭ ������ ����
		for (int j = 0; j < NUMPEOPLE; j++) { //i=0 �׸��� j��0 ���� i=0 j=1�� ������ �� ���ÿ��� ö���� ���� ���� ������ ���� totalDays�� ���� �ȴ� 
			totalDays += travelDays[i][j];
		}
		float averageDays = (float)totalDays / NUMPEOPLE;//���� ����� ������ �� ���� �ö� i���� 1�� �Ǹ鼭 for���� �ݺ��ϰ� �ȴ�
		printf("���� %s���� ���� �� �ϼ� : %d,��� �� �� : %.2f\n", cities[i], totalDays, averageDays); //����� ���ش�
	}
}
