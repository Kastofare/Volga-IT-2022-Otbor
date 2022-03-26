#pragma once

#include <iostream>
#include <fstream> 
#include <utility>
#include <vector> //все библиотеки

enum class Character
{
    Ivan,
    Elena,
}; //персонажи

enum class Direction : char
{
    Pass = 'P',
    Up = 'U',
    Down = 'D',
    Left = 'L',
    Right = 'R',
}; //направления движения

class Fairyland
{
    using Position = std::pair<int, int>; //где стоят Иван и Елена

public:
    explicit Fairyland(); //класс Fairyland
    ~Fairyland();

public:
    int getTurnCount() const;
    bool canGo(Character name, Direction direction) const; //могут ли идти Иван и Елена 
    bool go(Direction directionIvan, Direction directionElena); //идут ли Иван и Елена

private:
    static void check(bool expression, const char* message); //проверка
    static bool move(Position& position, Direction direction); //перемещение

private:
    static const std::size_t gSize = 10; //размер input.txt
    std::vector<std::vector<bool>> mMaze;
    Position mIvanPos; //где стоит Иван
    Position mElenaPos; //где стоит Елена
    std::ofstream mOutput;
    int mTurnCount; //счётчик ходов
};
