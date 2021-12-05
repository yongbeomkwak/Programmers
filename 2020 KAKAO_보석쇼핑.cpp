#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> gems)
{

    set<string> s(gems.begin(), gems.end()); //보석 종류를 기억(중복 x)
    unordered_map<string, int> container;    //현재 어떤 보석을 몇개 담고 있는지 알고 있기 위해
    int kinds = s.size();                    //총 보석 종류
    int start = 0, end = 0;
    int shortest = INT_MAX;   //가장 짧은 길이를 기억
    vector<int> answer(2, 0); // [start,end]

    while (end < gems.size()) // end가 끝까지 돌며
    {
        if (container.find(gems[end]) == container.end()) //현재 담은 적 없으면
        {
            container[gems[end]] = 1; // 1개 담음
        }
        else
        {
            container[gems[end]] += 1; //이미 담겨 있으면 더 담는다.
        }
        end++; //이동

        if (container.size() == kinds) //만약 현재 담은 보석 종류가 모든 보석 종류를 담았다면
        {
            while (start < end)
            {

                if (container[gems[start]] <= 1) //현재 시작점이 가르키는 보석의담은 개수가 1이하면 멈추고
                {
                    break;
                }
                container[gems[start]] -= 1; // 2개 이상이면 빼준다.
                start++;                     //빼야 하기때문에 시작점을 옮김
            }
            if ((end - start) < shortest) //만약 현재 길이보다 더 작다면 업데이트
            {
                answer[0] = start + 1;  //인덱스가 0부터 이므로 시작점은 +1
                answer[1] = end;        // end
                shortest = end - start; //이후 길이를 업데이트
            }
        }
    }

    return answer;
}