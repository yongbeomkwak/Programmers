#include <bits/stdc++.h>

#define has(a) (building.find(pred[(a)]) != building.end())
//셋이 해당 벡터를 갖고 있나?  pred[a] ={x,y,a}

using namespace std;

bool isRunnable(const set<vector<int>> building)
{
    for (auto build : building)
    { //모든 원소에 대하여
        int x = build[0], y = build[1], a = build[2];

        if (a == 0)
        { // 기둥
            vector<int> pred[3] = {{x, y - 1, 0}, {x, y, 1}, {x - 1, y, 1}};
            //{x,y-1,0}: 밑에 기둥이 있는가?
            //{x,y,1}: 보 한쪽 위에 있는가? (x->x+1)
            //{x-1,y,1}:보 한쪽 위에 있는가 ? (x-1->x)
            // y==0 바닥 이거나
            if (y == 0 || has(0) || has(1) || has(2))
                continue;
            return false;
        }
        else
        { //보

            vector<int> pred[4] = {{x, y - 1, 0}, {x + 1, y - 1, 0}, {x + 1, y, 1}, {x - 1, y, 1}};
            //{x,y-1,0}:한쪽 끝에 기둥이 있나?
            //{x+1,y-1,0}: 한쪽 끝에 기둥이 있나?
            //{x+1,y,1}: 양쪽 끝에 기둥이 있나? (오른쪽)
            //{x-1,y,1}: 양쪽 끝에 기둥이 있나? (왼쪽)
            if (has(0) || has(1) || (has(2) && has(3)))
                continue;
            return false;
        }
    }

    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame)
{
    vector<vector<int>> answer;
    set<vector<int>> building;
    for (const vector<int> &task : build_frame)
    {
        vector<int> tmp = {task[0], task[1], task[2]}; // x,y,보 or 기둥
        const int act = task[3];                       // 0:삭제 1:설치

        if (act == 0) //삭제 이슈
        {
            building.erase(tmp); //일다 삭제해보고
            if (!isRunnable(building))
                building.insert(tmp); //조건에 맞지 않으면 다시 넣음
        }
        else //설치 이슈
        {
            building.insert(tmp); //일단 넣어보고
            if (!isRunnable(building))
                building.erase(tmp); // 상황에 맞지않으면 다시 삭제
        }
    }

    for (auto build : building) // set이므로 모든 오름차순을 만족
        answer.push_back(build);

    return answer;
}