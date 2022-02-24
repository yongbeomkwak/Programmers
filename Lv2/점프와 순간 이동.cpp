#include <bits/stdc++.h>
using namespace std;

#define MAX 500000000
int dp[MAX] = {
    0,
};
bool twoN(int num)
{
    return (num & (num - 1)) == 0;
}

int solution(int n)
{
    int ans = 0;
    if (twoN(n))
        return 1;
    while (n != 0)
    {

        if (n % 2 == 0)
            n /= 2;
        else
        {
            ans++;
            n -= 1;
        }
    }
    return ans;
}