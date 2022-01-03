#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int f_min(const int a,const int b)
{
    return a<b ? a : b;
}

int solution(string s) {
    int len=s.length();
    int answer = len;
    int n=len/2;
  
    for(int i=1;i<=n;i++) //문자열을 자를 길이 
    {
        string conv,pattern;
        
        pattern=s.substr(0,i); //처음부터 i개 까지 패턴 설정 
        int cnt=1;
        for(int j=i;j<=len;j+=i) //패턴 길이만큼 건너뛰며 확인
        {
            if(pattern==s.substr(j,i)) //j부터 i개를 짜른게 패턴과 같다면
            {
                cnt++;
            }
            else //같지 않으면 이제 처리를 해줘야함
            {
                if(cnt==1) //만약 1이라면 자신을 제외한 패턴이 없는 것
                {
                    conv+=pattern; //abc
                }
                else
                {
                    conv+=(to_string(cnt) + pattern); //2abc
                }
                
                pattern=s.substr(j,i); //패턴 변경 
                cnt=1; // 카운트 초기화 
            }
        }
        
        if((len%i)!=0) //i(해당 패턴 길이) 패턴 길이로 전체 문자열 길이가 나누어 떨어지지 않으면 잔여 문자 존재 
        {
            //(len/i) *i -> 아직 확인하지 않은 끝부분 시작 점
            //len/i = 문자열/해당 패턴 길이 
            cout << "len(pattern): " << i <<endl;
            cout << s.substr((len / i)*i) << " " << len <<endl;
            conv+=s.substr((len / i)*i,len); //
        }
        
       if(answer>conv.length()) answer=conv.length();// 길이 최솟 값
    }
   
    return answer;
}