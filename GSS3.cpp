#include<bits/stdc++.h>
using namespace std;
#define INF -200000
struct data
{
 long long int left,right,cross,maxi;
};
typedef struct data data;
long long int A[100005];
data st[500005];
void build(long long int node,long long int low,long long int high)
{
	if(low==high)
	{
		st[node].left=st[node].right=st[node].cross=st[node].maxi=A[low];
		return;
	}
	long long int mid=(low+high)/2,a,b;
    build(2*node,low,mid);
    build((2*node)+1,mid+1,high);
    st[node].left=max((st[2*node+1].left+st[2*node].cross),st[2*node].left);
    st[node].right=max((st[2*node+1].cross+st[2*node].right),st[2*node+1].right);
    st[node].cross=st[2*node].cross+st[2*node+1].cross;
    st[node].maxi=max(st[2*node].maxi,max(st[2*node+1].maxi,(st[2*node].right+st[2*node+1].left)));
}
void update(long long int node,long long int low,long long int high,long long int idx,long long int val)
{
    if(low>high)
        return;
    if(low==high)
    {
        st[node].left=val;
        st[node].right=val;
        st[node].cross=val;
        st[node].maxi=val;
        return;
    }
    long long int mid=(low+high)/2;
    if(idx<=mid)
      update((2*node),low,mid,idx,val);
    else
      update((2*node)+1,mid+1,high,idx,val);
    st[node].left=max((st[2*node+1].left+st[2*node].cross),st[2*node].left);
    st[node].right=max((st[2*node+1].cross+st[2*node].right),st[2*node+1].right);
    st[node].cross=st[2*node].cross+st[2*node+1].cross;
    st[node].maxi=max(st[2*node].maxi,max(st[2*node+1].maxi,(st[2*node].right+st[2*node+1].left)));
}
data query(long long int node,long long int low,long long int high,long long int l,long long int r)
{
	if(low>r||high<l)
		return {INF,INF,INF,INF};
	if(low>=l&&high<=r)
	{
       return st[node];
    }    
	long long int mid=(low+high)/2,a,b,c;
	data ans1=query(2*node,low,mid,l,r);
    data ans2=query((2*node)+1,mid+1,high,l,r);
    a=max(ans1.left,(ans2.left+ans1.cross));
    b=max(ans2.right,(ans1.right+ans2.cross));
    c=ans1.cross+ans2.cross;
    return {a,b,c,max(ans1.maxi,max(ans2.maxi,(ans1.right+ans2.left)))};
}
int main()
{
   long long int t,k;
     long long int n,m,q,a,b,c,i;
     long long int ans;
     scanf("%lld",&n);
     for(i=1;i<=n;i++)
     {
     	scanf("%lld",&A[i]);
     }
     build(1,1,n);	
     //for(i=1;i<=2*n;i++)
       // printf("%lld %lld %lld %lld\n",st[i].left,st[i].right,st[i].cross,st[i].maxi);
     scanf("%lld",&m);
     while(m--)
     {
   	    scanf("%lld%lld%lld",&a,&b,&c);
        if(a==0)
        {
            update(1,1,n,b,c);
        }
        else
    	{
            ans=query(1,1,n,b,c).maxi;
    	    printf("%lld\n",ans);
        }    
     }
     return 0;	
} 