#include <bits/stdc++.h>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(string& s:skill_trees)
    {
        unordered_map<char,int> um;
        for(int i=0;i<s.length();i++)
        {
            um[s[i]]=i+1; //해당 스킬의 위치를 기억 
        }
        bool flag=true;
        int prev=-1;  //이전 스킬 위치
        for(const char& c:skill)
        {
            if(um[c]==0) //0이면 스킬트리에 없다는 뜻 
            {
                prev=s.length()+1;//가장 큰 값
                continue;
            }
            
            if(prev>um[c]) //이전 스킬이 현재 스킬보다 크다(나중에 찍혔다)
            {
                flag=false; //실패 
                break;
            }
            prev=um[c];
            
            
        }
        if(flag) answer++; //성공이면 증가
        
    }
    return answer;
}