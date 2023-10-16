#include <stdio.h>
#define NUMCITY 3
#define NUMPEOPLE 2

char names[NUMPEOPLE][10]; // 앞에서 define 한 상수를 바탕으로 names 및 cities 라는 이차원 배열을 정의한다
char cities[NUMCITY][10];

void calculateTravelDays();

int main() {
	//사용자로부터 도시 이름 입력받기

	printf("%d개의 도시명을 차례대로 입력해주세요. \n", NUMCITY);
	for (int i = 0; i < NUMCITY; i++) {  //NUMCITY가 3임으로 입력받은 도시가 광주 부산 서울이라고 하면 cities[0]에는 광주가 들어가고
											//i값이 1이 된후 cities[1]에는 부산 cities[2]에는 서울이 들어간다
		scanf_s("%s", cities[i], (int)sizeof(cities[i]));
	}
	//사용자로부터 사람 이름 받기

	printf("%d개의 여행자 이름을 차례대로 입력해주세요. \n", NUMPEOPLE);
	for (int i = 0; i < NUMPEOPLE; i++) {    //NUMPEOPLE 은 2 임으로  입력받은 여행자가 철수와 영희라 하면 names[0]에는 철수 names[1]에는 영희라는 값이 들어간다
		scanf_s("%s", names[i], (int)sizeof(names[i]));
	}
	//함수호출
	calculateTravelDays();

	return 0;
}

void calculateTravelDays() { //caclulateTravelDays 라는 함수를 만든다
	int travelDays[NUMCITY][NUMPEOPLE]; //travelDays라는 2차원 배열을 만든다
	//각 도시에서 각 사람이 보낸 일 수 입력받기
	for (int i = 0; i < NUMCITY; i++) {
		for (int j = 0; j < NUMPEOPLE; j++) {
			printf("도시 %s에서 사람%s가 보낸 일 수를 입력하세요: ", cities[i], names[j]); //i가 0이고 for문에 의해서 j가 0임으로 cities[0]은 광주 names[0]은 철수 임으로 광주와 철수가 들어간 문장이 출력이 된다
			scanf_s("%d", &travelDays[i][j]);//5라는 숫자를 입력하면 tracelDays[0][0]에 5라는 숫자가 들어가게 된다
		} //이 과정을 반복하게 되면 철수 와 영희가 각각 광주 부산 서울에 다 가게 됨으로 총 6번 입력을 통해 입력한 숫자가 travelDays라는 배열에 2차원으로 들어가게 된다.
	}

	//각 도시별 총 일 수 및 평균 일 수 계산 및 출력
	for (int i = 0; i < NUMCITY; i++) {
		int totalDays = 0;  //totalDays는 초기화 시켜준 다음
		for (int j = 0; j < NUMPEOPLE; j++) { //i=0 그리고 j가0 그후 i=0 j=1이 됨으로 한 도시에서 철수와 영희가 지낸 날들의 합이 totalDays에 들어가게 된다 
			totalDays += travelDays[i][j];
		}
		float averageDays = (float)totalDays / NUMPEOPLE;//그후 평균을 구해준 후 위로 올라가 i값이 1이 되면서 for문을 반복하게 된다
		printf("도시 %s에서 보낸 총 일수 : %d,평균 일 수 : %.2f\n", cities[i], totalDays, averageDays); //출력을 해준다
	}
}
