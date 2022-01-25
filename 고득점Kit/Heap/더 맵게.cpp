#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<int> > pq;

    for (const int k : scoville)
    {
        pq.push(k);
    }

    while (pq.size() > 1) // 힙에 2개이상있을 시
    {

        int k1 = pq.top();
        pq.pop();
        if (k1 >= K)
            break; //힙의 가장위 즉 최솟값이 K이상일 때 멈춤
        int k2 = k2 = pq.top();
        pq.pop();
        pq.push(k1 + k2 * 2); //섞음
        answer++;             //섞음 수 증가
    }

    if (pq.top() < K)
        return -1; //만약 남아있는 값이 K미만이면 -1

    return answer;
}