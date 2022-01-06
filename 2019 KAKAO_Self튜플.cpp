#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
unordered_map<string, int> _m;

void insert(vector<int> &ans, vector<string> &s)
{
    for (const string &str : s)
    {
        string temp;
        for (const char &c : str)
        {
            if (isdigit(c)) //숫자면
            {
                temp.push_back(c); // temp에 추가
            }
        }
        if (!temp.empty() && _m[temp] == 0) // temp가 비어있지 않고 한번도 추가 안됬으면 추가
        {
            _m[temp] = 1;
            int conv = stoi(temp); // convert
            ans.push_back(conv);   //추가
        }
    }
}

bool comp(string str1, string str2)
{
    return str1.length() < str2.length();
}

vector<string> split(string s, char delim) // split
{
    vector<string> ret;
    stringstream ss(s);
    string temp;
    while (getline(ss, temp, delim))
    {

        ret.push_back(temp);
    }
    return ret;
}

void print(vector<string> v)
{
    for (const string &str : v)
    {
        cout << str << " ";
    }
}

vector<int> solution(string s)
{
    vector<int> answer;
    s.erase(s.length() - 1, 1);
    s.erase(0, 1);
    //양쪽 끝 제거
    vector<string> v0 = split(s, '{');
    //위에서 { 를 제거하고
    string s0; //담아둘 s0
    for (const string &str : v0)
    {
        for (const char &c : str)
        {
            s0.push_back(c); // { 를 제하고 s0에 넣음
        }
    }
    vector<string> s1 = split(s0, '}'); //마찬가지로 }를 제거
    sort(s1.begin(), s1.end(), comp);   //길이가 짧은게 앞으로
    vector<vector<string> > res;
    for (int i = 0; i < s1.size(); i++)
    {
        res.push_back(split(s1[i], ',')); // ,로 구분하여 넣어줌
    }
    for (vector<string> &s : res)
    {
        insert(answer, s); //최종 작업
    }

    return answer;
}