#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
int linearSearch(const vector<int>& a, int target) {
    for (int i = 0; i < (int)a.size(); ++i) if (a[i] == target) return i;
    return -1;
}
int main() {
    const int reps = 2000;
    for (int n : {10, 100, 500, 1000, 5000, 10000, 50000}) {
        vector<int> a(n);
        for (int i=0;i<n;++i) a[i]=i;
        volatile int sink = 0;
        auto start = chrono::high_resolution_clock::now();
        for (int r=0;r<reps;++r) sink += linearSearch(a, -1);
        auto end = chrono::high_resolution_clock::now();
        double us = chrono::duration<double, micro>(end-start).count() / reps;
        cout << n << "," << us << "\n";
    }
}
