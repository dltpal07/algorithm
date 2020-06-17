//https://www.acmicpc.net/problem/1929


#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int a,b, cnt = 0, all_cnt = 0, sum = 0, min = 987654321, prime_num[1000001] = {0,1};
    cin.tie(NULL);
    cin>>a>>b;
    
    for(int i = 2;i<=b;i++)
    {
        for(int j=2;i*j<=b;j++)
        {
            prime_num[i*j] = 1;
        }
    }
    for(int i = a;i<=b;i++)
    {
        if(prime_num[i]!=1)
        {
            cout<<i<<"\n";
        }
    }
    
    return 0;
}

