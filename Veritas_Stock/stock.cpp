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
	if (student[���ݺ�����][studentnumber] < number*stock[price][company]){
		cout << "������ ������ �����մϴ�." << endl; return 1;
	}
	if (company > COMPNUM) {
		cout << "ȸ�� �̸��� �߸� �ԷµǾ����ϴ�." << endl; return 1;
	}
	student[���ݺ�����][studentnumber] -= (number*stock[price][company]);
	student[company][studentnumber] += number;

	return 0;
}
