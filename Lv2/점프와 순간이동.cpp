#include <bits/stdc++.h>
using namespace std;
#define MAX 500000001

int dp[MAX] = {
    0,
};
int dist = 0;
int divide(int n)
{

    while (n > 10)
    {
        dist += n % 2;
        n /= 2;
    }
    return n;
}

int solution(int n)
{
    int ans = 0;
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= 10; i++)
    {
        if (i % 2 == 0)
            dp[i] = dp[i / 2]; //짝수 일 경우 이전 순간이동 값
        else
            dp[i] = dp[i - 1] + 1; //아닐경우 바로 전 거리에 +1
    }
    // dp로 미리 값을 넣어놓고

    return dp[divide(n)] + dist; // n을 10이하로 내려왔을 때 n값 + 점프로 이동 한 수
}