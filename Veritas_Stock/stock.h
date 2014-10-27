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
#define STUDENT 1600
#define t 2 // 한 턴의 길이

char companyname[COMPNUM][30] = { "장보고해운", "NEVER", "샘숭전자", "와플", "Gogle", "박카스제약", "해이트", "장’s 동원", "김’s 정원", "Sadi&Majo Ent", "GG Ent", "목우촌", "보잉", "911항공", "삼풍건설" }; //회사 이름 설정 
int stock[10][COMPNUM] = {};
int student[STUDENT][COMPNUM + 5] = {};

FILE*fp = fopen("data.csv", "w+"); //파일출력
int i, j, n, temp, ran, social_ran, sum, count, endgame;

int stockgame();
int input();
int buy(int, int, int);


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
	이름,
	플레이여부,
	현금보유액,
};

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


/*********************************************************************************************************************************************/

void print_box(){
	gotoxy(14, 3); //좌표이동함수 
	printf("∮VERITAS 모의주식 WITH LIMES∮");
	srand(time(NULL));
	gotoxy(3, 6);
	printf("┌─────────────────────────┬────────────────────┬───────────────────────────────┐");
	gotoxy(3, 2 * COMPNUM + 7 - 1);
	printf("└─────────────────────────┴────────────────────┴──────────────┘");
	gotoxy(59, 15);
	printf("           ");

}


/**********************************************************************************************************************************************/


void stock_price(){
	
	social_ran = rand() % 100;

	int randomconst = 1000;
	if (social_ran < 80) randomconst = 950;

	for (i = 0; i<COMPNUM; i++)	{
		if (stock[bankrupt][i] == 1) stock[bankrupt_turns][i]++;
		if (stock[bankrupt_turns][i] >= 5) stock[bankrupt][i] = 0, stock[price][i] = 20000;
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
			temp += rand() % 700 + 200, stock[plus_or_minus][i] = 0;
		else if (ran < 800)
			temp -= rand() % 700 + 200, stock[plus_or_minus][i] = 1;
		else if (ran < 875)
			temp += rand() % 1500 + 300, stock[plus_or_minus][i] = 0;
		else if (ran < 950)
			temp -= rand() % 1500 + 300, stock[plus_or_minus][i] = 1;
		else if (ran < 965)
			temp += (rand() % 3000 + 2000), stock[plus_or_minus][i] = 0;
		else if (ran < 980)
			temp -= (rand() % 3000 + 2000), stock[plus_or_minus][i] = 1;
		else if (ran < 985)
			temp += (rand() % 5000 + 5000), stock[plus_or_minus][i] = 0;
		else if (ran < 990)
			temp -= (rand() % 5000 + 5000), stock[plus_or_minus][i] = 1;
		else if (ran < 993)
			temp += (rand() % 3000 + 2000), stock[plus_or_minus][i] = 0, stock[pos_jump][i] = 1;
		else if (ran < 996)
			temp -= (rand() % 3000 + 2000), stock[plus_or_minus][i] = 1, stock[pos_collapse][i] = 1;
		else if (ran < 998)
			temp += (rand() % 5000 + 7000), stock[plus_or_minus][i] = 0;
		else
			temp -= (rand() % 5000 + 7000), stock[plus_or_minus][i] = 1;

		
		//stock[price][i] 랜덤 변경 함수 종료 
		/******************************************/
		// 사회적 요인 결정 함수

		/******************************************/

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
			gotoxy(45, 2 * i + 7);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			printf("%d턴 후에 복구", 5 - stock[bankrupt_turns][i]);
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
			printf("├─────────────────────────┼────────────────────┤                            │");
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


void news(){
	/************ 뉴스 조절 부분 ***********/
	int news_num, type = 12, det;
	double eq_deg;
	/***************************************/


	gotoxy(45, 8);
	printf("─────┼──────────────────────────┤");
	gotoxy(53, 7);
	printf("         Daily NEWS");
	news_num = 1;
	//rand()%type;
	det = rand() % 3;
	gotoxy(53, 11);
	switch (news_num)
	{
	case 0: //화산 폭발
		if (det == 0) printf("백두산 폭발, 용암바다 한반도 전체를 뒤덮어...");
		else if (det == 1) printf("아이슬란드 화산재 구름 한국꺼지 확산");
		else printf("엘로우스톤 국립공원, 사상 초유의 폭발 발생");
		break;
	case 1: //지진 발생 
		eq_deg = (double)(rand() % 10) / 10 + 9;
		if (det == 0) printf("중국 쓰촨성 %.1f 지진 발생, 지진 여파 한국까지...", eq_deg);
		else if (det == 1) printf("일본 도쿄에서 %.1f 지진 발생, 쓰나미에 한국 동부연안 초토화", eq_deg);
		else printf("");
		break;
	case 2: //전염병 확산 중
		if (det == 0) printf("백두산 폭발, 용암바다 한반도 전체를 뒤덮어...");
		else printf("아이슬란드 화산재 구름 한국꺼지 확산");
		break;
	case 3: //태풍 발생
		if (det == 0) printf("백두산 폭발, 용암바다 한반도 전체를 뒤덮어...");
		else printf("아이슬란드 화산재 구름 한국꺼지 확산");
		break;
	case 4: //가뭄 발생
		if (det == 0) printf("백두산 폭발, 용암바다 한반도 전체를 뒤덮어...");
		else printf("아이슬란드 화산재 구름 한국꺼지 확산");
		break;
	case 5: //테러
		if (det == 0) printf("백두산 폭발, 용암바다 한반도 전체를 뒤덮어...");
		else printf("아이슬란드 화산재 구름 한국꺼지 확산");
		break;
	case 6: //화재 
		if (det == 0) printf("백두산 폭발, 용암바다 한반도 전체를 뒤덮어...");
		else printf("아이슬란드 화산재 구름 한국꺼지 확산");
		break;
	case 7: //붕괴 
		if (det == 0) printf("백두산 폭발, 용암바다 한반도 전체를 뒤덮어...");
		else printf("아이슬란드 화산재 구름 한국꺼지 확산");
		break;
	case 8: //해킹 
		if (det == 0) printf("백두산 폭발, 용암바다 한반도 전체를 뒤덮어...");
		else printf("아이슬란드 화산재 구름 한국꺼지 확산");
		break;
	case 9: //스캔들 
		if (det == 0) printf("백두산 폭발, 용암바다 한반도 전체를 뒤덮어...");
		else printf("아이슬란드 화산재 구름 한국꺼지 확산");
		break;
	case 10: //매뚜기 
		if (det == 0) printf("백두산 폭발, 용암바다 한반도 전체를 뒤덮어...");
		else printf("아이슬란드 화산재 구름 한국꺼지 확산");
		break;
	case 11: //사망 
		if (det == 0) printf("백두산 폭발, 용암바다 한반도 전체를 뒤덮어...");
		else printf("아이슬란드 화산재 구름 한국꺼지 확산");
		break;
	}
}

void init(){
	for (i = 0; i<COMPNUM; i++)	stock[price][i] = 20000; // 주식 초기값 설정


	int studentnumber=0;

	while (1) {

		cout << "* VERITAS 모의주식 (with LIMES) ver. 2.0.2 *" << endl << endl;
		cout << "게임에 참여하시려면 학번을 입력해 주세요 : ";
		cin >> studentnumber;
		if (studentnumber>1100 &&
			(studentnumber <= 1121 ||
			(studentnumber > 1200 && studentnumber <= 1220) ||
			(studentnumber > 1300 && studentnumber <= 1320) ||
			(studentnumber > 1400 && studentnumber <= 1420) ||
			(studentnumber > 1500 && studentnumber <= 1520)) || studentnumber == 2487){
			if (studentnumber == 2487) {
				gotoxy(0, 2);
				cout << "게임이 곧 시작됩니다.                                        " << endl;  break;
			}
				student[플레이여부][studentnumber] = 1;
		}


		
		if (student[플레이여부][studentnumber]) cout << studentnumber << " 게임 참가 신청 완료." << endl << endl;
		else if(studentnumber != 2487) cout << "잘못된 학번" << endl << endl;
		fflush(stdin);
		system("PAUSE");
		clrscr();
	}

	for (i = 0; i < STUDENT; i++) 
		if(student[플레이여부][i]) student[현금보유액][i] = 200000;
	system("PAUSE");
	clrscr();
	

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //글자 색 변화 

}

int input(){
	gotoxy(3, 2 * COMPNUM + 14);
	int studentnumber, company, number;
	cout << " \"학번   구입할_주식_이름   구입할_주식_개수\"를 공백으로 구분하여 입력해 주세요" << endl;
	cin >> studentnumber >> company >> number;

	switch (studentnumber){
	case 2487:
		cout << endl << "다음 턴이 곧 시작됩니다";
		return 0;

	case 4606:
		cout << endl << "마지막 턴입니다";
		endgame++;
		return 0;

	default:
		gotoxy(3, 2 * COMPNUM + 15);
		cout << endl << endl;
		if (student[플레이여부][studentnumber]){
			int chkerror = buy(studentnumber, company, number);// 주식 구입 기능 구현할 자리
			if (chkerror) cout << "에러가 발생했습니다.";
			else cout << "거래가 성공적으로 완료되었습니다.";
		}
		else cout << "잘못된 학번 입력입니다.";

		cout << endl << endl;
		system("PAUSE");

		gotoxy(0, 2 * COMPNUM + 15);
		cout << "                                                 " << endl;
		cout << "                                                 " << endl;
		cout << "                                                 " << endl;
		cout << "                                                 " << endl;
		cout << "                                                 " << endl;
		cout << "                                                 " << endl;

		return 1;
	}
}


