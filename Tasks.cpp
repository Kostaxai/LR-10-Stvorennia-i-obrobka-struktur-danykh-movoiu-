#pragma execution_character_set("utf-8")
#include "tasks.h"

// Перевірка часу: години 0-23, хвилини/секунди 0-59 
bool InputTime(TTime* t, int h, int m, int s) {
    if (h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60) {
        t->Hour = h; t->Min = m; t->Sec = s;
        return true;
    }
    return false;
}

// Перевірка для Begin16: координати не можуть бути 0 
bool InputBegin16(Begin16* b, float x1, float x2) {
    if (x1 == 0 || x2 == 0) return false; // Умова перевірки
    b->x1 = x1;
    b->x2 = x2;
    return true;
}

// Перевірка для Boolean25: x та y не можуть бути 0 
bool InputBoolean25(Boolean25* b, float x, float y) {
    if (x == 0 || y == 0) return false; // Умова перевірки
    b->x = x;
    b->y = y;
    return true;
}

// Процедура зміни часу 
void PrevMin(TTime* t) {
    if (t->Min > 0) t->Min--;
    else {
        t->Min = 59;
        if (t->Hour > 0) t->Hour--;
        else t->Hour = 23;
    }
}

// Обчислення відстані 
void CalcBegin16(Begin16* b) {
    b->dist = fabsf(b->x2 - b->x1);
}

// Перевірка чверті 
void CalcBoolean25(Boolean25* b) {
    b->result = (b->x < 0 && b->y > 0);
}
