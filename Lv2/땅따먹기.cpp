#include <bits/stdc++.h>
using namespace std;
int answer = 0;
#define MAX 100001

int dp[MAX][4];

int solution(vector<vector<int>> land)
{
    const int n = land.size();
    dp[0][0] = land[0][0];
    dp[0][1] = land[0][1];
    dp[0][2] = land[0][2];
    dp[0][3] = land[0][3];

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = max({dp[i - 1][1], dp[i - 1][2], dp[i - 1][3]}) + land[i][0];
        dp[i][1] = max({dp[i - 1][0], dp[i - 1][2], dp[i - 1][3]}) + land[i][1];
        dp[i][2] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][3]}) + land[i][2];
        dp[i][3] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + land[i][3];
    }

    return max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2], dp[n - 1][3]});
}