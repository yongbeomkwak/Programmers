#include <bits/stdc++.h>

#define endl "\n"
using namespace std;
int last_index = 26;
unordered_map<string, int> _map;
void init(unordered_map<string, int> &m) // A~Z까지 초기화
{
    char a = 'A';
    int cnt = 1;
    while (a <= 'Z')
    {
        string s(1, a++); // char to string
        m[s] = cnt++;     // 1~26까지 맵에 삽입
    }
}

void print(const vector<string> &v)
{
    for (const string &s : v)
    {
        cout << s << endl;
    }
}

bool check(const string &a, const string &b) //해당 문자열이 맵에 포함되나?
{
    return _map.find(a + b) != _map.end();
}

vector<int> solution(string msg)
{
    vector<int> answer;

    init(_map);
    string w, c;

    int i = 0, j = 1;    // i는 현재 j는 다음
    int next_index = 27; //초기화 이후 다음 인덱스는 27
    w += msg[i];         //현재입력 초기화
    while (i < msg.length())
    {
        c += msg[j];     //다음 글자
        if (check(w, c)) //현재 글자  다음글자가 존재한다면
        {
            w += c;    // 다음 글자를 뒤에 붙임
            c.clear(); //다음글자 초기화
            j++;       // 다음글자 위치 이동
            continue;
        }
        else //존재하지 않다면
        {
            _map[w + c] = next_index++; //맵에 인덱스와 함께 저장 , 인덱스 증가
            answer.push_back(_map[w]);  //현재 w에 대한 인덱스 삽입
            w = c;                      //현재 문자열 다음 문자열로 변경
            i = j++;                    //현재 문자열 위치를 다음 문자열 위치로 변경, 다음 문자열 위치 증가
            c.clear();                  //다음 문자열 초기화
        }
    }

    return answer;
}