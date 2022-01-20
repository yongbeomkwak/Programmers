#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
char num[]={'0','1','2','3','4','5','6','7','8','9'};

void print(vector<string>v)
{
    for(const string& i:v)
    {
        cout << i << endl;
    }
}

string invert(int n,const int k)
{
    string R_value="";
    while(n/k!=0) //몫이 0 이상이면  
    {
        string tmp=R_value;
        R_value=num[n%k];
        R_value+=tmp;
        n/=k;
    }
    string tmp=R_value;
    R_value=num[n%k];
    R_value+=tmp;
    return R_value;
}

bool isPrime(const string str)
{
    long num=stol(str); 

    if(num==1) return false;
    
    int end=(int)sqrt((double)num);
    
    bool ret=true;
    
    for(int i=2;i<=end;i++)
    {
        if(num%i==0)
        {
            ret=false;
            break;
        }
    }
    
    return ret;
}


int solution(int n, int k) {
    int answer = 0;
    string inv= invert(n,k); //해당 진법으로 변환 
    vector<int> pos;
    const char * str=inv.c_str(); // char 포인터로 변환 후

    char *pch = strchr(str, '0'); //'0' 위치를 찾음
 
    
    while(pch!=NULL)
    {
        //cout << pch <<endl;
        pos.push_back(pch-str); //pch는 0의 위치를 갖고 았고 이것을 출발지점 str에서 빼면 인덱스가 나온다 
        pch =strchr(pch+1, '0'); //다음 위치인 pch+1 부터 '0'을 찾기 시작
    }
    
    //pos에 0의 인덱스가 쌓인다. 
    vector<string> cands;
    int curr_pos=0;
    for(const int next:pos)
    {
        string sub=inv.substr(curr_pos,next-curr_pos); //현재 위치부터 0전까지 숫자를 문자열 형태로 저장
        curr_pos=next+1; //현재위치를 next의 다음으로 옮긴다.
        if(sub!="") cands.push_back(sub); //만약 저장한 형태가 빈문자열이 아니면 담는다.
    }
    

    string sub=inv.substr(curr_pos); //현재 위치부터 끝까지 담는다.
    //만약 pos 벡터에 저장된 요소가 없으면 처음부터 끝까지 모든 문자열이 저장된다.
    if(sub!="") cands.push_back(sub);   //마찬가지로 cands 후보 벡터에 저장 
    

    
    for(const string& s:cands) //해당 후보들을 돌면서 소수 판단하여 소수일 경우 answer증가
    {
        if(isPrime(s)) answer++;
    }
    
    
    
    
    
    
    return answer;
}