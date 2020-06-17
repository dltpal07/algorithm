//https://www.acmicpc.net/problem/2581


#include <iostream>
#include <vector>
using namespace std;


int main()
{
    vector<int> prime_num;
    int a,b, cnt = 0, all_cnt = 0, sum = 0, min = 987654321;
    cin>>a>>b;
    
    for(int i=a;i<=b;i++)
    {
        cnt = 0;
        for(int j=1;j<=i;j++)
        {
            if(i%j == 0)
            {
                cnt++;
            }
        }
        if(cnt == 2)
        {
            prime_num.push_back(i);
        }
    }
    for(auto x: prime_num)
    {
        if(min>x)
        {
            min = x;
        }
        sum += x;
    }
    if(prime_num.size()==0)
    {
        cout<<-1;
    }
    else
    {
        cout<<sum<<"\n"<<min;
    }
    return 0;
}

