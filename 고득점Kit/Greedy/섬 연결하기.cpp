#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> p;
#define INF 987654321

int prim(const int start,vector<vector<p>>& graph)
{
    vector<bool> visit(graph.size(),false);
     priority_queue<p,vector<p>,greater<p>> pq;
    pq.push({start,0});
    int ret=0;
    
    while(!pq.empty())
    {
        int dept=pq.top().second;
        int dist=pq.top().first;
        pq.pop();
        
        
        if(visit[dept]) continue;
      
        visit[dept]=1;
        ret +=dist;

        for(int i=0;i<graph[dept].size();i++)
        {
               int dest=graph[dept][i].second;
               int dist=graph[dept][i].first;
                
                if(!visit[dest]) pq.push({dist,dest});
                
        }
        
    }
   // cout << start << " " << ret <<endl;
    return ret;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = INF;
    vector<vector<p>> graph(n);
    
    for(int i=0;i<costs.size();i++)
    {
        int start=costs[i][0];
        int dest=costs[i][1];
        int dist=costs[i][2];
        graph[start].push_back({dist,dest});
        graph[dest].push_back({dist,start});
    }
    
    for(int i=0;i<n;i++) //모든 섬을 출발로 prim 알고리즘 돌림
    {
        answer=min(answer,prim(i,graph));
    }
    
    
    return answer;
}