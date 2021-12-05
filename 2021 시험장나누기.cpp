#include <bits/stdc++.h>

using namespace std;
#define MAX 10001
#define INF 987654321
int root = 0;
int _count = 0;
int _left[MAX];   //_left[i]= i의 왼쪽 자식
int _right[MAX];  // _right[i]= i의 오른쪽 자식
int _parent[MAX]; //_parent[i]= i의 부모
vector<int> group;
void Make_Binary_Tree(vector<vector<int> > &links)
{
    //이진 트리 만들기
    memset(_left, -1, sizeof(_left));
    memset(_right, -1, sizeof(_right));
    memset(_parent, -1, sizeof(_parent));
    //모든 배열 -1 초기화
    for (int i = 0; i < links.size(); i++)
    {
        int left = links[i][0];
        int right = links[i][1];

        if (left != -1) //-1 가 아니면 왼쪽 자식이 있으므로
        {
            _left[i] = left;   // i의 왼쪽을 left로 저장
            _parent[left] = i; // 해당 왼쪽의 부모는 i
        }
        if (right != -1)
        {
            _right[i] = right;  // i의 오른쪽을 right
            _parent[right] = i; // right의 부모를 i
        }
    }

    for (int i = 0; i < links.size(); i++)
    {
        if (_parent[i] == -1) //최상위 root 구하기
        {
            root = i;
            break;
        }
    }
}

int dfs(const int now, const int limit)
{
    int lc = 0, rc = 0;

    if (_left[now] != -1)
        lc = dfs(_left[now], limit);
    if (_right[now] != -1)
        rc = dfs(_right[now], limit);
    //왼쪽과 오른쪽이 -1이 아니면 자식이 존재하므로 탐색  ㄱㄱ
    //대신 limit를 달고간다
    if (group[now] + lc + rc <= limit) //탐색후 세 개의 합이 limit을 넘기지 않으면 그룹을 만들필요 없음 그대로 모든 값을 위로 올림
    {
        return group[now] + lc + rc;
    }

    if (group[now] + min(lc, rc) <= limit) //만약 현재 노드와 자식노드 둘중 작은것의 합이 limit를 넘어버리면 그룹 하나 추가 ,이후 현재노드와 자식노드의 최솟값의 합을 위로 올림
    {
        _count++; // 그룹추가
        return group[now] + min(lc, rc);
    }

    //마지막으로 위 2케이스가 안된다는 것은 어떤 자식노드랑 합하여도 limit를 넘어버리면 어떤 노드도 같은 그룹으로 만들 수 없으므로 그룹을 2 개추가해야함
    _count += 2;       //그룹 2개 추가
    return group[now]; //자기 자신만 갖고 올라감
}

int search(const int limit)
{
    _count = 0;
    dfs(root, limit); //최상위 root부터 제한값 limit를 가지고 탐색 ㄱ
    _count += 1;

    return _count;
}

int solution(int k, vector<int> num, vector<vector<int> > links)
{
    int answer = 0;
    Make_Binary_Tree(links);
    group = num;
    for (int i = 0; i < group.size(); i++)
    {
        answer = max(answer, group[i]); //일단 가장 최대값으로 가져간 후
    }

    int end = 10000 * 10000;

    while (answer < end)
    {
        int mid = (answer + end) / 2; // 2분 탐색ㄱㄱ

        if (search(mid) <= k) //만약 탐색 후 최종 그룹 수가 요구조건인 k 이하면 성공
        {
            end = mid; //다시 범위 줄인 후 탐색
        }
        else
        {
            answer = mid + 1; //만족하는 제한 값을 찾았으므로 최대 그룹인원 수는 제한인원수 +1
        }
    }

    return answer;
}