#include <bits/stdc++.h>

using namespace std;

long long dp[21] = {
    0,
};

vector<int> answer;

vector<int> solution(int n, long long k)
{
    vector<int> num;
    long long now = k;

    for (int i = 1; i <= 20; i++)
    {
        num.push_back(i);
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1] * i;
    }

    while (1)
    {
        // n=3  k=5
        // 1 2 3 , 가장 앞자리가 고정 됬을 때 2 두자리는 2! 가지수 가있음
        // 그래서  n=3 일 때 dp[n-1]
        // k(now)-1은 인덱싱을 위해 , num[0]=1

        if (n == 0)
            break;                         //더 이상 채울 수가 벗을 시
        const long long slice = dp[n - 1]; // 가장 앞 한 도막을 제외한 도막 수
        const int idx = (now - 1) / slice;
        answer.push_back(num[idx]); //해당 요소 사용
        
        num.erase(num.begin() + idx); //해당 요소 삭제

        n--;
        now %= slice; //앞에 숫자를 지정하고 나면 그 수 앞수들의 조합을 제거 해준다.
        // ex) 1 x x x 면  x x x 부분을 구할 때 1은 사용 되면 안되므로
        if (now == 0)
            now = slice; //나눠질 경우 가장 해당 도막의 가장 끝 값이므로 그대로 전달
    }

    return answer;
}