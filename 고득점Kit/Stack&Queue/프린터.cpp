#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;
    vector<int> prop = priorities;
    queue<pair<int, int> > q; // first:우선순위,second:location

    for (int i = 0; i < priorities.size(); i++)
    {
        q.push({priorities[i], i});
    }

    int top_idx = prop.size() - 1;
    sort(prop.begin(), prop.end()); // prop 우선순위 벡터를 오름차순

    int cnt = 1; //몇번 째 인쇄일 때 location 작업이 출력되는가
    while (1)
    {
        int rank = q.front().first;
        /
            int task_num = q.front().second;
        if (rank != prop[top_idx]) //현재  큐 가장 위 우선순위와 출력되야하는 최고 우선순위 값과 다르면
        {
            q.pop(); // top에서 뽑은 후 뒤로 삽입한다.
            q.push({rank, task_num});
        }
        else
        {
            if (task_num == location) //만약 location과 task_num이 같으면 해당 문서가 출력될 차례
            {
                answer = cnt;
                break; //작업 멈춤
            }
            q.pop();   //만약 해당 location이 아니면 그냥 뽑고
            top_idx--; //최고 우선순위 인덱스를 다음 낮은 순위로 옮김
            cnt++;     //다음차례로 증가
        }
    }

    return answer;
}