#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, long long left, long long right)
{
    vector<int> answer;

    // 0 1 2 3 4 5 6 7 8 l:2 r:5
    // 1 2 3 2 2 3 3 3 3

    // 0 1 2 3 4 5 6 7 8 9 10 12 13 14 15 15  l:7 r:14
    // 1 2 3 4 2 2 3 4 3 3  3  4  4  4  4  4

    while (left <= right)
    {
        answer.push_back(max(left / n, left % n) + 1);
        left++;
    }

    return answer;
}