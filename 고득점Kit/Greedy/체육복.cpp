#include <bits/stdc++.h>

using namespace std;

bool cmp(const int n)
{
    return n >= 1;
}

void print(vector<int> a)
{
    for (const int i : a)
    {
        cout << i << " ";
    }
}
int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;
    vector<int> stu(n, 1);
    for (const int &i : reserve)
    {
        stu[i - 1] = 2;
    }
    for (const int &i : lost)
    {
        stu[i - 1]--;
    }

    for (int i = 0; i < n; i++)
    {
        int prev = i - 1;
        int next = i + 1;
        if (i > 0 && stu[i] == 0 && stu[prev] == 2)
        { // i>0 이고 i가 체육복이 없으며, 이전 친구가 여벌이 있을경우
            stu[prev]--;
            stu[i]++;
        }
        if (i < n - 1 && stu[i] == 0 && stu[next] == 2)
        { // n-1보다 작으며, i가 체육복이 없고 next가 여벌이 있을경우
            stu[next]--;
            stu[i]++;
        }
    }

    answer = count_if(stu.begin(), stu.end(), cmp);
    return answer;
}