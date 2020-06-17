#include <iostream>

using namespace std;

int main()
{
    long long x = 1,a,b, N;
    a = 1;
    b = 1+6*x;
    cin>>N;
    if(N==1)
    {
        cout<<1;
        return 0;
    }
    while(1)
    {
        if(N>=a && N<=b)
        {
            cout<<x+1;
            break;
        }
        x++;
        a = b+1;
        b+=6*x;
    }
    return 0;
}
