#include <bits/stdc++.h>

#define DIV 1000000007
#define MAX 60001

using namespace std;

int dp[MAX] = {
    0,
};

int solution(int n)
{
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 2] % DIV + dp[i - 1] % DIV;
    }

    int answer = dp[n] % DIV;
    return answer;
}