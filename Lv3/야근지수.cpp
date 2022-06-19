#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> works)
{
    long long answer = 0;

    priority_queue<long long> pq;

    for (const int work : works)
    {
        long long llwork = (long long)work;
        pq.push(llwork);
    }

    while (n != 0 && !pq.empty()) // n이 0이거나 우선순위 큐가 비어있으면 종료
    {
        long long _max = pq.top();
        pq.pop();
        if (_max > 0)
        { // 남은 작업량이 0또는 음수 일 수 는 없으므로 ,양수일 때만 감소한 후 넣어준다.
            _max--;
            pq.push(_max);
        }
        n--;
    }

    while (!pq.empty())
    {
        answer += pq.top() * pq.top();
        pq.pop();
    }

    return answer;
}