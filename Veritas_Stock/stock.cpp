#include "news.h"

int main(int argc, char *argv[]) {

	init();
	printfile();
	while (stockgame()){};

	fclose(fout);
	return 0;
}

int stockgame(){
	
	turn++;
	print_box();
	news();
	stock_price();

	while (input());

	print_time();
	clrscr();
	printfile();
	if (endgame) return 0;
	else return 1;
}

void printfile(){
	/*
	fprintf(fout, "%d \t", turn);
	for (int i = 0; i < COMPNUM; i++)
		fprintf(fout, "%d \t", stock[price][i]);
	fprintf(fout, "\n");

	for (int i = 0; i < 1521; i++){
		if (student[�÷��̿���][i]){
			sumprice(i);
			fprintf(fout, "%d \t", student[�����][i]);
		}
	}
	fprintf(fout, "\n\n");

	return;  */
}

void sumprice(int n){
	for (int i = 0; i < COMPNUM; i++){
		student[�����][n] += stock[price][i];
	}
}