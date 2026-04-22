#pragma execution_character_set("utf-8")
#include <iostream>
#include <windows.h>
#include "tasks.h"

using namespace std;

// Допоміжна функція для гарного виводу часу 
void PrintTime(TTime t) {
    if (t.Hour < 10) cout << "0"; cout << t.Hour << ":";
    if (t.Min < 10) cout << "0"; cout << t.Min << ":";
    if (t.Sec < 10) cout << "0"; cout << t.Sec << endl;
}

void run_param74() {
    TTime t[5];
    cout << "\n[Param74] Введіть 5 моментів часу (Год Хв Сек):\n";
    for (int i = 0; i < 5; i++) {
        int h, m, s;
        cout << i + 1 << ": "; cin >> h >> m >> s;
        if (!InputTime(&t[i], h, m, s)) {
            cout << "Помилка: некоректний час. Пропущено.\n";
            t[i].Hour = -1;
        }
    }
    cout << "\nРезультати (-1 хв):\n";
    for (int i = 0; i < 5; i++) {
        if (t[i].Hour != -1) {
            PrevMin(&t[i]);
            PrintTime(t[i]);
        }
    }
}

void run_begin16() {
    Begin16 b;
    float x1, x2;
    cout << "\n[Begin16] Введіть x1 та x2 (не 0): ";
    cin >> x1 >> x2;

    //  Виклик функції перевірки та обробки
    if (InputBegin16(&b, x1, x2)) {
        CalcBegin16(&b);
        cout << "Відстань = " << b.dist << endl; // 
    }
    else {
        cout << "Помилка: координати не можуть дорівнювати 0!\n";
    }
}

void run_boolean25() {
    Boolean25 b;
    float x, y;
    cout << "\n[Boolean25] Введіть x та y (не 0): ";
    cin >> x >> y;

    //  Виклик функції перевірки та обробки
    if (InputBoolean25(&b, x, y)) {
        CalcBoolean25(&b);
        cout << "Точка у 2-й чверті: " << (b.result ? "ТАК" : "НІ") << endl; // 
    }
    else {
        cout << "Помилка: координати не можуть дорівнювати 0!\n";
    }
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int choice;
    do {
        cout << "\n========== ГОЛОВНЕ МЕНЮ ==========\n";
        cout << "1 - Param74 (час -1 хв)\n";
        cout << "2 - Begin16 (відстань)\n";
        cout << "3 - Boolean25 (чверть)\n";
        cout << "0 - Вихід\n";
        cout << "Ваш вибір: ";

        if (!(cin >> choice)) {
            cin.clear(); cin.ignore(10000, '\n');
            choice = -1; continue;
        }

        switch (choice) {
        case 1: run_param74(); break;
        case 2: run_begin16(); break;
        case 3: run_boolean25(); break;
        }
    } while (choice != 0);

    return 0;
}
