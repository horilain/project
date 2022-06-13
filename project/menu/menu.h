//
// Created by Евгений Нескуба on 10.06.2022.
//

#ifndef PROJECT_MENU_H
#define PROJECT_MENU_H

#include "../utils.h"

#include <string>
#include <vector>
#include <fstream>
using namespace std;


void show_main_menu();
void show_alg_menu();
void show_save_menu();

void run_alg_menu(vector<point2d>* (*alg_func)(vector<point2d>*));
void run_save_menu(vector<point2d>* values);

// utils
vector<point2d>* load_from_file(const string& filepath);
vector<point2d>* load_from_console();

#endif //PROJECT_MENU_H
