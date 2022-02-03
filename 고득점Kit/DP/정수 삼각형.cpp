#include <bits/stdc++.h>

using namespace std;
#define MAX 501
vector<int> DP[MAX];
int solution(vector<vector<int> > triangle)
{
    int answer = 0;
    int h = triangle.size();         //높이
    for (int i = 1; i <= h + 1; i++) //주어진 높이 다음 층까지 기본적으로 해놓음 예외를 막기 위해
    {
        DP[i] = vector<int>(i, 0);
    }
    for (int i = h; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
        {
            // DP[i][j]:i층 j위치 최댓값
            // triangle[i-1][j]:i층 j위치,인덱스이기 때문에 i-1이 i위치
            // DP[i+1]:밑의 층, j:왼쪽 최댓값, j+1:오른쪽 최댓값
            DP[i][j] = max(triangle[i - 1][j] + DP[i + 1][j], triangle[i - 1][j] + DP[i + 1][j + 1]);
        }
    }

    return answer = DP[1][0]; //꼭대기 값이 모든 경우의 수의 최댓값
}