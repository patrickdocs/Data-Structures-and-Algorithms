#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Đề bài: Cho 2 dãy kí tự s1, s2, tìm dãy con chung dài nhất của s1 và s2.
// Dãy con của s là một dãy thu được bằng cách xóa đi 0 hoặc một số phần tử trong s.
// Ví dụ: s1 = 'abcb', s2 = 'bdcab', kết quả là 'bcb' với độ dài 3.
/* Giải bài này bằng Quy hoạch động:
 * - Gọi c[i][j] là độ dài dãy con chung dài nhất của 2 dãy a[1..i] và b[1..j]
 * - Nếu a[i] = b[j], c[i][j] = c[i-1][j-1] + 1
 * - Nếu a[i] != b[j], c[i][j] = max(c[i-1][j], c[i][j-1])
 */
string a = "Patrick"; string b = "Jack";
int memory[1000][1000]; //memory[i][j] = -1: lcs(i, j) chua duoc tinh bao gio

int lcs(int i, int j) {
    if (i == -1 || j == -1) return 0;
    if (memory[i][j] != -1) return memory[i][j];
    if (a[i] == b[j]) { 
        memory[i][j] = lcs(i - 1, j - 1) + 1;
    }
    else {
        memory[i][j] = max(lcs(i, j -1), lcs(i - 1, j));
    }
    return memory[i][j];
}

void trace(int i, int j) {
    if (i == -1 || j == -1) return;
    if (a[i] == b[j] && memory[i][j] == memory[i - 1][j - 1] + 1) {
        trace(i - 1, j -1);
        cout << a[i] << "";
        return;
    }
    if (memory[i][j] == memory[i][j - 1]) {
        trace(i, j -1);
        return;
    }
    if (memory[i][j] == memory[i-1][j]) {
        trace(i - 1, j);
        return;
    }
}

int main()  {
    memset(memory, -1, sizeof(memory));
    int m = a.length(); int n = b.length();
    
    int result = lcs(m - 1, n - 1);
    cout << "Do dai day con chung dai nhat: " << result << endl;
    
    cout << "Day con chung do la: ";
    trace(m - 1, n - 1);
    return 0;
}
