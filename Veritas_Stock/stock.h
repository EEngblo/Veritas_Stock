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
#define STUDENT 25
#define t 2 // �� ���� ����

/*********************/

int news_num, type = 11, det;
double eq_deg;
char st_name[20][30] = { "������", "����", "���", "�췰", "�����", "���", "����", "���", "�ٶ��", "����", "����", "������", "����", "����", "�۷�", "�̷�", "����", "����", "����", "����" };
char terror[10][30] = { "������", "���縶 �˶��", "Burrows", "Big Bros", "ETA", "GyeongGwak", "�ϸ�s", "SWAT", "GYLS", "AINS" };
char bname[20][30] = { "�迵��", "�̹μ�", "������", "��ö��", "�̹α�", "������", "������", "������", "��ϰ�", "���̽�" }; //���� �ٲ��� ����� �̹μ�, ������ ����!!! 
char gname[20][30] = { "�ִϿ�", "����", "������", "����", "������", "������", "������", "����", "�ڽ���", "������" };
int st_num = 0, ter_num, bnum, gnum, scandle_c;
int effect[15] = {};

/***************/
char companyname[COMPNUM][30] = { "�庸���ؿ�", "NEVER", "��������", "����", "Gogle", "��ī������", "����Ʈ", "�塯s ����", "�衯s ����", "Sadi&Majo Ent", "GG Ent", "�����", "����", "911�װ�", "��ǳ�Ǽ�" }; //ȸ�� �̸� ���� 
int stock[10][COMPNUM] = {};
int student[COMPNUM + 5][STUDENT] = {};

FILE*fout = fopen("data.csv", "wt"); //�������
int i, j, n, temp, ran, social_ran, sum, count, endgame, turn=0;

int stockgame();
int input();
int buy(int, int, int);
void printfile();
void sumprice(int);
void printaccount(int);

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
	�й�,
	���ݺ�����,
	�����
};

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


/*********************************************************************************************************************************************/

void print_box(){
	gotoxy(14, 3); //��ǥ�̵��Լ� 
	printf("��VERITAS �����ֽ� WITH LIMES��");
	srand(time(NULL));
	gotoxy(3, 6);
	printf("������������������������������������������������������������������������������������������������");
	gotoxy(3, 2 * COMPNUM + 7 - 1);
	printf("������������������������������������������������������������������������������������������������");
	gotoxy(59, 15);
	printf("           ");
	
}


/**********************************************************************************************************************************************/


void stock_price(){
	
	social_ran = rand() % 100;

	int randomconst = 1000;
	if (social_ran < 80) randomconst = 950;

	for (i = 0; i<COMPNUM; i++)	{
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
			temp += rand() % 700 + 200;
		else if (ran < 800)
			temp -= rand() % 700 + 200;
		else if (ran < 875)
			temp += rand() % 1500 + 300;
		else if (ran < 950)
			temp -= rand() % 1500 + 300;
		else if (ran < 965)
			temp += (rand() % 3000 + 2000);
		else if (ran < 980)
			temp -= (rand() % 3000 + 2000);
		else if (ran < 985)
			temp += (rand() % 5000 + 5000);
		else if (ran < 990)
			temp -= (rand() % 5000 + 5000);
		else if (ran < 993)
			temp += (rand() % 3000 + 2000), stock[pos_jump][i] = 1;
		else if (ran < 996)
			temp -= (rand() % 3000 + 2000), stock[pos_collapse][i] = 1;
		else if (ran < 998)
			temp += (rand() % 5000 + 7000);
		else
			temp -= (rand() % 5000 + 7000);

		
		//stock[price][i] ���� ���� �Լ� ���� 
		/******************************************/
		// ��ȸ�� ���� ���� �Լ�
		temp += effect[i];
		/******************************************/
		if (temp>0) stock[plus_or_minus][i] = 0;
		else if (temp < 0) stock[plus_or_minus][i] = 1;
		else stock[plus_or_minus][i] = 2;


		/*******************************************/
		if (turn == 1) temp = 0;
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
			if(!(i==0||i==8))printf("������������������������������������������������������������������������������������������������");
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



int input(){
	gotoxy(53, 26);
	cout << "                                                                                                                                                                                                      ";
	gotoxy(53, 28);
	cout << "                                                       ";

	gotoxy(3, 2 * COMPNUM + 14);
	int studentnumber, company, number;

	cout << "�й��� �Է��� �ּ���" << endl;
	cin >> studentnumber;
	fflush(stdin);
	/************************************************/
	switch (studentnumber){
	case 2487:
		cout << endl << "���� ���� �� ���۵˴ϴ�";
		return 0;

	case 4606:
		cout << endl << "������ ���Դϴ�";
		endgame++;
		return 0;

	default:
		for (int i = 0; i < STUDENT; i++){
			if (student[�й�][i] == studentnumber){
				printaccount(i);
				goto rightstudentnumber;
			}
		}
		cout << "��ȿ���� ���� �й� �Է��Դϴ�" << endl;
		system("PAUSE");
		gotoxy(0, 2 * COMPNUM + 15);
		cout << "                                                                                " << endl;
		cout << "                                                                                " << endl;
		cout << "                                                                                " << endl;
		cout << "                                                                                " << endl;
		cout << "                                                                                " << endl;
		cout << "                                                                                " << endl;
		return 1;
	}
	
	rightstudentnumber:
	gotoxy(3, 2 * COMPNUM + 16);
	/************************************************/
	cout << " \"������_�ֽ�_�̸�   ������_�ֽ�_����\"�� �������� �����Ͽ� �Է��� �ּ���" << endl;
	cin >> company >> number;
	
		gotoxy(3, 2 * COMPNUM + 15);
		cout << endl << endl;
				int chkerror = buy(studentnumber, company, number);// �ֽ� ���� ��� ������ �ڸ�
				if (chkerror) cout << "������ �߻��߽��ϴ�.";
				else cout << "�ŷ��� ���������� �Ϸ�Ǿ����ϴ�.";
			
		
			
		cout << endl << endl;
		system("PAUSE");

		gotoxy(0, 2 * COMPNUM + 15);
		cout << "                                                                                " << endl;
		cout << "                                                                                " << endl;
		cout << "                                                                                " << endl;
		cout << "                                                                                " << endl;
		cout << "                                                                                " << endl;
		cout << "                                                                                " << endl;

		return 1;
}


int buy(int studentnumber, int company, int number){

	if (company >= COMPNUM || company < 0) {
		cout << "ȸ�� �̸��� �߸� �ԷµǾ����ϴ�." << endl; return 1;
	}

	for (int i = 0; i < STUDENT; i++){
		if (student[�й�][i] == studentnumber){
			if (student[���ݺ�����][i] < number*stock[price][company]){
				cout << "������ ������ �����մϴ�." << endl; return 1;
		}
			if (student[company][i] + number < 0){
				cout << "������ �ֽĺ��� ���� �ֽ��� �ȷ��� �õ��ϼ̽��ϴ�" << endl; return 1;
			}
			student[���ݺ�����][i] -= (number*stock[price][company]);
			student[company][i] += number;

		}


		
	} 
	return 0;
}

void printaccount(int studentnumber){
	gotoxy(53, 26);
	for (int i = 0; i < COMPNUM; i++){
		if (student[i][studentnumber] != 0)
			cout << companyname[i] << " : " << student[i][studentnumber] << "\t";
	}



	return;
}