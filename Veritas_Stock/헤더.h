		news_num = rand() % type;
		det = rand() % 3;
		gotoxy(70, 13);
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
				for (i = 0; i<k; i++) effect[i] -= 300;
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
				printf("���! S Ent %s, %s ȸ���� ������� ������", gname[gnum], c[scandle_c + 2]);
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
			for (i = 0; i<k; i++) effect[i] += 1000;
		}

		//����â
		gotoxy(67, 19);
		printf("         �迭�� ����");
		for (i = 0; i<5; i++)
		{
			gotoxy(70, 23 + 2 * i);
			printf("%s��%s", c[i], comp_det[i]);

		}


		/*------------------------------------------------------------------------------------------------------------*/
		for (i = 0; i<k; i++)
		{
			temp = a[i];

			//a[i] ���� ���� �Լ� ���� 
			n = rand() % 10000;

			if (a[i]>40000)
			{
				d[i]++;
				if (d[i]>5)
				{
					n = 9850;
					d[i] = 0;
				}
			}
			else
				d[i] = 0;

			if (hahaha[i] == 1) n = 9300, hahaha[i]++;
			if (hahaha[i] == 2) n = 9700, hahaha[i]++;
			if (hahaha[i] == 3) n = 10000, hahaha[i] = 0;

			if (kaboom[i] == 1) n = 9000, kaboom[i]++;
			if (kaboom[i] == 2) n = 9700, kaboom[i]++;
			if (kaboom[i] == 3) n = 10001, kaboom[i] = 0;

			if (n<4500)
				a[i] += rand() % 700, b[i] = 0;
			else if (4500 <= n && n<9000)
				a[i] -= rand() % 700, b[i] = 1;
			else if (9000 <= n && n<9300)
				a[i] += rand() % 1500, b[i] = 0;
			else if (9300 <= n && n<9600)
				a[i] -= rand() % 1500, b[i] = 1;
			else if (9600 <= n && n<9700)
				a[i] += (rand() % 3000 + 2000), b[i] = 0;
			else if (9700 <= n && n<9800)
				a[i] -= (rand() % 3000 + 2000), b[i] = 1;
			else if (9800 <= n && n<9830)
				a[i] += (rand() % 5000 + 5000), b[i] = 0;
			else if (9830 <= n && n<9900)
				a[i] -= (rand() % 5000 + 5000), b[i] = 1;
			else if (9900 <= n && n<9930)
				a[i] += (rand() % 3000 + 2000), b[i] = 0, hahaha[i] = 1;
			else if (9930 <= n && n<10000)
				a[i] -= (rand() % 3000 + 2000), b[i] = 1, kaboom[i] = 1;
			else if (n == 10000)
				a[i] += (rand() % 5000 + 7000), b[i] = 0;
			else
				a[i] -= (rand() % 5000 + 7000), b[i] = 1;


			//a[i] ���� ���� �Լ� ���� 

			if (a[i]<0) //�Ļ���� 
			{
				boom[i] = 1;
				a[i] = 0;
			}

			if ((a[i] - temp) == 0) b[i] = 2;

			gotoxy(3, 2 * i + 7);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			printf("�� %s ", c[i]);
			gotoxy(20, 2 * i + 7);
			if (boom[i] == 0){
				printf(": %5d ", a[i]);
				gotoxy(31, 2 * i + 7);
				if (b[i] == 0){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
					printf("�� %5d", a[i] - temp);
				}
				else if (b[i] == 1){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
					printf("�� %5d", temp - a[i]);
				}
				else{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					printf("�� %5d", temp - a[i]);

				}
			}
			else{
				gotoxy(27, 2 * i + 7);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				printf("     �Ļ�");
				gotoxy(45, 2 * i + 7);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				printf("%d�� �Ŀ� ����", 5 - boomc[i]);
			}

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			gotoxy(65, 2 * i + 7);
			printf("��");
			gotoxy(29, 2 * i + 7);
			printf("��");
			gotoxy(173, 2 * i + 7);
			printf("��");
			if (i == k - 1) continue;
			else
			{
				gotoxy(3, 2 * i + 8);
				if (i == 4) printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
				else printf("����������������������������������������������������������������                                                                                                          ��");
			}
		}
		/*------------------------------------------------------------------------------------------------------------*/

		for (i = 0; i<k; i++)
			fprintf(fp, "%d ", a[i]);

		fprintf(fp, "\n");

		for (j = 0; j<t; j++)
		{
			gotoxy(7, 2 * k + 10 - 1);
			printf("Time Left : %2dmin %2dsec", (t - j) / 60, (t - j) % 60);
			delay(1000);
		}


		clrscr();
	}

	fclose(fp);
	return 0;
}
