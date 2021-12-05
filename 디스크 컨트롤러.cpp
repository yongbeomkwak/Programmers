#include <bits/stdc++.h>

using namespace std;

struct cmp
{
    bool operator()(const vector<int> &v1, const vector<int> &v2)
    {
        return v2[1] < v1[1]; // 수행시간 오름차순
    }
};

int solution(vector<vector<int> > jobs)
{

    sort(jobs.begin(), jobs.end()); //시작시간 오름차순
    priority_queue<vector<int>, vector<vector<int> >, cmp> pq;
    int answer = 0;
    int task = 0; //작업 순서를 가르킬 인덱스
    int time = 0; //현재 시간

    while (!pq.empty() || task < jobs.size()) //디스크에 담겨있는 작업이 있거나,작업모두를 끝내지 않았다면
    {
        //현재시간이 다음 작업의 시작시간보다 클 때
        if (task < jobs.size() && time >= jobs[task][0])
        {
            pq.push(jobs[task++]); // 작업을 넣어준다 이후 task 증가
            continue;
        }
        //수행할 작업이 있으면
        if (!pq.empty())
        {
            //[0]:요청 시작시간  [1]:수행시간
            time += pq.top()[1];          //현재시간+수행시간= 작업 종료시간
            answer += time - pq.top()[0]; //총 작업완료 시간(작업종료시간 - 요청시작시간)
            pq.pop();                     //작업 종료
        }
        else
        {
            time = jobs[task][0]; //현재시간을 다음 작업 시작 시간으로(task를 위에서 증가시켜 놓음)
        }
    }

    return answer / jobs.size();
}