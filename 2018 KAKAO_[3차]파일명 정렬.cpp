#include <bits/stdc++.h>

#define endl "\n"
/*
1. 대소문자 구분 없이 사전순 정렬
2.  앞에 0은 무시하여 오름차차순
3.  Stable Sort
*/

using namespace std;

struct compare
{
    bool operator()(vector<string> a, vector<string> b) const
    {
        if (strcasecmp(a[0].c_str(), b[0].c_str()) == 0) //대소문 상관없이 오름차순 정렬 0일때는 같다는 뜻
        {
            return stoi(a[1]) < stoi(b[1]); //같을 때는 NUMBER의 숫자 크기 비교 stoi가 001과 1을 같게 봄
        }
        return strcasecmp(a[0].c_str(), b[0].c_str()) < 0; //오르차순 정렬
    }
};

vector<int> split(const string &a) // NUMBER의 시작과 끝 인덱스를 벡터에 담아 반환
{
    vector<int> ret(2, 0); //
    int start = -1;        //일단 겹치지 않게 -1 시작
    int end = a.length();  // end는 일단 길이 값 (마지막 인덱스 +1)

    for (int i = 0; i < a.length(); i++)
    {
        const char c = a[i];
        if (start == -1 && isdigit(c) != 0) //아직 start값이 -1이고 c가 숫자형일 때(!=0)
        {
            start = i; // start 위치 저장
            continue;
        }
        if (start != -1 && isdigit(c) == 0) // start가 초기화가 됬고 숫자형이 아닐 때(==0)
        {
            end = i; //끝 위치
            break;   //이후 종료
        }
    }
    ret[0] = start;
    ret[1] = end;
    return ret;
}

void print(vector<string> a)
{
    for (string &str : a)
    {
        cout << str << " ";
    }
}

vector<string> solution(vector<string> files)
{
    vector<string> answer;
    vector<vector<string> > temp;
    for (const string &str : files)
    {
        string HEAD, NUMBER, TAIL = "";
        vector<int> se = split(str);
        int start = se[0];
        int end = se[1];                         // end는 숫자 이후 문자가 다시시작하는 구간
        HEAD = str.substr(0, start);             //처음부터 start위치까지
        NUMBER = str.substr(start, end - start); // start부터 end-start 개 만큼(abc123a)
        //면 1위치가 start ,3뒤 a가 end , end-start=6-3=3, start부터 3개,123이 찾아진다.

        if (end < str.length()) // end가 전체길이 보다 작으면 남은게 더있음
        {
            TAIL = str.substr(end); // end부터 끝까지
        }

        vector<string> tmp = {HEAD, NUMBER, TAIL}; //
        temp.push_back(tmp);
    }

    stable_sort(temp.begin(), temp.end(), compare()); // stable_sort
    for (vector<string> a : temp)
    {
        print(a);
        answer.push_back(a[0] + a[1] + a[2]); //붙인다
    }

    return answer;
}