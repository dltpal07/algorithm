#include <iostream>

using namespace std;

int main()
{
    long long A, B, V, cnt = 1;
    cin.tie(NULL);
    cin>>A>>B>>V;
    if((V-B)%(A-B) == 0)
    {
        cnt = (V-B)/(A-B);
    }
    else
    {
        cnt = (V-B)/(A-B) + 1;
    }
    cout<<cnt;
    
    return 0;
}

