#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> works)
{
    long long answer = 0;

    priority_queue<int> pq(works.begin(), works.end());

    while (n > 0)
    {
        const int top = pq.top();
        pq.pop();
        int sub = 1;
        if (!pq.empty())
            sub = pq.top();
        const int diff = min(top - sub + 1, n);
        //최소 감소 값이 1이기 때문에  top-sub (+1)과 sub을 1로 출발한다
        //남아있는 시간 n과 top과 sub 차이 +1 작은 값을 최댓값 top에서 빼준다
        n -= diff; //해당 차이 만큼 빼준다.
        pq.push(top - diff);
    }

    while (!pq.empty())
    {
        if (pq.top() > 0)
            answer += pq.top() * pq.top();
        pq.pop();
    }

    return answer;
}