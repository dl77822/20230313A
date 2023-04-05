#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <Windows.h>

int title_screen() //메인 타이틀 화면
{
	printf("***********************************\n");
	printf("*          지렁이 게임	          *\n");
	printf("*          (Snake Bite)           *\n");
	printf("*         1. 게임 시작            *\n");
	printf("*         2. 게임 설명            *\n");
	printf("*         3. 게임랭킹 보기        *\n");
	printf("*         4. 게임 종료(ese)       *\n");
	printf("***********************************\n");

	return 0;
}
void gotoxy(int x, int y) {  //좌표지정
	//x, y 좌표 설정
	COORD pos = { x,y };
	//커서 이동
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int game_start(int stage_width, int stage_height) { //1번 게임 화면 출력 
	gotoxy(stage_width, stage_height);
	for (int i = 0; i < stage_width + 20; i++) {
		printf("*");
	}
	gotoxy(stage_width, stage_height + 20);
	for (int i = 0; i < stage_width + 20; i++) {
		printf("*");
	}
	gotoxy(stage_width, stage_height);
	for (int i = 0; i < stage_height + 19; i++) {

		gotoxy(stage_width, stage_height + i);
		printf("*\n");
	}
	gotoxy(stage_width + 20, stage_height);
	for (int i = 0; i < stage_height + 19; i++) {

		gotoxy(stage_width + 21, stage_height + i);
		printf("*\n");
	}
	gotoxy(stage_width, stage_height + 21);
	printf(" 타이틀화면으로 돌아갈까요? (Y/N)  \n");

	return 0;
}
int game_introduction_screen() //2 번 게임설명 화면
{
	printf("***********************************\n");
	printf("*      게임 설명 화면입니다       *\n");
	printf("***********************************\n");
	printf(" 타이틀화면으로 돌아갈까요? (Y/N)  \n");
	return 0;
}
int ranking_screen() //3번 게임랭킹 화면
{
	printf("***********************************\n");
	printf("*      게임 랭킹 화면입니다.      *\n");
	printf("***********************************\n");
	printf(" 타이틀화면으로 돌아갈까요? (Y/N)  \n");
	return 0;
}




int main()
{
	int game_state = 0;
	int is_game = 1;
	int screen = 1;
	int stage = 0;
	while (is_game)
	{
		char key_input = 0;

		switch (game_state) //game_state = 0
		{
		case 0: // 바로 실행 
			if (screen == 1) //screen 값이 1, 바로 실행
			{
				title_screen(); //메인화면 출력
				screen = 0;
			}
			key_input = 0;
			key_input = _getch();//입력받은 키 key_input
			if (key_input == '1') // 1번키를 입력 받으면 실행
			{
				game_state = 1;
				screen = 4;
			}
			if (key_input == '2') //2번키를 입력 받으면 실행 
			{
				game_state = 2;
				screen = 2;
			}
			else if (key_input == '3')
			{
				game_state = 3;
				screen = 3;
			}
			else if (key_input == '4' || key_input == 27)
				is_game = 0; //다시 switch
			break;

		case 1:
			if (screen == 4)
			{
				system("cls");
				game_start(2, 2);
				screen = 0;

			}
			key_input = 0;
			key_input = _getch();
			if (key_input == 'y')
			{
				system("cls");
				game_state = 0;
				screen = 1;
			}

			break;
		case 2: //2번 키를 입력 받았을때 실행
			if (screen == 2)
			{
				game_introduction_screen(); //2.게임설명 화면 출력
				screen = 0;
			}
			key_input = 0;
			key_input = _getch();
			if (key_input == 'y')
			{
				game_state = 0;
				screen = 1;
			}
			break;
		case 3:
			if (screen == 3)
			{
				ranking_screen();
				screen = 0;
			}
			key_input = 0;
			key_input = _getch();
			if (key_input == 'y')
			{
				game_state = 0;
				screen = 1;
			}
			break;
		default:

			break;
		}

	}

	return 0;
}
/*
while (1)
{
	snake_bite();

		if (_getch() == '2') {
			print_introduction_screen();
			if (_getch() == 89) {
				snake_bite();
			}
		}
		if (_getch() == 27) {
			break;
		}
		else {
			printf(" \n");
		}

}
*/



