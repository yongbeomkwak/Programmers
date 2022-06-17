#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> gmap;
vector<int> answer(3, 0); //이게 중요함 3개 인덱스를 사용해 0은 0번째에 1은 1에 2는 2에 저장

int split(const int left, const int right, const int top, const int bottom, const int n)
{
    if (n == 1) // 1개 남았을 때 왼쪽 위에 것 리턴
    {
        return gmap[top][left];
    }

    int hmid = (left + right) / 2;                            //가로 중앙
    int vmid = (top + bottom) / 2;                            //세로 중앙
    int lt = split(left, hmid, top, vmid, n / 2);             //왼쪽 윗 값,left~hmid,top~vmid까지
    int rt = split(hmid + 1, right, top, vmid, n / 2);        //오른쪽 윗 값 hmid+1~right,top~vmid까지
    int lb = split(left, hmid, vmid + 1, bottom, n / 2);      //왼쪽 아랫값 left~hmid,vmid+1~bottom
    int rb = split(hmid + 1, right, vmid + 1, bottom, n / 2); //오른쪽 아랫값 hmid+1~right,vmid+1~bottom까지

    if (lt == rt && lt == lb && lt == rb)
        return lt; //만약 네 값이 모두 같을때는 그 값을 리턴

    //여기 왔다는 것은 하나라도 다르다는 것
    //해당 값의 개수를 모두 올려줌
    answer[lt]++;
    answer[rt]++;
    answer[lb]++;
    answer[rb]++;

    return 2; //그리고 쓸 대 없는 2를 리턴
}

vector<int> solution(vector<vector<int>> arr)
{
    gmap = arr;
    const int n = gmap.size();
    answer[split(0, n - 1, 0, n - 1, n)]++; //최종 압축 개수 역시 더 해줌 , 하나라도 다르면 2가 리턴

    answer.pop_back(); //이후 쓸대 없는 2는 제거
    return answer;
}