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

