#include <bits/stdc++.h>
using namespace std;

#define MAX 101
#define INF 10001
typedef pair<int, int> p;

int x_move[] = {0, 0, 1, -1};
int y_move[] = {1, -1, 0, 0};
int dist[MAX][MAX];

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    fill(&dist[0][0], &dist[MAX - 1][MAX], INF);

    const int N = maps.size() - 1;
    const int M = maps[0].size() - 1;
    queue<p> q;
    dist[0][0] = 1; //출발 1
    q.push({0, 0});

    while (!q.empty())
    {
        int curr_x = q.front().first;
        int curr_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int next_x = curr_x + x_move[i];
            int next_y = curr_y + y_move[i];

            if (next_y < 0 || next_y > N || next_x < 0 || next_x > M)
                continue;

            if (maps[next_y][next_x] == 0)
                continue;

            if (dist[next_y][next_x] > dist[curr_y][curr_x] + 1)
            {

                dist[next_y][next_x] = dist[curr_y][curr_x] + 1;
                q.push({next_x, next_y});
            }
        }
    }

    if (dist[N][M] == INF)
        return -1; //탐색 후에도 그대로 INF면
    else
        return dist[N][M]; //출발

    return answer;
}