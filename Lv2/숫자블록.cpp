#include <bits/stdc++.h>

using namespace std;
#define MAX 10000000
int task(long long n)
{
    int end = sqrt(n);
    int ret = 1;
    for (int i = 2; i <= end; i++)
    {
        int div = n / i;
        if (n % i == 0 && div <= MAX)
        {
            ret = div;
            break;
        }
    }
    return ret;
}

vector<int> solution(long long begin, long long end)
{
    vector<int> answer(end - begin + 1, 0);

   
    int idx = 0;

    for (long long start = begin; start <= end; start++)
    {
        if (start != 1)
            answer[idx] = task(start);
        idx++;
    }

    return answer;
}