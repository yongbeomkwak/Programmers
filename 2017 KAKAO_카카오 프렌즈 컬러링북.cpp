#include <bits/stdc++.h>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

int f_max(const int a, const int b)
{
    return a > b ? a : b;
}
int dx[] = {0, 0, -1, 1}; // 좌 우
int dy[] = {-1, 1, 0, 0}; // 상 하
int g_m = 0, g_n = 0;
#define MAX 100

bool isVisit[MAX][MAX];

int bfs(const int i, const int j, vector<vector<int> > &map)
{
    int color = map[i][j]; //현재 색
    int size = 1;
    queue<pair<int, int> > q;
    q.push({i, j});       // 큐삽입 (BFS)
    isVisit[i][j] = true; //출발점은 방문 처리

    while (!q.empty())
    {
        int curr_x = q.front().first;  //현재 x
        int curr_y = q.front().second; //현재 y
        q.pop();

        for (int move = 0; move < 4; move++) // 4가지 무브 먼트
        {
            int next_x = curr_x + dx[move]; //다음 x
            int next_y = curr_y + dy[move]; //다으 y

            if ((next_x >= 0 && next_x < g_m) && (next_y >= 0 && next_y < g_n)) //범위를 안나가고
            {

                if (color == map[next_x][next_y] && isVisit[next_x][next_y] == false)
                {                                   //현재 색깔과 다음 색깔이 같고 아직 다음 좌표 방문하지 않앗다면
                    isVisit[next_x][next_y] = true; //방문 처리
                    size++;                         //사이즈 증가
                    q.push({next_x, next_y});       // 큐삽입
                }
            }
        }
    }

    return size;
}

vector<int> solution(int m, int n, vector<vector<int> > picture)
{

    g_m = m, g_n = n;

    fill(&isVisit[0][0], &isVisit[MAX][MAX + 1], false); // 0,0  99,99 까지 false로 초기화 100 x 100 초기화, colum쪽은 +1 해줘야함

    vector<int> answer(2, 0);
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int color = picture[i][j];
            if (color != 0 && isVisit[i][j] == false) //현재 색과 아직 방문 하지 않았다면
            {
                int _size = bfs(i, j, picture);                            //해당 색 영역 크기 탐색
                max_size_of_one_area = f_max(max_size_of_one_area, _size); //최대값
                number_of_area++;                                          //영역 하나 증가
            }
        }
    }

    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    return answer;
}