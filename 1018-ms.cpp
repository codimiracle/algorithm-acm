#include <iostream>

using namespace std;

struct Position
{
    int start;
    int end;
};

int numbers[50001];
int results[50001];

int n;

void merge(Position a, Position b);
void mergeSort(Position s);

int main()
{
        while(cin >> n)
        {
            for (int i = 0; i < n; i++)
                cin >> numbers[i];
            Position s;
            s.start = 0, s.end = n - 1;
            mergeSort(s);
            for (int i = 0; i < n; i++)
                cout << results[i] << endl;
        }
}

void merge(Position a, Position b)
{
    Position c;
    c.start = a.start, c.end = b.end;
    int start = c.start, end = c.end;
    while (a.start <= a.end && b.start <= b.end)
    {
        if (numbers[a.start] <= numbers[b.start]) {
            results[c.start++] = numbers[a.start++];
        } else {
            results[c.start++] = numbers[b.start++];
        }
    }
    
    while (a.start <= a.end)
    {
        results[c.start++] = numbers[a.start++];
    }
    
    while (b.start <= b.end)
    {
        results[c.start++] = numbers[b.start++];
    }
    for (int i = start; i <= end; i++)
        numbers[i] = results[i];
}
void print(int start, int end)
{
    for (int i = start; i <= end; i++)
        cout << results[i] << " ";
    cout << endl;
}
void print(Position p)
{
    for (int i = p.start; i <= p.end; i++)
        cout << numbers[i] << " ";
    cout << endl;
}

void mergeSort(Position s)
{
    unsigned short length = s.end - s.start + 1;
    if (length != 1) {
        unsigned short mid = (s.start + s.end) / 2;
        Position a,b;
        a.start = s.start, a.end = mid;
        b.start = mid + 1, b.end = s.end;
        mergeSort(a);
        mergeSort(b);
        merge(a,b);
    }
}
