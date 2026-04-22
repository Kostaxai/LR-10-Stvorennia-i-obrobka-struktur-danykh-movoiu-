#ifndef TASKS_H
#define TASKS_H

#include <iostream>
#include <cmath>

using namespace std;

// --- СТРУКТУРИ ДАНИХ  ---

// Param74: структура для збереження часу
struct TTime {
    int Hour, Min, Sec;
};

// Begin16: вхідні координати та вихідна відстань
struct Begin16 {
    float x1, x2;
    float dist;
};

// Boolean25: координати точки та результат перевірки чверті
struct Boolean25 {
    float x, y;
    bool result;
};

// --- ПРОТОТИПИ ФУНКЦІЙ  ---

bool InputTime(TTime* t, int h, int m, int s);
bool InputBegin16(Begin16* b, float x1, float x2);
bool InputBoolean25(Boolean25* b, float x, float y);

void PrevMin(TTime* t);
void CalcBegin16(Begin16* b);
void CalcBoolean25(Boolean25* b);

#endif
