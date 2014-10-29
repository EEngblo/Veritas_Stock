		news_num = rand() % type;
		det = rand() % 3;
		gotoxy(70, 13);
		switch (news_num)
		{
		case 0: //화산 폭발
			if (det == 0) printf("백두산 폭발, 용암바다 한반도를 뒤덮어...");
			else if (det == 1) printf("아이슬란드 화산재 구름 한국꺼지 확산");
			else printf("블루스톤 국립공원, 사상 초유의 폭발 발생");
			effect[12] -= 1500;//배열의 숫자는 기업의 숫자를 의미 
			effect[13] -= 2000;//숫자 증가는 뉴스 효과 지속 턴 수를 지정 - > 랜덤으로 해서 증폭하거나 일정 하락 적용; 
			break;

		case 1: //지진 발생 
			eq_deg = (double)(rand() % 10) / 10 + 9;
			if (det == 0) printf("중국 쓰촨성 %.1f 지진 발생, 지진 여파 한국까지...", eq_deg);
			else if (det == 1) printf("일본 도쿄에서 %.1f 지진 발생, 쓰나미가 한국까지 도달해", eq_deg);
			else printf("백두산 부근에서 %.1f 지진 발생, 전문가들 ""화산 폭발의 징조 보여.""", eq_deg - 4);
			effect[2] -= 1000;
			effect[3] -= 1000;
			effect[5] -= 1000;
			effect[6] -= 100;
			effect[7] -= 1500;
			effect[8] -= 1500;
			effect[11] -= 1500;
			effect[14] -= 2500;
			break;

		case 2: //전염병 확산 중
			if (det == 0)
			{
				printf("보급 예정이던 신약에서 치명적인 부작용 발견, 정부 긴급 감사 실시");
				effect[5] -= 1500;
			}
			else if (det == 1)
			{
				printf("신종 구제역 발생. 발생 지역 인근 소들 살처분 계획");
				effect[11] -= 3000;
			}
			else
			{
				printf("에볼라 바이러스, 다시 심각한 변이 일으켜.");
				effect[0] -= 1000;
				effect[5] += 1500; //긍정적인 효과 부여 필요
				effect[12] -= 1000;
				effect[13] -= 1000;
			}
			break;

		case 3: //태풍 발생
			if (det == 0) printf("동남아시아에서 발생한 강력한 열대 폭풍 <%s> 접근 중, 전문가들 주의 당부", st_name[st_num]);
			else if (det == 1)
			{
				printf("<%s>, 서해안 쪽으로 상륙, 현재 모든 지역에 경보 발령 중", st_name[st_num]);
				st_num = (st_num + 1) % 20;
			}
			else printf("미국 해안 부근에서 엄청난 규모의 폭풍 발생, 수입품 운송에 차질 예상");
			effect[0] -= 700;
			effect[7] -= 700;
			break;

		case 4: //가뭄 및 농업
			eq_deg = (double)(rand() % 10) / 10 + 38;
			if (det == 0)
			{
				printf("중국에서 메뚜기 때 날아와, 농민들 울상");
				effect[6] -= 2000;
			}
			else if (det == 1)
			{
				printf("전국적 가뭄 장기화, 저수지 바닥을 드러내... 물 공급 비상");
				effect[6] -= 1000;
				effect[8] -= 1000;
				effect[11] -= 1000;
			}
			else
			{
				printf("오늘 기온 %.1f, 오랫동안 고온 현상이 지속될 것으로 전망", eq_deg);
				effect[6] += 500;
			}
			break;

		case 5: //테러
			ter_num = rand() % 10;
			if (det == 0)
			{
				printf("테러단 %s, 청와대와 강남 거리 습격, 전쟁 선포", terror[ter_num]);
				effect[14] -= 500;
			}
			else if (det == 1)
			{
				printf("국제선 비행기 납치당해, 테러단 %s 소행으로 드러나.", terror[ter_num]);
				effect[12] -= 500;
				effect[13] -= 500;
			}
			else
			{
				printf("%s, 폭탄으로 해경들 위협, 현재 해경들은 병원에서 치료 중", terror[ter_num]);
				effect[0] -= 500;
			}
			break;

		case 6: //화재 
			if (det == 0)
			{
				printf("전국적 산불 확산 중, 헬기 동원해 진압 시도");
				for (i = 0; i<k; i++) effect[i] -= 300;
			}

			else if (det == 1)
			{
				printf("중국 공장에서 화재 발생, 원인은 기계 과열인듯");
				effect[2] -= 1000;
				effect[3] -= 1000;
			}
			else
			{
				printf("동해 바다에서 원유 유출 사고 발생, 큰 화재로 이어져 상황 악화");
				effect[0] -= 1000;
				effect[7] -= 500;
			}
			break;

		case 7: //붕괴 
			if (det == 0) printf("63-73 쌍둥이빌딩 일부 붕괴. 추가 붕괴 위험 지점 탐색 중");
			else if (det == 1) printf("삼풍그룹의 명물, <삼풍백화점>, 테러로 붕괴, 진상 규명 중");
			else
			{
				printf("장보고대교 차량의 무게를 버티지 못하고 붕괴해... 부실 공사 여부 조사 중");
				effect[0] -= 300;
			}
			effect[14] -= 700;
			break;

		case 8: //해킹 
			if (det == 0)
			{
				printf("유나니머스, 세계적인 기업 Gogle에 도전. DDos로 현재 서버가 마비되어...");
				effect[4] -= 1500; //해킹은 조금 영향이 크게 넣으면 재미있을 듯. 
			}
			else if (det == 1)
			{
				printf("해킹 그룹 Xinker, NEVER 고객 정보 유출 사건의 배후로 드러나");
				effect[1] -= 1500; //해킹은 조금 영향이 크게 넣으면 재미있을 듯. 
			}
			else
			{
				printf("Corner Zone, 어느 시스템이든 뚫을 수 있는 코드로 해킹 중. 보안 업체는 속수무책");
				effect[1] -= 1500;
				effect[2] -= 2000;
				effect[3] -= 2000;
				effect[4] -= 1500;
			}
			break;

		case 9: //스캔들
			bnum = rand() % 10;
			gnum = rand() % 10;
			scandle_c = rand() % 2;
			if (det == 0)
			{
				printf("S Ent의 %s와(과) G Ent의 %s의 사이는?", bname[bnum], gname[gnum]);
				effect[9] -= 1000;
				effect[10] -= 1000;
			}
			else if (det == 1)
			{
				printf("충격! S Ent %s, %s 회장의 내연녀로 밝혀져", gname[gnum], c[scandle_c + 2]);
				effect[9] -= 500;
				effect[scandle_c + 2] -= 1000;
			}
			else
			{
				printf("제약회사 사장, 바바리맨 행위 하려다 실패해.");
				effect[5] -= 300;
			}
			break;
		case 10:
			printf("정부, 규제 완화 개혁안 발표.");//돈 추가 인상 
			for (i = 0; i<k; i++) effect[i] += 1000;
		}

		//설명창
		gotoxy(67, 19);
		printf("         계열사 설명");
		for (i = 0; i<5; i++)
		{
			gotoxy(70, 23 + 2 * i);
			printf("%s→%s", c[i], comp_det[i]);

		}


		/*------------------------------------------------------------------------------------------------------------*/
		for (i = 0; i<k; i++)
		{
			temp = a[i];

			//a[i] 랜덤 변경 함수 시작 
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


			//a[i] 랜덤 변경 함수 종료 

			if (a[i]<0) //파산결정 
			{
				boom[i] = 1;
				a[i] = 0;
			}

			if ((a[i] - temp) == 0) b[i] = 2;

			gotoxy(3, 2 * i + 7);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			printf("│ %s ", c[i]);
			gotoxy(20, 2 * i + 7);
			if (boom[i] == 0){
				printf(": %5d ", a[i]);
				gotoxy(31, 2 * i + 7);
				if (b[i] == 0){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
					printf("▲ %5d", a[i] - temp);
				}
				else if (b[i] == 1){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
					printf("▼ %5d", temp - a[i]);
				}
				else{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					printf("━ %5d", temp - a[i]);

				}
			}
			else{
				gotoxy(27, 2 * i + 7);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				printf("     파산");
				gotoxy(45, 2 * i + 7);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				printf("%d턴 후에 복구", 5 - boomc[i]);
			}

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			gotoxy(65, 2 * i + 7);
			printf("│");
			gotoxy(29, 2 * i + 7);
			printf("│");
			gotoxy(173, 2 * i + 7);
			printf("│");
			if (i == k - 1) continue;
			else
			{
				gotoxy(3, 2 * i + 8);
				if (i == 4) printf("├────────────┼─────────────────┼─────────────────────────────────────────────────────┤");
				else printf("├────────────┼─────────────────┤                                                                                                          │");
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
