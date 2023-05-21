#pragma once
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>

class Object
{
public:
    void Render(char* screenBuf) const; // Object의 렌더링 함수
};

class Scene
{
public:
    int width; // 게임 화면 가로 길이
    int height; // 게임 화면 세로 길이
    std::vector<Object> objList; // Object 리스트

    char* screenBuf; // 화면 버퍼

    Scene(int w, int h); // Scene 생성자
    ~Scene(); // Scene 소멸자

    void Initialize(); // Scene 초기화 함수
    void InitScreenBuf(); // 화면 버퍼 초기화 함수
    void ReleaseScreenBuf(); // 화면 버퍼 메모리 해제 함수
    void Draw(); // 화면 그리기 함수
    void ClearScreenBuf(); // 화면 버퍼 지우기 함수
};

class Component
{
public:
    void Start(); // Component 시작 함수
    void Update(); // Component 업데이트 함수
};

void print_title_screen(); // 타이틀 화면 출력 함수
void start_game(); // 게임 시작 함수

#endif