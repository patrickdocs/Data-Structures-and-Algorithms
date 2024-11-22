#include <iostream>
#define MAX 100
using namespace std;

// Đề bài: Tìm trọng lượng (tổng) của dãy con lớn nhất trong dãy a[0], a[1], ..., a[n - 1]

int n;
int a[MAX];
int memory[MAX];
int comp[MAX] = {0};


int max(int a, int b) {
    return a > b ? a: b;
}

int max_sum(int i) {
    if (i == 1) return a[i];
    if (comp[i]) return memory[i];
    int res = max(a[i], a[i] + max_sum(i - 1));
    memory[i] = res;
    comp[i] = 1;
    return res;
}
int main()
{
    cout<<"Nhap n = ";; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    max_sum(n);
    int maximum = memory[1];
    int last = 1;
    for (int i = 2; i <= n; i++) {
        if (maximum < memory[i]) {
            maximum = memory[i];
            last = i; // chua phan tu a[last] la phan tu cuoi cung cua day con lon nhat
            
        }
    }
    int sum = maximum; int first;
    for (int k = last; k >= 1; k--) {
        sum -= a[k];
        if (sum == 0) {
            first = k;
            break;
        }
    }
    cout << "Trong luong lon nhat: " << maximum << endl;
    cout << "Gom cac phan tu: ";
    for (int k = first; k <= last; k++) {
        cout << a[k] << " ";
    }
        return 0;
}
