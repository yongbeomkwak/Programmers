#include <bits/stdc++.h>

using namespace std;

template <typename T>
void print(vector<T> &v)
{
    for (const T &s : v)
    {
        cout << s << " ";
    }
    cout << endl;
}

int conv_h_to_mm(const string &s)
{
    int h = stoi(s.substr(0, 2));
    int mm = stoi(s.substr(3, 3));
    return h * 60 + mm;
}

string conv(const int &i)
{
    string h = to_string(i / 60);
    if (h.length() == 1)
        h.insert(0, "0");

    string mm = to_string(i % 60);
    if (mm.length() == 1)
        mm.insert(0, "0");
    return h + ":" + mm;
}

string solution(int n, int t, int m, vector<string> timetable)
{

    /**
    09:00부터
    n=셔틀 운행 횟수
    t=운행 간격(분)
    m=크루 수
    timetable=크루들 대기열
    **/

    vector<int> ItimeTable;

    for (const string &s : timetable)
    {
        ItimeTable.push_back(conv_h_to_mm(s)); //승객 도착시간들을 분으로 머두 바꿔넣음
    }
    sort(ItimeTable.begin(), ItimeTable.end(), greater<int>()); //이후 내림차순

    int t_start = 540;    // 셔틀 첫 출발 시간=09:00 -> 540
    const int interv = t; //셔틀 간격

    int ret = 0;
    int t_last = 0;             //가장 마지막에 탄 승객 시간
    for (int i = 0; i < n; i++) //운행 횟수 만큼 반복
    {
        int cnt = 0; //현재 버스 탑승인원
        //기다리는 승객이 남아있고
        //현재 시점에서 가장빠르게 온 승객의 시간<=현재 오는 셔틀버스 시간
        //아직 버스가 꽉 차지 않았다면
        while (!ItimeTable.empty() && ItimeTable.back() <= t_start && cnt < m)
        {
            t_last = ItimeTable.back(); //버스에 탄 인원 시간 저장
            cnt++;                      //버스인원 즈악
            ItimeTable.pop_back();      //버스에 탔으니 빼주고
        }

        if (cnt == m) //만약 버스가 만석이면
        {
            ret = t_last - 1; //가장 최적의 시간은 가장 마지막에 탄사람보다 1분 빠른 시간
        }
        else //버스가 만석이 아니면 버스가 오는 정확한 시간에 타면 됨
        {
            ret = t_start; //가장 최근 온 버스 시간
        }

        t_start += interv; //다음 버스로 이동
    }

    //마지막 버스가 까지 본 후 해당 형식에 맞게 변환
    string answer = conv(ret);

    return answer;
}