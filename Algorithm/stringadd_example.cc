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

int main() {
    string num1 = "123";
    string num2 = "321";
    cout << add(num1, num2) << endl;
    return 0;
}
