#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left=10; // *
    int right=12; // #
    for(const int& num:numbers)
    {
        int number= num==0? 11 : num; //이면 11로 대치 아니면 그대로
        if(number==1||number==4||number==7) //왼손
        {
            answer+="L";
            left=number;
        }else if(number==3||number==6||number==9) //오른손
        {
            answer+="R";
            right=number;
        }
        else
        {
            //number은 2580라인
            int l_dis=0;
            int r_dis=0;
            if(right%3==2) //만약 right값이 2580 라인이면
            {
                //number right 모두 2580  이므로 두 값 모두 3으로 나누면, 높이 알 수 있음
                //그 높이의 차가 결국 오른쪽 손가락과 목표 다이얼과 거리차
                r_dis=max(right/3,number/3)-min(right/3,number/3);
            }
            else // 오른손가락이 369 라인이면
            {
                //number는 2580 오른 손가락은 369라인 이므로
                //number+1 은 오른쪽 369라인으로 배치시켜 높이를 구할 수 있게 함 
                //그후 -right 후 /3을하면 높이차가 나옴 
                //이후 가로 한번 이동해야 하므로 +1(왼쪽으로)
                //2,9 일 때, 2를 +1 하여 3으로 옮겨 3과 9의 높이차 2,
                //이후 가로 이동 왼쪽으로 (3->2)
                r_dis=abs((number+1)-right)/3 +1;
            }
            if(left%3==2)
            {
                //number left 모두 2580  이므로 두 값 모두 3으로 나누면, 높이 알 수 있음
                //그 높이의 차가 결국 왼쪽 손가락과 목표 다이얼과 거리차
                l_dis=max(left/3,number/3)-min(left/3,number/3);
            }
            else //왼손이 147 라인
            {
                //number는 2580 왼 손가락은 147라인 이므로
                //number-1 은 왼쪽 147라인으로 배치시켜 높이를 구할 수 있게 함 
                //그후 -left 후 /3을하면 높이차가 나옴 
                //이후 가로 한번 이동해야 하므로 +1(오른으로)
                // 8 ,1 일때 8을 7로 옮겨  (1과 7의 높이차) =2 이후 오른쪽 이동 +1(7->8)
                l_dis=abs((number-1)-left)/3 +1;
            }
            
            //왼쪽이 최단 거리면 왼손 
            if(l_dis<r_dis)
            {
                left=number;
                answer+="L";
                continue;
            }
            else if(l_dis==r_dis) //같을 경우 어느손잡이 비교
            {
                if(hand=="left")
                {
                   left=number;
                    answer+="L";
                    continue; 
                }
                else
                {
                    right=number;
                    answer+="R";
                    continue;
                }
            }
            else //오른손이 가까우면 오른손 
            {
                right=number;
                answer+="R";
                continue;
            }
        }
    }
    return answer;
}