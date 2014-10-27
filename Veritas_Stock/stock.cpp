#include <stdio.h>
#include <stdlib.h>
#include <turboc.h> //include������ �߰� �ʿ��� 
#include <time.h>
#include <windows.h>
#pragma warning(disable:4996)
#define timemax 10
#define COMPNUM 15 // ȸ�� ����
#define STUDENT 120
#define t 2 // �� ���� ����

char companyname[COMPNUM][30] = { "�庸���ؿ�", "NEVER", "��������", "����", "Gogle", "��ī������", "����Ʈ", "�塯s ����", "�衯s ����", "Sadi&Majo Ent", "GG Ent", "�����", "����", "911�װ�", "��ǳ�Ǽ�"}; //ȸ�� �̸� ���� 
int stock[10][COMPNUM] = {};
int student[STUDENT][COMPNUM + 5];

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
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void news();

int main(int argc, char *argv[]) {

	FILE*fp;
	int tl = timemax;
	fp = fopen("data.csv", "w+"); //�������
	int i, j, n, temp, sum, count; 


	for (i = 0; i<COMPNUM; i++)	stock[price][i] = 20000; // �ֽ� �ʱⰪ ����
	

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //���� �� ��ȭ 

	while (1){
		gotoxy(14, 3); //��ǥ�̵��Լ� 
		printf("��VERITAS �����ֽ� WITH LIMES��");
		srand(time(NULL));
		gotoxy(3, 6);
		printf("������������������������������������������������������������������������������������������������������������������������������������������������������");
		gotoxy(3, 2 * COMPNUM + 7-1);
		printf("��������������������������������������������������������������������������������������������������������������������");
		gotoxy(59, 15);
		printf("           ");


		news();
		/*------------------------------------------------------------------------------------------------------------*/
		for (i = 0; i<COMPNUM; i++)	{
			if (stock[bankrupt][i] == 1) stock[bankrupt_turns][i]++;
			if (stock[bankrupt_turns][i] >= 5) stock[bankrupt][i] = 0, stock[price][i] = 20000;
			temp = stock[price][i];

			//a[i] ���� ���� �Լ� ���� 
			stock[randomseed][i] = rand() % 10000;

			if (stock[price][i]>40000){
				stock[overflow][i]++;
				if (stock[overflow][i]>5){
					stock[randomseed][i] = 9850;
					stock[overflow][i] = 0;
				}
			}
			else
				stock[overflow][i] = 0;

			if (stock[pos_jump][i] == 1) stock[randomseed][i] = 9300, stock[pos_jump][i]++;
			if (stock[pos_jump][i] == 2) stock[randomseed][i] = 9700, stock[pos_jump][i]++;
			if (stock[pos_jump][i] == 3) stock[randomseed][i] = 10000, stock[pos_jump][i] = 0;

			if (stock[pos_collapse][i] == 1) stock[randomseed][i] = 9000, stock[pos_collapse][i]++;
			if (stock[pos_collapse][i] == 2) stock[randomseed][i] = 9700, stock[pos_collapse][i]++;
			if (stock[pos_collapse][i] == 3) stock[randomseed][i] = 10001, stock[pos_collapse][i] = 0;

			if (stock[randomseed][i]<4500)
				stock[price][i] += rand() % 700, stock[plus_or_minus][i] = 0;
			else if (4500 <= stock[randomseed][i] && stock[randomseed][i]<9000)
				stock[price][i] -= rand() % 700, stock[plus_or_minus][i] = 1;
			else if (9000 <= stock[randomseed][i] && stock[randomseed][i]<9300)
				stock[price][i] += rand() % 1500, stock[plus_or_minus][i] = 0;
			else if (9300 <= stock[randomseed][i] && stock[randomseed][i]<9600)
				stock[price][i] -= rand() % 1500, stock[plus_or_minus][i] = 1;
			else if (9600 <= stock[randomseed][i] && stock[randomseed][i]<9700)
				stock[price][i] += (rand() % 3000 + 2000), stock[plus_or_minus][i] = 0;
			else if (9700 <= stock[randomseed][i] && stock[randomseed][i]<9800)
				stock[price][i] -= (rand() % 3000 + 2000), stock[plus_or_minus][i] = 1;
			else if (9800 <= stock[randomseed][i] && stock[randomseed][i]<9830)
				stock[price][i] += (rand() % 5000 + 5000), stock[plus_or_minus][i] = 0;
			else if (9830 <= stock[randomseed][i] && stock[randomseed][i]<9900)
				stock[price][i] -= (rand() % 5000 + 5000), stock[plus_or_minus][i] = 1;
			else if (9900 <= stock[randomseed][i] && stock[randomseed][i]<9930)
				stock[price][i] += (rand() % 3000 + 2000), stock[plus_or_minus][i] = 0, stock[pos_jump][i] = 1;
			else if (9930 <= stock[randomseed][i] && stock[randomseed][i]<10000)
				stock[price][i] -= (rand() % 3000 + 2000), stock[plus_or_minus][i] = 1, stock[pos_collapse][i] = 1;
			else if (stock[randomseed][i] == 10000)
				stock[price][i] += (rand() % 5000 + 7000), stock[plus_or_minus][i] = 0;
			else
				stock[price][i] -= (rand() % 5000 + 7000), stock[plus_or_minus][i] = 1;
			//stock[price][i] ���� ���� �Լ� ���� 

			if (stock[price][i]<0){ // �Ļ����
				stock[bankrupt][i] = 1;
				stock[price][i] = 0;
			}

			if ((stock[price][i] - temp) == 0) stock[plus_or_minus][i] = 2;

			gotoxy(3, 2 * i + 7);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			printf("�� %s : ", companyname[i]);
			gotoxy(20, 2 * i + 7);
			if (stock[bankrupt][i] == 0){
				printf("%5d ", stock[price][i]);
				gotoxy(31, 2 * i + 7);
				if (stock[plus_or_minus][i] == 0){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
					printf("�� %5d", stock[price][i] - temp);
				}
				else if (stock[plus_or_minus][i] == 1){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
					printf("�� %5d", temp - stock[price][i]);
				}
				else{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					printf("�� %5d", temp - stock[price][i]);
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
			gotoxy(45, 2 * i + 7);
			printf("��");
			gotoxy(29, 2 * i + 7);
			printf("��");
			gotoxy(75, 2 * i + 7);
			if (i == COMPNUM - 1) continue;
			else {
				gotoxy(3, 2 * i + 8);
				printf("��������������������������������������������������������������������������������������                            ��");
			}
		}
		/*------------------------------------------------------------------------------------------------------------*/

		for (i = 0; i<COMPNUM; i++)
			fprintf(fp, "%d ", stock[price][i]);

		fprintf(fp, "\n");

		for (j = 0; j<t; j++)
		{
			gotoxy(14, 2 * COMPNUM + 10);
			printf("Time Left : %2dmin %2dsec", (t - j) / 60, (t - j) % 60);
			delay(1000);
		}

		clrscr();
	}

	fclose(fp);
	return 0;
}


void news(){
	/************ ���� ���� �κ� ***********/
	int news_num, type = 12, det;
	double eq_deg;
	/***************************************/


	gotoxy(45, 8);
	printf("��������������������������������������������������������");
	gotoxy(47, 7);
	printf("         Daily NEWS");
	news_num = 1;
	//rand()%type;
	det = rand() % 3;
	gotoxy(47, 11);
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
