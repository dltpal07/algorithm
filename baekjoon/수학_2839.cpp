#include <iostream>

using namespace std;

int main()
{
    int cnt = 0,N, sum = 0, x,y, M;
    cin>>N;
    if(N%5==0)
    {
        cout<<N/5;
        
    }
    else
    {
        while(1)
        {    
            M = N;
            x = M/5 - cnt;
            M = M%5 + 5*cnt;
            if(M%3 == 0)
            {
                cout<<x+M/3;
                break;
            }
            else
            {
                cnt++;
            }
            if(cnt > N/5)
            {
                cout<<-1;
                break;
            }
        }
    }
    
    return 0;
}
