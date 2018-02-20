#include <iostream>
using namespace std;
int n;
int numbers[50000];
int inverse;
int main()
{
    while(cin >> n) {
        int inserted = 0;
        inverse = 0;
        for (int i = 0; i < n; i++) {
            cin >> numbers[i];
            inserted++;
            for (int j = 0; j < inserted;j++) {
                if (numbers[j] > numbers[i])
                    inverse++;
            }
        }
        cout << inverse << endl;
    }
    return 0;
} 
