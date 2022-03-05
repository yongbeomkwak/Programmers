#include <bits/stdc++.h>

using namespace std;
#define MAX 100001

int answer = 0;

int solution(vector<int> A, vector<int> B)
{

    sort(A.begin(), A.end());

    priority_queue<int, vector<int>, greater<int>> pq(B.begin(), B.end()); //오름차순

    int idx = 0;
    while (!pq.empty())
    {
        if (A[idx] < pq.top()) // 이겼을 때만 A를 이동
        {
            idx++;
            answer++;
        }
        pq.pop(); //졌을 때는 A는 그대로 왜냐하면 작은 값이기 때문에 다음 B값이 이길 가능성 있음
    }

    return answer;
}