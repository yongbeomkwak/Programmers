#include <bits/stdc++.h>

using namespace std;

#define MULTI 65536

int _min(const int a,const int b){return a<b?a:b;}
int _max(const int a,const int b){return a>b?a:b;}

int state(const char c) 
{
    int ret=0;
    if('a'<=c && c<='z') ret=1; // 소문자일 경우 state 값 1
    if('A'<=c && c<='Z') ret=2;// 대문자일 경우 state 값 2
    return ret;
}


int solution(string str1, string str2) {
    int answer = 0;
    unordered_map<string,int> A;
    unordered_map<string,int> B;
    vector<string> total;
    for(int i=0;i<str1.length()-1;i++) //length-2까지 돔 
    {
        char c1=str1[i];
        char c2=str1[i+1];
        int state1=state(c1);
        int state2=state(c2);
        if(state1==1){ //소문자일 경우 state를 2로 바꾸며 대문자로 바꾼다
            state1=2;
            c1=toupper(c1); //대문자 변환
        }
        if(state2==1) //소문자일 경우 state를 2로 바꾸며 대문자로 바꾼다
        {
            c2=toupper(c2);
            state2=2;
        }
        if(state1==2 && state2==2)
        {
            string temp;
            temp+=c1;
            temp+=c2;
            //한번도 삽입이 안됬을 때만 넣음 (중복 없이)
            if(A[temp]==0) total.push_back(temp);
            A[temp]++; //카운트는 계속
        }
    }
    
    for(int i=0;i<str2.length()-1;i++)
    {
        char c1=str2[i];
        char c2=str2[i+1];
        int state1=state(c1);
        int state2=state(c2);
        
        if(state1==1){ //소문자일 경우 state를 2로 바꾸며 대문자로 바꾼다
            state1=2;
            c1=toupper(c1);
        }
        if(state2==1) //소문자일 경우 state를 2로 바꾸며 대문자로 바꾼다
        {
            c2=toupper(c2);
            state2=2;
        }
        if(state1==2 && state2==2)
        {
            string temp;
            temp+=c1;
            temp+=c2;
            //한번도 삽입이 안됬을 때만 넣음 (중복 없이)
            if (A[temp] == 0 && B[temp] == 0)total.push_back(temp);
            B[temp]++; //카운트는 계속 
        }
    }
    
    if(total.size()==0) return MULTI;
    
    int Union=0,Intersection=0;
    
    for(int i=0;i<total.size();i++)
    {
        string temp=total[i];
        Union+=_max(A[temp],B[temp]);
        Intersection+=_min(A[temp],B[temp]);
    }
    
    answer=MULTI * (double(Intersection)/Union);
    
    
    return answer;
}