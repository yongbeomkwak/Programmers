#include <bits/stdc++.h>

using namespace std;

char vowels[5] = {'A', 'E', 'I', 'O', 'U'};
vector<string> v;

void insert(const int len, string s)
{
    if (len == s.length())
    {
        v.push_back(s);
        return;
    }

    for (int i = 0; i < 5; i++)
    {
        insert(len, s + vowels[i]);
    }
}
int solution(string word)
{
    int answer = 0;

    for (int i = 1; i <= 5; i++)
    {
        insert(i, "");
    }
    sort(v.begin(), v.end());
    auto it = lower_bound(v.begin(), v.end(), word);
    answer = it - v.begin() + 1;

    return answer;
}