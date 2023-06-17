#include "game.h"



void Setup()
{
	gameOver = false;

	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	defruitX = rand() % width;
	defruitY = rand() % height;
	trapX = rand() % width;
	trapY = rand() & height;
	fruitX2 = rand() % width;
	fruitY2 = rand() % height;
	score = 0;
	nTail = 0;
		
}


void Draw()
{
	system("cls");
	for (int i = 0; i < width + 2; i++)
		cout << "*";
	cout << endl;


	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "*";
			if (i == y && j == x)
				cout << "O";
			else if (i == fruitY && j == fruitX)
				cout << "F";
			else if (i == defruitY && j == defruitX)
				cout << "T";
			else if (i == trapY && j == trapX)
				cout << "X";
			else if (i == fruitY2 && j == fruitX2)
				cout << "G";
			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "o";
						print = true;
					}
				}
				if (!print)
					cout << " ";
			}

			if (j == width - 1)
				cout << "*";
		}
		cout << endl;
	}

	for (int i = 0; i < width + 2; i++)
		cout << "*";
	cout << endl;
	cout << "Score:" << score << endl;
}

void Input()
{
	if (_kbhit())
	{
		char keyPressed = _getch();
		switch (keyPressed)
		{
		case 'a':
			if (dir != RIGHT) // ���������� �̵� ���� ���� ���������� �̵��� ����
				dir = LEFT;
			break;
		case 'd':
			if (dir != LEFT) // �������� �̵� ���� ���� ������������ �̵��� ����
				dir = RIGHT;
			break;
		case 'w':
			if (dir != DOWN) // �Ʒ��� �̵� ���� ���� ���������� �̵��� ����
				dir = UP;
			break;
		case 's':
			if (dir != UP) // ���� �̵� ���� ���� �Ʒ��������� �̵��� ����
				dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}


void Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}

	// ���� ����� �� ���� ����
	if (x >= width || x < 0 || y >= height || y < 0)
		gameOver = true;

	for (int i = 0; i < nTail; i++)
		if (tailX[i] == x && tailY[i] == y)
			gameOver = true;

	if (x == fruitX && y == fruitY)
	{
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		nTail++;
	}

	if (x == defruitX && y == defruitY)
	{
		if (score > 0)
		{
			score -= 10;
		}
		defruitX = rand() % width;
		defruitY = rand() % height;
		if (nTail > 0)
		{
			nTail--;
		}
	}

	if (x == trapX && y == trapY)
	{
		score = 0;
		trapX = rand() % width;
		trapY = rand() % height;
		nTail = 0;
	}

	if (x == fruitX2 && y == fruitY2)
	{
		

		if (rand() % 2 == 0)
		{
			score += 30;
			nTail += 3;
		}
		else
		{
			if (score < 10)
			{

			}
			else if (score > 30)
			{
				score -= 30;
				nTail -= 3;
			}
			else if (score == 20)
			{
				score = 0;
				nTail = 0;
			}
			else if (score == 10)
			{
				score = 0;
				nTail = 0;
			}

			
			
		}
		fruitX2 = rand() % width;
		fruitY2 = rand() % height;
	}
}

void start_game()
{



	std::cout << "\n���� ���� ���̴� ���� ���̺��� �ι��̻��� �����մϴ�.  ";
	std::cout << "\n (��õ �� ������ 40 x 20, 60 x 30)  ";
	std::cout << "\n\n���� ���� ���̸� �Է��ϼ���. : ";
	std::cin >> width;
	std::cout << "\n���� ���� ���̸� �Է��ϼ���. : ";
	std::cin >> height;
	std::cout << "\n������ ���̵��� �����ϼ���. : ���� : easy (1) , ���� : nomal (2) , ����� : hard (3) , �ſ� ����� : hell (4)\n\n";
	std::cout << "���̵� ���� : ";
	std::cin >> nani;


	std::system("cls");
	Setup();
	auto previousTime = std::chrono::high_resolution_clock::now();
	float deltaTime = 0.0f;

	while (!gameOver)
	{
		auto currentTime = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> elapsed = currentTime - previousTime;
		previousTime = currentTime;
		deltaTime = elapsed.count();

		Draw();
		Input();
		Logic();

		// ���� ������ delta Ÿ�ӿ� ����Ͽ� ������Ʈ
		if (nani == 1)
		{
			Sleep(10);
		}
		else if (nani == 2)
		{
			Sleep(3);
		}
		else if (nani == 3)
		{
			Sleep(1);
		}
		else if (nani == 4)
		{
			Sleep(0.00001);
		}

		// deltaTime�� ����Ͽ� ���� ������ ������Ʈ
		// ��: Logic �Լ� ������ ������ ��� �� deltaTime�� ������

		// deltaTime�� ����Ͽ� ���� ������ ������Ʈ�� �� ȭ���� �׸��� ���� ���� ����
	}
}



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
			re:
				system("cls");
				start_game();
				std::cout << "\n\nGAME OVER!!";
				std::cout << "\n\n";
				std::cout << "(�ٽ��ϱ� : R ��ư)\n";
				std::cout << "(������ : Esc)\n";
				while (true)
				{

					key_input = _getch();
					if (key_input == 'r')
					{
						system("cls");
						goto re;
					}
					if (key_input == 27)
					{
						return 0;
					}
				}
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
