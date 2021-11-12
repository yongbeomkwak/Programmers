#include <bits/stdc++.h>

#define MAX 16
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    vector<string> map1;
    vector<string> map2;
    
    
    for(int i=0;i<n;i++)
    {
        //MAX=16 bitset<MAX>(십진수).to_string() -> MAX비트 로 해당 십진수를 이진수로 변경 후 문자열 리턴 ,현재는 16비트로 
        map1.push_back(bitset<MAX>(arr1[i]).to_string());
        map2.push_back(bitset<MAX>(arr2[i]).to_string());
    }
    
    // st:MAX-n+1  end=MAX-1
    
    for(int i=0;i<n;i++)
    {
        map1[i]=map1[i].substr(MAX-n,n); 
        //n=5면 5자리 필요 위에서 MAX=16 자리로 바꿨기 때문에, 인덱스 11부터 5개 11,12,13,14,  15 까지 자름 , 16비트를 5비트로 
        map2[i]=map2[i].substr(MAX-n,n);
    }
    
    for(int i=0;i<n;i++)
    {
        string ret;
        for(int j=0;j<map1.size();j++)
        {
            if(map1[i][j]=='0' && map2[i][j]=='0') //두 맵 모두 벽이 아니면
            {
                ret+=" "; //공백 추가
                continue;
            }
            ret+="#"; //하나라도 벽일 경우 벽 추가
        }
        answer.push_back(ret);
    }
    
    for(int i=0; i<answer.size();i++)
    {
        cout << answer[i] <<endl;
    }
    
    return answer;
}