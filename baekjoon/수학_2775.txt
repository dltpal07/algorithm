#include <iostream>
#include <iomanip>
using namespace std;

int get_resident(int a,int b)
{
    int sum = 0;
    if(a == 0)
    {
        return b;
    }
    while(1)
    {
        sum+=get_resident(a-1, b);
        b--;
        if(b==0)
        {
            break;
        }
    }
    return sum; 
}

int main()
{
    int T,k,n;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        cin>>k>>n;
        cout<<get_resident(k,n)<<"\n";
    }
    
    return 0;
}

