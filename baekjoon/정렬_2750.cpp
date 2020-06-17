//https://www.acmicpc.net/problem/2750


#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int N, temp;
    cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++)
    {
        cin>>A[i];
    }
    for(int i=0;i<N;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            if(A[i]>A[j])
            {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
    for(auto x:A)
    {
        cout<<x<<"\n";
    }
    return 0;
}