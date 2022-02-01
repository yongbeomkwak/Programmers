#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int> &v1, vector<int> &v2)
{
    return v1[0] < v2[0];
}

int solution(vector<vector<int> > routes)
{
    int answer = 1;
    sort(routes.begin(), routes.end(), cmp);

    int curr_gate = routes[0][1]; //첫번 째 진출 지점
    for (const vector<int> gate : routes)
    {
        if (curr_gate < gate[0]) //다음 차량의 진입 지점이 현재 차량의 진출 지점보다 크다면, 카메라 필요 (겹치는 구간 없음)
        {
            curr_gate = gate[1]; //현재 진출 지점은 다음 차량의 진출 시점이 된다.
            answer++;            //카메라 수 증가
        }
        if (curr_gate >= gate[1]) //현재 진출지점이 다음 차량의 진출 지점보다 멀거나 같으면 카메라 필요 없음
        {
            curr_gate = gate[1]; //현재 진출 지점을 다음 차량의 진출지점으로 변경(더 가까우므로)
        }
    }

    return answer;
}