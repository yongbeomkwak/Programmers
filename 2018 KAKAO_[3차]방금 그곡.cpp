#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define MAX 101

int _time[MAX];
int _songLen[MAX];
vector<string> split(const string s,const char delim=',')
{
    vector<string> ret;
    stringstream ss(s);
    string temp;
    
    while(getline(ss,temp,delim))
    {
        ret.push_back(temp);
    }
    return ret;
}

int calc_time(const string start,const string end)
{
    vector<string> st=split(start,':');
    vector<string> et=split(end,':');
    int hour=stoi(et[0])-stoi(st[0]);
    int min=hour*60+stoi(et[1])-stoi(st[1]);
    return min;
}

void print(vector<string> v)
{
    for(const string& s:v)
    {
        cout << s<< " ";
    }
    cout << endl;
}

bool cmp(pair<int, string> a, pair<int, string> b) {
    return a.first > b.first;
}


string solution(string m, vector<string> musicinfos) {
    string answer;
    vector<vector<string>> songs(musicinfos.size());
    
    for(int i=0;i<m.length();i++)
    {
        if(m[i]=='#')
        {
            m[i-1]=tolower(m[i-1]); //소문자
            m.erase(m.begin()+i); //# 지우기
        }
    }
    
    for(int i=0;i<musicinfos.size();i++)
    {
        songs[i]=split(musicinfos[i]); // 스플릿
        _time[i]=calc_time(songs[i][0],songs[i][1]);
    }
    
    int num_song=0;
    while(num_song<songs.size()) //모든 음악에 대하여 # 검사 
    {
        //songs 구조
        //["12:00,12:14,HELLO,CDEFGAB"]
        // 3번 인덱스가 음계
        for(int i=0;i<songs[num_song][3].length();i++)
        {
            char& curr_scale=songs[num_song][3][i];
            if(curr_scale=='#')
            {
                // C#을(소문자 변경 후 # 삭제) c로 변경 ,A# -> a로 변경
                char& prev_scale=songs[num_song][3][i-1];
                prev_scale=tolower(prev_scale); //소문자
                songs[num_song][3].erase(songs[num_song][3].begin()+i); //현재문자열에서 #삭제
            }
        
            _songLen[num_song]=songs[num_song][3].length(); //실제 곡 길이 저장
        }

        num_song++; //곡 번호 증가
    }
    
    vector<pair<int,string>> last_candidate_song;  //후보곡들 저장 벡터(시간,곡명)
    
    for(int i=0;i<songs.size();i++)
    {
        string tmp;
        int len=_songLen[i]; 
        const string& song=songs[i][3];
        for(int j=0;j<_time[i];j++)
        {
            tmp+=song[j%len]; //시간이 곡 길이보다 넘을 경우 반복 재생을 위한 나머지 연산자
        }
        cout <<  "tmp: "<< tmp <<endl;
        if(tmp.find(m)!=string::npos) //찾으면 후보 등록
        {
            last_candidate_song.push_back({_time[i],songs[i][2]}); //재생시간,노래 제목 삽입
         
        }
       
    }
    
    
  
    
    if(last_candidate_song.empty())
    {
        answer="(None)";
    }
    else
    {
        //조건을 부합하는 후보곡 들이 많을 경우 재생시간 기준 정렬 후 가장 앞에꺼
        stable_sort(last_candidate_song.begin(),last_candidate_song.end(),cmp);
        answer=last_candidate_song[0].second;
    }
    
    
    return answer;
}