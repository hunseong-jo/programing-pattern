#include "game.h"
#include <conio.h>

void print_title_screen()
{
    std::cout << "****************************************" << std::endl;
    std::cout << "*                                      *" << std::endl;
    std::cout << "*                                      *" << std::endl;
    std::cout << "*             지렁이 게임              *" << std::endl;
    std::cout << "*            (Snake Bite)              *" << std::endl;
    std::cout << "*                                      *" << std::endl;
    std::cout << "*            1. 게임 시작              *" << std::endl;
    std::cout << "*            2. 게임 설명              *" << std::endl;
    std::cout << "*            3. 게임 랭킹 보기         *" << std::endl;
    std::cout << "*            4. 게임 종료 (esc)        *" << std::endl;
    std::cout << "*                                      *" << std::endl;
    std::cout << "****************************************" << std::endl;
}

int print_introduction_screen() {

    std::cout << "****************************************" << std::endl;
    std::cout << "*              게임 설명.              *" << std::endl;
    std::cout << "*      Snake bite란 뭘까욥?....        *" << std::endl;
    std::cout << "****************************************" << std::endl;
    std::cout << "*   타이틀화면으로 돌아갈까용? (Y/N)   *" << std::endl;

    return 0;
}


int main()
{
    int game_state = 0; // 게임 상태 변수
    int mod = 1; // 화면 모드 변수
    int is_game_running = 1; // 게임이 실행 중인지 여부를 나타내는 변수
    bool isYesSelected = true;

    while (is_game_running)
    {
        char key_input = 0; // 키 입력 변수 초기화
        switch (game_state)
        {
            case 0: // 타이틀 화면
                if (mod)
                {
                    print_title_screen();
                }
                key_input = _getch(); // 1, 2, 3, 4 중 입력 받기

                mod = 0; // 모드 변경

                switch (key_input)
                {
                    case '1':
                        game_state = 1; // 게임 화면으로 이동
                        mod = 1;
                        break;
                    case '2':
                        game_state = 2; // 게임 설명 화면으로 이동
                        mod = 1;
                        break;
                    case '3':
                        break; // 게임 랭킹 보기
                    case '4':
                        is_game_running = 0; // 게임 종료
                        break;
                    case 27:
                        is_game_running = 0; // 게임 종료 (esc 키 입력)
                    default:
                        break;
                }
                break;
            case 1: // 게임 화면
                if (mod)
                {
                    system("cls");
                    start_game();
                }
                key_input = _getch();
                mod = 0;
                break;
            case 2: // 게임 설명 화면
                if (mod)
                {
                    system("cls");
				print_introduction_screen(); // 게임 설명 화면으로 이동
			}

			key_input = 0;  //키 입력을 위해 변수 초기화
			key_input = _getch();  // 문자 하나 입력 받음

			mod = 0;

			if (key_input == 'y') {
				system("cls");
				game_state = 0;  // 타이틀 스크린
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

