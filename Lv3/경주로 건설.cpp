#include <bits/stdc++.h>

using namespace std;

#define INF 9876543
//직진 100 코너 500

enum DIR
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

int x_move[] = {0, 0, -1, 1}; // 상 하 좌 우
int y_move[] = {-1, 1, 0, 0};

typedef struct _INFO
{
    int x, y, cost, dir;
} info;

int solution(vector<vector<int>> board)
{

    int answer = INF;

    int size = board.size();
    vector<vector<vector<int>>> cost(size, vector<vector<int>>(size, vector<int>(4, INF)));
    // [x][y][바라보는 방향] 상하좌우
    //
    cost[0][0][0] = 0;
    cost[0][0][1] = 0;
    cost[0][0][2] = 0;
    cost[0][0][3] = 0;
    queue<info> q;

    q.push({0, 0, 0, -1}); // x:0 ,y:0 cost:0 dir: 0 가로, 1:세로

    while (!q.empty())
    {
        int now_x = q.front().x;
        int now_y = q.front().y;
        int now_cost = q.front().cost;
        int now_dir = q.front().dir;
        q.pop();

        for (int i = 0; i < 4; i++) // 0:상 1:하 2:좌 3:우
        {
            int next_x = now_x + x_move[i];
            int next_y = now_y + y_move[i];
            int next_dir = i;
            int next_cost = now_cost;

            if (next_x < 0 || next_y < 0 || next_x >= size || next_y >= size)
                continue;
            //범위 이탈
            if (board[next_x][next_y] == 1)
                continue; //벽

            next_cost += 100; //직진 코스 100 코너 600

            if (now_dir == UP || now_dir == DOWN) // 코너 일 경우
            {
                if (next_dir == LEFT || next_dir == RIGHT)
                    next_cost += 500;
            }
            if (now_dir == LEFT || now_dir == RIGHT)
            {
                if (next_dir == UP || next_dir == DOWN)
                    next_cost += 500;
            }

            if (cost[next_x][next_y][next_dir] > next_cost)
            {
                q.push({next_x, next_y, next_cost, next_dir});
                cost[next_x][next_y][next_dir] = next_cost;
            }
        }
    }

    answer = *min_element(cost[size - 1][size - 1].begin(), cost[size - 1][size - 1].end());

    return answer;
}