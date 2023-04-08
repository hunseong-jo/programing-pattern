#include <iostream> // input, output 스트림
#include <conio.h> // 콘솔 인풋 아웃풋
#include <Windows.h> // 창문

//game state == 0
int print_title_screen() {


	std::cout << "****************************************" << std::endl;
	std::cout << "*                                      *" << std::endl;
	std::cout << "*                                      *" << std::endl;
	std::cout << "*             지렁이 게임              *" << std::endl;
	std::cout << "*            (Snake  Bite)             *" << std::endl;
	std::cout << "*                                      *" << std::endl;
	std::cout << "*  1. 게임 시작                        *" << std::endl;
	std::cout << "*  2. 게임 설명                        *" << std::endl;
	std::cout << "*  3. 게임 랭킹 보기                   *" << std::endl;
	std::cout << "*  4. 게임 종료 (esc)                  *" << std::endl;
	std::cout << "*                                      *" << std::endl;
	std::cout << "****************************************" << std::endl;

	return 0;

}

void gotoxy(int x, int y) {
	//x, y 좌표 설정
	COORD pos = { x,y }; // x, y 좌표를 받음
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); // 받은 좌표로 커서를 이동
}

int print_game_screen(int stage_width, int stage_height)
{

	for (int i = 0; i < stage_width; i++) {
		gotoxy(i, 0);  
		std::cout << "*" << std::endl;
	}
	for (int i = 0; i < stage_height; i++) {
		gotoxy(0, i);
		std::cout << "*" << std::endl;
	}
	for (int i = 0; i < stage_height; i++) {
		gotoxy(stage_width, i);
		std::cout << "*" << std::endl;
	}
	for (int i = 0; i <= stage_width; i++) {
		gotoxy(i, stage_height);
		std::cout << "*" << std::endl;
	}

	return 0;
}


//game state == 2
int print_introduction_screen() {

	std::cout << "****************************************" << std::endl;
	std::cout << "*              게임 설명.              *" << std::endl;
	std::cout << "*      Snake bite란 뭘까욥?....        *" << std::endl;
	std::cout << "****************************************" << std::endl;
	std::cout << "*   타이틀화면으로 돌아갈까용? (Y/N)   *" << std::endl;

	return 0;
}


int main() {

	int game_state = 0;
	int mod = 1; // 처음에 한번 무조건 메인화면을 띄워야 하기에 1이다.
	int is_game_runing = 1;

	while (is_game_runing)
	{
		char key_input = 0;  // 0으로 초기화
		switch (game_state)
		{
		case 0: // 1번을 누를 경우
			if (mod) {
				print_title_screen();
			};
			key_input = _getch(); // 1,2,3,4 중 입력을 받음


			mod = 0; // 0으로 바꿔서 안뜨게 만든다.

			switch (key_input)
			{
			case '1':
				game_state = 1;
				mod = 1; 
				break;  // while 문으로 첨부터 감
			case '2':
				game_state = 2;
				mod = 1;
				break;
			case '3':
				break;
			case '4':
				is_game_runing = 0;
				break;
			case 27:
				is_game_runing = 0;
			default:
				break;
			}
			break;
		case 1:
			
			if (mod) {
				int x = 0;
				int y = 0;
				std::cout << "*맵을 만들기 위해 x,y값을 입력해주세요!*" << std::endl;
				std::cout << "****************************************" << std::endl;
				scanf_s("%d", &x);
				scanf_s("%d", &y);
				system("cls");  //지금까지 출력된 화면을 지워줌
				print_game_screen(x, y);
			};
			key_input = _getch();
			mod = 0;
			break;
		case 2:

			if (mod) {
				print_introduction_screen();
			}

			key_input = 0;
			key_input = _getch();

			mod = 0;

			if (key_input == 'y') {
				game_state = 0;
				mod = 1;
			}
			else if (key_input == 'n') {

			}

		default:
			break;
		}

	}
	return 0;
}

