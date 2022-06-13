//
// Created by Евгений Нескуба on 10.06.2022.
//

#include "jarvis.h"

#include<vector>
#include<numeric>

vector<point2d>* jarvis_get_convex_hull(vector<point2d>* points)
{
    /*Первая фаза*/

    for (int i = 1; i < points->size(); i++)
    {
        if ((*points)[i].x < (*points)[0].x
            || ((*points)[i].x == (*points)[0].x && (*points)[i].y < (*points)[0].y))
        {
            swap ((*points)[0], (*points)[i]);
        }
    }


    /*Вторая фаза*/

    auto* ch = new  vector<point2d>;
    int cur = 0;

    while (true){
        ch->push_back((*points)[cur]);
        int id = -1;

        for (int i = 0; i < (*points).size(); ++i) {
            if (i != cur && (id == -1 || cross(
                    vector2d((*points)[cur], (*points)[i]),
                    vector2d((*points)[cur], (*points)[id])
            ) > 0))
            {
                id = i;
            }
        }
        if(id == 0){
            break;
        }

        cur = id;
    }

    return ch;
}