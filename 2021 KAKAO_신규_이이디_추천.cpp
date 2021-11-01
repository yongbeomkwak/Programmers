#include <bits/stdc++.h>
using namespace std;

string solution(string new_id) {
    for (char& ch : new_id){
        if ('A' <= ch && ch <= 'Z'){
            ch ^= 0b100000;
            /**
            대문자의 아스키코드는 모두 여섯번째비트가 0이고 
            소문자의 경우에는 여섯번째 비트가 모두1이다.
            즉 6번 째 자리 비트만 변경하면됨
            그러므로 변환은 32(0x20) 즉 ob100000  와 or 또는 xor연산 하면 됨
            a ^= ob100000 ,|=ob100000, ^=32,|=32,^=ox20, |=0x20= 모두 같은 연산
            */
        }
     
    }
    
    string ret;
    for (char& ch: new_id) {
        if ('a' <= ch && ch <= 'z' ||
            '0' <= ch && ch <= '9' ||
            strchr("-_.", ch)) ret += ch;
        /*
        char* strchr (char* str, int c);
         해당 문자열(str)에 해당 문자 c가 존재하면 해당 존재하는 곳 포인터 없으면 Null
         
         그러므로 ,a~z,0~9,-_. 어느 곳 안에 포함되면 ret에 뒤에서 앞으로 삽입 됨
        */


    }
    
    new_id = ret;
    ret.clear();
    for (char& ch: new_id) {
        if (!ret.empty() && ret.back() == '.' && ch == '.') continue;
        //비어 있지 않고 현재 마지막(ret.back)이 .이고  현재 삽입 고민중인 문자(ch)가 . 이면 넘어감
        ret += ch;
    }

    if (ret.front() == '.') ret.erase(ret.begin());
    if (ret.back() == '.') ret.pop_back();
    //처음과 마지막이 .이면 삭제

    if (ret.empty()) ret = "a";
    //버이있으면 a 
    
    if (ret.size() >= 16) ret = ret.substr(0, 15);
    //16 이상 일시 0~15까지만 남음
    if (ret.back() == '.') ret.pop_back();
    //여전히 마지막에 .존재시 삭제
    while (ret.size() <= 2) ret += ret.back();
    //3이 될 때까지 ret.back()을 계속 더함

    return ret;
}