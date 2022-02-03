#include <bits/stdc++.h>

using namespace std;

#define MAX 101

int dp[MAX][MAX];
#define mod 1000000007

void init(vector<vector<int> > &puddles)
{
    for (vector<int> &puddle : puddles)
    {

        dp[puddle[1]][puddle[0]] = -1;
    }
}

int solution(int m, int n, vector<vector<int> > puddles)
{

    dp[1][1] = 1;
    init(puddles);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {

            int x = 0, y = 0;
            if (dp[i][j] == -1)
                continue; // 침수 지역
            if (dp[i][j - 1] != -1)
                x = dp[i][j - 1]; //이전 왼쪽 값
            if (dp[i - 1][j] != -1)
                y = dp[i - 1][j];      //이전 윗값
            dp[i][j] += (x + y) % mod; // 누적
        }
    }

    return dp[n][m];
}