#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int fact[500000000];
int f(int n){
    if(fact[n] != 0) return fact[n];
    long long res = (long long)n*(long long)f(n-1);
    res = res%1000000007;
    fact[n]=(int)res;
    return fact[n];
}

int numberOfWays(int n) {
    fact[0] = 1;
    fact[1] = 1;
   int t = n/3;
    int b = n -t*3;
    long long res = 0;
    while(t>0){
        cout << t << ","<<b << endl;
        res += (f(t+b) - f(t) -f(b));
        if(res >= 1000000007) res-= 1000000007;
        t--;
        b+=3;
    }
    res++;
    if(res >= 1000000007) res-= 1000000007;
    return (int)res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    int result = numberOfWays(n);

    cout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
