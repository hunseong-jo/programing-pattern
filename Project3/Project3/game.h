#pragma once
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>

class Object
{
public:
    void Render(char* screenBuf) const; // Object�� ������ �Լ�
};

class Scene
{
public:
    int width; // ���� ȭ�� ���� ����
    int height; // ���� ȭ�� ���� ����
    std::vector<Object> objList; // Object ����Ʈ

    char* screenBuf; // ȭ�� ����

    Scene(int w, int h); // Scene ������
    ~Scene(); // Scene �Ҹ���

    void Initialize(); // Scene �ʱ�ȭ �Լ�
    void InitScreenBuf(); // ȭ�� ���� �ʱ�ȭ �Լ�
    void ReleaseScreenBuf(); // ȭ�� ���� �޸� ���� �Լ�
    void Draw(); // ȭ�� �׸��� �Լ�
    void ClearScreenBuf(); // ȭ�� ���� ����� �Լ�
};

class Component
{
public:
    void Start(); // Component ���� �Լ�
    void Update(); // Component ������Ʈ �Լ�
};

void print_title_screen(); // Ÿ��Ʋ ȭ�� ��� �Լ�
void start_game(); // ���� ���� �Լ�

#endif