/*카르노맵 만들기 프로그램*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

//int bowl_value(char bowl[100]);
//void kr();

int main()
{
	char formular[100] = { NULL };
	int kr[100][100] = { NULL };
	int map[100] = { NULL };
	char *last_formular[100] = { NULL };
	int value, a = 0, i, token_stack = 0;
	char *token;
	char copy_formular[100] = { NULL };
	char *sep_fm[100] = { NULL };
	char seps[] = "+";
	int x, y; //xy값을 카르노맵으로 그릴 때 값을 집어넣기 위해
	printf("☆★카르노맵을 이용한 부울 대수 간소화 프로그램☆★\n\n\n");
	printf("\n\n몇 변수 부울 대수식인지 입력하세요(2,3변수까지 가능합니다):");
	scanf("%d", &value);


	if (value == 2)  //2변수 식일 때
	{
		printf("\n간소화하고자 하는 식을 입력하세요(2변수)(최대 100항)\n\n");
		printf("X,Y에 관한 식으로 입력해야 합니다:\n");
		scanf("%s", formular);
		strcpy(copy_formular, formular);
		token = strtok(formular, seps);//토큰을 이용하여 항을 나눈다.
		while (token != NULL)
		{
			sep_fm[a] = token;
			a++;
			token_stack++;//token_stack = 항의 개수
			token = strtok(NULL, seps);
		}
		for (i = 0; i < token_stack; i++) // 2변수식 데이터베이스
		{
			if (sep_fm[i][0] == 'X' && sep_fm[i][1] == 'Y')
			{
				kr[i][4] = 1;
			}
			if (sep_fm[i][0] == 'X' && sep_fm[i][1] == 0)
			{
				kr[i][2] = 1;
				kr[i][4] = 1;
			}
			if (sep_fm[i][0] == 'Y' && sep_fm[i][1] == 0)
			{
				kr[i][3] = 1;
				kr[i][4] = 1;
			}
			if (sep_fm[i][0] == 'X' && sep_fm[i][1] == 'Y' && sep_fm[i][2] == '`')
			{
				kr[i][2] = 1;
			}
			if (sep_fm[i][0] == 'X' && sep_fm[i][1] == '`' && sep_fm[i][2] == 'Y')
			{
				kr[i][3] = 1;
			}
			if (sep_fm[i][0] == 'X' && sep_fm[i][1] == '`' && sep_fm[i][2] == 'Y' && sep_fm[i][3] == '`')
			{
				kr[i][1] = 1;
			}
			if (sep_fm[i][0] == 'X' && sep_fm[i][1] == '`' && sep_fm[i][2] == 0)
			{
				kr[i][1] = 1;
				kr[i][3] = 1;
			}
			if (sep_fm[i][0] == 'Y' && sep_fm[i][1] == '`' && sep_fm[i][2] == 0)
			{
				kr[i][1] = 1;
				kr[i][2] = 1;
			}
		} // 2변수식 데이터베이스 입력 완료
		for (i = 0; i < token_stack; i++)
		{
			map[1] += kr[i][1];
			map[2] += kr[i][2];
			map[3] += kr[i][3];
			map[4] += kr[i][4];
		} // 각 항의 값을 더한다
		for (i = 1; i < 5; i++)
		{
			if (map[i] > 1)
				map[i] = 1;
		}
		system("cls");
		printf("\n\n\n\n\n\n\n\t\t간 소 화 중 . . . ");
		Sleep(2000);//windows.h가 선언되있어야 함
		system("cls");
		printf("\n\n\t\t□■□■Karnaugh Map□■□■\n");
		printf("\t\t  F= %s\n", copy_formular);
		printf("\t\t┏━━━━━━━━━━━┓\n");
		printf("\t\t┃   X ┃  0    ┃  1   ┃\n");
		printf("\t\t┃Y    ┃       ┃      ┃\n");
		printf("\t\t┃━━━━━━━━━━━┃\n");
		printf("\t\t┃0    ┃  %d    ┃  %d   ┃\n", map[1], map[2]);
		printf("\t\t┃━━━━━━━━━━━┃\n");
		printf("\t\t┃1    ┃  %d    ┃  %d   ┃\n", map[3], map[4]);
		printf("\t\t┗━━━━━━━━━━━┛\n\n");

		if (map[1] == 1) // 묶는 경우의수
		{
			if (map[2] == 1)
			{
				if (map[3] == 0 && map[4] == 0)
					last_formular[0] = "Y`";
				if (map[3] == 1 && map[4] == 0)
					last_formular[0] = "X`+Y`";
				if (map[3] == 0 && map[4] == 1)
					last_formular[0] = "X+Y`";
				if (map[3] == 1 && map[4] == 1)
					last_formular[0] = "1";
			}
			if (map[2] == 0)
			{
				if (map[3] == 0 && map[4] == 0)
					last_formular[0] = "X`Y`";
				if (map[3] == 1 && map[4] == 0)
					last_formular[0] = "X`";
				if (map[3] == 0 && map[4] == 1)
					last_formular[0] = "X`Y`+XY";
				if (map[3] == 1 && map[4] == 1)
					last_formular[0] = "X`+Y";
			}

		}
		if (map[1] == 0)
		{
			if (map[2] == 1)
			{
				if (map[3] == 0 && map[4] == 0)
					last_formular[0] = "XY`";
				if (map[3] == 1 && map[4] == 0)
					last_formular[0] = "XY`+X`Y";
				if (map[3] == 0 && map[4] == 1)
					last_formular[0] = "X";
				if (map[3] == 1 && map[4] == 1)
					last_formular[0] = "X+Y";
			}
			if (map[2] == 0)
			{
				if (map[3] == 0 && map[4] == 0)
					last_formular[0] = "0";
				if (map[3] == 1 && map[4] == 0)
					last_formular[0] = "X`Y";
				if (map[3] == 0 && map[4] == 1)
					last_formular[0] = "XY";
				if (map[3] == 1 && map[4] == 1)
					last_formular[0] = "Y";
			}
		}
			printf("\t\t  F=%sㅡ>간소화 결과ㅡ>F=%s입니다.\n\n", copy_formular, last_formular[0]);
			system("pause");
	}
	if (value == 3)
	{
		printf("\n간소화하고자 하는 식을 입력하세요(최대 100항)\n\n");
		printf("X,Y,Z에 관한 식으로 입력해야 합니다:\n");
		scanf("%s", formular);
		strcpy(copy_formular, formular);
		token = strtok(formular, seps);
		while (token != NULL)
		{
			sep_fm[a] = token;
			a++;
			token_stack++;//token_stack = 항의 개수
			token = strtok(NULL, seps);
		}
		
		for (i = 0; i < token_stack; i++) // 3변수식 데이터베이스
		{
			if (sep_fm[i][0] == 'X'&&sep_fm[i][1] == 0) //X
			{
				kr[i][3] = 1;
				kr[i][4] = 1;
				kr[i][7] = 1;
				kr[i][8] = 1;
			}
			if (sep_fm[i][0] == 'X'&&sep_fm[i][1] == 'Y'&&sep_fm[i][2] == 0) //XY
			{
				kr[i][3] = 1;
				kr[i][7] = 1;
			}
			if (sep_fm[i][0] == 'X'&&sep_fm[i][1] == 'Y'&&sep_fm[i][2] == '`'&&sep_fm[i][3] == 0)//XY`
			{
				kr[i][4] = 1;
				kr[i][8] = 1;
			}
			if (sep_fm[i][0] == 'X'&&sep_fm[i][1] == 'Y'&&sep_fm[i][2] == 'Z'&&sep_fm[i][3] == 0)//XYZ
			{
				kr[i][7] = 1;
			}
			if (sep_fm[i][0] == 'X'&&sep_fm[i][1] == 'Y'&&sep_fm[i][2] == 'Z'&&sep_fm[i][3] == '`')//XYZ`	
			{
				kr[i][3] = 1;
			}
			if (sep_fm[i][0] == 'X'&&sep_fm[i][1] == 'Y'&&sep_fm[i][2] == '`'&&sep_fm[i][3] == 'Z'&&sep_fm[i][4] == 0)//XY`Z
			{
				kr[i][8] = 1;
			}
			if (sep_fm[i][0] == 'X'&&sep_fm[i][1] == 'Y'&&sep_fm[i][2] == '`'&&sep_fm[i][3] == 'Z' &&sep_fm[i][4] == '`')//XY`Z`
			{
				kr[i][4] = 1;
			}
			if (sep_fm[i][0] == 'X'&&sep_fm[i][1] == 'Z'&&sep_fm[i][2] == 0)//XZ
			{
				kr[i][7] = 1;
				kr[i][8] = 1;
			}
			if (sep_fm[i][0] == 'X'&&sep_fm[i][1] == 'Z'&&sep_fm[i][2] == '`'&&sep_fm[i][3] == 0)//XZ`
			{
				kr[i][3] = 1;
				kr[i][4] = 1;
			}
			if (sep_fm[i][0] == 'X'&&sep_fm[i][1] == '`'&&sep_fm[i][2] == 'Z'&&sep_fm[i][3] == '`'&&sep_fm[i][4] == 0)//X`Z`
			{
				kr[i][1] = 1;
				kr[i][2] = 1;
			}
			if (sep_fm[i][0] == 'X'&&sep_fm[i][1] == '`'&&sep_fm[i][2] == 'Z'&&sep_fm[i][3] == 0)//X`Z
			{
				kr[i][5] = 1;
				kr[i][6] = 1;
			}
			if (sep_fm[i][0] == 'X'&&sep_fm[i][1] == '`'&&sep_fm[i][2] == 0)//X`
			{
				kr[i][1] = 1;
				kr[i][2] = 1;
				kr[i][5] = 1;
				kr[i][6] = 1;
			}
			if (sep_fm[i][0] == 'X'&&sep_fm[i][1] == '`'&&sep_fm[i][2] == 'Y'&&sep_fm[i][3] == 0)//X`Y
			{
				kr[i][2] = 1;
				kr[i][6] = 1;
			}
			if (sep_fm[i][0] == 'X' && sep_fm[i][1] == '`' && sep_fm[i][2] == 'Y' &&sep_fm[i][3] == '`'&&sep_fm[i][4] == 0)//X`Y`
			{
				kr[i][1] = 1;
				kr[i][5] = 1;
			}
			if (sep_fm[i][0] == 'X'&&sep_fm[i][1] == '`'&&sep_fm[i][2] == 'Y'&&sep_fm[i][3] == 'Z'&&sep_fm[i][4] == 0)//X`YZ
				kr[i][6] = 1;
			if (sep_fm[i][0] == 'X'&&sep_fm[i][1] == '`'&&sep_fm[i][2] == 'Y'&&sep_fm[i][3] == 'Z'&&sep_fm[i][4] == '`')//X`YZ`
				kr[i][2] = 1;
			if (sep_fm[i][0] == 'X'&&sep_fm[i][1] == '`'&&sep_fm[i][2] == 'Y'&&sep_fm[i][3] == '`'&&sep_fm[i][4] == 'Z'&&sep_fm[i][5] == 0)//X`Y`Z
				kr[i][5] = 1;
			if (sep_fm[i][0] == 'X'&&sep_fm[i][1] == '`'&&sep_fm[i][2] == 'Y'&&sep_fm[i][3] == '`'&&sep_fm[i][4] == 'Z'&&sep_fm[i][5] == '`')//X`Y`Z`
				kr[i][1] = 1;
			if (sep_fm[i][0] == 'Y'&&sep_fm[i][1] == 0)//Y
			{
				kr[i][2] = 1;
				kr[i][3] = 1;
				kr[i][6] = 1;
				kr[i][7] = 1;
			}
			if (sep_fm[i][0] == 'Z'&&sep_fm[i][1] == '`'&&sep_fm[i][2] == 0)//Z`
			{
				kr[i][1] = 1;
				kr[i][2] = 1;
				kr[i][3] = 1;
				kr[i][4] = 1;
			}
			if (sep_fm[i][0] == 'Z'&&sep_fm[i][1] == 0)//Z
			{
				kr[i][5] = 1;
				kr[i][6] = 1;
				kr[i][7] = 1;
				kr[i][8] = 1;
			}
			if (sep_fm[i][0] == 'Y'&&sep_fm[i][1] == '`'&&sep_fm[i][2] == 0)//Y`
			{
				kr[i][1] = 1;
				kr[i][4] = 1;
				kr[i][5] = 1;
				kr[i][8] = 1;
			}
			if (sep_fm[i][0] == 'Y'&&sep_fm[i][1] == '`'&&sep_fm[i][2] == 'Z' &&sep_fm[i][3] == 0)//Y`Z
			{
				kr[i][5] = 1;
				kr[i][8] = 1;
			}
			if (sep_fm[i][0] == 'Y'&&sep_fm[i][1] == '`'&&sep_fm[i][2] == 'Z' &&sep_fm[i][3] == '`')//Y`Z`
			{
				kr[i][1] = 1;
				kr[i][4] = 1;
			}
			if (sep_fm[i][0] == 'Y'&&sep_fm[i][1] == 'Z'&&sep_fm[i][2] == '`' &&sep_fm[i][3] == 0)//YZ`
			{
				kr[i][2] = 1;
				kr[i][3] = 1;
			}
			if (sep_fm[i][0] == 'Y'&&sep_fm[i][1] == 'Z'&&sep_fm[i][2] == 0)//YZ
			{
				kr[i][6] = 1;
				kr[i][7] = 1;
			}
		}// 3변수식 데이터베이스 입력 완료
		for (i = 0; i < token_stack; i++)
		{
			map[1] += kr[i][1];
			map[2] += kr[i][2];
			map[3] += kr[i][3];
			map[4] += kr[i][4];
			map[5] += kr[i][5];
			map[6] += kr[i][6];
			map[7] += kr[i][7];
			map[8] += kr[i][8];
		} // 각 항의 값을 더한다
		for (i = 1; i < 9; i++)
		{
			if (map[i] > 1)
				map[i] = 1;
		}
		system("cls");
		printf("\n\n\n\n\n\n\n\t\t간 소 화 중 . . . ");
		Sleep(2000);
		system("cls");
		printf("\t\t\t□■□■Karnaugh Map□■□■\n");
		printf("\n\n\t\t  F= %s\n", copy_formular);
		printf("\t\t┏━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t\t┃   XY┃  00   ┃  01  ┃  11  ┃  10  ┃\n");
		printf("\t\t┃Z    ┃       ┃      ┃      ┃      ┃\n");
		printf("\t\t┃━━━━━━━━━━━━━━━━━━━┃\n");
		printf("\t\t┃0    ┃  %d    ┃  %d   ┃  %d   ┃  %d   ┃\n", map[1], map[2], map[3], map[4]);
		printf("\t\t┃━━━━━━━━━━━━━━━━━━━┃\n");
		printf("\t\t┃1    ┃  %d    ┃  %d   ┃  %d   ┃  %d   ┃\n", map[5], map[6], map[7], map[8]);
		printf("\t\t┗━━━━━━━━━━━━━━━━━━━┛\n\n");

		if (map[1] == 0 && map[2] == 0 && map[3] == 0 && map[4] == 0 && map[5] == 0 && map[6] == 0 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "0";
		if (map[1] == 1 && map[2] == 0 && map[3] == 0 && map[4] == 0 && map[5] == 0 && map[6] == 0 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "X`Y`Z`";
		if (map[1] == 0 && map[2] == 1 && map[3] == 0 && map[4] == 0 && map[5] == 0 && map[6] == 0 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "X`YZ`";
		if (map[1] == 0 && map[2] == 0 && map[3] == 1 && map[4] == 0 && map[5] == 0 && map[6] == 0 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "XYZ`";
		if (map[1] == 0 && map[2] == 0 && map[3] == 0 && map[4] == 1 && map[5] == 0 && map[6] == 0 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "XY`Z";
		if (map[1] == 0 && map[2] == 0 && map[3] == 0 && map[4] == 0 && map[5] == 1 && map[6] == 0 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "X`Y`Z";
		if (map[1] == 0 && map[2] == 0 && map[3] == 0 && map[4] == 0 && map[5] == 0 && map[6] == 1 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "X`YZ";
		if (map[1] == 0 && map[2] == 0 && map[3] == 0 && map[4] == 0 && map[5] == 0 && map[6] == 0 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "XYZ";
		if (map[1] == 0 && map[2] == 0 && map[3] == 0 && map[4] == 0 && map[5] == 0 && map[6] == 0 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "XY`Z";//1개만 1일때
									  //2개가 1일때
		if (map[1] == 1 && map[2] == 1 && map[3] == 0 && map[4] == 0 && map[5] == 0 && map[6] == 0 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "X`Z`";
		if (map[1] == 1 && map[2] == 0 && map[3] == 1 && map[4] == 0 && map[5] == 0 && map[6] == 0 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "X`Y`Z`+XYZ`";
		if (map[1] == 1 && map[2] == 0 && map[3] == 0 && map[4] == 1 && map[5] == 0 && map[6] == 0 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "Y`Z`";
		if (map[1] == 1 && map[2] == 0 && map[3] == 0 && map[4] == 0 && map[5] == 1 && map[6] == 0 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "X`Y`";
		if (map[1] == 1 && map[2] == 0 && map[3] == 0 && map[4] == 0 && map[5] == 0 && map[6] == 1 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "X`Y`Z`+X`YZ";
		if (map[1] == 1 && map[2] == 0 && map[3] == 0 && map[4] == 0 && map[5] == 0 && map[6] == 0 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "X`Y`Z`+XYZ";
		if (map[1] == 1 && map[2] == 0 && map[3] == 0 && map[4] == 0 && map[5] == 0 && map[6] == 0 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "X`Y`Z`+XY`Z";
		if (map[1] == 0 && map[2] == 1 && map[3] == 1 && map[4] == 0 && map[5] == 0 && map[6] == 0 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "YZ`";
		if (map[1] == 0 && map[2] == 1 && map[3] == 0 && map[4] == 1 && map[5] == 0 && map[6] == 0 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "X`YZ`+XY`Z`";
		if (map[1] == 0 && map[2] == 1 && map[3] == 0 && map[4] == 0 && map[5] == 1 && map[6] == 0 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "X`YZ`+X`Y`Z";
		if (map[1] == 0 && map[2] == 1 && map[3] == 0 && map[4] == 0 && map[5] == 0 && map[6] == 1 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "X`Y";
		if (map[1] == 0 && map[2] == 1 && map[3] == 0 && map[4] == 0 && map[5] == 0 && map[6] == 0 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "X`YZ`+XYZ";
		if (map[1] == 0 && map[2] == 1 && map[3] == 0 && map[4] == 0 && map[5] == 0 && map[6] == 0 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "X`YZ`+XY`Z";
		if (map[1] == 0 && map[2] == 0 && map[3] == 1 && map[4] == 1 && map[5] == 0 && map[6] == 0 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "XZ`";
		if (map[1] == 0 && map[2] == 0 && map[3] == 1 && map[4] == 0 && map[5] == 1 && map[6] == 0 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "XYZ`+X`Y`Z";
		if (map[1] == 0 && map[2] == 0 && map[3] == 1 && map[4] == 0 && map[5] == 0 && map[6] == 1 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "XYZ`+X`YZ";
		if (map[1] == 0 && map[2] == 0 && map[3] == 1 && map[4] == 0 && map[5] == 0 && map[6] == 0 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "XY";
		if (map[1] == 0 && map[2] == 0 && map[3] == 1 && map[4] == 0 && map[5] == 0 && map[6] == 0 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "XYZ`+XY`Z";
		if (map[1] == 0 && map[2] == 0 && map[3] == 0 && map[4] == 1 && map[5] == 1 && map[6] == 0 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "XY`Z+X`Y`Z";
		if (map[1] == 0 && map[2] == 0 && map[3] == 0 && map[4] == 1 && map[5] == 0 && map[6] == 1 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "XY`Z+X`YZ";
		if (map[1] == 0 && map[2] == 0 && map[3] == 0 && map[4] == 1 && map[5] == 0 && map[6] == 0 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "XY`Z+XYZ";
		if (map[1] == 0 && map[2] == 0 && map[3] == 0 && map[4] == 1 && map[5] == 0 && map[6] == 0 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "XY`";
		if (map[1] == 0 && map[2] == 0 && map[3] == 0 && map[4] == 0 && map[5] == 1 && map[6] == 1 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "X`Z";
		if (map[1] == 0 && map[2] == 0 && map[3] == 0 && map[4] == 0 && map[5] == 1 && map[6] == 0 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "X`Y`Z+XYZ";
		if (map[1] == 0 && map[2] == 0 && map[3] == 0 && map[4] == 0 && map[5] == 1 && map[6] == 0 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "Y`Z";
		if (map[1] == 0 && map[2] == 0 && map[3] == 0 && map[4] == 0 && map[5] == 0 && map[6] == 1 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "YZ";
		if (map[1] == 0 && map[2] == 0 && map[3] == 0 && map[4] == 0 && map[5] == 0 && map[6] == 1 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "X`YZ+XY`Z";
		if (map[1] == 0 && map[2] == 0 && map[3] == 0 && map[4] == 0 && map[5] == 0 && map[6] == 0 && map[7] == 1 && map[8] == 1)
			last_formular[0] = "XZ";//1이 2개일 경우
		if (map[1] == 1 && map[2] == 1 && map[3] == 1 && map[4] == 0 && map[5] == 0 && map[6] == 0 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "X`Z`+XYZ`";
		if (map[1] == 1 && map[2] == 1 && map[3] == 0 && map[4] == 1 && map[5] == 0 && map[6] == 0 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "X`Z`+XY`Z`";
		if (map[1] == 1 && map[2] == 1 && map[3] == 0 && map[4] == 0 && map[5] == 1 && map[6] == 0 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "X`Y`+X`Z`";
		if (map[1] == 1 && map[2] == 1 && map[3] == 0 && map[4] == 0 && map[5] == 0 && map[6] == 1 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "X`Z`+X`YZ";
		if (map[1] == 1 && map[2] == 1 && map[3] == 0 && map[4] == 0 && map[5] == 0 && map[6] == 0 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "X`Z`+XYZ";
		if (map[1] == 1 && map[2] == 1 && map[3] == 0 && map[4] == 0 && map[5] == 0 && map[6] == 0 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "X`Z`+XY`Z";
		if (map[1] == 1 && map[2] == 0 && map[3] == 1 && map[4] == 1 && map[5] == 0 && map[6] == 0 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "XZ`+X`Y`Z`";
		if (map[1] == 1 && map[2] == 0 && map[3] == 1 && map[4] == 0 && map[5] == 1 && map[6] == 0 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "X`Y`+XYZ`";
		if (map[1] == 1 && map[2] == 0 && map[3] == 1 && map[4] == 0 && map[5] == 0 && map[6] == 1 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "X`Y`Z`+XYZ`+X`YZ";
		if (map[1] == 1 && map[2] == 0 && map[3] == 1 && map[4] == 0 && map[5] == 0 && map[6] == 0 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "XY+X`Y`Z`";
		if (map[1] == 1 && map[2] == 0 && map[3] == 1 && map[4] == 0 && map[5] == 0 && map[6] == 0 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "X`Y`Z`+XYZ`+XY`Z";
		if (map[1] == 1 && map[2] == 0 && map[3] == 0 && map[4] == 1 && map[5] == 1 && map[6] == 0 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "XY`Z`+X`Y`";
		if (map[1] == 1 && map[2] == 0 && map[3] == 0 && map[4] == 1 && map[5] == 0 && map[6] == 1 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "Y`Z`+X`YZ";
		if (map[1] == 1 && map[2] == 0 && map[3] == 0 && map[4] == 1 && map[5] == 0 && map[6] == 0 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "Y`Z`+XYZ";
		if (map[1] == 1 && map[2] == 0 && map[3] == 0 && map[4] == 1 && map[5] == 0 && map[6] == 0 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "X`Y`Z`+XY`";
		if (map[1] == 1 && map[2] == 0 && map[3] == 0 && map[4] == 0 && map[5] == 1 && map[6] == 1 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "X`Y`+X`Z";
		if (map[1] == 1 && map[2] == 0 && map[3] == 0 && map[4] == 0 && map[5] == 1 && map[6] == 0 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "X`Y`+XYZ";
		if (map[1] == 1 && map[2] == 0 && map[3] == 0 && map[4] == 0 && map[5] == 1 && map[6] == 0 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "X`Y`+XY`Z";
		if (map[1] == 1 && map[2] == 0 && map[3] == 0 && map[4] == 0 && map[5] == 0 && map[6] == 1 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "YZ+X`Y`Z`";
		if (map[1] == 1 && map[2] == 0 && map[3] == 0 && map[4] == 0 && map[5] == 0 && map[6] == 1 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "X`Y`Z`+X`YZ+XY`Z";
		if (map[1] == 1 && map[2] == 0 && map[3] == 0 && map[4] == 0 && map[5] == 0 && map[6] == 0 && map[7] == 1 && map[8] == 1)
			last_formular[0] = "X`Y`Z`+XZ";
		if (map[1] == 0 && map[2] == 1 && map[3] == 1 && map[4] == 1 && map[5] == 0 && map[6] == 0 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "YZ`+XY`Z`";
		if (map[1] == 0 && map[2] == 1 && map[3] == 1 && map[4] == 0 && map[5] == 1 && map[6] == 0 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "YZ`+X`Y`Z";
		if (map[1] == 0 && map[2] == 1 && map[3] == 1 && map[4] == 0 && map[5] == 0 && map[6] == 1 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "X`Y+YZ`";
		if (map[1] == 0 && map[2] == 1 && map[3] == 1 && map[4] == 0 && map[5] == 0 && map[6] == 0 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "XY+YZ`";
		if (map[1] == 0 && map[2] == 1 && map[3] == 1 && map[4] == 0 && map[5] == 0 && map[6] == 0 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "YZ`+XY`Z";
		if (map[1] == 0 && map[2] == 1 && map[3] == 0 && map[4] == 1 && map[5] == 1 && map[6] == 0 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "X`YZ`+XY`Z`+X`Y`Z";
		if (map[1] == 0 && map[2] == 1 && map[3] == 0 && map[4] == 1 && map[5] == 0 && map[6] == 1 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "X`Y+XY`Z`";
		if (map[1] == 0 && map[2] == 1 && map[3] == 0 && map[4] == 1 && map[5] == 0 && map[6] == 0 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "X`YZ`+XY`Z`+XYZ";
		if (map[1] == 0 && map[2] == 1 && map[3] == 0 && map[4] == 1 && map[5] == 0 && map[6] == 0 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "XY`+X`YZ`";
		if (map[1] == 0 && map[2] == 1 && map[3] == 0 && map[4] == 0 && map[5] == 1 && map[6] == 1 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "X`Y+X`Z";
		if (map[1] == 0 && map[2] == 1 && map[3] == 0 && map[4] == 0 && map[5] == 1 && map[6] == 0 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "X`YZ`+X`Y`Z+XYZ";
		if (map[1] == 0 && map[2] == 1 && map[3] == 0 && map[4] == 0 && map[5] == 1 && map[6] == 0 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "Y`Z+X`YZ`";
		if (map[1] == 0 && map[2] == 1 && map[3] == 0 && map[4] == 0 && map[5] == 0 && map[6] == 1 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "X`Y+YZ";
		if (map[1] == 0 && map[2] == 1 && map[3] == 0 && map[4] == 0 && map[5] == 0 && map[6] == 1 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "X`Y+XY`Z";
		if (map[1] == 0 && map[2] == 1 && map[3] == 0 && map[4] == 0 && map[5] == 0 && map[6] == 0 && map[7] == 1 && map[8] == 1)
			last_formular[0] = "X`YZ`+XZ";
		if (map[1] == 0 && map[2] == 0 && map[3] == 1 && map[4] == 1 && map[5] == 1 && map[6] == 0 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "XZ`+X`Y`Z";
		if (map[1] == 0 && map[2] == 0 && map[3] == 1 && map[4] == 1 && map[5] == 0 && map[6] == 1 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "XZ`+X`YZ";
		if (map[1] == 0 && map[2] == 0 && map[3] == 1 && map[4] == 1 && map[5] == 0 && map[6] == 0 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "XZ`+XY";
		if (map[1] == 0 && map[2] == 0 && map[3] == 1 && map[4] == 1 && map[5] == 0 && map[6] == 0 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "XZ`+XY`";
		if (map[1] == 0 && map[2] == 0 && map[3] == 1 && map[4] == 0 && map[5] == 1 && map[6] == 1 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "X`Z+XYZ`";
		if (map[1] == 0 && map[2] == 0 && map[3] == 1 && map[4] == 0 && map[5] == 1 && map[6] == 0 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "XY+X`Y`Z";
		if (map[1] == 0 && map[2] == 0 && map[3] == 1 && map[4] == 0 && map[5] == 1 && map[6] == 0 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "XYZ`+Y`Z";
		if (map[1] == 0 && map[2] == 0 && map[3] == 1 && map[4] == 0 && map[5] == 0 && map[6] == 1 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "XY+YZ";
		if (map[1] == 0 && map[2] == 0 && map[3] == 1 && map[4] == 0 && map[5] == 0 && map[6] == 1 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "XYZ`+X`YZ+XY`Z";
		if (map[1] == 0 && map[2] == 0 && map[3] == 1 && map[4] == 0 && map[5] == 0 && map[6] == 0 && map[7] == 1 && map[8] == 1)
			last_formular[0] = "XY+XZ";
		if (map[1] == 0 && map[2] == 0 && map[3] == 0 && map[4] == 1 && map[5] == 1 && map[6] == 1 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "XY`Z`+X`Z";
		if (map[1] == 0 && map[2] == 0 && map[3] == 0 && map[4] == 1 && map[5] == 1 && map[6] == 0 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "XY`Z`+X`Y`Z+XYZ";
		if (map[1] == 0 && map[2] == 0 && map[3] == 0 && map[4] == 1 && map[5] == 1 && map[6] == 0 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "XY`+Y`Z";
		if (map[1] == 0 && map[2] == 0 && map[3] == 0 && map[4] == 1 && map[5] == 0 && map[6] == 1 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "XY`Z`+YZ";
		if (map[1] == 0 && map[2] == 0 && map[3] == 0 && map[4] == 1 && map[5] == 0 && map[6] == 1 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "XY`+X`YZ";
		if (map[1] == 0 && map[2] == 0 && map[3] == 0 && map[4] == 1 && map[5] == 0 && map[6] == 0 && map[7] == 1 && map[8] == 1)
			last_formular[0] = "XZ+XY`";
		if (map[1] == 0 && map[2] == 0 && map[3] == 0 && map[4] == 0 && map[5] == 1 && map[6] == 1 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "X`Z+YZ";
		if (map[1] == 0 && map[2] == 0 && map[3] == 0 && map[4] == 0 && map[5] == 1 && map[6] == 1 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "X`Z+Y`Z";
		if (map[1] == 0 && map[2] == 0 && map[3] == 0 && map[4] == 0 && map[5] == 1 && map[6] == 0 && map[7] == 1 && map[8] == 1)
			last_formular[0] = "XZ+Y`Z";
		if (map[1] == 0 && map[2] == 0 && map[3] == 0 && map[4] == 0 && map[5] == 0 && map[6] == 1 && map[7] == 1 && map[8] == 1)
			last_formular[0] = "XZ+YZ";//3개 끝
		if (map[1] == 1 && map[2] == 1 && map[3] == 1 && map[4] == 1 && map[5] == 0 && map[6] == 0 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "Z`";
		if (map[1] == 1 && map[2] == 1 && map[3] == 1 && map[4] == 0 && map[5] == 1 && map[6] == 0 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "X`Y`+YZ`";
		if (map[1] == 1 && map[2] == 1 && map[3] == 1 && map[4] == 0 && map[5] == 0 && map[6] == 1 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "X`Y+X`Z`+YZ`";
		if (map[1] == 1 && map[2] == 1 && map[3] == 1 && map[4] == 0 && map[5] == 0 && map[6] == 0 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "X`Z`+XY";
		if (map[1] == 1 && map[2] == 1 && map[3] == 1 && map[4] == 0 && map[5] == 0 && map[6] == 0 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "X`Z`+YZ`+XY`Z";
		if (map[1] == 1 && map[2] == 1 && map[3] == 0 && map[4] == 1 && map[5] == 1 && map[6] == 0 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "X`Y`+X`Z`+Y`Z`";
		if (map[1] == 1 && map[2] == 1 && map[3] == 0 && map[4] == 1 && map[5] == 0 && map[6] == 1 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "X`Y+Y`Z`";
		if (map[1] == 1 && map[2] == 1 && map[3] == 0 && map[4] == 1 && map[5] == 0 && map[6] == 0 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "XYZ+X`Z`+Y`Z`";
		if (map[1] == 1 && map[2] == 1 && map[3] == 0 && map[4] == 1 && map[5] == 0 && map[6] == 0 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "X`Z`+XY`";
		if (map[1] == 1 && map[2] == 1 && map[3] == 0 && map[4] == 0 && map[5] == 1 && map[6] == 1 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "X`";
		if (map[1] == 1 && map[2] == 1 && map[3] == 0 && map[4] == 0 && map[5] == 1 && map[6] == 0 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "X`Y`+X`Z`+XYZ";
		if (map[1] == 1 && map[2] == 1 && map[3] == 0 && map[4] == 0 && map[5] == 1 && map[6] == 0 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "X`Z`+Y`Z";
		if (map[1] == 1 && map[2] == 1 && map[3] == 0 && map[4] == 0 && map[5] == 0 && map[6] == 1 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "X`Z`+YZ";
		if (map[1] == 1 && map[2] == 1 && map[3] == 0 && map[4] == 0 && map[5] == 0 && map[6] == 1 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "X`Z`+X`Y+XY`Z";
		if (map[1] == 1 && map[2] == 1 && map[3] == 0 && map[4] == 0 && map[5] == 0 && map[6] == 0 && map[7] == 1 && map[8] == 1)
			last_formular[0] = "X`Z`+XZ";
		if (map[1] == 1 && map[2] == 0 && map[3] == 1 && map[4] == 1 && map[5] == 1 && map[6] == 0 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "X`Y`+XZ`";
		if (map[1] == 1 && map[2] == 0 && map[3] == 1 && map[4] == 1 && map[5] == 0 && map[6] == 1 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "XZ`+Y`Z`+X`YZ";
		if (map[1] == 1 && map[2] == 0 && map[3] == 1 && map[4] == 1 && map[5] == 0 && map[6] == 0 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "XY+Y`Z`";
		if (map[1] == 1 && map[2] == 0 && map[3] == 1 && map[4] == 1 && map[5] == 0 && map[6] == 0 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "XY`+XZ`+Y`Z`";
		if (map[1] == 1 && map[2] == 0 && map[3] == 1 && map[4] == 0 && map[5] == 1 && map[6] == 1 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "X`Y`+X`Z+XYZ`";
		if (map[1] == 1 && map[2] == 0 && map[3] == 1 && map[4] == 0 && map[5] == 1 && map[6] == 0 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "X`Y`+XY";
		if (map[1] == 1 && map[2] == 0 && map[3] == 1 && map[4] == 0 && map[5] == 1 && map[6] == 0 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "X`Y`+Y`Z+XYZ`";
		if (map[1] == 1 && map[2] == 0 && map[3] == 1 && map[4] == 0 && map[5] == 0 && map[6] == 1 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "XY+YZ+X`Y`Z`";
		if (map[1] == 1 && map[2] == 0 && map[3] == 1 && map[4] == 0 && map[5] == 0 && map[6] == 1 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "X`Y`Z`+XYZ`+X`YZ+XY`Z";
		if (map[1] == 1 && map[2] == 0 && map[3] == 1 && map[4] == 0 && map[5] == 0 && map[6] == 0 && map[7] == 1 && map[8] == 1)
			last_formular[0] = "X`Y`Z`+XY+XZ";
		if (map[1] == 1 && map[2] == 0 && map[3] == 0 && map[4] == 1 && map[5] == 1 && map[6] == 1 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "X`Z+Y`Z`";
		if (map[1] == 1 && map[2] == 0 && map[3] == 0 && map[4] == 1 && map[5] == 1 && map[6] == 0 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "X`Y`+Y`Z`+XYZ";
		if (map[1] == 1 && map[2] == 0 && map[3] == 0 && map[4] == 1 && map[5] == 1 && map[6] == 0 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "X`Y`+XY`";
		if (map[1] == 1 && map[2] == 0 && map[3] == 0 && map[4] == 1 && map[5] == 0 && map[6] == 1 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "Y`Z`+YZ";
		if (map[1] == 1 && map[2] == 0 && map[3] == 0 && map[4] == 1 && map[5] == 0 && map[6] == 1 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "XYZ+XY`+Y`Z`";
		if (map[1] == 1 && map[2] == 0 && map[3] == 0 && map[4] == 1 && map[5] == 0 && map[6] == 0 && map[7] == 1 && map[8] == 1)
			last_formular[0] = "Y`Z`+XZ";
		if (map[1] == 1 && map[2] == 0 && map[3] == 0 && map[4] == 0 && map[5] == 1 && map[6] == 1 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "X`Y`+YZ";
		if (map[1] == 1 && map[2] == 0 && map[3] == 0 && map[4] == 0 && map[5] == 1 && map[6] == 1 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "X`Y`+X`Z+Y`Z";
		if (map[1] == 1 && map[2] == 0 && map[3] == 0 && map[4] == 0 && map[5] == 1 && map[6] == 0 && map[7] == 1 && map[8] == 1)
			last_formular[0] = "X`Y`+XZ";
		if (map[1] == 1 && map[2] == 0 && map[3] == 0 && map[4] == 0 && map[5] == 0 && map[6] == 1 && map[7] == 1 && map[8] == 1)
			last_formular[0] = "X`Y`Z`+YZ+XZ";
		if (map[1] == 0 && map[2] == 1 && map[3] == 1 && map[4] == 1 && map[5] == 1 && map[6] == 0 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "YZ`+XZ`+X`Y`Z";
		if (map[1] == 0 && map[2] == 1 && map[3] == 1 && map[4] == 1 && map[5] == 0 && map[6] == 1 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "XZ`+X`Y";
		if (map[1] == 0 && map[2] == 1 && map[3] == 1 && map[4] == 1 && map[5] == 0 && map[6] == 0 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "XZ`+YZ`+XY";
		if (map[1] == 0 && map[2] == 1 && map[3] == 1 && map[4] == 1 && map[5] == 0 && map[6] == 0 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "YZ`+XY`";
		if (map[1] == 0 && map[2] == 1 && map[3] == 1 && map[4] == 0 && map[5] == 1 && map[6] == 1 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "YZ`+X`Z";
		if (map[1] == 0 && map[2] == 1 && map[3] == 1 && map[4] == 0 && map[5] == 1 && map[6] == 0 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "YZ`+XY+X`Y`Z";
		if (map[1] == 0 && map[2] == 1 && map[3] == 1 && map[4] == 0 && map[5] == 1 && map[6] == 0 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "YZ`+Y`Z";
		if (map[1] == 0 && map[2] == 1 && map[3] == 1 && map[4] == 0 && map[5] == 0 && map[6] == 1 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "Y";
		if (map[1] == 0 && map[2] == 1 && map[3] == 1 && map[4] == 0 && map[5] == 0 && map[6] == 1 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "X`Y+YZ`+XY`Z";
		if (map[1] == 0 && map[2] == 1 && map[3] == 1 && map[4] == 0 && map[5] == 0 && map[6] == 0 && map[7] == 1 && map[8] == 1)
			last_formular[0] = "YZ`+XZ";
		if (map[1] == 0 && map[2] == 1 && map[3] == 0 && map[4] == 1 && map[5] == 1 && map[6] == 1 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "X`Y+X`Z+XY`Z`";
		if (map[1] == 0 && map[2] == 1 && map[3] == 0 && map[4] == 1 && map[5] == 1 && map[6] == 0 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "X`YZ`+XY`Z`+X`Y`Z+XYZ";
		if (map[1] == 0 && map[2] == 1 && map[3] == 0 && map[4] == 1 && map[5] == 1 && map[6] == 0 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "XY`+Y`Z+X`YZ`";
		if (map[1] == 0 && map[2] == 1 && map[3] == 0 && map[4] == 1 && map[5] == 0 && map[6] == 1 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "X`Y+YZ+XY`Z`";
		if (map[1] == 0 && map[2] == 1 && map[3] == 0 && map[4] == 1 && map[5] == 0 && map[6] == 1 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "X`Y+XY`";
		if (map[1] == 0 && map[2] == 1 && map[3] == 0 && map[4] == 1 && map[5] == 0 && map[6] == 0 && map[7] == 1 && map[8] == 1)
			last_formular[0] = "XY`+XZ+X`YZ`";
		if (map[1] == 0 && map[2] == 1 && map[3] == 0 && map[4] == 0 && map[5] == 1 && map[6] == 1 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "X`Y+X`Z+YZ";
		if (map[1] == 0 && map[2] == 1 && map[3] == 0 && map[4] == 0 && map[5] == 1 && map[6] == 1 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "X`Y+Y`Z";
		if (map[1] == 0 && map[2] == 1 && map[3] == 0 && map[4] == 0 && map[5] == 1 && map[6] == 0 && map[7] == 1 && map[8] == 1)
			last_formular[0] = "XZ+X`YZ`+X`Y`Z";
		if (map[1] == 0 && map[2] == 1 && map[3] == 0 && map[4] == 0 && map[5] == 0 && map[6] == 1 && map[7] == 1 && map[8] == 1)
			last_formular[0] = "X`Y+XZ";
		if (map[1] == 0 && map[2] == 0 && map[3] == 1 && map[4] == 1 && map[5] == 1 && map[6] == 1 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "XZ`+X`Z";
		if (map[1] == 0 && map[2] == 0 && map[3] == 1 && map[4] == 1 && map[5] == 1 && map[6] == 0 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "XY+XZ`+X`Y`Z";
		if (map[1] == 0 && map[2] == 0 && map[3] == 1 && map[4] == 1 && map[5] == 1 && map[6] == 0 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "XZ`+Y`Z";
		if (map[1] == 0 && map[2] == 0 && map[3] == 1 && map[4] == 1 && map[5] == 0 && map[6] == 1 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "XZ`+YZ";
		if (map[1] == 0 && map[2] == 0 && map[3] == 1 && map[4] == 1 && map[5] == 0 && map[6] == 1 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "XY`+XZ`+X`YZ";
		if (map[1] == 0 && map[2] == 0 && map[3] == 1 && map[4] == 1 && map[5] == 0 && map[6] == 0 && map[7] == 1 && map[8] == 1)
			last_formular[0] = "X";
		if (map[1] == 0 && map[2] == 0 && map[3] == 0 && map[4] == 1 && map[5] == 1 && map[6] == 1 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "XY`Z`+X`Z+YZ";
		if (map[1] == 0 && map[2] == 0 && map[3] == 0 && map[4] == 1 && map[5] == 1 && map[6] == 1 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "XY`+X`Z";
		if (map[1] == 0 && map[2] == 0 && map[3] == 0 && map[4] == 0 && map[5] == 1 && map[6] == 1 && map[7] == 1 && map[8] == 1)
			last_formular[0] = "Z";//4개인거 완료.
		if (map[1] == 1 && map[2] == 1 && map[3] == 1 && map[4] == 1 && map[5] == 1 && map[6] == 0 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "Z`+X`Y`";
		if (map[1] == 1 && map[2] == 1 && map[3] == 1 && map[4] == 1 && map[5] == 0 && map[6] == 1 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "Z`+X`Y";
		if (map[1] == 1 && map[2] == 1 && map[3] == 1 && map[4] == 1 && map[5] == 0 && map[6] == 0 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "Z`+XY";
		if (map[1] == 1 && map[2] == 1 && map[3] == 1 && map[4] == 1 && map[5] == 0 && map[6] == 0 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "Z`+XY`";
		if (map[1] == 1 && map[2] == 1 && map[3] == 1 && map[4] == 0 && map[5] == 1 && map[6] == 1 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "X`+YZ`";
		if (map[1] == 1 && map[2] == 1 && map[3] == 1 && map[4] == 0 && map[5] == 1 && map[6] == 0 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "XY+X`Z`+X`Y`";
		if (map[1] == 1 && map[2] == 1 && map[3] == 1 && map[4] == 0 && map[5] == 1 && map[6] == 0 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "X`Z`+YZ`+Y`Z";
		if (map[1] == 1 && map[2] == 1 && map[3] == 1 && map[4] == 0 && map[5] == 0 && map[6] == 1 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "Y+X`Z`";
		if (map[1] == 1 && map[2] == 1 && map[3] == 1 && map[4] == 0 && map[5] == 0 && map[6] == 1 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "X`Z`+YZ`+X`Y+XY`Z";
		if (map[1] == 1 && map[2] == 1 && map[3] == 1 && map[4] == 0 && map[5] == 0 && map[6] == 0 && map[7] == 1 && map[8] == 1)
			last_formular[0] = "XY+XZ+Y`Z`";
		if (map[1] == 1 && map[2] == 1 && map[3] == 0 && map[4] == 1 && map[5] == 1 && map[6] == 1 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "X`+Y`Z`";
		if (map[1] == 1 && map[2] == 1 && map[3] == 0 && map[4] == 1 && map[5] == 1 && map[6] == 0 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "X`Y`+X`Z`+Y`Z`+XYZ";
		if (map[1] == 1 && map[2] == 1 && map[3] == 0 && map[4] == 1 && map[5] == 1 && map[6] == 0 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "X`Y`+XY`+X`Z`";
		if (map[1] == 1 && map[2] == 1 && map[3] == 0 && map[4] == 0 && map[5] == 1 && map[6] == 1 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "X`+YZ";
		if (map[1] == 1 && map[2] == 1 && map[3] == 0 && map[4] == 0 && map[5] == 1 && map[6] == 1 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "X`+Y`Z";
		if (map[1] == 1 && map[2] == 1 && map[3] == 0 && map[4] == 0 && map[5] == 1 && map[6] == 0 && map[7] == 1 && map[8] == 1)
			last_formular[0] = "X`Y`+X`Z`+XZ";
		if (map[1] == 1 && map[2] == 1 && map[3] == 0 && map[4] == 0 && map[5] == 0 && map[6] == 1 && map[7] == 1 && map[8] == 1)
			last_formular[0] = "Y`Z`+YZ+XZ";
		if (map[1] == 1 && map[2] == 0 && map[3] == 1 && map[4] == 1 && map[5] == 1 && map[6] == 1 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "X`Y`+X`Z+XZ`";
		if (map[1] == 1 && map[2] == 0 && map[3] == 1 && map[4] == 1 && map[5] == 1 && map[6] == 0 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "X`Y`+XY+XZ`";
		if (map[1] == 1 && map[2] == 0 && map[3] == 1 && map[4] == 1 && map[5] == 1 && map[6] == 0 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "X`Y`+XY`+XZ`";
		if (map[1] == 1 && map[2] == 0 && map[3] == 1 && map[4] == 1 && map[5] == 0 && map[6] == 1 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "YZ+XZ`+Y`Z`";
		if (map[1] == 1 && map[2] == 0 && map[3] == 1 && map[4] == 1 && map[5] == 0 && map[6] == 1 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "XZ`+XY`+Y`Z`+X`YZ";
		if (map[1] == 1 && map[2] == 0 && map[3] == 1 && map[4] == 1 && map[5] == 0 && map[6] == 0 && map[7] == 1 && map[8] == 1)
			last_formular[0] = "X+Y`Z`";
		if (map[1] == 1 && map[2] == 0 && map[3] == 1 && map[4] == 0 && map[5] == 1 && map[6] == 1 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "X`Y`+X`Z+XY";
		if (map[1] == 1 && map[2] == 0 && map[3] == 1 && map[4] == 0 && map[5] == 1 && map[6] == 1 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "X`Y`+X`Z+Y`Z+XYZ`";
		if (map[1] == 1 && map[2] == 0 && map[3] == 1 && map[4] == 0 && map[5] == 0 && map[6] == 1 && map[7] == 1 && map[8] == 1)
			last_formular[0] = "X`Y`Z`+XY+YZ+XZ";
		if (map[1] == 1 && map[2] == 0 && map[3] == 0 && map[4] == 1 && map[5] == 1 && map[6] == 1 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "Y`Z`+X`Z+YZ";
		if (map[1] == 1 && map[2] == 0 && map[3] == 0 && map[4] == 1 && map[5] == 1 && map[6] == 1 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "XY`+X`Y`+X`Z";
		if (map[1] == 1 && map[2] == 0 && map[3] == 0 && map[4] == 0 && map[5] == 1 && map[6] == 1 && map[7] == 1 && map[8] == 1)
			last_formular[0] = "Z+X`Y`";
		if (map[1] == 0 && map[2] == 1 && map[3] == 1 && map[4] == 1 && map[5] == 1 && map[6] == 1 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "XZ`+X`Y+X`Z";
		if (map[1] == 0 && map[2] == 1 && map[3] == 1 && map[4] == 1 && map[5] == 1 && map[6] == 0 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "XY+YZ`+XZ`+X`Y`Z";
		if (map[1] == 0 && map[2] == 1 && map[3] == 1 && map[4] == 1 && map[5] == 1 && map[6] == 0 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "Y`Z+YZ`+XZ`";
		if (map[1] == 0 && map[2] == 1 && map[3] == 1 && map[4] == 1 && map[5] == 0 && map[6] == 1 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "Y+XZ`";
		if (map[1] == 0 && map[2] == 1 && map[3] == 1 && map[4] == 1 && map[5] == 0 && map[6] == 1 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "X`Y+XY`+XZ`";
		if (map[1] == 0 && map[2] == 1 && map[3] == 1 && map[4] == 1 && map[5] == 0 && map[6] == 0 && map[7] == 1 && map[8] == 1)
			last_formular[0] = "X+YZ`";
		if (map[1] == 0 && map[2] == 1 && map[3] == 1 && map[4] == 0 && map[5] == 1 && map[6] == 1 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "Y+X`Z";
		if (map[1] == 0 && map[2] == 1 && map[3] == 1 && map[4] == 0 && map[5] == 1 && map[6] == 1 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "X`Y+YZ`+Y`Z";
		if (map[1] == 0 && map[2] == 1 && map[3] == 1 && map[4] == 0 && map[5] == 0 && map[6] == 1 && map[7] == 1 && map[8] == 1)
			last_formular[0] = "Y+XZ";
		if (map[1] == 0 && map[2] == 1 && map[3] == 0 && map[4] == 1 && map[5] == 1 && map[6] == 1 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "X`Y+X`Z+YZ+XY`Z`";
		if (map[1] == 0 && map[2] == 1 && map[3] == 0 && map[4] == 1 && map[5] == 1 && map[6] == 1 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "X`Y+XY`+X`Z";
		if (map[1] == 0 && map[2] == 1 && map[3] == 0 && map[4] == 0 && map[5] == 1 && map[6] == 1 && map[7] == 1 && map[8] == 1)
			last_formular[0] = "Z+X`Y";
		if (map[1] == 0 && map[2] == 0 && map[3] == 1 && map[4] == 1 && map[5] == 1 && map[6] == 1 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "XZ`+X`Z+XY";
		if (map[1] == 0 && map[2] == 0 && map[3] == 1 && map[4] == 1 && map[5] == 1 && map[6] == 1 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "XZ`+X`Z+XY`";
		if (map[1] == 0 && map[2] == 0 && map[3] == 1 && map[4] == 1 && map[5] == 1 && map[6] == 0 && map[7] == 1 && map[8] == 1)
			last_formular[0] = "X+XY`Z`";
		if (map[1] == 0 && map[2] == 0 && map[3] == 0 && map[4] == 1 && map[5] == 1 && map[6] == 1 && map[7] == 1 && map[8] == 1)
			last_formular[0] = "Z+XY`";//5개인경우
		if (map[1] == 1 && map[2] == 1 && map[3] == 1 && map[4] == 1 && map[5] == 1 && map[6] == 1 && map[7] == 0 && map[8] == 0)
			last_formular[0] = "Z`+X`Z";
		if (map[1] == 1 && map[2] == 1 && map[3] == 1 && map[4] == 1 && map[5] == 1 && map[6] == 0 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "Z`+X`Y`+XY";
		if (map[1] == 1 && map[2] == 1 && map[3] == 1 && map[4] == 1 && map[5] == 1 && map[6] == 0 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "Z`+Y`Z";
		if (map[1] == 1 && map[2] == 1 && map[3] == 1 && map[4] == 1 && map[5] == 0 && map[6] == 1 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "Z`+YZ";
		if (map[1] == 1 && map[2] == 1 && map[3] == 1 && map[4] == 1 && map[5] == 0 && map[6] == 1 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "Z`+X`Y+XY`";
		if (map[1] == 1 && map[2] == 1 && map[3] == 1 && map[4] == 1 && map[5] == 0 && map[6] == 0 && map[7] == 1 && map[8] == 1)
			last_formular[0] = "Z`+XZ";
		if (map[1] == 1 && map[2] == 1 && map[3] == 1 && map[4] == 0 && map[5] == 1 && map[6] == 1 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "X`+XY";
		if (map[1] == 1 && map[2] == 1 && map[3] == 1 && map[4] == 0 && map[5] == 1 && map[6] == 1 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "X`+YZ`+Y`Z";
		if (map[1] == 1 && map[2] == 1 && map[3] == 1 && map[4] == 0 && map[5] == 0 && map[6] == 1 && map[7] == 1 && map[8] == 1)
			last_formular[0] = "Y+X`Z`+XZ";
		if (map[1] == 1 && map[2] == 1 && map[3] == 0 && map[4] == 1 && map[5] == 1 && map[6] == 1 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "X`+YZ+Y`Z`";
		if (map[1] == 1 && map[2] == 1 && map[3] == 0 && map[4] == 1 && map[5] == 1 && map[6] == 1 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "X`+XY`";
		if (map[1] == 1 && map[2] == 1 && map[3] == 0 && map[4] == 0 && map[5] == 1 && map[6] == 1 && map[7] == 1 && map[8] == 1)
			last_formular[0] = "Z+X`Y`";
		if (map[1] == 1 && map[2] == 0 && map[3] == 1 && map[4] == 1 && map[5] == 1 && map[6] == 1 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "Y`Z`+XY+X`Z";
		if (map[1] == 1 && map[2] == 0 && map[3] == 1 && map[4] == 1 && map[5] == 1 && map[6] == 1 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "XY`+XZ`+Y`Z`+X`Z";
		if (map[1] == 1 && map[2] == 0 && map[3] == 0 && map[4] == 1 && map[5] == 1 && map[6] == 1 && map[7] == 1 && map[8] == 1)
			last_formular[0] = "Z+Y`Z`";
		if (map[1] == 0 && map[2] == 1 && map[3] == 1 && map[4] == 1 && map[5] == 1 && map[6] == 1 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "Y+XZ`+X`Z";
		if (map[1] == 0 && map[2] == 1 && map[3] == 1 && map[4] == 1 && map[5] == 1 && map[6] == 1 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "X`Z+YZ`+XY`";
		if (map[1] == 0 && map[2] == 0 && map[3] == 1 && map[4] == 1 && map[5] == 1 && map[6] == 1 && map[7] == 1 && map[8] == 1)
			last_formular[0] = "Z+XZ`";//6개 끝
		if (map[1] == 1 && map[2] == 1 && map[3] == 1 && map[4] == 1 && map[5] == 1 && map[6] == 1 && map[7] == 1 && map[8] == 0)
			last_formular[0] = "X`+XY+Z`";
		if (map[1] == 1 && map[2] == 1 && map[3] == 1 && map[4] == 1 && map[5] == 1 && map[6] == 1 && map[7] == 0 && map[8] == 1)
			last_formular[0] = "X`+Z`+XY`";
		if (map[1] == 0 && map[2] == 1 && map[3] == 1 && map[4] == 1 && map[5] == 1 && map[6] == 1 && map[7] == 1 && map[8] == 1)
			last_formular[0] = "X+Y+Z";
		if (map[1] == 1 && map[2] == 1 && map[3] == 1 && map[4] == 1 && map[5] == 1 && map[6] == 1 && map[7] == 1 && map[8] == 1)
			last_formular[0] = "1";
		printf("\t\t  F=%sㅡ>간소화 결과ㅡ>F=%s입니다.\n\n", copy_formular, last_formular[0]);
		
		system("pause");



	}//3변수의 끝


	return 0;
}
