// JAY SWAMINARAYAN //
// DIGANT SHELADIYA //
// Codeforces:Digant0204 //

#include<iostream>
#include<cstring>
#include<cstdio>
#include<set>
#include<string>
#include<map>
#include<stack>
#include<cmath>
#include<queue>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define test int t; cin>>t; while(t--)
#define pi (3.141592653589)
#define ll long long int
#define of(i, x, n) for (ll i = x; i >= n; i--)
#define f(i, x, n) for (ll i = x; i < n; i++)
#define fr(i, m) for (auto i : m)
#define vl vector<long long>
#define vs vector<string>
#define sl set<ll>
#define ss set<string>
#define sc set<char>
#define mll map<ll,ll>
#define mcl map<char,ll>
#define msi map<string,int>
#define msl map<string,ll>
#define pb push_back
#define pp pop_back
#define float double
#define all(v) (v).begin(), (v).end()
#define bll(v) (v).begin(), (v).end(),greater<int>()
#define fi first
#define se second
#define maxi *max_element
#define mini *min_element
#define min3(a, b, c) min(a, min(b, c))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define max3(a, b, c) max(a, max(b, c))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))
#define M 1000000007
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define rtn return
ll gcd(ll a, ll b)
{if (b == 0){rtn a;}rtn gcd(b, a % b);}
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll binpow(ll x,ll y)
{
    if(y==0){rtn 1;}
    if(y==1){rtn x;}
    ll ans=binpow(x,y/2);
    if(y%2==0){rtn (ans*ans);}
    rtn (ans*ans*x);
}
bool perfectsq(double x)
{
    if (x>=0)
    {ll sr = sqrt(x); rtn (sr*sr==x);}
    rtn false;
}
bool isprime(ll number)
{
    if (number <= 1)
        rtn false;
    if (number == 2)
        rtn true;
    if (number % 2 == 0)
        rtn false;
    ll boundary = (ll)floor(sqrt(number));
    for (ll i = 3; i <= boundary; i += 2)
        if (number % i == 0)
            rtn false;
    rtn true;
}
vl prime;
void primeFactors(ll n)
{
    ll c=2;
    while(n>1){if(n%c==0){prime.pb(c); n/=c;} else c++;}
}
ll nCr1[1001][1001];
ll nCr(ll n,ll r)
{
    if(nCr1[n][r])rtn nCr1[n][r];
    if(r==1) rtn nCr1[n][r]=n;
    if(n==r) rtn nCr1[n][r]=1;
    if(r==0) rtn nCr1[n][r]=1;
    rtn nCr1[n][r]=(nCr(n-1,r) + nCr(n-1,r-1));
}
// !(n&(n-1)) --> n==2^x n&(n-1) --> n!=2^x
vl sa;
//void precomp(){f(i,0,2e4+1){ll x=pow(i,2); sa.pb(x);}}
void solve()
{
     ll n;
    cin>>n;
    vl v(n),v1(n);
    f(i,0,n)
        v[i]=i;
    v1=v;
    ll j=n-1;
    while(j>=0)
        {
            ll c=v[j];
            auto it=lower_bound(all(sa),v[j])-sa.begin();
            ll cc=sa[it];
            reverse(v1.begin()+cc-c,v1.begin()+c+1);
            j=cc-c-1;
        }
    f(i,0,v1.size())
        {
            cout<<v1[i]<<" ";
        }
    cout<<endl;
}
int main()
{
    fast;
    f(i,0,2e4){sa.pb(i*i);}
    test
    solve();
    rtn 0;
}
