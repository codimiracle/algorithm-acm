 #include <iostream>
 
 using namespace std;
 void quick_sort(int *nums, int p, int r);
 
 int numbers[50000];
 int n;
 int main()
 {

     while (cin >> n) {
         for (int i = 0; i < n; i++) {
             cin >> numbers[i];
         }
         quick_sort(numbers, 0, n - 1);
         for (int i = 0; i < n; i++) {
             cout << numbers[i] << endl;
         }
     }
 }
 void print() {
    for (int i = 0; i < n; i++) {
             cout << numbers[i] << " ";
    }
 }
 void swap(int &a, int &b) {
     int t;
     t = a;
     a = b;
     b = t;
 }
 int partition(int *nums, int p, int r) {
     int x = nums[r];
     int i = p - 1;
     for (int j = p;j <= r - 1; j++) {
         if (nums[j] <= x) {
             i = i + 1; 
             swap(nums[i], nums[j]);
         }
     }
     swap(nums[i + 1], nums[r]);
     return i + 1;
 }
 
 void quick_sort(int *nums, int p, int r)
 {
     int q;
     if (p < r) {
         q = partition(nums, p, r);
         quick_sort(nums, p, q - 1);
         quick_sort(nums, q + 1, r); // 1,2
     }
 } 
