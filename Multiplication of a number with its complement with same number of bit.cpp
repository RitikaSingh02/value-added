#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t; cin>>t;
    while(t--)
    {
        long long n ; cin>>n;
        int num = floor(log2(n))+1;
 
        long long c =  ((1 << num) - 1) ^ n;
        long long res = n * (c);
        cout<<res<<"\n";
    }
    return 0;
}
