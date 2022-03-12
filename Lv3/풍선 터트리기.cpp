#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> a)
{
    int answer = 0;
    const int len = a.size();
    vector<int> check(len, 1);
    int now = 0;

    for (int i = 0; i < len; i++)
    {
        if (i == 0)
        {
            now = a[i];
            check[i] = 0;
        }
        else
        {
            if (now > a[i])
            {
                now = a[i];
                check[i] = 0;
            }
        }
    }

    for (int i = len - 1; i > 0; i--)
    {
        if (i == len - 1)
        {
            now = a[i];
            check[i] = 0;
        }
        else
        {
            if (now > a[i])
            {
                now = a[i];
                check[i] = 0;
            }
        }
    }

    answer = count(check.begin(), check.end(), 0);

    return answer;
}