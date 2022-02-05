#include <bits/stdc++.h>

using namespace std;
#define MAX 52

int diff(const string& s1,const string& s2) // 두 문자열 틀린 개수 리턴
{
    int ret=0;
    for(int i=0;i<s1.length();i++)
    {
        if(s1[i]!=s2[i]) ret++;
    }
    return ret;
}


vector<int> near[MAX]; //해당 문자열의 인접 벡터
int visited[MAX]={0,}; //방문 
 int answer=0;
void dfs(const int idx,const int cnt,string& target,vector<string>& words)
{
    //cout << words[idx] << " " << cnt <<endl;
   if(target==words[idx])  //현재가르키는 문자가 target일 때
   {
       if(answer==0) answer=cnt; //가장 처음에 찾았을 때 answer 값 초기화
       else answer=min(answer,cnt); //최솟값
        return;
   }
    visited[idx]=1; //방문 표시 
    
    for(int i=0;i<near[idx].size();i++)
    {
        int next=near[idx][i];
        if(visited[next]!=1) //방문하지 않았으면 dfs 돌림 
            dfs(next,cnt+1,target,words);//next:다음 문자열로 넘어감,cnt+1:카운트 증가
    }
   
}

void print(vector<string> words)
{
    for(const string& s:words)
    {
         cout << s << " " ;
    }
}

int solution(string begin, string target, vector<string> words) {
    if(count(words.begin(),words.end(),target)==0) return 0; //words안에 타겟 없으면 0
    
    words.insert(words.begin(),begin); //가장 앞에 begin 삽입 
    
    for(int i=0;i<words.size();i++)
    {
        string now=words[i]; //현재 문자열
        for(int j=0;j<words.size();j++)
        {
            string next=words[j]; //다음 문자열 
            if(diff(now,next)==1) near[i].push_back(j); //해당 두 문자열의 차이가 1이면
            // i 인덱스 인접벡터에 j를 삽입
        }
    }
    dfs(0,0,target,words); // 0:begin 부터 0:cnt,target,words;
    return answer;
}