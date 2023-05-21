#include "game.h"
#include <iostream> // input, output ��Ʈ��
#include <conio.h> // �ܼ� ��ǲ �ƿ�ǲ


void Object::Render(char* screenBuf) const
{
    // Object�� ������ ��� ����
    // screenBuf�� Ȱ���Ͽ� Object�� ����� �׸���.
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

    // Active�� Object�� Render ȣ��
    for (const Object& obj : objList)
    {
        obj.Render(screenBuf);
    }

    // ȭ�� ��ü�� ���
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
    // Start �Լ� ����
}

void Component::Update()
{
    // Update �Լ� ����
}

void start_game()
{
    int width, height;
    std::cout << "���� ���� ���̸� �Է��ϼ���. : ";
    std::cin >> width;
    std::cout << "���� ���� ���̸� �Է��ϼ���. : ";
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

