#include <bits/stdc++.h>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl; 
    
    while(a!=b)
    {
        if(a%2!=0) a=(a+1)/2;
        else a/=2;
        
        if(b%2!=0) b=(b+1)/2;
        else b/=2;
        
        answer++;
    }

    return answer;
}
