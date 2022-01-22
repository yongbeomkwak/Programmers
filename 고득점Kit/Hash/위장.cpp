#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

int solution(vector<vector<string> > clothes)
{
    int answer = 1;

    unordered_map<string, int> um;

    for (vector<string> cloth : clothes)
    {
        string kind = cloth[1];
        um[kind]++;
    }

    /*
     상의 가 주어졌을 때, 상의는 반팔, 긴팔, 셔츠 3가지라고 하자.
     (i=3)
     이때 상의를 고르는 경우의 수는
     반팔,긴팔,셔츠,선택 안 함
     으로 총 4가지이다.
     그로므로 옷종류 +1, i+1=4 가 총 경우의 수
    이 경우는 상의, 하의, 신발 모두 선택 안 했을 때의 경우가 포함되므로 -1을 해주자
    */
    for (auto it = um.begin(); it != um.end(); it++)
    {
        answer *= (it->second) + 1;
    }

    return --answer; //모두 입지 않았을 때를 제외 -1
}