#include "game.h"
#include <iostream> // input, output 스트림
#include <conio.h> // 콘솔 인풋 아웃풋


void Object::Render(char* screenBuf) const
{
    // Object의 렌더링 기능 구현
    // screenBuf를 활용하여 Object의 모양을 그린다.
}

Scene::Scene(int x, int y) : width(x), height(y)
{
    Initialize();
}

Scene::~Scene()
{
    ReleaseScreenBuf();
}

void Scene::Initialize()
{
    objList.clear();
    InitScreenBuf();
}

void Scene::InitScreenBuf()
{
    screenBuf = new char[(width + 1) * height + height];
    for (int i = 0; i < height; i++)
    {
        screenBuf[(width + 1) + (width + 1) * i - 1] = '\n';
    }
    screenBuf[(width + 1) + (width + 1) * (height - 1) - 1] = '\0';
}

void Scene::ReleaseScreenBuf()
{
    if (screenBuf != nullptr)
    {
        delete[] screenBuf;
    }
}

void Scene::Draw()
{
    ClearScreenBuf();

    // Active한 Object의 Render 호출
    for (const Object& obj : objList)
    {
        obj.Render(screenBuf);
    }

    // 화면 전체를 출력
    std::cout << screenBuf;
}

void Scene::ClearScreenBuf()
{
    for (int i = 0; i < (width + 1) * height; i++)
    {
        screenBuf[i] = ' ';
    }
}

void Component::Start()
{
    // Start 함수 구현
}

void Component::Update()
{
    // Update 함수 구현
}

void start_game()
{
    int width, height;
    std::cout << "맵의 가로 길이를 입력하세요. : ";
    std::cin >> width;
    std::cout << "맵의 세로 길이를 입력하세요. : ";
    std::cin >> height;
    system("cls");

    Scene scene(width, height);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == height / 2 && j >= width / 2 - 1 && j <= width / 2 + 1)
            {
                std::cout << "o";
            }
            else if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
            {
                std::cout << "*";
            }
            else
            {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

