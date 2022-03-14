#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;
#define MAX 101

typedef struct ROBOT
{
    int x, y, cost, dir;
} robot; // N,N에 가까운 로봇의 좌표

enum DIR
{
    HOR,
    VER
};
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
bool visit[MAX][MAX][2]; // x,y,DIR
vector<vector<int>> map;

bool check(int x, int y, int dir)
{ // map밖으로 나가거나, 벽에 부딪히면 false
    int N = map.size();
    if (dir == 0)
    { //가로일때
        if (x < 0 || y < 0 || x >= N || y + 1 >= N)
            return false;
        if (map[x][y] || map[x][y + 1])
            return false;
    }
    else
    { //세로일때
        if (x < 0 || y < 0 || x + 1 >= N || y >= N)
            return false;
        if (map[x][y] || map[x + 1][y])
            return false;
    }
    return true;
}

int solution(vector<vector<int>> board)
{

    map = board;
    memset(visit, 0, sizeof(visit));
    const int N = board.size();
    queue<robot> q;
    //시작 (0,0) (0,1)
    q.push({0, 0, 0, 0}); // N-1,N-1에서 먼 쪽을 선택

    while (!q.empty())
    {
        robot now = q.front();
        q.pop();

        //만약 방향이 가로 형태이고 x는 마지막 전 열,y는 끝행이면 도착한 것
        // o o o o
        // o o o o
        // o o o o
        // o o X X (N-2) (N-1)
        //만약 세로이면 x는 마지막열 y는  마지막 전 행 이면 도착한 것
        if ((now.dir == HOR && now.x == N - 1 && now.y == N - 2) || (now.dir == VER && now.x == N - 2 && now.y == N - 1))
            return now.cost;

        for (int i = 0; i < 4; i++) //기본 이동 (상,하,좌,우)
        {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            int ncost = now.cost + 1;
            //바깥으로 나가거나 벽에 걸리거나 이미 방문햇으면 continue
            if (!check(nx, ny, now.dir) || visit[nx][ny][now.dir])
                continue;
            visit[nx][ny][now.dir] = 1;
            q.push({nx, ny, ncost, now.dir});
        }

        //회전(그림 파일을 참고 )
        // 1.회전하는 반경 범위를 넘었나?
        // 2.회전하는 과정에 벽이있나?
        // 3.회전완료 지점이 벽이있나?
        // 4.이전 방문 기록이 있나(이 부분을 그림으로 굉장히 집중해서 보자)
        const int x = now.x;
        const int y = now.y;
        if (now.dir == HOR) //가로, (1-2인 상태)
        {
            // 1번이 이동

            /*
             1-2 ->  2 형태로
                     1
            */
            //가로에서 세로 형태로 되므로 vist[][][1]이 됨
            if (x + 1 < N && !map[x + 1][y] && !map[x + 1][y + 1] && !visit[x][y + 1][1])
            {
                q.push({x, y + 1, now.cost + 1, 1});
            }
            if (x - 1 >= 0 && !map[x - 1][y] && !map[x - 1][y + 1] && !visit[x - 1][y + 1][1])
            {
                q.push({x - 1, y + 1, now.cost + 1, 1});
            }

            if (x + 1 < N && !map[x + 1][y + 1] && !map[x + 1][y] && !visit[x][y][1])
            {
                q.push({x, y, now.cost + 1, 1});
            }

            if (x - 1 >= 0 && !map[x - 1][y + 1] && !map[x - 1][y] && !visit[x - 1][y][1])
            {
                q.push({x - 1, y, now.cost + 1, 1});
            }
        }
        else //세로, (1이 위, 2가 아래인 상태)
        {
            /*
             1
                 ->  1 2  2 1
             2

            */

            // 1번이 이동
            if (y - 1 >= 0 && !map[x][y - 1] && !map[x + 1][y - 1] && !visit[x + 1][y - 1][0])
            {
                q.push({x + 1, y - 1, now.cost + 1, 0});
            }
            if (y + 1 < N && !map[x][y + 1] && !map[x + 1][y + 1] && !visit[x + 1][y][0])
            {
                q.push({x + 1, y, now.cost + 1, 0});
            }

            // 2번 이동

            if (y - 1 >= 0 && !map[x + 1][y - 1] && !map[x][y - 1] && !visit[x][y - 1][0])
            {
                q.push({x, y - 1, now.cost + 1, 0});
            }
            if (y + 1 < N && !map[x + 1][y + 1] && !map[x][y + 1] && !visit[x][y][0])
            {
                q.push({x, y, now.cost + 1, 0});
            }
        }
    }
}