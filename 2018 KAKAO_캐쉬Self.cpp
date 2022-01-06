#include <bits/stdc++.h>

#define endl "\n"

using namespace std;



typedef list<string>::iterator iter;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int curr_count=0;
    list<string> _list;
    unordered_map<string,iter> cache;
    for(string& str:cities)
    {
        transform(str.begin(), str.end(), str.begin(),::toupper);
        if(cacheSize!=0)
        {
            if(curr_count!=cacheSize)//꽉 차지 않음 
            {
                
                if(cache.find(str)!=cache.end()) //캐쉬에 존재하면 1 담을 필요 없시 자리 옮김만 하면됨  
                {
                    answer+=1; //존재하므로 1 증가 
                    iter it=cache[str]; //해당 위치 얻고 
                    _list.erase(it); //해당 위치 값 지움
                    _list.push_front(str); //앞에 다시 넣고
                    cache[str]=_list.begin(); //캐쉬에 해당 키에 해당 list위치 넣기
                }
                else
                {
                    //없으니깐 담아야 하므로 개수 증가
                    curr_count++; //현재 담은 개수
                    answer+=5; //miss 므로 5
                    _list.push_front(str); //앞에 삽입
                    cache[str]=_list.begin(); //키에 해당 list위치 넣고
                }
            }
            else //꽉 찬 이후 잡업 
            {
                if(cache.find(str)!=cache.end()) //캐쉬에 존재하면 1 
                {
                    answer+=1; //존재하여 1 증가 
                    iter it=cache[str]; //자리 바꿈을 위한 이전 위치 얻고
                    _list.erase(it); //해당 위치 값 삭제 
                    _list.push_front(str);// 다시 앞으로 
                    cache[str]=_list.begin(); //앞에 값을 cahce가 기억
                }
                else
                {
                    answer+=5;//miss 5
                    cache.erase(_list.back()); //꽉 찼으므로 뒤에(가장 오래전에 쓴) 삭제
                    _list.pop_back(); //뒤에꺼 삭제
                    _list.push_front(str); // 앞에 새로운 값 삽입
                    cache[str]=_list.begin(); //위치 기억 
                }
            }
        }
        else
        {
            answer+=5;
        }
    }
   
    
    return answer;
}