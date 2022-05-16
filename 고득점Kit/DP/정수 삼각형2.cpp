#include <bits/stdc++.h>

using namespace std;
#define MAX 501
int dp[MAX][MAX][2]; //[높이][가로][2] ,높이=i+1층 (왼쪽에서 내려옴[0],오른쪽에서 내려옴[1])

int solution(vector<vector<int>> triangle)
{
    int answer = triangle[0][0]; // 최초 값 꼭대기

    dp[0][0][0] = triangle[0][0];
    dp[0][0][1] = triangle[0][0];
    // 1층 왼쪽 오른쪽은 그대로

    const int end = triangle.size() - 1;      //마지막 층
    for (int i = 1; i < triangle.size(); i++) // 2층부터 시작
    {
        for (int j = 0; j < triangle[i].size(); j++) //해당 층의 해당 가로 위치
        {
            if (j == 0) //가장 왼쪽 끝일 때는 이전 높이의 가장 왼쪽 값의 최댓값 + 현재값
            {
                dp[i][0][0] = max(dp[i - 1][0][0], dp[i - 1][0][1]) + triangle[i][0];
                dp[i][0][1] = max(dp[i - 1][0][0], dp[i - 1][0][1]) + triangle[i][0];
            }
            else if (j == triangle[i].size() - 1) //가장 오른쪽 값은 , 이전 높이의 가장 오른쪽 최댓값 + 현재값
            {
                dp[i][j][0] = max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]) + triangle[i][j];
                dp[i][j][1] = max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]) + triangle[i][j];
            }
            else //나머지 가로 위치는 2가지 경우가 있음
            {
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1]) + triangle[i][j];
                //왼쪽 의 최댓값은, 이전 층의 최댒값(왼쪽,오른쪽) + 현재값
                dp[i][j][1] = max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]) + triangle[i][j];
                //오른쪽 의 최댓값은, 이전 층의 바로 왼쪽 값 중 최댓값(왼쪽,오른쪽) + 현재 값
            }
        }
    }

    for (int i = 0; i < end; i++) //가장 마지막 층에서 모든 경우를 최댓값을 찾음
    {
        answer = max(answer, max(dp[end][i][0], dp[end][i][1]));
    }
    return answer;
}