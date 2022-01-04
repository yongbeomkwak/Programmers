#include <bits/stdc++.h>

using namespace std;
#define endl "\n"

string task(const string p); //재귀를 위한 프로토 타입
void divisionUV(const string &s, string &u, string &v);
string task3(string &u, string &v);

/*
1.  () 개수가 맞으면: 균현잡힌 괄호 문자열 ex) (()))(
2.  () 짝이 맞으면: 올바른 괄호 문자열 (())() -> 올바른 괄호 문자열이면서 균형잡힌 괄호 문자열
*/

/*
1. w: 빈문자열 -> return 빈 문자열
2. w를 u와 v로 분리 (u는  더 이상 분리할 수 없는 균현잡힌 괄호 문자열) v:는 빈 문자열 가능
3.  u가 올바른 문자열이면 v는 1번부터 다시 수행후 u에 결과 값을 붙인 후 반환
4.
*/

bool check(string s)
{
    int ret = 0;
    for (const char &c : s)
    {
        if (ret < 0)
            return false;

        if (c == '(')
        {
            ret++;
        }
        else
        {
            ret--;
        }
    }
    return true;
}

void divisionUV(const string &s, string &u, string &v) // u와v 분리 작업
{
    // u를 쪼개지지 않는 균현잡힌 괄호 문자열로 v는 빈칸가능
    int ret = 0;
    bool flag = true; // true면 u 작업 false면 v 작업
    for (const char &c : s)
    {
        if (c == '(') //좌 괄호면 +  우 괄호면 -
        {
            ret++;
        }
        else
        {
            ret--;
        }
        if (flag)
        {
            u += c;
        }
        else
        {
            v += c; // u를 제외한 나머지 문자를 v에 담음
        }
        if (ret == 0) //만약 ret가 0이 되면 u까지 작업 모두 된거임(균형잡힌 괄호 찾음)
        {
            flag = false;
        }
    }
}

string reverse(string &u) // 뒤집기
{
    string ret;
    if (u.length() == 0)
    {
        return ret;
    }
    u.erase(0, 1); // erase(index,count) 위치 0부터 1개 삭제

    if (u.length() == 0)
    {
        return ret;
    }
    // length가 0이면 뒤집을 수 없으므로 ""리턴
    u.erase(u.length() - 1, 1); //마지막 문자 제거

    //뒤집기
    for (int i = 0; i < u.size(); i++)
    {
        if (u[i] == '(')
        {

            ret.push_back(')');
        }
        else
        {

            ret.push_back('(');
        }
    }
    //뒤집기
    return ret;
}

string task3(string &u, string &v)
{

    //빈 문자열 ret에 ( + task(v)[재귀 v] + ) + 뒤집은 u를 넣어 리턴한다
    string ret = "(";
    ret += task(v);
    ret += ")";
    ret += reverse(u);
    return ret;
}

string task(const string p)
{
    if (p == "")
        return ""; // p 자체가 빈칸이면 그냥 리턴
    string u, v;
    divisionUV(p, u, v); // u 와 v 분리

    cout << "u: " << u << " "
         << "v: " << v << endl;
    if (check(u)) // u가 올바른 괄호 문자면
    {
        cout << "u가 올바름" << endl;
        return u + task(v); //올바를 경우 u + v에 대한 재귀
    }
    else //아니면 task3
    {
        cout << "u가 x" << endl;
        return task3(u, v); // task3 들어감
    }
}

string solution(string p)
{
    string answer = ""; //만약 p 자체가 올바른 문자열이면
    if (check(p))
        return answer = p; // 바로 리턴
    answer = task(p);      //아닐경우 작업을 해야함
    return answer;
}