#include <bits/stdc++.h>
using namespace std;

#define MAX 100001

/*int max(const int a,const int b,const int c)
{
    int ret=a;
    ret=b>ret? b : ret;
    ret=c>ret? c : ret;
    return ret;
}*/

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int len = land.size();
    vector<vector<int> > dp(MAX, vector<int>(4, 0));
    dp[0][0] = land[0][0];
    dp[0][1] = land[0][1];
    dp[0][2] = land[0][2];
    dp[0][3] = land[0][3];

    for (int i = 1; i < len; i++)
    {
        dp[i][0] = max({dp[i - 1][1], dp[i - 1][2], dp[i - 1][3]}) + land[i][0];
        dp[i][1] = max({dp[i - 1][0], dp[i - 1][2], dp[i - 1][3]}) + land[i][1];
        dp[i][2] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][3]}) + land[i][2];
        dp[i][3] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + land[i][3];
    }

    answer = *max_element(dp[len - 1].begin(), dp[len - 1].end());
    return answer;
}