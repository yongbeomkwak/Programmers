#include <bits/stdc++.h>

using namespace std;
#define MAX 11
int g_n = 0;
int max_score = -1000;
vector<int> answer(1, -1);

void dfs(const int cnt, vector<int> &arr, vector<int> &info)
{
    if (cnt == g_n)
    {
        int info_score = 0, lion_score = 0;
        for (int i = 0; i < MAX; i++)
        {
            if (info[i] != 0 || arr[i] != 0) // 10-i의 점수를 둘 중 한명이 맞췄다면 점수계산 해야함
            {
                if (info[i] < arr[i]) //라이언이 어피치 보다 많이 맞췄다면 라이언 점수
                    lion_score += 10 - i;
                else //같거나 어피치가 많이 맞췄다면 어피치 점수
                    info_score += 10 - i;
            }
        }
        if (lion_score > info_score) //라이언이 우승해야하므로 점수가 높고
        {
            if (lion_score - info_score >= max_score) //해당 점수차가 그 전 최대값보다 크거나 같을 때 갱신
                                                      //같을 때는 점수가 같을 경우 둘중 낮은 점수를 많이 맞춘 걸로 갱신해야함
                                                      //하지만 따로 분리하지 않은 이유는
                                                      // dfs 함수 아래 백트래킹 작업이 10~0점으로 확인하므로
                                                      //나중에 이 조건안에 들어오면 그 전보다 낮은 점수 많이 맞춘 조합임
            {
                answer = arr;
                max_score = lion_score - info_score;
            }
        }
        return;
    }

    for (int i = 0; i < MAX && arr[i] <= info[i]; i++)
    //라이언이 해당 10-i의 점수 과녁판을
    //맞춘 개수가 어피치가 맞힌 것보다 작거나 같을 때까지 반복
    //같을 때 반복하면 어피치보다 라이언이 딱 하나 많아지므로 더이상 해당 10-i 점 과녁판은 볼 필요 없음
    {
        arr[i]++;                //해당 점수 과녁 맞춘 경우
        dfs(cnt + 1, arr, info); // DFS
        arr[i]--;                // 백트래킹
    }
}

vector<int> solution(int n, vector<int> info)
{
    g_n = n;
    vector<int> arr(MAX, 0);

    dfs(0, arr, info);

    return answer;
}