#include <bits/stdc++.h>

using namespace std;

#define MAX 20001

vector<int> graph[MAX];

void print(const vector<int> &v)
{
    for (const int &i : v)
    {
        cout << i << " ";
    }
}

int solution(int n, vector<vector<int> > edge)
{
    int answer = 0;

    for (const vector<int> nodes : edge)
    {
        graph[nodes[0]].push_back(nodes[1]); //양방향 연결
        graph[nodes[1]].push_back(nodes[0]);
    }
    vector<int> dist(n + 1, INT_MAX); //최소 거리 벡터
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq; //다익스트라 (first:거리 값이 작은 것이 위에 오도록)

    pq.push({0, 1}); //출발지점 거리 0,노드번호 1

    dist[1] = 0; //출발지점 거리 0
    while (!pq.empty())
    {
        int u = pq.top().second; //현재 노드
        int u_dist = pq.top().first;
        pq.pop();

        for (int i = 0; i < graph[u].size(); i++) //인접 그래프
        {
            int v = graph[u][i]; //인접 v 값
            int w = u_dist + 1;  // 현재 거리 +1
            if (dist[v] > w)     //현재노드 +1 이 현재 v의 거리보다 작다면
            {
                dist[v] = w;     //값 변경
                pq.push({w, v}); //삽입
            }
        }
    }

    // print(dist);

    int largest_val = *max_element(dist.begin(), dist.end()); //최댓값 찾기

    for (const int &val : dist)
    {
        if (val == largest_val)
            answer++;
    }

    return answer;
}