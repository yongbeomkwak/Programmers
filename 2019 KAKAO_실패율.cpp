#include <bits/stdc++.h>

#define endl "\n";
using namespace std;
bool comp(const pair<int, double> &p1, const pair<int, double> &p2)
{
    if (p1.second >= p2.second)
    {
        if (p1.second == p2.second)
        {
            return p1.first < p2.first;
        }
        return true;
    }
    return false;
}
vector<int> solution(int N, vector<int> stages)
{
    vector<int> answer;
    vector<pair<int, double> > failRatio;

    for (int i = 1; i <= N; i++)
    {
        int curr_stage = i;
        int clear_users = 0;
        int progress_users = 0;
        for (const int &stage : stages)
        {
            //해당 유저가 도전중인 스테이지가 현재 스테이지 보다 높으면, 현재스테이지는 깬 것
            //즉 깬 유저 인원을 늘려준다.
            if (stage >= curr_stage)
                clear_users++;
            //같으면 해당 유저가 도전중인 스테이지가 현재스테이지와 같으면 해당유저는 지금
            //이 스테이지를 도전중인 유저이다.
            if (stage == curr_stage)
                progress_users++;
        }
        //해당 스테이지 검사를 끝낸 후
        if (clear_users == 0)
        {
            failRatio.push_back({curr_stage, 0});
            //해당 스테이지와 실패율 0
        }
        else
        {
            double fail = (double)progress_users / (double)clear_users;
            //실패율: 진행중인 인원/깬 인원
            failRatio.push_back({curr_stage, fail}); //해당 스테이지와 실패율을 넣어줌
        }
    }

    sort(failRatio.begin(), failRatio.end(), comp); //정렬

    for (const pair<int, double> &p : failRatio)
    {
        answer.push_back(p.first); // 해당 스테이지 삽입
    }

    return answer;
}