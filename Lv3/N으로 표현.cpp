#include <bits/stdc++.h>

using namespace std;
unordered_set<int> dp[9];
int get_Ns(int N, int idx) { // 1,11,111 숫자 이어 붙이기
    int result = N;
    
    for (int i = 1; i < idx; i++) { 
        result = result * 10 + N; 
    } 
    
    return result; 
} 
int solution(int N, int number) {
    if(N==number) return 1;
    int ans=-1;
    dp[1].insert(N); //1개를 써서 만들 수 있는 건 N뿐 
    
    for(int l=2;l<=8;l++) //길이 2~8 까지
    {
        dp[l].insert(get_Ns(N,l)); //해당 길이 이어붙이는 수 먼저 삽입
        for(int i=1;i<l;i++) //길이 1부터 l전까지
        {
            for(int j=1;j<l;j++) //길이 1부터 l전까지
            {
                if(i+j!=l) continue; //두 서브 길이의 합이 l이 아니면 다시
                
                for(const int& a:dp[i])
                {
                    for(const int& b:dp[j])
                    {
                        dp[l].insert(a+b);
                        dp[l].insert(a*b);
                        if(a>b) // 음수 존재 방지
                        {
                            dp[l].insert(a-b);
                        }
                        if((a/b)>0) //0 존재 방지
                        {
                            dp[l].insert(a/b);    
                        }
                        
                    }
                }
            }
        }
        if(dp[l].find(number)!=dp[l].end()) return l; //만약 찾으면 l
    }
    
    return ans; //없으면 -1
}
