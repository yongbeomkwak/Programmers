#include <bits/stdc++.h>
using namespace std;

#define MAX 11
#define P pair<int, int>

int _map[MAX][MAX][4]; // ULRD(0,1,2,3)

int solution(string dirs)
{
    int answer = 0;
    int x = 5;
    int y = 5;
    // 0,0 -> 5,5 , -5,-5 -> 0,0 , 5,5 -> 10,10 으로 좌표 변환

    for (const char &c : dirs)
    {
        if (c == 'U')
        {
            if (y + 1 > 10)
                continue;
            if (!_map[y][x][0]) //만약 y->y+1로 올라가는 방향 간선이 있나?
            {

                //없으면 올라가는 간선 1 , y+1->y로 내려가는 간선도 1
                _map[y][x][0] = 1;
                _map[y + 1][x][3] = 1;
                answer++;
            }
            y += 1; // y증가
        }
        else if (c == 'L')
        {
            if (x - 1 < 0)
                continue;
            if (!_map[y][x][1]) // x-> x-1 로 가는 간선있나?
            {
                //없으면
                _map[y][x][1] = 1;     // x-> x-1로 가는 간선 추가
                _map[y][x - 1][2] = 1; // x-1 -> x로 가는 간선 추가
                answer++;
            }
            x -= 1;
        }
        else if (c == 'R')
        {
            if (x + 1 > 10)
                continue;

            if (!_map[y][x][2]) // x->x+1로 가는 간선 있나?
            {
                _map[y][x][2] = 1;     // x->x+1로 간선 추가
                _map[y][x + 1][1] = 1; // x+1->x로 간선 추가
                answer++;
            }
            x += 1;
        }
        else
        {
            if (y - 1 < 0)
                continue;
            if (!_map[y][x][3]) // y->y-1 간선 있나?
            {
                _map[y][x][3] = 1;     // y->y-1로 간선 추가
                _map[y - 1][x][0] = 1; // y-1->y로 간선 추가
                answer++;
            }
            y -= 1;
        }
    }

    return answer;
}