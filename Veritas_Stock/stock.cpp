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

	if (endgame) return 0;
	else return 1;
}

int buy(int studentnumber, int company, int number){
	if (student[현금보유액][studentnumber] < number*stock[price][company]){
		cout << "보유한 현금이 부족합니다." << endl; return 1;
	}
	if (company > COMPNUM) {
		cout << "회사 이름이 잘못 입력되었습니다." << endl; return 1;
	}
	student[현금보유액][studentnumber] -= (number*stock[price][company]);
	student[company][studentnumber] += number;

	return 0;
}
