#include <bits/stdc++.h>
using namespace std;

const long int MOD = 1e9 + 7;

long long fact(int x)
{
    long long result = 1;
    for(int i = 1; i <= x; i++)
    {
        result = (result * i) % MOD;
    }
    return result;
}
long long inv_mod(int x)
{
    long long result = 1;
    long long power = MOD - 2;
    while(power >  0)
    {
        if(power % 2 == 1)
        {
            result = (result * x) % MOD;
        }
        x = (x * x) % MOD;
        power /= 2;
    }
    return result;
}
long long nPr(int n, int r)
{
    long long n_fact = fact(n);
    long long r_fact = fact(r);
    long long n_r_fact = fact(n-r);

    long long inv_fact_nr = inv_mod(n_r_fact);
    long long inv_fact_r = inv_mod(r_fact);

    return (n_fact * inv_fact_nr % MOD * inv_fact_r % MOD)%MOD;
}
int main()
{
     int t;
     cin >> t;
     
     while(t--)
     {
        int n, r;
        cin >> n >> r;
        long long result = nPr(n, r);
        cout << result << endl;
     }
     return 0;
}