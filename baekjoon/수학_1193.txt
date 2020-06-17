#include <iostream>

using namespace std;

int get_num(int n)
{
    
    if(n==1)
    {
        return 1;
    }
    else
    {
        return n+get_num(n-1);
    }
}

int main()
{
    int N, num, a,b, cnt = 1,x,y;
    cin>>N;
    a = 1;
    b = 1;
    cnt =1;
    while(1)
    {
        if(N>=a && N<=b)
        {
            break;
        }
        cnt++;
        a = b+1;
        b = get_num(cnt);
        
    }
    // cout<<a<<" "<<b<<endl;
    x = 1;
    y = b-a+1;
    
    for(int i=0;i<b-N;i++)
    {
        x++;
        y--;
    }
    if(cnt%2==0)
    {
        cout<<y<<'/'<<x<<endl;
    }
    else
    {
        cout<<x<<'/'<<y<<endl;
        
    }
        
    
    return 0;
}
