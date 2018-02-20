#include <iostream>
#define t_sum long long

using namespace std;

t_sum numbers[50001];
t_sum max_sum, temp_sum;
int n;

struct Position
{
    int start;
    int end;
};

int main()
{
    while(cin >> n)
    {
        max_sum = 0;
        for (int i = 0; i < n; i++)
            cin >> numbers[i];
        Position ruler;
        ruler.start = 0;
        ruler.end = n - 1;
        for (int i = ruler.start; i <= ruler.end; i++)
            max_sum += numbers[i];
        temp_sum = max_sum;
        while (ruler.start <= ruler.end)
        {
            //留左边
            t_sum left = temp_sum - numbers[ruler.end];
            //留右边
            t_sum right = temp_sum - numbers[ruler.start];
            
            if (left == right) { // 左右相等则忽略这两个的比较
                left += numbers[ruler.start];
                right += numbers[ruler.start];
                ruler.end--,ruler.start++;
            } else if (left > right) { //留大的
                ruler.end--;
            } else {
                ruler.start++;
            }
            //留最大的
            max_sum = max(temp_sum = max(left, right), max_sum);
        }
        cout << max_sum << endl;
    }
    return 0;
}
