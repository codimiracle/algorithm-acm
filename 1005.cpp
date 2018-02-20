#include <iostream>
#include <cstring>

using namespace std;

struct position
{
    int start;
    int end;
};

char a[10002];
char b[10002];
char c[100002];
short up[100002]; //进位

position a_cursor, b_cursor, c_cursor;

bool a_negative,b_negative,c_negative;

int main()
{
    while(cin >> a >> b)
    {
        memset(up, 0, sizeof(up));
        c_cursor.start = 100001;
        c_cursor.end = 100001;
        a_cursor.end = strlen(a) - 1;
        b_cursor.end = strlen(b) - 1;
        a_negative = a[0] == '-';
        b_negative = b[0] == '-';
        add();
    }
    return 0;
}

void add()
{
    position first = a_cursor;
    position second = b_cursor;
    if (!a_negative && !b_negative) {
        while(first.start <= first.end && second.start <= second.end) {
            position three = c_cursor;
            int result = (a[first.end--] - '0') + (b[second.end--] - '0');
            int left;
            if (!up[three.end]) {
                c[c_cursor.end] = '0';
            }
            while(result != 0) {
                left = result % 10;
                c[three.end++] += left;
                result /= 10;
            }
            c_cursor.end++;
        }
        while(first.start <= first.end){
            position three = c_cursor;
            if (!up[three.end]) {
                c[c_cursor.end] = '0';
            }
            
        }
        
        while(second.start <= second.end)
        {
            
        }
    } else if (a_negative && b_negative) {
        
    }
}


