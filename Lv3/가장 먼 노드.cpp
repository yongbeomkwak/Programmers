#include <bits/stdc++.h>

using namespace std;
#define MAX 20001
#define P pair<int,int>
vector<int> dist(MAX,987654321);
vector<int> graph[MAX];
int max_dist=0;
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    //다익스트라 이용 
    
    for(int i=0;i<edge.size();i++)
    {
        int a=edge[i][0];
        int b=edge[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    priority_queue<P,vector<P>,greater<P>> pq;
    pq.push({0,1});
    dist[1]=0;
    
    while(!pq.empty())
    {
        int dis=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        
        for(int i=0;i<graph[node].size();i++)
        {
            int n_dist=dis+1;
            int n_node=graph[node][i];
            
            if(dist[n_node]>n_dist)
            {
                pq.push({n_dist,n_node});
                dist[n_node]=n_dist;
                max_dist=max_dist<n_dist ? n_dist : max_dist;
            }
        }
    }
    cout << max_dist <<endl;
    for(int i=2;i<=n;i++)
    {
        if(dist[i]==max_dist) answer++;
    }
    
    
    return answer;
}
