#include<iostream>
using namespace std;

string add(string num1, string num2) {
    int n = num1.size(), m = num2.size();
        if (n == 0 && m == 0) return "0";
        int i = n - 1, j = m - 1;
        int b = 0, a1, a2, c;
        string ans;
        while (i >= 0 && j >= 0) {
            a1 = num1[i] - '0';
            a2 = num2[j] - '0';
            c = a1 + a2 + b;
            b = c / 10;
            ans.push_back(c % 10 + '0');
            --i;
            --j;
        }
        while (i >= 0) {
            a1 = num1[i] - '0';
            c = a1 + b;
            b = c / 10;
            ans.push_back(c % 10 + '0');
            --i;
        }
        while (j >= 0) {
            a2 = num2[j] - '0';
            c = a2 + b;
            b = c / 10;
            ans.push_back(c % 10 + '0');
            --j;
        }
        if (b) {
            ans.push_back(b + '0');
        }
        reverse(ans.begin(), ans.end());
        return ans;
}

string multiply(string num1, string num2) {
    int n = num1.size(), m = num2.size();
    if (n == 0 || m == 0) return "0";
    if (num1 == "0" || num2 == "0") return "0";
    string ans = "0";
    for (int i = n-1; i >= 0; --i) {
        string cur;
        for (int j = n-1; j > i; --j) cur.push_back('0');
        int a1 = num1[i] - '0', a2, c, b = 0;
        for (int j = m-1; j >= 0; --j) {
            a2 = num2[j] - '0';
            c = a1 * a2 + b;
            b = c / 10;
            cur.push_back(c % 10 + '0');
        }
        while (b) {
            cur.push_back(b % 10 + '0');
            b /= 10;
        }
        reverse(cur.begin(), cur.end());
        ans = add(ans, cur);
    }
    return ans;
}

int main() {
    string num1 = "12", num2 = "13";
    cout << multiply(num1, num2) << endl;
    return 0;
}
