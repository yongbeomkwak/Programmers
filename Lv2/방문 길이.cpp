#include <bits/stdc++.h>
using namespace std;

#define MAX 11
set<pair<int, int> > is_visit[MAX][MAX];

int solution(string dirs)
{
    int answer = 0;
    int now_x = 5;
    int now_y = 5;

    for (const char &c : dirs)
    {
        pair<int, int> now = {now_y, now_x};
        if (c == 'U')
        {
            int next_y = now_y + 1;
            pair<int, int> next = {next_y, now_x};
            if (next_y > 10)
                continue;
            if (is_visit[next_y][now_x].find(now) == is_visit[next_y][now_x].end() && is_visit[now_y][now_x].find(next) == is_visit[now_y][now_x].end())
            {
                // cout << "U" << endl;
                answer++;
                is_visit[now_y][now_x].insert(next);
                is_visit[next_y][now_x].insert(now);
            }
            now_y = next_y;
        }
        else if (c == 'D')
        {
            int next_y = now_y - 1;
            pair<int, int> next = {next_y, now_x};
            if (next_y < 0)
                continue;
            if (is_visit[next_y][now_x].find(now) == is_visit[next_y][now_x].end() && is_visit[now_y][now_x].find(next) == is_visit[now_y][now_x].end())
            {
                // cout << "D" << endl;
                answer++;
                is_visit[now_y][now_x].insert(next);
                is_visit[next_y][now_x].insert(now);
            }
            now_y = next_y;
        }
        else if (c == 'R')
        {
            int next_x = now_x + 1;
            pair<int, int> next = {now_y, next_x};
            if (next_x > 10)
                continue;
            if (is_visit[now_y][next_x].find(now) == is_visit[now_y][next_x].end() && is_visit[now_y][now_x].find(next) == is_visit[now_y][now_x].end())
            {
                //   cout << "R" << endl;
                answer++;
                is_visit[now_y][now_x].insert(next);
                is_visit[now_y][next_x].insert(now);
            }
            now_x = next_x;
        }
        else
        {
            int next_x = now_x - 1;
            pair<int, int> next = {now_y, next_x};
            if (next_x < 0)
                continue;
            if (is_visit[now_y][next_x].find(now) == is_visit[now_y][next_x].end() && is_visit[now_y][now_x].find(next) == is_visit[now_y][now_x].end())
            {
                //  cout << "L" << endl;
                answer++;
                is_visit[now_y][now_x].insert(next);
                is_visit[now_y][next_x].insert(now);
            }
            now_x = next_x;
        }
    }

    return answer;
}