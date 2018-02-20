#include <iostream>
#define t_sum long long

using namespace std;

t_sum numbers[50000];
int n;

t_sum segment(int start, int end);

int main()
{
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            cin >> numbers[i];
        t_sum result = segment(0, n - 1);
        cout << (result < 0 ? 0 : result) << endl;
    }
    return 0;
}

t_sum segment(int start, int end)
{
    t_sum sum = 0,maximum = 0;
    for (int i = start; i <= end; i++) {
        if (sum < 0)
            sum = 0;
        sum += numbers[i];
        maximum = max(maximum, sum);
    }
    return maximum;
}
