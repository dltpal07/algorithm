//https://www.acmicpc.net/problem/1436


#include <iostream>
#include <vector>
using namespace std;
bool get_six(int n){
    int cnt = 0, m;
    while(1)
    {
        if(n==0)
            break;
        m = n%10;
        n = n/10;
        if(m!=6)
        {
            cnt = 0;
        }
        else
            cnt++;
        if(cnt>=3)
        {
            return true;
        }
        
    }
    if(cnt>=3)
        return true;
    else
        return false;
}
int main()
{
    vector<int> A(10000);
    int N,i=0, cnt = 0;
    cin>>N;
    while(1)
    {
        if(get_six(i))
        {
            A[cnt] = i;
            cnt++;
        }
        if(cnt == 10000)
        break;
        i++;
    }
    
    cout<<A[N-1]<<endl;
    
    return 0;
}
