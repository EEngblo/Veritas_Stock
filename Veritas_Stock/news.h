#include "stock.h"



/****************************************/


void news(){
	/************ ���� ���� �κ� ***********/
	int news_num, type = 11, det;
	double eq_deg;
	/***************************************/


	gotoxy(60, 7);
	printf("Daily NEWS");
	gotoxy(3, 8);
	printf("������������������������������������������������������������������������������������������������");
	gotoxy(49, 8);
	printf("������������������������������������������������������������");

	gotoxy(3, 24);
	printf("������������������������������������������������������������������������������������������������");
	gotoxy(49, 24);
	printf("������������������������������������������������������������");
	gotoxy(60, 23);
	printf("My Account");
	news_num = rand() % type;
	det = rand() % 3;
	gotoxy(53, 11);
	
	switch (news_num)
	{
	case 0: //ȭ�� ����
		if (det == 0) printf("��λ� ����, ��Ϲٴ� �ѹݵ��� �ڵ���...");
		else if (det == 1) printf("���̽����� ȭ���� ���� �ѱ����� Ȯ��");
		else printf("��罺�� ��������, ��� ������ ���� �߻�");
		effect[12] -= 1500;//�迭�� ���ڴ� ����� ���ڸ� �ǹ� 
		effect[13] -= 2000;//���� ������ ���� ȿ�� ���� �� ���� ���� - > �������� �ؼ� �����ϰų� ���� �϶� ����; 
		break;

	case 1: //���� �߻� 
		eq_deg = (double)(rand() % 10) / 10 + 9;
		if (det == 0) printf("�߱� ���Ӽ� %.1f ���� �߻�, ���� ���� �ѱ�����...", eq_deg);
		else if (det == 1) printf("�Ϻ� ���쿡�� %.1f ���� �߻�, �����̰� �ѱ����� ������", eq_deg);
		else printf("��λ� �αٿ��� %.1f ���� �߻�, �������� ""ȭ�� ������ ¡�� ����.""", eq_deg - 4);
		effect[2] -= 1000;
		effect[3] -= 1000;
		effect[5] -= 1000;
		effect[6] -= 100;
		effect[7] -= 1500;
		effect[8] -= 1500;
		effect[11] -= 1500;
		effect[14] -= 2500;
		break;

	case 2: //������ Ȯ�� ��
		if (det == 0)
		{
			printf("���� �����̴� �ž࿡�� ġ������ ���ۿ� �߰�, ���� ��� ���� �ǽ�");
			effect[5] -= 1500;
		}
		else if (det == 1)
		{
			printf("���� ������ �߻�. �߻� ���� �α� �ҵ� ��ó�� ��ȹ");
			effect[11] -= 3000;
		}
		else
		{
			printf("������ ���̷���, �ٽ� �ɰ��� ���� ������.");
			effect[0] -= 1000;
			effect[5] += 1500; //�������� ȿ�� �ο� �ʿ�
			effect[12] -= 1000;
			effect[13] -= 1000;
		}
		break;

	case 3: //��ǳ �߻�
		if (det == 0) printf("�����ƽþƿ��� �߻��� ������ ���� ��ǳ <%s> ���� ��, �������� ���� ���", st_name[st_num]);
		else if (det == 1)
		{
			printf("<%s>, ���ؾ� ������ ���, ���� ��� ������ �溸 �߷� ��", st_name[st_num]);
			st_num = (st_num + 1) % 20;
		}
		else printf("�̱� �ؾ� �αٿ��� ��û�� �Ը��� ��ǳ �߻�, ����ǰ ��ۿ� ���� ����");
		effect[0] -= 700;
		effect[7] -= 700;
		break;

	case 4: //���� �� ���
		eq_deg = (double)(rand() % 10) / 10 + 38;
		if (det == 0)
		{
			printf("�߱����� �޶ѱ� �� ���ƿ�, ��ε� ���");
			effect[6] -= 2000;
		}
		else if (det == 1)
		{
			printf("������ ���� ���ȭ, ������ �ٴ��� �巯��... �� ���� ���");
			effect[6] -= 1000;
			effect[8] -= 1000;
			effect[11] -= 1000;
		}
		else
		{
			printf("���� ��� %.1f, �������� ��� ������ ���ӵ� ������ ����", eq_deg);
			effect[6] += 500;
		}
		break;

	case 5: //�׷�
		ter_num = rand() % 10;
		if (det == 0)
		{
			printf("�׷��� %s, û�ʹ�� ���� �Ÿ� ����, ���� ����", terror[ter_num]);
			effect[14] -= 500;
		}
		else if (det == 1)
		{
			printf("������ ����� ��ġ����, �׷��� %s �������� �巯��.", terror[ter_num]);
			effect[12] -= 500;
			effect[13] -= 500;
		}
		else
		{
			printf("%s, ��ź���� �ذ�� ����, ���� �ذ���� �������� ġ�� ��", terror[ter_num]);
			effect[0] -= 500;
		}
		break;

	case 6: //ȭ�� 
		if (det == 0)
		{
			printf("������ ��� Ȯ�� ��, ��� ������ ���� �õ�");
			for (i = 0; i<COMPNUM; i++) effect[i] -= 300;
		}

		else if (det == 1)
		{
			printf("�߱� ���忡�� ȭ�� �߻�, ������ ��� �����ε�");
			effect[2] -= 1000;
			effect[3] -= 1000;
		}
		else
		{
			printf("���� �ٴٿ��� ���� ���� ��� �߻�, ū ȭ��� �̾��� ��Ȳ ��ȭ");
			effect[0] -= 1000;
			effect[7] -= 500;
		}
		break;

	case 7: //�ر� 
		if (det == 0) printf("63-73 �ֵ��̺��� �Ϻ� �ر�. �߰� �ر� ���� ���� Ž�� ��");
		else if (det == 1) printf("��ǳ�׷��� ��, <��ǳ��ȭ��>, �׷��� �ر�, ���� �Ը� ��");
		else
		{
			printf("�庸��뱳 ������ ���Ը� ��Ƽ�� ���ϰ� �ر���... �ν� ���� ���� ���� ��");
			effect[0] -= 300;
		}
		effect[14] -= 700;
		break;

	case 8: //��ŷ 
		if (det == 0)
		{
			printf("�����ϸӽ�, �������� ��� Gogle�� ����. DDos�� ���� ������ ����Ǿ�...");
			effect[4] -= 1500; //��ŷ�� ���� ������ ũ�� ������ ������� ��. 
		}
		else if (det == 1)
		{
			printf("��ŷ �׷� Xinker, NEVER �� ���� ���� ����� ���ķ� �巯��");
			effect[1] -= 1500; //��ŷ�� ���� ������ ũ�� ������ ������� ��. 
		}
		else
		{
			printf("Corner Zone, ��� �ý����̵� ���� �� �ִ� �ڵ�� ��ŷ ��. ���� ��ü�� �Ӽ���å");
			effect[1] -= 1500;
			effect[2] -= 2000;
			effect[3] -= 2000;
			effect[4] -= 1500;
		}
		break;

	case 9: //��ĵ��
		bnum = rand() % 10;
		gnum = rand() % 10;
		scandle_c = rand() % 2;
		if (det == 0)
		{
			printf("S Ent�� %s��(��) G Ent�� %s�� ���̴�?", bname[bnum], gname[gnum]);
			effect[9] -= 1000;
			effect[10] -= 1000;
		}
		else if (det == 1)
		{
			printf("���! S Ent %s, %s ȸ���� ������� ������", gname[gnum], companyname[scandle_c + 2]);
			effect[9] -= 500;
			effect[scandle_c + 2] -= 1000;
		}
		else
		{
			printf("����ȸ�� ����, �ٹٸ��� ���� �Ϸ��� ������.");
			effect[5] -= 300;
		}
		break;
	case 10:
		printf("����, ���� ��ȭ ������ ��ǥ.");//�� �߰� �λ� 
		for (i = 0; i<COMPNUM; i++) effect[i] += 1000;
	}
}

void init(){
	for (i = 0; i<COMPNUM; i++)	stock[price][i] = 20000; // �ֽ� �ʱⰪ ����

	//for (i = 0; i < STUDENT; i++) student[�÷��̿���][i] = 0;
	int studentnumber = 0;

	for (i = 0; i < STUDENT; i++) {

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
			student[�й�][i] = studentnumber;
		}



		if (student[�й�][i]) {
			cout << studentnumber << " ���� ���� ��û �Ϸ�." << endl << endl;
			student[���ݺ�����][i] = 200000;
		}
		else if (studentnumber != 2487) cout << "�߸��� �й�" << endl << endl;
		fflush(stdin);
		system("PAUSE");
		clrscr();
	}

	system("PAUSE");
	clrscr();

	printfile();

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //���� �� ��ȭ 

}