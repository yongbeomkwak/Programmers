#include <bits/stdc++.h>

#define endl "\n";
using namespace std;
void drawBoard(const vector<vector<int> > &v)
{

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << "----------" << endl;
}

int solution(vector<vector<int> > board, vector<int> moves)
{
    int answer = 0;
    int count = 0; //사라진 인형 개수
    stack<int> st;

    for (const int &col : moves)
    {
        //drawBoard(board);
        for (int i = 0; i < board.size(); i++)
        {
            int &doll = board[i][col - 1]; //&를 사용하여 쉽게 변경
            if (st.empty() && doll != 0)   //스택이 비어있고 0이 아니면 첫 삽입
            {
                st.push(doll); //삽입
                doll = 0;      // 빈칸으로
                break;
            }
            if (doll != 0) // 0이 아니면 빈칸이 아니므로 확인
            {
                if (st.top() == doll) //스택 맨 위와 같으면 터트리는 과정
                {
                    doll = 0;   // 빈칸으로 바꾸고
                    st.pop();   // 스택 하나 줄이고
                    count += 2; //그리고 2개 없어 졌으므로 +2
                    break;
                }
                else
                {
                    st.push(doll); //스택 맨 위와 다르므로 삽입
                    doll = 0;      //빈칸 만들기
                    break;
                }
            }
        }
    }
    answer = count;
    return answer;
}