#include <bits/stdc++.h>

using namespace std;
int main()
{
    int a[4][4];
    int b[10];
    fill(b, b + 10, 7);
    //cout << b[0] << " " << b[9] <<endl;

    /*
	- 1차원 배열

	fill(arr, arr+10, 5);
 

	- 2차원 배열

	fill(&map[0][0], &map[MAX-1][MAX], value)
 

	- 백터

	1 차원
	fill (v.begin(), v.end(), 5);
	*/
	// 2차원 
	/*
	fill(mat.begin(), mat.end(), vector<int>(열 개수, 초기화값));
	*/

    //fill(&a[0][0],&a[2][2],3);
    //a[0][0] ~ a[2][1] 까지 3으로 초기화 됨 , 즉
    // [ROW][COL] 을 2번 째 매개변수에 넣으면
    // [ROW][COL-1] 까지

    /*for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
				{
					cout << a[i][j] << " ";
				}
			cout << endl;
		}
	*/

    //memset(arr,val,sizeof(arr))
    memset(a, 0, sizeof(a));
    //[0][0] 부터 9개 즉 [2][0] 까지 초기화 됨
    //[0][0]~ [0][3] 4개
    //[1][0]~ [1][3] 4개
    //[2][0] 1개

    /*	for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
				{
					cout << a[i][j] << " ";
				}
			cout << endl;
		}
*/

	//2차원 벡터
	vector<vector<int>> dp(size,vector<int>(n+1,0)); //초기값 0으로 n+1(열 개수) size(행개수) [size][n+1] 배열 2차원 벡터
	//1차원 벡터
	vector<int> temp(n+1,0) // n+1개를 0으로
	//벡터는 fill 또는 memset말고 생성자를 이용하는게 빠르고 편함
    return 0;
}