#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

bool check(const string &a) {
    int r = 0;
    for (char ch : a) {
        if (ch == '(') ++r;
        else --r;
        if (r < 0) return false;
    }
    return r == 0;
}
string solution(string p) {
    if (p == "") return "";
    if (check(p)) return p;

    int i, t = 0;
    
    for (i = 0; i < p.size(); ++i) {
        //u와 v를 구분하는 위치 i를 찾아냄
        if (p[i] == '(') ++t;
        else --t; 
        if (t == 0) break; //t가 0일 때  찾은 것
    }

    string u = p.substr(0, i + 1); //u 0부터 i+1개 까지 i=1이라는 것은 0~1까지 를 의미하는 것이며 0부터 2개를 잘라야함 그러므로 i+1
    string v = p.substr(i + 1); //i+1부터 마지막까지
    cout << "u: " << u  << " "<< "v:" << v <<endl;

    if (check(u)) return u + solution(v); //만약 올바른 문자열이면 u+v에 대한 재귀 

    for (char &ch : u) ch = ch == '(' ? ')' : '('; // u에 대한 뒤집기
    // "(" + v에 대한 재귀 +")" +  위에서 뒤집은 u의 앞 뒤 자르기(1~크기-2)
    return string("(") + solution(v) + ")" + u.substr(1, u.size() - 2);
}
