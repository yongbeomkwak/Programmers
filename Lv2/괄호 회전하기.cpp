#include <bits/stdc++.h>

using namespace std;

bool confirm(string &s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (st.empty())
            st.push(s[i]);
        else
        {
            if (st.top() == '{' && s[i] == '}')
            {
                st.pop();
                continue;
            }
            if (st.top() == '[' && s[i] == ']')
            {
                st.pop();
                continue;
            }
            if (st.top() == '(' && s[i] == ')')
            {
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
    }

    return st.empty();
}

int solution(string s)
{
    int answer = 0;
    const int len = s.length();

    for (int i = 0; i < len; i++)
    {
        // cout << s<< endl;
        if (confirm(s))
            answer++;
        char tmp = s.front();
        s.erase(s.begin());
        s.push_back(tmp);
    }

    return answer;
}