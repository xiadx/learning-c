#include<iostream>
using namespace std;

//int gcd(int a, int b) {
//    while (b != 0) {
//        int z = a % b;
//        a = b;
//        b = z;
//    } 
//    return a;
//}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    cout << gcd(20, 30) << endl;
    return 0;
}
