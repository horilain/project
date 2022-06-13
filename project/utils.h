//
// Created by Евгений Нескуба on 10.06.2022.
//

#ifndef PROJECT_UTILS_H
#define PROJECT_UTILS_H

#include <string>
#include <vector>
#include <sstream>

// точка
struct point2d
{
    long long x, y;
};

// вектор
struct vector2d
{
    long long x, y;

    vector2d(point2d a, point2d b){
        x= b.x - a.x;
        y= b.y - a.y;
    }
};


long long cross(vector2d a, vector2d b);

std::vector<std::string> split(const std::string& s, char delimiter);
#endif //PROJECT_UTILS_H
