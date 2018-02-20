#include <iostream>
#include <cstring>

using namespace std;

char a[1001];
char b[1001];
int a_len, b_len;
char* dp[1001][1001];

int main()
{
    while (cin >> a >> b)
    {
        a_len = strlen(a);
        b_len = strlen(b);
        memset(length, 0, sizeof(dp));
        cout << longestCommonSubsequence(a_len - 1, b_len - 1);
    }
    return 0;
}

char* longestCommonSubsequence(int as, int bs)
{
    char* result;
    if (dp[as][bs] != NULL) {
        return dp[as][bs];
    }
    if (as > bs && bs == 0) {
        result = a[as];
    } else if (bs > as && as == 0) {
        result = b[bs];
    } else {
        char* first = longestCommonSubsequence(as - 1, bs);
        char* second = longestCommonSubsequence(as, bs - 1);
        result = (strlen(first) > strlen(second)) ? first : second;
        if (a[as] == b[bs]) {
            result = strcat(result, a[as]);
        }
    }
    dp[as][bs] = result;
    return result;
}
