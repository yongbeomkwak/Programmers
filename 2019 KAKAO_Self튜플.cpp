#include <bits/stdc++.h>

using namespace std;
#define MAX 100001
int cnt[MAX] = {
    0,
};
unordered_set<int> ss;
int len;
vector<int> solution(string s)
{
    vector<int> answer;
    bool flag1 = false;
    bool flag2 = false;
    string tmp = "";
    for (int i = 2; i < s.length() - 1; i++)
    {
        if (isdigit(s[i]))
            tmp += s[i];                //숫자이면 tmp에 더함
        if (s[i] == ',' || s[i] == '}') //만약 ,이거나 }이고
        {
            if (!tmp.empty()) // tmp가 비어있지 않으면
            {
                int itmp = stoi(tmp); //해당문자열 int로
                ss.insert(itmp);      //셋에 삽입
                cnt[itmp]++;          //해당 인덱스에 해당하는 카운트 갯수 증가
                tmp.clear();          //비워주고
            }
        }
    }
    len = ss.size(); //최대갯수는 len부터  ~1까지
    while (len >= 1)
    {
        for (auto it = ss.begin(); it != ss.end(); it++)
        {
            const int idx = *it; //해당 값의 카운트가 현재 len과 같다면 삽입
            if (len != cnt[idx])
                continue;
            answer.push_back(idx);
            len--;
        }
    }
    return answer;
}