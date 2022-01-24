#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 1;

    queue<pair<int, int> > q; // first:담은 트럭의 무게,종료시간
    int next_truck = 0;       //다음 트럭을 가르킬 인덱스
    int now_weight = 0;       //현재 다리가 견디는 무게

    int _time = 0;                                               //시간
    while (next_truck < truck_weights.size() || now_weight != 0) //만약 더이상 가르킬 트럭이 범위를 넘었거나 견디는 무게가 0이 되면 멈춤
    {
        _time++; //시간 증가
        if (!q.empty() && q.front().second == _time)
        //큐가 비어있지 않거나 , 가장 앞 트럭의 종료시간이 도달 했을경우
        {

            now_weight -= q.front().first; //하중무게에서 해당 트럭 무게를 빼준 후
            q.pop();                       //제거
        }

        //해당 큐가 허용 수의 트럭보다 적게 건너고 있고 현재무게 + 다음 트럭 무게가 허용 중량을 넘지 않고 다음 트럭이 트럭 벡터 범위를 넘지 않았을 때
        if (q.size() < bridge_length && (now_weight + truck_weights[next_truck]) <= weight && next_truck < truck_weights.size())
        {
            //큐에 해당 트럭의 무게와 종료 시간을 넣어주고
            // 하중을 해당 트럭만큼늘려준다. 이때 트럭인덱스도 이동
            q.push({truck_weights[next_truck], _time + bridge_length});
            now_weight += truck_weights[next_truck++];
        }
    }

    return answer = _time;
}