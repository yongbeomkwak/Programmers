#include <bits/stdc++.h>

using namespace std;
typedef vector<string>::iterator It;
int solution(int cacheSize, vector<string> cities)
{

    vector<string> q;
    int duration = 0;

    for (It it = cities.begin(); it != cities.end(); it++)
    {
        transform(it->begin(), it->end(), it->begin(), ::tolower); //소문자로 변경

        bool flag = false; // hit 여부
        for (It itt = q.begin(); itt != q.end(); itt++)
        {
            if (*itt == *it)
            {                //값이 갔다면
                flag = true; // hit
                duration += 1;
                q.erase(itt);     //해당 위치 제거
                q.push_back(*it); //해당 값 뒤로 삽입
                break;            //다음 꺼
            }
        }
        if (!flag)
        { // hit이 아니면 miss
            duration += 5;
            if (cacheSize != 0 && q.size() >= cacheSize) //만약 사이즈가 넘었다면
                q.erase(q.begin());                      //가장 앞에꺼 제거
            if (q.size() < cacheSize)                    //사이즈가 아직 넘지 않앗다면
                q.push_back(*it);                        //뒤에 삽입
        }
    }

    return duration;
}