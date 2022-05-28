#include <bits/stdc++.h>

using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> st=stack<char>(); //스택 이용 
    
    
    for(const char& c:s)
    {
        if(!st.empty()&&st.top()!=c)
        {
            st.push(c);
            continue;
        }
        else if(!st.empty()&&st.top()==c)
        {
            st.pop();
            continue;
        }
        else st.push(c);
    }
    
    if(st.empty()) answer=1;
    else answer=0;
    
    return answer;
}