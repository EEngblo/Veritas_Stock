#include <stdio.h>
#include <stdlib.h>
#include <turboc.h> //include������ �߰� �ʿ��� 
#include <time.h>
#include <windows.h>
#include <iostream>

using namespace std;
#pragma warning(disable:4996)
#define timemax 10
#define COMPNUM 15 // ȸ�� ����
#define STUDENT 1600
#define t 2 // �� ���� ����

char companyname[COMPNUM][30] = { "�庸���ؿ�", "NEVER", "��������", "����", "Gogle", "��ī������", "����Ʈ", "�塯s ����", "�衯s ����", "Sadi&Majo Ent", "GG Ent", "�����", "����", "911�װ�", "��ǳ�Ǽ�" }; //ȸ�� �̸� ���� 
int stock[10][COMPNUM] = {};
int student[STUDENT][COMPNUM + 5] = {};

FILE*fp = fopen("data.csv", "w+"); //�������
int i, j, n, temp, ran, social_ran, sum, count, endgame;

int stockgame();
int input();
int buy(int, int, int);


enum array {
		price, // ���� �ְ�
		plus_or_minus, // 0�̸� ����, 1�̸� ����
		overflow, // �ʹ� ���Ƽ� �޶����Ѿ� ��
		pos_collapse, // �޶� ���ɼ�
		pos_jump, // �޵� ���ɼ�
		bankrupt, // �Ļ� ����; 1:�Ļ�, 0:�Ļ� x
		bankrupt_turns, // �Ļ� �� ���� �� ��
		randomseed, // �����õ�
		randomnum
};

enum account {
	�庸���ؿ�,
	NEVER,
	��������,
	����,
	Gogle,
	��ī������,
	����Ʈ,
	��s����,
	��s����,
	Sadi_and_Majo_Ent,
	GG_Ent,
	�����,
	����,
	�������װ�,
	��ǳ�Ǽ�,
	�̸�,
	�÷��̿���,
	���ݺ�����,
};

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


/*********************************************************************************************************************************************/

void print_box(){
	gotoxy(14, 3); //��ǥ�̵��Լ� 
	printf("��VERITAS �����ֽ� WITH LIMES��");
	srand(time(NULL));
	gotoxy(3, 6);
	printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������");
	gotoxy(3, 2 * COMPNUM + 7 - 1);
	printf("������������������������������������������������������������������������������������������������������������������������������");
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

		//stock[price][i] ���� ���� �Լ� ���� 
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

		
		//stock[price][i] ���� ���� �Լ� ���� 
		/******************************************/
		// ��ȸ�� ���� ���� �Լ�

		/******************************************/

		double tempercent = (double)temp/stock[price][i]*100;
		stock[price][i] += temp;
		if (stock[price][i]<0){ // �Ļ����
			stock[bankrupt][i] = 1;
			stock[price][i] = 0;
		}

		if (temp == 0) stock[plus_or_minus][i] = 2;

		gotoxy(3, 2 * i + 7);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		printf("�� %s : ", companyname[i]);
		gotoxy(20, 2 * i + 7);
		if (stock[bankrupt][i] == 0){
			printf("%5d ", stock[price][i]);
			gotoxy(31, 2 * i + 7);
			if (stock[plus_or_minus][i] == 0){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				printf("�� %5d     %2.2lf %%", temp, tempercent);
			}
			else if (stock[plus_or_minus][i] == 1){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				printf("�� %5d    %2.2lf %%", temp, tempercent);
			}
			else{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				printf("�� %5d", temp);
			}
		}
		else{
			gotoxy(27, 2 * i + 7);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			printf("     �Ļ�");
			gotoxy(45, 2 * i + 7);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			printf("%d�� �Ŀ� ����", 5 - stock[bankrupt_turns][i]);
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		gotoxy(50, 2 * i + 7);
		printf("��");
		gotoxy(29, 2 * i + 7);
		printf("��");
		gotoxy(75, 2 * i + 7);
		if (i == COMPNUM - 1) continue;
		else {
			gotoxy(3, 2 * i + 8);
			printf("������������������������������������������������������������������������������������������������                            ��");
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
	/************ ���� ���� �κ� ***********/
	int news_num, type = 12, det;
	double eq_deg;
	/***************************************/


	gotoxy(45, 8);
	printf("������������������������������������������������������������������");
	gotoxy(53, 7);
	printf("         Daily NEWS");
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
	case 4: //���� �߻�
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


	int studentnumber=0;

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
		else if(studentnumber != 2487) cout << "�߸��� �й�" << endl << endl;
		fflush(stdin);
		system("PAUSE");
		clrscr();
	}

	for (i = 0; i < STUDENT; i++) 
		if(student[�÷��̿���][i]) student[���ݺ�����][i] = 200000;
	system("PAUSE");
	clrscr();
	

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //���� �� ��ȭ 

}

int input(){
	gotoxy(3, 2 * COMPNUM + 14);
	int studentnumber, company, number;
	cout << " \"�й�   ������_�ֽ�_�̸�   ������_�ֽ�_����\"�� �������� �����Ͽ� �Է��� �ּ���" << endl;
	cin >> studentnumber >> company >> number;

	switch (studentnumber){
	case 2487:
		cout << endl << "���� ���� �� ���۵˴ϴ�";
		return 0;

	case 4606:
		cout << endl << "������ ���Դϴ�";
		endgame++;
		return 0;

	default:
		gotoxy(3, 2 * COMPNUM + 15);
		cout << endl << endl;
		if (student[�÷��̿���][studentnumber]){
			int chkerror = buy(studentnumber, company, number);// �ֽ� ���� ��� ������ �ڸ�
			if (chkerror) cout << "������ �߻��߽��ϴ�.";
			else cout << "�ŷ��� ���������� �Ϸ�Ǿ����ϴ�.";
		}
		else cout << "�߸��� �й� �Է��Դϴ�.";

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


