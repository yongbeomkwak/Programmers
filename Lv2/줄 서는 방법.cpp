#include <bits/stdc++.h>

using namespace std;
long long fact[21] = {0};
int used[21] = {
    0,
};
vector<int> solution(int n, long long k)
{
    vector<int> answer, numbers;
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fact[i] = fact[i - 1] * i;
        numbers.push_back(i);
    }
    if (k == 1)
        return numbers;

    k--; //인덱스와 숫자를 매칭시키기 위해
    long long prev = fact[n - 1];
    long long div, mod;
    while (numbers.size() != 1)
    {
        mod = k % prev;
        div = k / prev;
        answer.push_back(numbers[div]);
        numbers.erase(numbers.begin() + div); //핵심은 사용한 숫자를 빼주는 것

        k = mod;

        n--;
        prev /= n;
    }
    answer.push_back(numbers[0]);

    return answer;
}