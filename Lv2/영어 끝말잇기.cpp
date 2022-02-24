#include <bits/stdc++.h>

using namespace std;
#define P pair<string, int>

vector<int> solution(int n, vector<string> words)
{
    vector<int> answer(2, 0);
    unordered_map<string, int> map;
    map[words[0]]++; //첫 값 증가
    for (int i = 1; i < words.size(); i++)
    {
        if (map[words[i]] != 0 || words[i].front() != words[i - 1].back())
            //중복 되지 않고 현재 front(앞) 이 이전(i-1)의  뒤(back())과 같지 않음면 틀림

            return {(i % n) + 1, (i / n) + 1}; //(i%n)+1 :해당 유저 번호,(i/n)+1 해당 턴
        map[words[i]]++;
    }

    return answer;
}