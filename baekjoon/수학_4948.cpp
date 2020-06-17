//https://www.acmicpc.net/problem/4948

#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int n, cnt = 0, all_cnt = 0, sum = 0, min = 987654321, prime_num[1000001] = {0,1};
    cin.tie(NULL);
    while(1)
    {
        cin>>n;
        cnt = 0;
        if(n == 0)
        {
            break;
        }
        for(int i = 2;i<=2*n;i++)
        {
            for(int j=2;i*j<=2*n;j++)
            {
                prime_num[i*j] = 1;
            }
        }
        for(int i = n+1;i<=2*n;i++)
        {
            if(prime_num[i]!=1)
            {
                cnt++;
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}

