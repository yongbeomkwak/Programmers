#include <bits/stdc++.h>

using namespace std;
#define MAX 10001
vector<int> answer;
unordered_map<string, int> n_enrolls; //해당 직원에 해당하는 index
unordered_map<int, string> parents;   //해당 하는 index의 부모 직원

void dfs(const string &seller, const int money)
{
    if (seller == "-" || money == 0)
        return; // 현재 판매직원이 center 이거나 더 이상 보낼 돈이 없을 때

    int rest = money / 10;
    int pure_income = money - rest;
    const int idxOf_seller = n_enrolls[seller];
    answer[idxOf_seller] += pure_income;

    dfs(parents[idxOf_seller], rest);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount)
{

    int len = enroll.size();
    answer = vector<int>(len, 0);

    for (int i = 0; i < len; i++)
    {
        n_enrolls[enroll[i]] = i; //해당 판매원에 대한 인덱스를 기억
        parents[i] = referral[i]; //해당 인덱스의 부모 직원을 기억
    }

    for (int i = 0; i < seller.size(); i++)
    {
        dfs(seller[i], amount[i] * 100);
    }

    return answer;
}