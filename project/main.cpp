#include <iostream>
#include "graham/graham.h"
#include "jarvis/jarvis.h"
#include "menu/menu.h"

using namespace std;

int main()
{
    int menu_num;

    while (true) {
        show_main_menu();
        cout << "Введите номер меню: ";
        cin >> menu_num;

        switch (menu_num) {
            case 1:
                run_alg_menu(graham_get_convex_hull);
                continue;
            case 2:
                run_alg_menu(jarvis_get_convex_hull);
                continue;
            case 3:
                continue;
            case 4:
                return 0;
            default:
                cout << "Неизвестный номер меню";
                continue;
        }
    }
}
