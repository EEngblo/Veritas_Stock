#include "stock.h"

int main(int argc, char *argv[]) {

	init();

	while (stockgame()){};

	fclose(fp);
	return 0;
}

int stockgame(){
	print_box();
	news();
	stock_price();
	print_time();
	clrscr();

	return 1; // 나중에 수정
}
