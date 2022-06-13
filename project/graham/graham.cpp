//
// Created by Евгений Нескуба on 10.06.2022.
//

#include "graham.h"

#include<algorithm>
#include<numeric>

vector<point2d>* graham_get_convex_hull(vector<point2d>* points)
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


    sort(
            (*points).begin() + 1,
            (*points).end(),
            [&points](point2d a, point2d b) {
                return cross(
                        vector2d((*points)[0], a),
                        vector2d((*points)[1], b)
                ) > 0;
            }
    );
    /*Вторая фаза*/

    // внешние точки
    auto* ch = new  vector<point2d>;
    *ch = {(*points)[0], (*points)[1]};

    for (int i = 2; i < points->size(); i++){
        while (ch->size() >= 2
               && cross(
                    vector2d((*ch)[ch->size() - 2], (*ch)[ch->size() - 1]),
                    vector2d((*ch)[ch->size() - 1], (*points)[i])
                ) < 0)
        {
            ch->pop_back();
        }

        ch->push_back((*points)[i]);
    }

    return ch;
}