#include <bits/stdc++.h>

#define endl "\n"
using namespace std;

//A~Z가 27 ,
int cnt[27]; // cnt[i]=n : 길이가 i인 조합 중 최대 주문 횟수는 n번
unordered_map<string,int> um; // um[str]=n : 조합 str의 주문 횟수는 n번
vector<string> menu[27][21]; // menu[i][j] : 길이가 i이고 j번 주문된 조합들의 목록

void print(string s)
{
    for(const char& c:s)
    {
        cout << c << " ";
    }
    cout <<endl;
}

int _max(const int a,const int b)
{
    return a>b ? a : b;
}

void comb(string s, int index, string made)
{
    if(made.size()>1) //두개 이상 주문됬다면
    {
        um[made]++; //해당 메뉴 주문 횟수 증가
         cnt[made.size()]=_max(cnt[made.size()],um[made]); // 조합 길이 별 최대 주문 횟수 갱신
        menu[made.size()][um[made]].push_back(made); 
        //[i][j]메뉴 조합 길이가 i면서 j번 주문 한 메뉴에 made 추가 
    }
    
    
    //백트래킹
    for(int i=index+1;i<s.size();i++)
    {
    
        made.push_back(s[i]);
        comb(s,i,made);
        made.pop_back();
    }
    
   
    
    
}



vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(string& s:orders)
    {
        sort(s.begin(),s.end());//문자를  오름차순
        comb(s,-1,""); //빈문자열로 시작하여 해당 문자열 s로 만들 수 있는 모든 경우의 조합 탐색 
    }
    
     // 쿼리 수행
    for(int i:course)
        if(cnt[i]>1) // 길이가 i인 조합의 최대 주문 횟수가 1 이상인 경우만
            for(string s:menu[i][cnt[i]])
                answer.push_back(s);
    
    sort(answer.begin(),answer.end()); //사전 순 정렬 
    
    return answer;
}