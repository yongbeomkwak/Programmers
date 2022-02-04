#include <bits/stdc++.h>

using namespace std;
int answer = 0;
vector<int> nums;

void dfs(const int idx, const int target, const int sum)
{
    // cout << target << " " << nums[idx] << " " << sum <<endl;
    if (idx == nums.size())
    {
        if (sum == target)
            answer++;
        return;
    }

    for (int i = 0; i < 2; i++)
    {
        if (i == 0)
            dfs(idx + 1, target, sum - nums[idx]); // i==0이면 빼고
        else
            dfs(idx + 1, target, sum + nums[idx]); // 1이면 더하고
    }
}

int solution(vector<int> numbers, int target)
{
    nums = numbers;
    dfs(0, target, 0);
    return answer;
}