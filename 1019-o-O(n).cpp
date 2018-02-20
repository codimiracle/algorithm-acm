#include <iostream>

using namespace std;
int inverse; //逆序数
bool calc; //是否进行计算
//数组结构体
struct Array {
    int data[50000];
    int start;
    int end;
};

//数组操作
void ArrayInit(Array &arr);
void ArrayCreate(Array &arr, int data[], int start, int end);
void ArrayDump(Array arr);
//归并算法
void merge(Array a, Array b, Array &c);
//二路归并排序
void mergeSort(Array input, Array &result);

Array nil; //空数组


int main()
{
    int n;
    ArrayInit(nil);
    Array a,result;
    while (cin >> n) {
        inverse = 0;
        calc = true;
        ArrayInit(a);
        ArrayInit(result);
        for (int i = 0; i < n; i++)
            cin >> a.data[i];
        a.end = n - 1;
        mergeSort(a,result);
        cout << inverse << endl;
    }
    
    return 0;
}
void ArrayInit(Array &arr)
{
    arr.start = 0;
    arr.end = -1;
}
void ArrayDump(Array arr)
{
    cout << "Array { ";
    for(int i = arr.start; i <= arr.end; i++)
        cout << arr.data[i] << " ";
    cout << "}" << endl;
}
void ArrayCreate(Array &arr, Array data, int start, int end)
{
    arr = data;
    arr.start = start;
    arr.end = end;
}
void merge(Array a, Array b, Array &c)
{
    while (a.start <= a.end && b.start <= b.end) {
        if (a.data[a.start] <= b.data[b.start]) {
            c.data[++c.end] = a.data[a.start++];
        } else {
            c.data[++c.end] = b.data[b.start++];
            cout << "bs:" << b.start << endl;
            cout << "be:" << b.end << endl;
            inverse += b.start;
        }
    }
    while (a.start <= a.end) {
        c.data[++c.end] = a.data[a.start++];
    }
    while (b.start <= b.end) {
        c.data[++c.end] = b.data[b.start++];
    }
}
void mergeSort(Array input, Array &result)
{
    if ((input.end - input.start + 1) > 1) {
        Array a, b, c, d;
        int mid = (input.start + input.end) / 2;
        ArrayCreate(a, input, input.start, mid);
        ArrayCreate(b, input, mid + 1, input.end);
        ArrayInit(c);
        ArrayInit(d);
        mergeSort(a, c);
        mergeSort(b, d);
        merge(c,d,result);
    } else {
        merge(input, nil, result);
    }
}
