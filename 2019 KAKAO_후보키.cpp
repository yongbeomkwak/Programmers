#include <bits/stdc++.h>

#define endl "\n"

using namespace std;
// 최소성 확인
bool possi(vector<int> vec, int now)
{
    for (int i = 0; i < vec.size(); i++)
        // ans에 있던 조합이 이번에 들어온 조합이랑 같은 것인지 확인

        if ((vec[i] & now) == vec[i]) // ans이 가지고 있는 조합과 현재 조합이 같으면 최소성 실패
            return false;

    return true;
}

int solution(vector<vector<string> > relation)
{
    int rowSize = (int)relation.size();
    int colSize = (int)relation[0].size();
    vector<int> ans; //조건을 만족하는 조합들을 저장한 벡터

    // 조합 경우의 수
    /*
     1(0001) - 학번
     2(0010) - 이름
     3(0011) - 이름, 학번
     4(0100) - 전공
     5(0101) - 학번, 전공
     6(0110) - 이름, 전공
     7(0111) - 학번, 이름, 전공
     8(1000) - 학년
     9(1001) - 학번, 학년
     10(1010) - 이름, 학년
     11(1011) - 학번, 이름, 학년
     12(1100) - 이름, 학번
     13(1101) - 학번, 전공, 학년
     14(1110) - 이름, 전공, 학년
     15(1111) - 학번, 이름, 전공, 학년
     */
    for (int i = 1; i < (1 << colSize); i++)
    {
        // i(현재 조합)
        //모든 조합을 고려
        //컬럼 하나하나가 속성
        //예) 속성이 4개 이며 4개를 모두 사용하면 1111
        //    101(두번째)0(첫번째) 은 4번째와 두번째를 사용한다
        set<string> s;

        for (int j = 0; j < rowSize; j++)
        {
            // j 현재 행
            string now = "";

            for (int k = 0; k < colSize; k++)
            {
                //현재 colum
                // 선택된 컬럼과 일치한다면
                if (i & (1 << k)) //현재 colum과 현재 조합 colum들
                    // cout << i << " " << (1<<k) <<endl;
                    now += relation[j][k]; //해당 attribute 넣기
            }
            s.insert(now); //삽입
        }

        // s.size() == rowSize => 중복체크 , set은 중복이 허용이 안되므로
        // set의 크기가 rowSize와 같고 possi의 값이 true(최소성)이면 삽입
        if (s.size() == rowSize && possi(ans, i))
            ans.push_back(i);
    }

    return (int)ans.size();
}