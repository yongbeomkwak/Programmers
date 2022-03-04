#include <bits/stdc++.h>

using namespace std;

#define DIV 1234567
#define MAX 2001
long long answer = 0;

long long dp[MAX] = {
    0,
};

long long solution(int n)
{

    dp[1] = 1;
    dp[2] = 2; // 11 2
               // 1 1 1, 1 2, 2 1

    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] % DIV + dp[i - 2] % DIV;
    }

    return dp[n] % DIV;
}