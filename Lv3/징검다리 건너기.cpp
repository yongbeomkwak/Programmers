#include <bits/stdc++.h>

using namespace std;

bool bs(const vector<int> stones, const int now, const int k)
{
    int cnt = 0; //못 건너는 돌

    for (int i = 0; i < stones.size(); i++)
    {
        if (stones[i] - now <= 0)
            cnt++; // 만약 현재인원(now)가 해당 돌을 밞았을 때 0이 되거나 0보다 작으면  i번 째 돌은 해당 인원수 전원 모두를 수용하지 못한다
        else
            cnt = 0; // 해당인원수가 모두 건널 수 있으면 다시 0부터 카운트 한다.

        if (cnt >= k)
            return true;
        //만약 연속으로 카운트가 모두 되고 그 값이 제한 값 k 이상이면 더 이상 건널 수 없음
    }

    return false; //모두 건널 수 있음
}

int solution(vector<int> stones, int k)
{

    int left = 1;
    int right = *max_element(stones.begin(), stones.end());

    while (left <= right) //이분 탐색
    {
        int mid = (left + right) / 2; //건널 인원수
        if (bs(stones, mid, k))       //못 건너면 건널 수 있원수를 줄이다 , 즉 right 을 이동
        {
            right = mid - 1;
        }
        else
            left = mid + 1; //건널 수 있다면  인원ㅅ룰 증가 ,left를 움직인다.
    }

    return left;
}