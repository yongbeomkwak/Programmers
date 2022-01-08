#include <bits/stdc++.h>

using namespace std;

long long calc(long long a, long long b, char op)
{
    if (op == '-')
        return a - b;
    else if (op == '+')
        return a + b;
    else
        return a * b;
}

long long solution(string expression)
{
    long long answer = 0;
    vector<char> oper_list = {'*', '+', '-'};
    vector<long long> number;
    vector<char> oper;
    string num = "";

    for (const char &c : expression)
    { //연산자와 숫자 분리
        if (c == '+' || c == '*' || c == '-')
        {
            oper.push_back(c);
            number.push_back(atoi(num.c_str())); // string -> char* -> int
            num = "";
        }
        else
            num += c;
    }
    number.push_back(atoi(num.c_str())); //마지막 숫자 삽입

    long long _max = 0;
    do
    {
        vector<char> tmp_oper = oper;
        vector<long long> tmp_num = number;
        for (int i = 0; i < 3; i++) // i가 작을수록 우선순위가 높은 연산자
        {
            for (int j = 0; j < tmp_oper.size(); j++) // a+b+c 면 연산자 2 숫자 3, 그러므로 연산자 개수 만큼 반복하면 j+1은 인덱스를 넘지 않음
            {
                if (tmp_oper[j] == oper_list[i]) //현재 계산해야할 연산자인가?
                {

                    tmp_num[j] = calc(tmp_num[j], tmp_num[j + 1], oper_list[i]);
                    //해당 위치숫자와 다음꺼 연산함
                    tmp_num.erase(tmp_num.begin() + j + 1); //연산 했으므로 그 뒤 숫자 제거
                    tmp_oper.erase(tmp_oper.begin() + j);   //해당 위치 연산했으므로 연산자 제거
                    j--;

                    /*
                    1 - 2  + 3
                    1-2 연산 -> -1 이 현재 1위치로 대채  tmp_num[j] = calc(tmp_num[j],tmp_num[j+1],oper_list[i]);
                    -1 + 3   그러면 -와 2를 제거해야함
                    tmp_num.erase(tmp_num.begin()+j+1) 이 2의 위치를 제거
                    tmp_oper.erase(tmp_oper.begin()+j) 이 -의 위치를 제거
                    그러면 현재 연산자(-) 1개 숫자(2) 1개를 각각 숫자와 연산자 벡터에서 1개 씩 지웠다
                    그러므로 j를 줄여줘야함 j--


                    */
                }
            }
        }
        if (_max < abs(tmp_num[0]))
            _max = abs(tmp_num[0]);
    } while (next_permutation(oper_list.begin(), oper_list.end())); // oper_list 모든 순열 계산
    answer = _max;
    return answer;
}