//https://www.acmicpc.net/problem/1978


#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
    int n, a, cnt = 0, all_cnt = 0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        cnt = 0;
        for(int j=1;j<=a;j++)
        {
            if(a%j == 0)
            {
                cnt++;
            }
        }
        if(cnt == 2)
        {
            all_cnt++;
        }
    }
    cout<<all_cnt;
    return 0;
}

