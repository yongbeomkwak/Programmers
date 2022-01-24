#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer(prices.size());
    stack<int> s;
    int size = prices.size();
    for (int i = 0; i < size; i++)
    {
        while (!s.empty() && prices[s.top()] > prices[i])
        {
            //스택이 비어있지 않고, s.top() :가장최근에 담은 과거 값, i:현재 값,
            //과거값이 현재값보다 크다, 즉 감소했다.
            cout << s.top() << " " << i << endl;
            cout << prices[s.top()] << " " << prices[i] << endl;
            answer[s.top()] = i - s.top(); //그 구간 만큼 넣어준다.
            s.pop();
        }
        s.push(i);
    }

    while (!s.empty()) //끝까지 도달 했을 때  남아있는 것은, size- 자신위치 -1(자기자신)
    {
        answer[s.top()] = size - s.top() - 1; //
        s.pop();
    }

    return answer;
}