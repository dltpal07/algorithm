#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int T,H,W,N,cnt = 1,a,b;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        cin>>H>>W>>N;
        cnt = 1;
        a = N%H;
        b = N/H+1;
        if(a==0)
        {
            a+=H;
            b--;
        }
        cout<<a<<setw(2)<<setfill('0')<<b<<endl;
    }
    
    return 0;
}

