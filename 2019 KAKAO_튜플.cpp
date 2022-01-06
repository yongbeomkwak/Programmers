#include <bits/stdc++.h>

#define MAX 100001
#define endl "\n"
using namespace std;

bool comp(const pair<int, int> &p1, const pair<int, int> &p2)
{
    return p1.first > p2.first;
}

vector<int> solution(string s)
{
    vector<int> answer;

    int srr[MAX] = {
        0,
    };

    string temp;
    for (const char &c : s)
    {
        if (0 <= c - '0' && c - '0' <= 9) //숫자 문자일 경우
        {
            temp += c;
        }
        else //쉼표를 만났을 때
        {
            if (temp.length() != 0) // 0이 아니면 숫자를 갖고 있음
            {
                srr[stoi(temp)]++; //해당 숫자 증가 카운트 증가
                temp.clear();      //문자열 비우기
            }
        }
    }

    vector<pair<int, int> > v;

    for (int i = 0; i < MAX; i++)
    {
        if (srr[i] != 0) // 0이 아니면 생각해줘야함
        {
            v.push_back({srr[i], i}); // 카운트값,해당 숫자
        }
    }

    sort(v.begin(), v.end(), comp); // 카운트값을 기준으로 내림차순

    for (pair<int, int> &p : v)
    {
        if (p.first != 0) //카운트 값이 0이 아니면
        {
            answer.push_back(p.second); //해당 숫자를 넣어 줌
        }
    }

    return answer;
}