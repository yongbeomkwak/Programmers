#include <bits/stdc++.h>

using namespace std;

bool putKey(int x, int y, vector<vector<int> > key, vector<vector<int> > board)
{

    for (int i = y; i < y + key.size(); i++)
    {
        for (int j = x; j < x + key.size(); j++)
        {
            board[i][j] += key[i - y][j - x]; //해당 키를 board에 밀어 넣는다.
        }
    }

    //좌물쇠 부분 확인
    for (int i = key.size() - 1; i <= board.size() - key.size(); i++)
    {
        for (int j = key.size() - 1; j <= board.size() - key.size(); j++)
        {
            if (board[i][j] == 1)
                continue;

            // 1이 아니라면 바로 false를 리턴
            return false;
        }
    }

    return true;
}

void print(vector<vector<int> > v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
void rotateKey(vector<vector<int> > &key)
{
    vector<vector<int> > tmp(key.size(), vector<int>(key.size(), 0));
    const int len = key.size() - 1;

    for (int i = 0; i <= len; i++)
    {
        for (int j = len; j >= 0; j--)
        {
            tmp[i][len - j] = key[j][i];
        }
    }

    key = tmp;
}

bool solution(vector<vector<int> > key, vector<vector<int> > lock)
{
    bool answer = false;
    const int lock_len = lock.size();
    const int key_len = key.size();
    const int len = lock_len + (key_len - 1) * 2;
    vector<vector<int> > board(len, vector<int>(len, 0));

    for (int i = key_len - 1; i <= len - key_len; i++)
    {
        for (int j = key_len - 1; j <= len - key_len; j++)
        {
            board[i][j] = lock[i - key_len + 1][j - key_len + 1]; // 해당 board중간에 lock 넣기
        }
    }

    for (int r = 0; r < 4; r++) // 4방향 회전
    {

        for (int i = 0; i <= len - key_len; i++)
        {
            for (int j = 0; j <= len - key_len; j++)
            {
                if (putKey(i, j, key, board))
                {
                    return true;
                }
            }
        }

        rotateKey(key);
    }

    return answer;
}