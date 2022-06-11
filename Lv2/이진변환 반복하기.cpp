#include <bits/stdc++.h>

using namespace std;

int cnt = 0;
int turn = 0;

string fillter(string &s)
{
    turn++; //순환 횟수
    int len = s.length();
    int zero_cnt = count(s.begin(), s.end(), '0');
    cnt += zero_cnt;        //삭제할 zero 개수
    int c = len - zero_cnt; // 1의 개수

    string ret;
    while (c != 0)
    {
        ret = to_string(c % 2) + ret;
        c /= 2;
    }
    //이진 변환

    return ret;
}

vector<int> solution(string s)
{
    vector<int> answer;

    while (s != "1") // 1이 아니면 계속
    {
        s = fillter(s);
    }

    answer.push_back(turn);
    answer.push_back(cnt);

    return answer;
}