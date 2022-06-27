#include <bits/stdc++.h>

using namespace std;

void show(vector<vector<int>> &b)
{
    for (int i = 0; i < b.size(); i++)
    {
        for (int j = 0; j < b[0].size(); j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;
    stack<int> st;
    const int h = board.size();
    const int v = board[0].size();

    show(board);

    for (int &move : moves)
    {
        int curr_v = move - 1;
        for (int i = 0; i < h; i++)
        {
            if (board[i][curr_v] == 0)
                continue;

            const int dolls = board[i][curr_v];
            board[i][curr_v] = 0;

            if (!st.empty())
            {
                if (dolls == st.top())
                {
                    answer += 2;
                    st.pop();
                }
                else
                {
                    st.push(dolls);
                }
            }
            else
            {
                st.push(dolls);
            }
            break;
        }
    }

    return answer;
}