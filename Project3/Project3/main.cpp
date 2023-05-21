#include "game.h"
#include <conio.h>

void print_title_screen()
{
    std::cout << "****************************************" << std::endl;
    std::cout << "*                                      *" << std::endl;
    std::cout << "*                                      *" << std::endl;
    std::cout << "*             ������ ����              *" << std::endl;
    std::cout << "*            (Snake Bite)              *" << std::endl;
    std::cout << "*                                      *" << std::endl;
    std::cout << "*            1. ���� ����              *" << std::endl;
    std::cout << "*            2. ���� ����              *" << std::endl;
    std::cout << "*            3. ���� ��ŷ ����         *" << std::endl;
    std::cout << "*            4. ���� ���� (esc)        *" << std::endl;
    std::cout << "*                                      *" << std::endl;
    std::cout << "****************************************" << std::endl;
}

int print_introduction_screen() {

    std::cout << "****************************************" << std::endl;
    std::cout << "*              ���� ����.              *" << std::endl;
    std::cout << "*      Snake bite�� �����?....        *" << std::endl;
    std::cout << "****************************************" << std::endl;
    std::cout << "*   Ÿ��Ʋȭ������ ���ư����? (Y/N)   *" << std::endl;

    return 0;
}


int main()
{
    int game_state = 0; // ���� ���� ����
    int mod = 1; // ȭ�� ��� ����
    int is_game_running = 1; // ������ ���� ������ ���θ� ��Ÿ���� ����
    bool isYesSelected = true;

    while (is_game_running)
    {
        char key_input = 0; // Ű �Է� ���� �ʱ�ȭ
        switch (game_state)
        {
            case 0: // Ÿ��Ʋ ȭ��
                if (mod)
                {
                    print_title_screen();
                }
                key_input = _getch(); // 1, 2, 3, 4 �� �Է� �ޱ�

                mod = 0; // ��� ����

                switch (key_input)
                {
                    case '1':
                        game_state = 1; // ���� ȭ������ �̵�
                        mod = 1;
                        break;
                    case '2':
                        game_state = 2; // ���� ���� ȭ������ �̵�
                        mod = 1;
                        break;
                    case '3':
                        break; // ���� ��ŷ ����
                    case '4':
                        is_game_running = 0; // ���� ����
                        break;
                    case 27:
                        is_game_running = 0; // ���� ���� (esc Ű �Է�)
                    default:
                        break;
                }
                break;
            case 1: // ���� ȭ��
                if (mod)
                {
                    system("cls");
                    start_game();
                }
                key_input = _getch();
                mod = 0;
                break;
            case 2: // ���� ���� ȭ��
                if (mod)
                {
                    system("cls");
				print_introduction_screen(); // ���� ���� ȭ������ �̵�
			}

			key_input = 0;  //Ű �Է��� ���� ���� �ʱ�ȭ
			key_input = _getch();  // ���� �ϳ� �Է� ����

			mod = 0;

			if (key_input == 'y') {
				system("cls");
				game_state = 0;  // Ÿ��Ʋ ��ũ��
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

