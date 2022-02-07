#include <bits/stdc++.h>

using namespace std;

#define MAX 101

int Prev[MAX][MAX];
int adj[MAX][MAX];
int solution(int n, vector<vector<int> > results)
{
    int answer = 0;

    for (vector<int> &result : results)
    {
        int winner = result[0];
        int loser = result[1];

        Prev[winner][loser] = 1; // 해당 loser의 winner가 있다
        //즉 둘간의 상관 관계가 있다.
    }

    for (int k = 1; k <= n; k++) //중간
    {
        for (int i = 1; i <= n; i++) //승자
        {
            for (int j = 1; j <= n; j++) //패자
            {
                if (Prev[i][k] == 1 && Prev[k][j] == 1) // 만약 i가 k를 이겼고,k가 j를 이겼다면 i가 j를 이겼다.
                {
                    Prev[i][j] = 1;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (Prev[i][j] == 1 || Prev[j][i])
                cnt++; // i가 j를 이기거나 j가 i를 이기면 증가
        }
        if (cnt == n - 1)
            answer++; //만약 해당 인원과 연관된 인원이 자신읠 제외한 n-1과 관계가 있다면 순위를 알 수 있다.
    }

    return answer;
}