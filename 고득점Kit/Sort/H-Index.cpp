#include <bits/stdc++.h>

using namespace std;

int h;

bool over(const int n)
{
    return h <= n;
}

bool _less(const int n)
{
    return h >= n;
}

void print(vector<int> &v)
{
    for (const int &i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

int solution(vector<int> citations)
{
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<int>());

    if (!citations[0])
        return 0;
    // print(citations);
    for (int i = 0; i < citations.size(); i++)
    {
        if (citations[i] > i)
            answer++; // 해당 인덱스가 인용 수보다 적으면 H-index 조건 만족
        else
            break; //더이상 전진이 안되면
    }
    return answer;

    return answer;
}