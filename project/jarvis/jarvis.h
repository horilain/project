//
// Created by Евгений Нескуба on 10.06.2022.
//

#ifndef PROJECT_JARVIS_H
#define PROJECT_JARVIS_H

#include "../utils.h"
#include <vector>
#include<algorithm>
#include<numeric>

using namespace std;

vector<struct point2d> * jarvis_get_convex_hull(vector<struct point2d> *points);

#endif //PROJECT_JARVIS_H
