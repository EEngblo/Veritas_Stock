#include <stdio.h>
#include <stdlib.h>
#include <turboc.h> //include폴더에 추가 필요함 
#include <time.h>
#include <windows.h>
#include <iostream>

using namespace std;
#pragma warning(disable:4996)
#define timemax 10
#define COMPNUM 15 // 회사 개수
#define STUDENT 25
#define t 2 // 한 턴의 길이

/*********************/

int news_num, type = 11, det;
double eq_deg;
char st_name[20][30] = { "강아지", "개미", "우산", "우럭", "태허란", "고수", "숯불", "고니", "바라기", "병마", "은행", "사이펀", "가온", "루템", "글롭", "미래", "굉이", "솔턴", "봉봉", "베닌" };
char terror[10][30] = { "김정을", "오사마 알라딘", "Burrows", "Big Bros", "ETA", "GyeongGwak", "하마s", "SWAT", "GYLS", "AINS" };
char bname[20][30] = { "김영득", "이민석", "성재현", "김철수", "이민기", "유진상", "구준혁", "박해준", "김북곽", "제이스" }; //절대 바꾸지 말라고 이민석, 성재현 주장!!! 
char gname[20][30] = { "주니엘", "수지", "아이유", "혜리", "한지민", "오남희", "정은지", "유라", "박신혜", "김지원" };
int st_num = 0, ter_num, bnum, gnum, scandle_c;
int effect[15] = {};

/***************/
char companyname[COMPNUM][30] = { "장보고해운", "NEVER", "샘숭전자", "와플", "Gogle", "박카스제약", "해이트", "장’s 동원", "김’s 정원", "Sadi&Majo Ent", "GG Ent", "목우촌", "보잉", "911항공", "삼풍건설" }; //회사 이름 설정 
int stock[10][COMPNUM] = {};
int student[COMPNUM + 5][STUDENT] = {};

FILE*fout = fopen("data.csv", "wt"); //파일출력
int i, j, n, temp, ran, social_ran, sum, count, endgame, turn=0;

int stockgame();
int input();
int buy(int, int, int);
void printfile();
void sumprice(int);
void printaccount(int);

enum array {
		price, // 현재 주가
		plus_or_minus, // 0이면 증가, 1이면 감소
		overflow, // 너무 높아서 급락시켜야 함
		pos_collapse, // 급락 가능성
		pos_jump, // 급등 가능성
		bankrupt, // 파산 여부; 1:파산, 0:파산 x
		bankrupt_turns, // 파산 후 지난 턴 수
		randomseed, // 랜덤시드
		randomnum
};

enum account {
	장보고해운,
	NEVER,
	샘숭전자,
	와플,
	Gogle,
	박카스제약,
	해이트,
	장s동원,
	김s정원,
	Sadi_and_Majo_Ent,
	GG_Ent,
	목우촌,
	보잉,
	구일일항공,
	삼풍건설,
	학번,
	현금보유액,
	총재산
};

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


/*********************************************************************************************************************************************/

void print_box(){
	gotoxy(14, 3); //좌표이동함수 
	printf("∮VERITAS 모의주식 WITH LIMES∮");
	srand(time(NULL));
	gotoxy(3, 6);
	printf("┌─────────────────────────┬────────────────────┐");
	gotoxy(3, 2 * COMPNUM + 7 - 1);
	printf("└─────────────────────────┴────────────────────┘");
	gotoxy(59, 15);
	printf("           ");
	
}


/**********************************************************************************************************************************************/


void stock_price(){
	
	social_ran = rand() % 100;

	int randomconst = 1000;
	if (social_ran < 80) randomconst = 950;

	for (i = 0; i<COMPNUM; i++)	{
		temp = 0;

		//stock[price][i] 랜덤 변경 함수 시작 
		ran = rand() % randomconst;

		if (stock[price][i]>40000){
			stock[overflow][i]++;
			if (stock[overflow][i]>5){
				ran = 985;
				stock[overflow][i] = 0;
			}
		}
		else
			stock[overflow][i] = 0;

		if (stock[pos_jump][i] == 1) stock[randomseed][i] = 930, stock[pos_jump][i]++;
		if (stock[pos_jump][i] == 2) stock[randomseed][i] = 970, stock[pos_jump][i]++;
		if (stock[pos_jump][i] == 3) stock[randomseed][i] = 1000, stock[pos_jump][i] = 0;

		if (stock[pos_collapse][i] == 1) ran = 900, stock[pos_collapse][i]++;
		if (stock[pos_collapse][i] == 2) ran = 970, stock[pos_collapse][i]++;
		if (stock[pos_collapse][i] == 3) ran = 1001, stock[pos_collapse][i] = 0;

		if (ran < 400)
			temp += rand() % 700 + 200;
		else if (ran < 800)
			temp -= rand() % 700 + 200;
		else if (ran < 875)
			temp += rand() % 1500 + 300;
		else if (ran < 950)
			temp -= rand() % 1500 + 300;
		else if (ran < 965)
			temp += (rand() % 3000 + 2000);
		else if (ran < 980)
			temp -= (rand() % 3000 + 2000);
		else if (ran < 985)
			temp += (rand() % 5000 + 5000);
		else if (ran < 990)
			temp -= (rand() % 5000 + 5000);
		else if (ran < 993)
			temp += (rand() % 3000 + 2000), stock[pos_jump][i] = 1;
		else if (ran < 996)
			temp -= (rand() % 3000 + 2000), stock[pos_collapse][i] = 1;
		else if (ran < 998)
			temp += (rand() % 5000 + 7000);
		else
			temp -= (rand() % 5000 + 7000);

		
		//stock[price][i] 랜덤 변경 함수 종료 
		/******************************************/
		// 사회적 요인 결정 함수
		temp += effect[i];
		/******************************************/
		if (temp>0) stock[plus_or_minus][i] = 0;
		else if (temp < 0) stock[plus_or_minus][i] = 1;
		else stock[plus_or_minus][i] = 2;


		/*******************************************/
		if (turn == 1) temp = 0;
		double tempercent = (double)temp/stock[price][i]*100;

		stock[price][i] += temp;
		if (stock[price][i]<0){ // 파산결정
			stock[bankrupt][i] = 1;
			stock[price][i] = 0;
		}
		
		if (temp == 0) stock[plus_or_minus][i] = 2;

		gotoxy(3, 2 * i + 7);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		printf("│ %s : ", companyname[i]);
		gotoxy(20, 2 * i + 7);
		if (stock[bankrupt][i] == 0){
			printf("%5d ", stock[price][i]);
			gotoxy(31, 2 * i + 7);
			if (stock[plus_or_minus][i] == 0){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				printf("▲ %5d     %2.2lf %%", temp, tempercent);
			}
			else if (stock[plus_or_minus][i] == 1){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				printf("▼ %5d    %2.2lf %%", temp, tempercent);
			}
			else{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				printf("━ %5d", temp);
			}
		}
		else{
			gotoxy(27, 2 * i + 7);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			printf("     파산");
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		gotoxy(50, 2 * i + 7);
		printf("│");
		gotoxy(29, 2 * i + 7);
		printf("│");
		gotoxy(75, 2 * i + 7);
		if (i == COMPNUM - 1) continue;
		else {
			gotoxy(3, 2 * i + 8);
			if(!(i==0||i==8))printf("├─────────────────────────┼────────────────────┤");
		}
	}
}


/*******************************************************************************************************************************************/


void print_time(){
	for (j = 0; j<t; j++){
		gotoxy(14, 2 * COMPNUM + 10);
		printf("Time Left : %2dmin %2dsec", (t - j) / 60, (t - j) % 60);
		delay(1000);
	}
}


/******************************************************************************************************************************************/



int input(){
	gotoxy(53, 26);
	cout << "                                                                                                                                                                                                      ";
	gotoxy(53, 28);
	cout << "                                                       ";

	gotoxy(3, 2 * COMPNUM + 14);
	int studentnumber, company, number;

	cout << "학번을 입력해 주세요" << endl;
	cin >> studentnumber;
	fflush(stdin);
	/************************************************/
	switch (studentnumber){
	case 2487:
		cout << endl << "다음 턴이 곧 시작됩니다";
		return 0;

	case 4606:
		cout << endl << "마지막 턴입니다";
		endgame++;
		return 0;

	default:
		for (int i = 0; i < STUDENT; i++){
			if (student[학번][i] == studentnumber){
				printaccount(i);
				goto rightstudentnumber;
			}
		}
		cout << "유효하지 않은 학번 입력입니다" << endl;
		system("PAUSE");
		gotoxy(0, 2 * COMPNUM + 15);
		cout << "                                                                                " << endl;
		cout << "                                                                                " << endl;
		cout << "                                                                                " << endl;
		cout << "                                                                                " << endl;
		cout << "                                                                                " << endl;
		cout << "                                                                                " << endl;
		return 1;
	}
	
	rightstudentnumber:
	gotoxy(3, 2 * COMPNUM + 16);
	/************************************************/
	cout << " \"구입할_주식_이름   구입할_주식_개수\"를 공백으로 구분하여 입력해 주세요" << endl;
	cin >> company >> number;
	
		gotoxy(3, 2 * COMPNUM + 15);
		cout << endl << endl;
				int chkerror = buy(studentnumber, company, number);// 주식 구입 기능 구현할 자리
				if (chkerror) cout << "에러가 발생했습니다.";
				else cout << "거래가 성공적으로 완료되었습니다.";
			
		
			
		cout << endl << endl;
		system("PAUSE");

		gotoxy(0, 2 * COMPNUM + 15);
		cout << "                                                                                " << endl;
		cout << "                                                                                " << endl;
		cout << "                                                                                " << endl;
		cout << "                                                                                " << endl;
		cout << "                                                                                " << endl;
		cout << "                                                                                " << endl;

		return 1;
}


int buy(int studentnumber, int company, int number){

	if (company >= COMPNUM || company < 0) {
		cout << "회사 이름이 잘못 입력되었습니다." << endl; return 1;
	}

	for (int i = 0; i < STUDENT; i++){
		if (student[학번][i] == studentnumber){
			if (student[현금보유액][i] < number*stock[price][company]){
				cout << "보유한 현금이 부족합니다." << endl; return 1;
		}
			if (student[company][i] + number < 0){
				cout << "보유한 주식보다 많은 주식을 팔려고 시도하셨습니다" << endl; return 1;
			}
			student[현금보유액][i] -= (number*stock[price][company]);
			student[company][i] += number;

		}


		
	} 
	return 0;
}

void printaccount(int studentnumber){
	gotoxy(53, 26);
	for (int i = 0; i < COMPNUM; i++){
		if (student[i][studentnumber] != 0)
			cout << companyname[i] << " : " << student[i][studentnumber] << "\t";
	}



	return;
}