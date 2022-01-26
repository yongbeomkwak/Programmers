#include <bits/stdc++.h>

using namespace std;

void init(vector<string> &s, vector<int> &numbers)
{
    for (const int i : numbers)
    {
        s.push_back(to_string(i));
    }
}

void print(const vector<string> sv)
{
    for (const string &s : sv)
    {
        cout << s << " ";
    }
    cout << endl;
}

bool cmp(const string &s1, const string &s2)
{
    return s1 + s2 > s2 + s1; // 앞쪽이 커야 전체적인 숫자가 큼 //  9,11  911 > 119
}

string solution(vector<int> numbers)
{
    string answer = "";
    vector<string> tmp;
    init(tmp, numbers);
    sort(tmp.begin(), tmp.end(), cmp);

    // print(tmp);

    for (const string &s : tmp)
    {
        answer += s;
    }
    if (answer[0] == '0')
        return 0; //가장 앞이 0이면 뒤에값 상관없이 0

    return answer;
}