#include <bits/stdc++.h>

using namespace std;
#define DIV 1000000007
#define MAX 100001
int dp[MAX] = {
    0,
};

int solution(int n, vector<int> money)
{
    int answer = 0;
    int len = money.size();
    dp[0] = 1; // 0원 경우의 수

    for (const int &coin : money)
    {
        for (int price = coin; price <= n; price++) //해당 동전부터 n까지 모두 만듬
        {
            if (price >= coin)
                dp[price] += dp[price - coin]; //해당 price를 해당 coin을 사용해서 만들 수 있는 경우의 수
        }
    }

    return dp[n];
}