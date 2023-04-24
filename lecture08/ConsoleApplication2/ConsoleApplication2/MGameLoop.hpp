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
			COORD pos = { x,y }; // x, y ��ǥ�� ����

			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		}


	public :

		bool isGameRunning = false;

		MGameLoop(){}
		~MGameLoop(){}

		void Initialize()
		{
			std::cout << "�ʱ�ȭ �Ϸ�" << std::endl;

			gotoxy(0, 10);


			isGameRunning = true;
		}

		void Release()
		{
			std::cout << "�ý��� ���� �Ϸ�" << std::endl;
		}

		void Update()
		{
			std::cout << "������Ʈ�� �Ϸ�" << std::endl;
			if (_kbhit)
			{
				
				keyEvent(_getch());
				


			}
			
		}

		void Render()
		{
			std::cout << "������ �Ϸ�" << std::endl;
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
			case key_Left: //���� Ű
				a = 0;
				break;
			case key_Right://������ Ű
				b = 0;
				break;
			case 27:
				isGameRunning = false;

				std::cout << "���� ������ �����Ͻðڽ��ϱ�?" << std::endl;

				break;  
				//27 : esc Ű  �ѹ� ������ �Ͻ����� �ι� ������ ���� ����
			default:
				break;
			}
		}

	};
}