#include "stock.h"

void news(){
	/************ 뉴스 조절 부분 ***********/
	int news_num, type = 12, det;
	double eq_deg;
	/***************************************/


	gotoxy(45, 8);
	printf("─────┼────────────────────────────");
	gotoxy(60, 7);
	printf("Daily NEWS");
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
	case 4: //가8뭄 발생
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

	for (i = 0; i < 1521; i++) student[플레이여부][i] = 0;
	int studentnumber = 0;

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
		else if (studentnumber != 2487) cout << "잘못된 학번" << endl << endl;
		fflush(stdin);
		system("PAUSE");
		clrscr();
	}

	for (i = 0; i < STUDENT; i++)
		if (student[플레이여부][i]) student[현금보유액][i] = 200000;
	system("PAUSE");
	clrscr();

	printfile();

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //글자 색 변화 

}