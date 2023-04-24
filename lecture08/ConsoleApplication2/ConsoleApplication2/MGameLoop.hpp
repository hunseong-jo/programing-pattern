#pragma once //#define _IS_THIS_HEADER_INCLUDED

#define key_Exit 27;
#define key_Right 'd'
#define key_Left 'a'



namespace MuSoeun
{
	class MGameLoop
	{
		void gotoxy(int x, int y)
		{
			COORD pos = { x,y }; // x, y 좌표를 받음

			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		}


	public :

		bool isGameRunning = false;

		MGameLoop(){}
		~MGameLoop(){}

		void Initialize()
		{
			std::cout << "초기화 완료" << std::endl;

			gotoxy(0, 10);


			isGameRunning = true;
		}

		void Release()
		{
			std::cout << "시스템 해제 완료" << std::endl;
		}

		void Update()
		{
			std::cout << "업데이트중 완료" << std::endl;
			if (_kbhit)
			{
				
				keyEvent(_getch());
				


			}
			
		}

		void Render()
		{
			std::cout << "렌더링 완료" << std::endl;
		}

		void Run()
		{
			Initialize();

			while (isGameRunning)
			{
				Update();
				Render();
			}

			Release();
		}

		void keyEvent(char keyInput)
		{
			int a, b;
			switch (keyInput)
			{
			case key_Left: //왼쪽 키
				a = 0;
				break;
			case key_Right://오른쪽 키
				b = 0;
				break;
			case 27:
				isGameRunning = false;

				std::cout << "정말 게임을 종료하시겠습니까?" << std::endl;

				break;  
				//27 : esc 키  한번 누를시 일시정지 두번 누를시 게임 종료
			default:
				break;
			}
		}

	};
}