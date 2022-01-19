#include <bits/stdc++.h>

using namespace std;

#define DEAD "23:59"

bool cmp(pair<string,int> p1,pair<string,int> p2) //차량번호 오름차순
{
    return stoi(p1.first) <stoi(p2.first);
}


int calc_time(string start,string end) //주차 시간 계산하기
{
    vector<string> stime;
    vector<string> etime;

    stringstream ss(start);
    string tmp;
    while(getline(ss,tmp,':')) // : split하여 시와 분 나누기
    {
        stime.push_back(tmp);
   
    }
   
    ss.str(""); // 초기화 한다
    ss.clear(); // Clear state flags.
    ss<<end; //end 삽입
    
    while(getline(ss,tmp,':'))
    {
        etime.push_back(tmp); //마찬가지로 시와 분 
    }
    //cout << "S:" << stime.size()  << " E: " <<etime.size()<<endl;
//cout << stime[0] << " " <<  stime[1] << " " << etime[0] << " " << etime[1] << endl;
    
    // (출차 시 - 입차 시) * 60 + 출고 분 - 입차 분  하여 총 몇분 주차하였는지 구함 
    int min=(stoi(etime[0])-stoi(stime[0]))*60 + (stoi(etime[1])-stoi(stime[1]));
    
    
    return min;
}


vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    int base_time=fees[0]; //기본 시간
    int base_cost=fees[1]; //기본 요금
    int unit_time=fees[2]; // 단위 분 
    int unit_cost=fees[3]; // 단위 요금
    
    

   
    unordered_map<string,string> start_time; //시작 시간을 저장할 맵
    unordered_map<string,int> _map; //최종 시간을 저장할 맵
    
    
    for(const string& s:records)
    {
        stringstream ss(s);
        string sarr[3];
        ss >> sarr[0] >> sarr[1] >> sarr[2]; // 시각 차번호 입차내역
  
        if(sarr[2]=="IN") //IN일 경우 시작 시간 맵에 , 차량과 입차 시간을 넣음
        {
            start_time[sarr[1]]=sarr[0];
        }
        else //OUT 일 때 sarr[0]는 출차시간 
        {
            if(_map.find(sarr[1])==_map.end()) //최종시간이 없다면 넣고 있으면 더해주고
            {
                //최종시간 맵에 계산된 시간을 넣어줌
                _map[sarr[1]]=calc_time(start_time[sarr[1]],sarr[0]);
            }
            else
            {
                //기존에 있을 경우 더한다.
                _map[sarr[1]]+=calc_time(start_time[sarr[1]],sarr[0]);
            }
            start_time.erase(sarr[1]); //시간을 계산 했으므로 삭제한다.
        }    
    }
    
    for(auto it=start_time.begin();it!=start_time.end();it++) //만약 입차 시간은 있는데 출차 시간이 없을 경우
    {
        
        string remain_car=(*it).first;  //map의 key(차 번호)
        string park_time=(*it).second; //map의 입차 시간(string)
        if(_map.find(remain_car)==_map.end())
        {
            _map[remain_car]=calc_time(park_time,DEAD); //출차시간이 없을경우 endtime="23:59" 이 된다 DEAD="23:59"
            continue;
        }
        _map[remain_car]+=calc_time(park_time,DEAD); //마찬가지로 존재 시 더해줌
    }
    
     vector<pair<string,int>> machine;
    
     for(auto it=_map.begin();it!=_map.end();it++)
    {
        string car_tag=(*it).first;   
        int total_time=(*it).second;
        if(total_time<=base_time) //기본시간 이하일 경우 해당 차량번호는 기본 요금만
        {
            machine.push_back({car_tag,base_cost});
        }
        else //아니면 기본요금 + (초과시간 올림연산) * 유닛 요금
        {
            int cost=base_cost+(int)ceil((double)(total_time-base_time)/(double)unit_time) * unit_cost;
            machine.push_back({car_tag,cost});
        }
    }
    
    
    
    sort(machine.begin(),machine.end(),cmp); //차량 번호로 오름차순
    
    for(int i=0;i<machine.size();i++)
    {
        answer.push_back(machine[i].second); //요금을 넣어준다
    }
    
    
    return answer;
}