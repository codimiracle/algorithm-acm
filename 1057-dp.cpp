#include <iostream>
#include <cstring>

#define t_int unsigned long long

using namespace std;

t_int factorial(int n);

t_int dp[10001];

int n;

int main()
{
    memset(dp, -1, sizeof(dp));
    dp[0] = 1;
    while(cin >> n) {
        cout << factorial(n) << endl;
    }
    return 0;
}

t_int factorial(int n)
{
    if (dp[n] != -1) {
        return dp[n];
    } else {
        dp[n] = n * factorial(n - 1);
    }
    return dp[n];
}
