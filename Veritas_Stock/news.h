#include "stock.h"

void news(){
	/************ ���� ���� �κ� ***********/
	int news_num, type = 12, det;
	double eq_deg;
	/***************************************/


	gotoxy(45, 8);
	printf("��������������������������������������������������������������������");
	gotoxy(60, 7);
	printf("Daily NEWS");
	news_num = 1;
	//rand()%type;
	det = rand() % 3;
	gotoxy(53, 11);
	switch (news_num)
	{
	case 0: //ȭ�� ����
		if (det == 0) printf("��λ� ����, ��Ϲٴ� �ѹݵ� ��ü�� �ڵ���...");
		else if (det == 1) printf("���̽����� ȭ���� ���� �ѱ����� Ȯ��");
		else printf("���ο콺�� ��������, ��� ������ ���� �߻�");
		break;
	case 1: //���� �߻� 
		eq_deg = (double)(rand() % 10) / 10 + 9;
		if (det == 0) printf("�߱� ���Ӽ� %.1f ���� �߻�, ���� ���� �ѱ�����...", eq_deg);
		else if (det == 1) printf("�Ϻ� ���쿡�� %.1f ���� �߻�, �����̿� �ѱ� ���ο��� ����ȭ", eq_deg);
		else printf("");
		break;
	case 2: //������ Ȯ�� ��
		if (det == 0) printf("��λ� ����, ��Ϲٴ� �ѹݵ� ��ü�� �ڵ���...");
		else printf("���̽����� ȭ���� ���� �ѱ����� Ȯ��");
		break;
	case 3: //��ǳ �߻�
		if (det == 0) printf("��λ� ����, ��Ϲٴ� �ѹݵ� ��ü�� �ڵ���...");
		else printf("���̽����� ȭ���� ���� �ѱ����� Ȯ��");
		break;
	case 4: //��8�� �߻�
		if (det == 0) printf("��λ� ����, ��Ϲٴ� �ѹݵ� ��ü�� �ڵ���...");
		else printf("���̽����� ȭ���� ���� �ѱ����� Ȯ��");
		break;
	case 5: //�׷�
		if (det == 0) printf("��λ� ����, ��Ϲٴ� �ѹݵ� ��ü�� �ڵ���...");
		else printf("���̽����� ȭ���� ���� �ѱ����� Ȯ��");
		break;
	case 6: //ȭ�� 
		if (det == 0) printf("��λ� ����, ��Ϲٴ� �ѹݵ� ��ü�� �ڵ���...");
		else printf("���̽����� ȭ���� ���� �ѱ����� Ȯ��");
		break;
	case 7: //�ر� 
		if (det == 0) printf("��λ� ����, ��Ϲٴ� �ѹݵ� ��ü�� �ڵ���...");
		else printf("���̽����� ȭ���� ���� �ѱ����� Ȯ��");
		break;
	case 8: //��ŷ 
		if (det == 0) printf("��λ� ����, ��Ϲٴ� �ѹݵ� ��ü�� �ڵ���...");
		else printf("���̽����� ȭ���� ���� �ѱ����� Ȯ��");
		break;
	case 9: //��ĵ�� 
		if (det == 0) printf("��λ� ����, ��Ϲٴ� �ѹݵ� ��ü�� �ڵ���...");
		else printf("���̽����� ȭ���� ���� �ѱ����� Ȯ��");
		break;
	case 10: //�Ŷѱ� 
		if (det == 0) printf("��λ� ����, ��Ϲٴ� �ѹݵ� ��ü�� �ڵ���...");
		else printf("���̽����� ȭ���� ���� �ѱ����� Ȯ��");
		break;
	case 11: //��� 
		if (det == 0) printf("��λ� ����, ��Ϲٴ� �ѹݵ� ��ü�� �ڵ���...");
		else printf("���̽����� ȭ���� ���� �ѱ����� Ȯ��");
		break;
	}
}

void init(){
	for (i = 0; i<COMPNUM; i++)	stock[price][i] = 20000; // �ֽ� �ʱⰪ ����

	for (i = 0; i < 1521; i++) student[�÷��̿���][i] = 0;
	int studentnumber = 0;

	while (1) {

		cout << "* VERITAS �����ֽ� (with LIMES) ver. 2.0.2 *" << endl << endl;
		cout << "���ӿ� �����Ͻ÷��� �й��� �Է��� �ּ��� : ";
		cin >> studentnumber;
		if (studentnumber>1100 &&
			(studentnumber <= 1121 ||
			(studentnumber > 1200 && studentnumber <= 1220) ||
			(studentnumber > 1300 && studentnumber <= 1320) ||
			(studentnumber > 1400 && studentnumber <= 1420) ||
			(studentnumber > 1500 && studentnumber <= 1520)) || studentnumber == 2487){
			if (studentnumber == 2487) {
				gotoxy(0, 2);
				cout << "������ �� ���۵˴ϴ�.                                        " << endl;  break;
			}
			student[�÷��̿���][studentnumber] = 1;
		}



		if (student[�÷��̿���][studentnumber]) cout << studentnumber << " ���� ���� ��û �Ϸ�." << endl << endl;
		else if (studentnumber != 2487) cout << "�߸��� �й�" << endl << endl;
		fflush(stdin);
		system("PAUSE");
		clrscr();
	}

	for (i = 0; i < STUDENT; i++)
		if (student[�÷��̿���][i]) student[���ݺ�����][i] = 200000;
	system("PAUSE");
	clrscr();

	printfile();

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //���� �� ��ȭ 

}