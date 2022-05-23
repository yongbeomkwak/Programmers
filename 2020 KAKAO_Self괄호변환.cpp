#include <bits/stdc++.h>

using namespace std;

bool count_check(string s) //균형잡힌 문자열 체크
{
    const int cnt1 = count(s.begin(), s.end(), '(');
    const int cnt2 = s.length() - cnt1;

    return cnt1 == cnt2;
}

bool check(string s) //올바른 문자열 확인
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (!st.empty() && st.top() == '(' && s[i] == ')')
            st.pop();
        else
            st.push(s[i]);
    }

    return st.empty();
}

char rev(char c) //두집기
{
    if (c == '(')
        return ')';
    else
        return '(';
}

string solution(string p)
{
    if (check(p) || p.empty())
        return p;

    string u, v;
    int i;
    for (i = 0; i < p.size(); i++)
    {
        u += p[i];
        if (count_check(u))
            break;
    }
    if (i != p.size() - 1)
        v = p.substr(i + 1);
    if (check(u))
        return u + solution(v);
    else
    {
        string ret = "(";
        ret += solution(v);
        ret += ")";
        for (int i = 1; i < u.size() - 1; i++)
        {
            ret += rev(u[i]);
        }
        return ret;
    }
}