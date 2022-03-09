#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> answer;
void hanoi(const int n, const int source, const int target)
{

    if (n == 1)
    {
        answer.push_back({source, target});
        cout << "Last: " << source << " " << target << endl;
    } //현 시점 가장 큰원판을 끝으로 이동
    else
    {
        const int via = 6 - source - target;
        hanoi(n - 1, source, via);
        cout << "Rest: " << source << " " << target << endl;
        answer.push_back({source, target}); // n-1개의 원판들을 목적지로 이동
        hanoi(n - 1, via, target);
    }
}

vector<vector<int>> solution(int n)
{

    hanoi(n, 1, 3);

    return answer;
}