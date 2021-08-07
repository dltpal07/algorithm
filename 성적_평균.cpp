//https://softeer.ai/practice/info.do?eventIdx=1&psProblemId=389

#include <iostream>
#include <cmath>
using namespace std;

int grade[1000005];

int main()
{
    int N, k, tmp;
    cin >> N >> k;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        grade[i] = tmp;
        if (i > 0)
            grade[i] += grade[i - 1];
    }
    int a, b;
    for (int i = 0; i < k; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        double answer;
        answer = (double)(grade[b] - grade[a - 1]) / (b - a + 1);
        cout << fixed;
        cout.precision(2);
        cout << answer<<endl;
    }
    return 0;
}
