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
			if (dir != RIGHT) // 오른쪽으로 이동 중일 때는 왼쪽으로의 이동을 무시
				dir = LEFT;
			break;
		case 'd':
			if (dir != LEFT) // 왼쪽으로 이동 중일 때는 오른쪽으로의 이동을 무시
				dir = RIGHT;
			break;
		case 'w':
			if (dir != DOWN) // 아래로 이동 중일 때는 위쪽으로의 이동을 무시
				dir = UP;
			break;
		case 's':
			if (dir != UP) // 위로 이동 중일 때는 아래쪽으로의 이동을 무시
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

	// 벽에 닿았을 때 게임 종료
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



	std::cout << "\n맵의 가로 길이는 세로 길이보다 두배이상을 권장합니다.  ";
	std::cout << "\n (추천 맵 사이즈 40 x 20, 60 x 30)  ";
	std::cout << "\n\n맵의 가로 길이를 입력하세요. : ";
	std::cin >> width;
	std::cout << "\n맵의 세로 길이를 입력하세요. : ";
	std::cin >> height;
	std::cout << "\n게임의 난이도를 선택하세요. : 쉬움 : easy (1) , 보통 : nomal (2) , 어려움 : hard (3) , 매우 어려움 : hell (4)\n\n";
	std::cout << "난이도 선택 : ";
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

		// 게임 로직을 delta 타임에 기반하여 업데이트
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

		// deltaTime을 사용하여 게임 로직을 업데이트
		// 예: Logic 함수 내에서 움직임 계산 시 deltaTime을 곱해줌

		// deltaTime을 사용하여 게임 로직을 업데이트한 후 화면을 그리는 등의 동작 수행
	}
}



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
			re:
				system("cls");
				start_game();
				std::cout << "\n\nGAME OVER!!";
				std::cout << "\n\n";
				std::cout << "(다시하기 : R 버튼)\n";
				std::cout << "(나가기 : Esc)\n";
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
