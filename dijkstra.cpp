#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define P pair<int, int>
typedef vector<vector<P> > vvp;
typedef vector<int> vi;
int solution(int N, vector<vector<int> > road, int K)
{
    int answer = 0;
    vvp adj(N + 1);
    vi dist(N + 1, INF);
    for (int i = 0; i < road.size(); i++)
    {
        int src = road[i][0];
        int dest = road[i][1];
        int cost = road[i][2];
        adj[src].push_back({cost, dest});
        adj[dest].push_back({cost, src});
    }

    priority_queue<P, vector<P>, greater<P> > pq;
    pq.push({0, 1});
    dist[1] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        int u_dist = pq.top().first; //u 누적거리
        pq.pop();

        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].second;
            int w = adj[u][i].first;
            if (dist[v] > u_dist + w) // v 누적거리가 u누적 거리+w 보다 크다면
            {
                dist[v] = u_dist + w;
                pq.push({dist[v], v}); //힙에 삽입
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        cout << dist[i] << endl;
        if (dist[i] <= K)
            answer++;
    }

    return answer;
}