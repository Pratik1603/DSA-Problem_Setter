#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;  // find_by_order, order_of_key 
#define ff first
#define ss second
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define ll long long
#define pb push_back
#define fl(i,n,m) for(int i=n;i<m;i++)
#define pii pair<int,int>
#define vi vector<int>
#define print(a) for(auto &it:a) cout<<it<<" "; cout<<endl
#define mii map<int,int>
#define setbits(x) __builtin_popcountll(x)
#define mp make_pair
#define all(a) a.begin(),a.end()
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
 
bool isPrime(int n)
{
    if (n <= 1)  return false;
    if (n <= 3)  return true;
    if (n%2 == 0 || n%3 == 0) return false;
    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
        return false;
    return true;
}
 
int pw(ll int a, ll int b, ll int m) {
    if(b==0) {
        return 1;
    }
 
    if(b%2 == 0) {
        ll int t = pw(a, (b/2), m);
        return (1ll*t*t)%m;
    }
    else {
        ll int t = pw(a, (b-1)/2, m);
        t = (1ll*t*t)%m;
        return (1ll*a*t)%m;
    }
}
 
void seive(){
    int n;
    vector<int>prm;
    bool is_prime[n + 1];
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0]=is_prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
}
for (int i = 2; i <= n; i++) {
    if (is_prime[i]) {
        prm.pb(i);
    }
}
//Used to find the multiplicity of prime factorization
// 	for(int i=0;i<n;i++){
//		for(int j=0;j<prm.size();j++){
//			if(v[i]%prm[j]==0){
//				while(v[i]%prm[j]==0){
//					[i]/=prm[j];
//				}
//				mp1[prm[j]]++;
//			}
//		}
//	}
}
 
void init(){ // used to find the prime ,but also the smallest prime number of non prime , if prm[i]=0 then it is prime
    vector<int> prm(10000001,0);
    prm[1]=1;
    for(int i=2;i<=1e7;i++)
    {
        if(prm[i])
             continue;
        prm[i]=i;
        for(int j=2*i;j<=1e7;j+=i)
        {
            if(prm[j]!=0)
            continue;
            prm[j]=i;
        }
    }
    cout<<prm[10];
}
 
const int N=500000;
const ll int mod = 1e9 + 7;
void findFact(){
    vector<vector<ll>>fact(N);
    for(ll i=0;i<N;i++){
        ll el=6; // v[i]
        vector<ll>temp;
        for(ll j=1;j*j<=el;j+=1){
            if(el%j==0){
                temp.pb(j);
                if(j!=el/j ){
                    temp.pb(el/j);
                }
            }
        }
        fact[i]=temp;
    }
}
void primeMul(){
    vector<int> prime(N + 1, -1);
        for(int i=2; i<=N; i++)
            {
                if(prime[i] == -1)
                {
                    for(int j=i; j<=N; j+=i)
                        prime[j] = i;
                }
            }  // To find the greatest prime of a number
            int ans = 0;
            for(int i=0; i<=N; i++) // finding multiplicity
            {
                int val = i;
                 while(val != 1)
                {
                    val /= prime[val];
                    ans++;
                }
            }
            cout<<ans<<endl;
}
 
 
ll dp1[1<<22];
ll dp2[1<<22];
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
void for1(ll dp[]){
    for (ll i=0;i<22;++i) {
        for (ll mask=0; mask<(1<<22);mask++) {
            if ((mask&(1<<i))) {
                dp[mask] = mod_add(dp[mask], dp[mask^(1<<i)],mod);
            }
        }
    }
}
void for2(ll dp[]) {
    for (ll i = 0; i < 22; i++) {
         for (ll mask = 0; mask < (1 << 22); mask++) {
            if ((mask & (1 << i))) {
                dp[mask ^ (1 << i)] = mod_add(dp[mask ^ (1 << i)], dp[mask],mod);
            }
        }
    }
}
ll int fact[N], invfact[N];
void inv() {
    ll int p = mod;
    fact[0]=1;
    int i;
    for(i=1; i<N; i++) {
        fact[i] = (i*fact[i-1])%p;
    }
    i--;
    invfact[i] = pw(fact[i], p-2, p);
    for(i--; i>=0; i--) {
        invfact[i] = (invfact[i+1]*(i+1))%p;
    }
}
 
int ncr(int n, int r) {
    return (((fact[n]*invfact[r])%mod)*invfact[n-r])%mod;
}
 
string  S;
string T;
int cnt[2];
int A[514514];
char buf[514514];
 
int main() {
  scanf(" %s", buf);
  S = buf;
  scanf(" %s", buf);
  T = buf;
 
  for (char c : S) {
    cnt[c-'0']++;
  }
 
  A[0] = -1;
  int j = -1;
  for (int i = 0; i < T.size(); i++) {
    while (j >= 0 && T[i] != T[j]) j = A[j];
    j++;
    A[i+1] = j;
  }
 
  int M = T.size();
  int k = M-A[M];
  string ans;
  while (1) {
    bool fail = false;
    rep(i, k) {
      char c = T[i];
      if (cnt[c-'0'] == 0) {
        fail = true;
        break;
      }
 
      cnt[c-'0']--;
      ans += c;
    }
 
    if (fail) {
      rep(i, 2) {
        rep(j, cnt[i]) {
          ans += char('0'+i);
        }
      }
      break;
    }
  }
  printf("%s\n", ans.c_str());
}
 