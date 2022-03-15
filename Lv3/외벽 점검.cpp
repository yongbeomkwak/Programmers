#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist)
{
    int answer = -1;
    //점검시간 1시간
    int w_len = weak.size();
    int d_len = dist.size();
    sort(dist.begin(), dist.end());

    //원형을 직선으로 피기
    for (int i = 0; i < w_len; i++)
    {
        weak.push_back(n + weak[i]);
    }

    for (int i = 0; i < d_len; i++) // i: 투입한 친구수(i+1)
    {
        for (int j = 0; j < w_len; j++)
        { // 시작 지점 선택

            vector<int> temp;
            for (int k = d_len - 1 - i; k < d_len; k++) // k= 몇번 째 전 친구부터 시작
            {
                temp.push_back(dist[k]);
            }

            do
            {
                int idx = 0;
                for (int k = 0; k <= i; k++)
                {                                        // 친구 투입
                    int cover = weak[j + idx] + temp[k]; // k번째 친구의 커버 영역

                    while (weak[j + idx] <= cover)
                        idx++; //해당 취약점이 현재 커버 영역 전이면
                }
                if (idx >= w_len)
                {
                    return i + 1;
                } //전부다 커버됬다면 i+1(이) 투입된 인구 수

            } while (next_permutation(temp.begin(), temp.end()));
        }
    }

    return answer;
}