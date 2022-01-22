#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, int> &p1, pair<int, int> &p2)
{
    //재생횟수가 같으면 고유번호 적게
    if (p1.second == p2.second)
        return p1.first < p2.first;
    else
        return p1.second > p2.second;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    unordered_map<string, vector<pair<int, int> > > um;
    unordered_map<string, int> total;
    priority_queue<pair<int, string>, vector<pair<int, string> >, less<pair<int, string> > > pq; //내림차순

    for (int i = 0; i < genres.size(); i++)
    {
        const string genre = genres[i];
        const int play = plays[i];
        total[genre] += play;
        um[genre].push_back({i, play}); //고유번호,재생 횟수
    }

    for (auto it = total.begin(); it != total.end(); it++)
    {
        pq.push({it->second, it->first});
    }

    for (auto it = um.begin(); it != um.end(); it++)
    {
        sort((it->second).begin(), (it->second).end(), comp);
    }

    while (!pq.empty())
    {
        string top = pq.top().second;

        if (um[top].size() == 1)
            answer.push_back(um[top][0].first);
        else
        {
            answer.push_back(um[top][0].first);
            answer.push_back(um[top][1].first);
        }
        pq.pop();
    }

    return answer;
}