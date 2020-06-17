//https://www.acmicpc.net/problem/2751


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int N;
    cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++)
    {
        cin>>A[i];
    }
    sort(A.begin(),A.end());
    for(auto x:A)
    {
        cout<<x<<"\n";
    }
    return 0;
}