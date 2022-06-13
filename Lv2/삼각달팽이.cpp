#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n)
{

    vector<int> answer;
    vector<vector<int>> _map(n + 1, vector<int>(n + 1));

    const int end = (n) * (n + 1) / 2;

    int s = 1;      // 넣어야할 감
    int pc = 1;     // state
    int top = 1;    //위에 끝
    int bottom = n; //밑에 끝
    int left = 1;   //왼쪽 끝
    int right = n;  //오른족 끝
    while (s <= end)
    {

        switch (pc)
        {
        case 1:
        {   //왼쪽아래로 진행
            // top~bottom까지 left에 넣음
            for (int i = top; i <= bottom; i++)
                _map[i][left] = s++;

            //끝난 후 top을 1칸 내리고 left를 한칸 오른쪽으로
            top++;
            left++;
            pc = 2; // state2
            break;
        }

        case 2:
        {
            for (int i = left; i <= right; i++)
                _map[bottom][i] = s++;
            // bottom의 왼쪽 끝부터 오른쪽 끝까지

            // bottom 한칸올리고
            // right 한칸 왼쪽
            bottom--;
            right--;
            pc = 3; // state 3
            break;
        }

        case 3:
        {
            int tmp_right = right;
            // bottom부터 top까지 임시 오른쪽 끝에 값을 넣어줌 넣은 후 임시 오른쪽 끝을 왼쪽으로 한칸 씩
            for (int i = bottom; i >= top; i--)
            {
                _map[i][tmp_right--] = s++;
            }

            right--; //오른쪽 끝을 왼쪽으로 한칸
            top++;   // top을 한칸 내린 후
            pc = 1;  //다시 state 1
            break;
        }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            answer.push_back(_map[i][j]);
    }

    return answer;
}