//
// Created by Евгений Нескуба on 10.06.2022.
//

#include "utils.h"

std::vector<std::string> split(const std::string& s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}


// векторное произведение
long long cross(vector2d a, vector2d b){
    return a.x * b.y - b.x * a.y;
}