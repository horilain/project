//
// Created by Евгений Нескуба on 10.06.2022.
//

#include "menu.h"

#include <iostream>

void show_main_menu()
{
    const int size = 4;
    string menu_list[size] = {
        "Алг. Грэхема",
        "Алг. Джарвиса",
        "Тест",
        "Выход"
    };

    cout << "\n~~~~~~~~~~~~~~~~~~~\n";
    for (int i = 0; i < size; i++)
    {
        cout << "[" << i + 1 << "] " << menu_list[i] << endl;
    }
    cout << "~~~~~~~~~~~~~~~~~~~\n";
}

void show_alg_menu()
{
    const int size = 4;
    string menu_list[size] = {
            "Загрузить значения из файла",
            "Считать значения",
            "Запуск алгоритма",
            "В главное меню"
    };

    cout << "\n~~~~~~~~~~~~~~~~~~~\n";
    for (int i = 0; i < size; i++)
    {
        cout << "[" << i + 1 << "] " << menu_list[i] << endl;
    }
    cout << "~~~~~~~~~~~~~~~~~~~\n";
}

void show_save_menu()
{
    const int size = 2;
    string menu_list[size] = {
            "Сохранить значения в файл",
            "Вывести значения",
    };

    cout << "\n~~~~~~~~~~~~~~~~~~~\n";
    for (int i = 0; i < size; i++)
    {
        cout << "[" << i + 1 << "] " << menu_list[i] << endl;
    }
    cout << "~~~~~~~~~~~~~~~~~~~\n";
}


vector<point2d>* load_from_file(const string& filepath)
{
    auto* points = new vector<point2d>;


    ifstream file(filepath);

    string s;
    while(getline(file, s))
    {
        vector<string> raw_point = split(s, ' ');
        int x = stoi(raw_point[0]);
        int y = stoi(raw_point[1]);
        point2d point{ x, y };
        points->push_back(point);
    }
    file.close();

    return points;
}

void save_to_file(const string& filepath, vector<point2d>* values )
{

    ofstream file(filepath);

    string s;
    for (int i = 0; i < values->size(); ++i)
    {
        file << (*values)[i].x << ' ' << (*values)[i].y << endl;
    }
    file.close();

}

vector<point2d>* load_from_console()
{
    cout << "Введите ко-во точек: ";
    int n;
    cin >> n;
    auto* points = new vector<point2d>(n);

    cout << "Введите координаты(x y) точек через пробел: \n";
    for (auto& pt : *points)
    {
        cin >> pt.x >> pt.y;
    }

    return points;
}

void run_alg_menu(vector<point2d>*(*alg_func)(vector<point2d>*))
{
    vector<point2d>* values = nullptr;

    int menu_num;
    while (true) {
        show_alg_menu();
        cout << "Введите номер меню: ";
        cin >> menu_num;

        switch (menu_num) {
            case 1:
                {
                    string filepath;
                    cout << "Введите путь к файлу, который хотите считать: ";
                    cin >> filepath;
                    values = load_from_file(filepath);
                    continue;
                }
            case 2:
                values = load_from_console();
                continue;
            case 3:
                if (values != nullptr)
                {
                    run_save_menu(alg_func(values));
                } else
                    cout << "\nСначала загрузите точки!\n";
                continue;
            case 4:
                return;
            default:
                cout << "Неизвестный номер меню";
                continue;
        }
    }
}

void run_save_menu(vector<point2d>* values)
{

    int menu_num;
    while (true) {
        show_save_menu();
        cout << "Введите номер меню: ";
        cin >> menu_num;

        switch (menu_num) {
            case 1:
            {
                string filepath;
                cout << "Введите путь к файлу, в который хотите сохранить: ";
                cin >> filepath;
                values = load_from_file(filepath);
                save_to_file(filepath, values);
                return;
            }
            case 2:
                cout << "Полученные значения:\n";
                for (int i = 0; i < values->size(); ++i)
                {
                    cout << (*values)[i].x << ' ' << (*values)[i].y << endl;
                }
                return;
            default:
                cout << "Неизвестный номер меню";
                continue;
        }
    }
}





// мусор
//int n;
//cin >> n;
//vector<point2d> points(n);
//
//for (auto& pt : points)
//{
//cin >> pt.x >> pt.y;
//}
//
//auto ch = get_convex_hull(points);
//
//cout << ch.size() << endl;
//
//for(auto pt : ch)
//{
//cout << pt.x << ' ' << pt.y << endl;
//}




//for(auto pt : ch)
//{
//cout << pt.x << ' ' << pt.y << endl;
//}
