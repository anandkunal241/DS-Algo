/*
  KUNAL ANAND
  MNNIT ALLAHABAD
*/  
 
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<assert.h>
using namespace std;
using namespace __gnu_pbds;
#define boost ios::sync_with_stdio(0); cin.tie(0)
#define debug1(x) cout << # x << " " << x << endl;
#define debug2(x,y) cout << #x << " " << x << " " << #y << " " << y << endl;
#define debug3(x,y,z) cout << #x << " " << x << " " << #y << " " << y << " " << #z << " " << z << endl;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
typedef long long int ll;
typedef long double ld;
const ll INF=1000000;
const ll mod=1e9+9;
 
ll fact[200005];
 
ll power(ll x,ll y,ll mod)
{
    if(y==0)
        return 1;
    ll a=power(x,y/2,mod);
    a=(a*a)%mod;
    if(y%2)
        a=(a*x%mod)%mod;
    return a;
}
 
ll nCr(ll n,ll r, ll mod)
{
    if(n<r)
        return 0;
    if(r==0||r==n)
        return 1;
    ll a,b,c;
    a=fact[n];
    b=(fact[r]*fact[n-r])%mod;
    b=power(b,mod-2,mod);
    a=(a*b)%mod;
 
    return a;
}
 
ll arr[1000005];
 
ll fun(ll cap,ll n)
{
    ll sum=0,i;
 
    for(i=0;i<n;i++)
    {
        sum+=arr[i]/cap;
 
        if(arr[i]%cap)
            sum++;
    }
 
    return sum;
}
int main()
{
    boost;
    ll t,y;
    t=1;
    //cin >> t;
 
    while(true)
    {   
        ll i,j,k,n,a,b,c,maxi=0,ans=0,x,cnt=0,h,l,r,q,idx,ans1=1,ans2=0,ans3=0,d,m,z;
 
        cin >> n >> b;
 
        if(n==-1)
            return 0;
 
        for(i=0;i<n;i++)
            cin >> arr[i];
 
        ll low=1,high=1e7,mid;
 
        while(low<=high)
        {
            mid=(low+high)>>1;
            //debug1(mid);
            a=fun(mid,n);
            //sdebug1(a);
            if(a<=b)
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
 
        cout << ans << endl;
 
    }
 
 
    
    return 0;
}    