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

	return 1; // ���߿� ����
}

int input(){
	gotoxy(3, 2 * COMPNUM + 14);
	int studentnumber, company, number;
	cout << " \"�й�   ������_�ֽ�_�̸�   ������_�ֽ�_����\"�� �������� �����Ͽ� �Է��� �ּ���" << endl;
	cin >> studentnumber >> company >> number;

	if (studentnumber == 2487){
		cout << endl << "���� ���� �� ���۵˴ϴ�";
		return 0;
	}

	gotoxy(3, 2 * COMPNUM + 15);
	cout << endl << endl;
	if (student[�÷��̿���][studentnumber]){

		// �ֽ� ���� ��� ������ �ڸ�

		cout  << "���������� ó���Ǿ����ϴ�";
	}
	else cout << "�߸��� �й� �Է��Դϴ�.";

	cout << endl << endl;
	system("PAUSE");
	
	gotoxy(0, 2 * COMPNUM + 15);
	cout << "                                                 " << endl << endl << "                                   " << endl << endl << "                                   ";

	return 1;
}
