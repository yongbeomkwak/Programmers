#include <bits/stdc++.h>

using namespace std;

#define P pair<int, int>

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;
    queue<int> q;
    queue<P> q1;                                   //종료시간,트럭무게 저장 큐
    for (int i = 0; i < truck_weights.size(); i++) //무게 저장 큐
    {
        q.push(truck_weights[i]);
    }
    int curr_weight = 0; //현재 다리무게

    while (!q.empty() || !q1.empty()) //두 큐가 모두 비어야 종료
    {
        answer++; // 초 증가

        //삭제
        while (!q1.empty() && answer == q1.front().first) //만약 q1이 비어있지 않고 answer(해당시간)==큐 가장 앞 종료시간과 같으면 빼야함
        {
            curr_weight -= q1.front().second; //다리 무게 감소
            q1.pop();                         //출력
        }

        //삽입
        //건너가야할 트럭이 남이있고 해당 다리무게 + 현재 트럭 무게 합이 제한보다 작거나 같으면 건널 수 있음
        if (!q.empty() && curr_weight + q.front() <= weight)
        {
            q1.push({answer + bridge_length, q.front()}); //종료시간,트럭무게 삽입
            curr_weight += q.front();                     //다리무게 증가
            q.pop();
        }
    }

    return answer;
}