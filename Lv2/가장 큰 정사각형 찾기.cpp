#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int> > board)
{
    int answer = board[0][0]; //초기값
    const int rows = board.size();
    const int cols = board[0].size();
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.

    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            if (board[i][j] == 1)
            {
                board[i][j] = min({board[i][j - 1], board[i - 1][j], board[i - 1][j - 1]}) + 1;
                //현재 기준으로  왼쪽,위,왼쪽 위 대각선 중 최소값이 현재 위치에서 만들 수 있는 정사각형의 한변의 길이 , 거기다 +1 을하면 현재 위치 기준 만들 수 있는 최소 정사각형 변의 길이 업데이트
                //현재 위치
                answer = max({answer, board[i][j]}); //정사각형의 최대 변 길이 업데이트
            }
        }
    }

    return answer * answer;
}