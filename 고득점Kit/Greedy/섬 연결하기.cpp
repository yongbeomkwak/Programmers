#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> p;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<vector<p>> graph(costs.size());
    vector<bool> visit(costs.size(),false);
    for(int i=0;i<costs.size();i++)
    {
        int start=costs[i][0];
        int dest=costs[i][1];
        int dist=costs[i][2];
        graph[start].push_back({dist,dest});
    }
    
    priority_queue<p,vector<p>,greater<p>> pq;
    pq.push({0,0});
    
    while(!pq.empty())
    {
        int dept=pq.top().second;
        int dist=pq.top().first;
        pq.pop();
        
        
        if(visit[dept]) continue;
      
        visit[dept]=1;
        answer +=dist;
        cout << dept << " "<<dist << " " <<answer << endl;
        for(int i=0;i<graph[dept].size();i++)
        {
               int dest=graph[dept][i].second;
               int dist=graph[dept][i].first;
                
                if(!visit[dest]) pq.push({dist,dest});
                
        }
        
    }
    
    
    return answer;
}