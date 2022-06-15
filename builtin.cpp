#include <bits/stdc++.h>

int main()
{
    cout << "Number of 1 "<< __builtin_popcount(x)<< endl;
    cout << "가장 왼쪽의 1 앞의 0 개수(왼쪽 기준 1의 위치): "<<__builtin_clz(x) << endl;  // 25 
    cout << "가장 오른쪽 1의 뒤 0의 개수: "<<  __builtin_ctz(x) << endl; // 2
}