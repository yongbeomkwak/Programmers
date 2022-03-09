#include <string>
#include <vector>

using namespace std;

int row[13] = {
    0,
}; //인덱스: 해당 행 ,값:열
int N = 0;
int answer = 0;

bool check(const int r)
{
    for (int i = 0; i < r; i++)
    {
        if (row[i] == row[r]) //열이 같은게 있으면 세로가 겹치므로 안되
            return false;
        if (abs(row[i] - row[r]) == r - i) //대각선 존재
            //(row[i]-row[r])[열차이]==r-i[행차이] 같으면 대각선
            return false;
    }
    return true; //모두 통과시 가능
}

void search(const int r)
{
    if (r == N)
    {
        answer++;
        return;
    }

    for (int i = 0; i < N; i++)
    {
        row[r] = i;
        if (check(r))
        {
            search(r + 1);
        }
        row[r] = 0;
    }
}

int solution(int n)
{
    N = n;
    search(0);

    return answer;
}