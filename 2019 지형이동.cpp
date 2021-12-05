#include <bits/stdc++.h>

typedef struct _Coordinate
{
    int cost, x, y;
} cd;

struct cmp
{
    bool operator()(const cd &c1, const cd &c2)
    {
        return c2.cost < c1.cost;
    }
};

using namespace std;
#define MAX 301
int y_move[4] = {1, -1, 0, 0}; //상 하 x x
int x_move[4] = {0, 0, -1, 1}; // x  x 좌 우
int _visit[MAX][MAX];          //방문 확인

int solution(vector<vector<int> > land, int height)
{

    int visit_count = 0;
    priority_queue<cd, vector<cd>, cmp> pq; // cost 오름차순
    //우선순위 큐를 가장 작은 cost부터 접근하기 때문에
    //최소비용을 구할 수 있다.
    pq.push({0, 0, 0}); // 시작
    int max_count = land.size() * land.size();
    int sumOfCost = 0;
    while (visit_count < max_count) //모든 노드를 돌 때 까지
    {
        int cost = pq.top().cost; //현재 비용
        int curr_x = pq.top().x;  //현재 x
        int curr_y = pq.top().y;  //현재 y

        pq.pop();
        if (_visit[curr_x][curr_y] == 1)
            continue; //방문했다면 다시
        cout << curr_x << " " << curr_y << endl;
        _visit[curr_x][curr_y] = 1; //방문
        visit_count++;              //방문한 노드 수 증가
        sumOfCost += cost;          //비용 증가

        int curr_height = land[curr_x][curr_y]; //현재 높이

        for (int i = 0; i < 4; i++) //상하좌우 4번
        {
            int next_x = curr_x + x_move[i];
            int next_y = curr_y + y_move[i];

            if (next_x < 0 || next_x >= land.size() || next_y < 0 || next_y >= land.size())
            //벗어났을 때 다시
            {
                continue;
            }

            int next_height = land[next_x][next_y]; //다음 높이

            int height_gap = abs(next_height - curr_height); //높이차

            if (height_gap > height) //높이차가 크다면
            {
                pq.push({height_gap, next_x, next_y}); //비용이 높이차, 다음 노드 좌표
                continue;
            }
            pq.push({0, next_x, next_y}); //비용 없음 0, 다음 좌표
        }
    }
    return sumOfCost;
}