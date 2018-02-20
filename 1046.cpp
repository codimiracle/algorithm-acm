#include <iostream>
#define ull unsigned long long

using namespace std;

ull a,b,c;

ull solve(ull times, ull result);

int main()
{
    while (cin >> a >> b >> c)
    {
        cout << solve(b, a) << endl;
    }
    return 0;
}

ull solve(ull times, ull result)
{
    if (times == 0) {
        return result;
    } else {
        result = (result * a) % c;
        return solve(times - 1, result);
    }
}
