#include <bits/stdc++.h>

#define P pair<int, int>
using namespace std;
#define MAX 1001

int dp[MAX][MAX];

int solution(vector<vector<int>> board)
{
    int answer = 0;
    for (vector<int> &b : board) //안에 1이 하나라도 존재하면 answer=1로 초기화
    {
        int sum = accumulate(b.begin(), b.end(), 0);
        if (sum != 0)
        {
            answer = 1;
            break;
        }
    }

    const int n = board.size();
    const int v = board[0].size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < v - 1; j++)
        {
            const int curr = board[i][j];        //현재
            const int right = board[i][j + 1];   //오른쪽
            const int bottom = board[i + 1][j];  //밑
            const int dig = board[i + 1][j + 1]; // 대각선
            if (curr == 0 || right == 0 || bottom == 0 || dig == 0)
                continue;
            //하나라도 0이면 다시

            const int _min = min({curr, right, bottom});
            board[i + 1][j + 1] = _min + 1; //가장 작은 값의 +1값 을 대각선에

            answer = max(answer, board[i + 1][j + 1]); // ansewr의 최댓값
        }
    }

    return answer * answer; //넓이 이므로
}