#include <bits/stdc++.h>

using namespace std;
int n;

vector<int> used;
set<int> g_set;

bool check(const int a)
{
    if (a < 2)
        return false;
    bool ret = true;
    int end = (int)sqrt(a);

    for (int i = 2; i <= end; i++)
    {
        if (a % i == 0)
        {
            ret = false;
            break;
        }
    }
    return ret;
}

void search(string num, int cnt, const string &numbers)
{
    // cout << num  << endl;
    if (cnt == n) // numbers의 길이까지 모두 돌앗을 때 마지막 체크
    {
        if (check(stoi(num)))
            g_set.insert(stoi((num)));
        return;
    }
    else
    {
        if (cnt != 0) //어떤 숫자든 num에 담겨있을 경우
        {
            if (check(stoi(num)))
                g_set.insert(stoi(num)); //통괗면 담음
        }
        for (int i = 0; i < n; i++)
        {
            if (used[i] == 1)
                continue;                  //이미 방문한 숫자면 넘어감
            used[i] = 1;                   // 사용
            num += numbers[i];             //숫자 붙혀주고
            search(num, cnt + 1, numbers); //개수 증가
            used[i] = 0;                   // 방문 취소
            num.pop_back();                // 뒤에 빼주고
        }
    }
}

int solution(string numbers)
{
    int answer = 0;
    n = numbers.size();
    used = vector<int>(n, 0);
    search("", 0, numbers);

    /* for(auto it=g_set.begin();it!=g_set.end();it++)
     {
         cout << *it << endl;
     }*/
    answer = g_set.size(); //최종 소수 개수

    return answer;
}