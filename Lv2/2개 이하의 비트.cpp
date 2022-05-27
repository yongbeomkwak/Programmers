#include <bits/stdc++.h>

using namespace std;

vector<long long> solution(vector<long long> numbers)
{
    vector<long long> answer;

    for (long long n : numbers)
    {
        if (n % 2 == 0)
            answer.push_back(n + 1);
        else
        {
            long long bit = 1;
            while (1)
            {
                if ((bit & n) == 0)
                    break;
                bit <<= 1; //계속 왼쪽으로 밀면서 틀릴 때 까지
            }
            bit >>= 1;
            answer.push_back(n + bit);
        }
    }

    // cout << bitset<50>(1000000000000000).to_string();

    return answer;
}