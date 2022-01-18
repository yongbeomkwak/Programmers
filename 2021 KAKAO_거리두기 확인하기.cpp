#include <bits/stdc++.h>

using namespace std;

int x_move[]={1,0,-1,0}; //우 하 좌 상
int y_move[]={0,1,0,-1}; 

typedef struct _Info{
    int x,y,d; //x좌표 y좌표 거리
}info;

bool bfs(const vector<string>& map,const int x,const int y)
{
    
    bool visit[5][5]={false,}, flag=true; // 방문배열,조건을 만족 했나?
    
    queue<info> q; 
    q.push({x,y,0}); 
    visit[x][y]=true;
    
    while(!q.empty())
    {
        int curr_x=q.front().x; //현재 좌표와 거리
        int curr_y=q.front().y;
        int curr_d=q.front().d;
        q.pop();
        
        
        for(int i=0;i<4;i++)
        {
            int next_x=curr_x+x_move[i]; // 다음 x
            int next_y=curr_y+y_move[i]; // 다음 y
            int next_d=curr_d+1; //현재거리 +1 
            if(next_x<0 ||next_x>=5 || next_y<0 || next_y>=5) continue; //범위를 벗어나면 continue
            if(visit[next_x][next_y]||map[next_x][next_y]=='X') continue; //이미 방문했거나 X(가림막일 경우) 
            if(map[next_x][next_y]=='P') //사람이 앉앗을 경우
            {
                if(next_d<=2) //맨해튼 거리가 2보다 작을 경우 
                {
                    flag=false; //false
                    break;
                }
            }
            visit[next_x][next_y]=true; //방문 후 
            q.push({next_x,next_y,next_d});// 다음꺼 큐에 삽입
                
            
        }
        if(!flag) break; //안에 for문을 break으로 빠져 나왔으면 현재 반복문도 빠져나옴
        
    
    }
  
   
      
    
  return flag;      
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(auto& p:places)
    {
        bool flag=true;
        for(int i=0;i<5;i++) //행
        {
            for(int j=0;j<5;j++) //열
            {
                if(p[i][j]=='P') //현재 P일 경우 bfs
                {
                    if(!bfs(p,i,j))
                    {
                        flag=false;
                        break;
                    }
                }
            }
            if(!flag) break; //만약 거리두기 어긴거 찾았을 때 탈출
        }
        if(flag) answer.push_back(1); //거리두기 어긴 사람 없으면 1
        else answer.push_back(0); //있으면 0삽입
    }
    return answer;
}