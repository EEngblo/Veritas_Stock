#include "stock.h"

int main(int argc, char *argv[]) {

	init();

	while (stockgame()){};

	fclose(fp);
	return 0;
}

int stockgame(){
	print_box();
	stock_price();
	news();
	while (input());

	print_time();
	clrscr();

	return 1; // 나중에 수정
}

int input(){
	gotoxy(3, 2 * COMPNUM + 14);
	int studentnumber, company, number;
	cout << " \"학번   구입할_주식_이름   구입할_주식_개수\"를 공백으로 구분하여 입력해 주세요" << endl;
	cin >> studentnumber >> company >> number;

	if (studentnumber == 2487){
		cout << endl << "다음 턴이 곧 시작됩니다";
		return 0;
	}

	gotoxy(3, 2 * COMPNUM + 15);
	cout << endl << endl;
	if (student[플레이여부][studentnumber]){

		// 주식 구입 기능 구현할 자리

		cout  << "정상적으로 처리되었습니다";
	}
	else cout << "잘못된 학번 입력입니다.";

	cout << endl << endl;
	system("PAUSE");
	
	gotoxy(0, 2 * COMPNUM + 15);
	cout << "                                                 " << endl << endl << "                                   " << endl << endl << "                                   ";

	return 1;
}
