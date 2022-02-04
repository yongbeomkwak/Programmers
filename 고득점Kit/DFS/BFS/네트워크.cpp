#include <bits/stdc++.h>

using namespace std;

#define MAX 201

int adj[MAX][MAX];

bool dfs(vector<vector<int> > &computers, const int n)
{
    if (!computers[n][n])
        return false;    // 이미 방문한 노드 였으면 탈출
    computers[n][n] = 0; //방문 했으므로 0으로

    for (int i = 0; i < computers.size(); i++)
    {
        if (computers[n][i]) // n과 연결된 노드가 있다면 탐색
        {
            dfs(computers, i);
        }
    }
    return true;
}

int solution(int n, vector<vector<int> > computers)
{
    int answer = 0;

    for (int i = 0; i < computers.size(); i++) //모든 노드에서 탐색
    {
        // computers[i][i]: 첫 방문이며
        // i와  연결되어있는 네트워크 탐색
        if (computers[i][i] && dfs(computers, i))
            answer++;
    }

    return answer;
}