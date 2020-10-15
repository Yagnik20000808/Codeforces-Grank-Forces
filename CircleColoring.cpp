#include <bits/stdc++.h>
#include <numeric>
using namespace std;

typedef long long ll;
typedef long double ld;

#define endl "\n"
#define all(a) a.begin(), a.end()

//vectors
#define vi vector<int>
#define vll vector<ll>
#define viip vector<pair<int, int>>
#define vllp vector<pair<ll, ll>>
#define pb push_back

//loops
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define repp(i, a, b) for (ll i = (a); i < (b); ++i)
#define repr(i, a, b) for (ll i = (a); i >= (b); --i)

//pairs
#define pi pair<int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define F first
#define S second

const int modulo = int(1e9 + 7);
const int N = int(2e6 + 7);

bool sec(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first == b.first)
        return (a.second < b.second);
    else
    {
        return (a.first < b.first);
    }
}

bool sortbysec(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.second < b.second);
}

bool sortbysecdesc(const pair<int, int> &a,
                   const pair<int, int> &b)
{
    return a.second > b.second;
}
ll powM(ll x, ll y, ll m)
{
    ll ans = 1, r = 1;
    x %= m;
    while (r > 0 && r <= y)
    {
        if (r & y)
        {
            ans *= x;
            ans %= m;
        }
        r <<= 1;
        x *= x;
        x %= m;
    }
    return ans;
}

ll modI(ll a, ll m)
{
    ll m0 = m, y = 0, x = 1;
    if (m == 1)
        return 0;
    while (a > 1)
    {
        ll q = a / m;
        ll t = m;
        m = a % m;
        a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}

void solve()
{
    ll n;
    cin>>n;

    ll a[n],b[n],c[n];
    rep(i,n)
    cin>>a[i];
    rep(i,n)
    cin>>b[i];
    rep(i,n)
    cin>>c[i];
    vll p(n,0);
    ll f=0;
     p[0]=a[0];


    repp(i,1,n){
        
        if(f==0&&a[i]==p[i-1])
           {
               p[i]= b[i];
               f=1;
               continue;
           }
           if(f==0&&a[i]!=p[i-1])
           {
               
                p[i]= a[i];
               continue;
           }
        if(f==1&&b[i]==p[i-1])
           {
                p[i]= c[i];
               f=2; continue;
           }
           if(f==1&&b[i]!=p[i-1])
           {
              p[i]= (b[i]);
             continue;
           }
        if(f==2&&c[i]==p[i-1])
           {
                p[i]= (a[i]);
                f=0;
           }
           if(f==2&&c[i]!=p[i-1])
           {
                p[i]= (c[i]);
               
           }

    }


    if(p[n-1]==p[0]){
        if(p[n-2]!=a[n-1])
        p[n-1]=a[n-1];
    }
    if(p[n-1]==p[0]){
        if(p[n-2]!=b[n-1])
        p[n-1]=b[n-1];
    }
    if(p[n-1]==p[0]){
        if(p[n-2]!=c[n-1])
        p[n-1]=c[n-1];
    }
    if(p[n-1]==p[0]){
        if(p[n-2]!=a[n-1])
        p[n-1]=a[n-1];
    }


    for(auto i: p)
    cout<<i<<" ";
    cout<<endl;
}

int main()
{

    ios::sync_with_stdio(false);
     cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t = 1;
    cin>>t;

    while (t--)
    {
        solve();
    }

    return 0;
}
