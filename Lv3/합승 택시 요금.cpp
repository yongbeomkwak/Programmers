#include <bits/stdc++.h>

using namespace std;
#define MAX 201
#define INF 9876543

int adj[MAX][MAX];  //글로벌로 선언하여 초기값 0 (간선)
int Prev[MAX][MAX]; //[i][j] j도착시  j 직전 노드

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    //플로이드 와샬 생각
    int answer = 0;

    for (int i = 1; i <= n; i++) //플로이드 와샬 초기화
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            else
                adj[i][j] = INF; //출발(i)와 도착지점(j)이 다르면 INF
        }
    }

    for (vector<int> &edge : fares)
    {
        int u, v, c;
        u = edge[0];
        v = edge[1];
        c = edge[2];
        adj[u][v] = c; // 방향 상관 없이 같은 코스트
        adj[v][u] = c;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                //플로이드 와샬
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    int cost = INF;
    for (int i = 1; i <= n; i++)
    {
        // s -> i(i까지 합승) 그러니 요금은 한번만
        // i(합승한 곳) 부터 이제 서로 다른 택시
        // i->a
        // i->b
        //총 세 요금의 최솟값을 구함
        cost = min(cost, adj[s][i] + adj[i][a] + adj[i][b]);
    }
    // cout << cost <<endl;
    // cout <<adj[s][a] << " " <<adj[s][b] <<endl;

    //합승한 가격 과 출발지 부터 따른 택시 일 때 가격
    answer = min(cost, adj[s][a] + adj[s][b]);

    return answer;
}