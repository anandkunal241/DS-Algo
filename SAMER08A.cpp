#include<bits/stdc++.h>
using namespace std;
#define INF 100000000
vector< vector< pair< int,int > > >path(505);
int dist[505];
vector< pair< int,int > >nottake(505);
vector<int>par(505);
void reset()
{
    for(int i=0;i<505;i++)
    {
       dist[i]=INT_MAX;
       par[i]=-1;
    }
}
void store(int s,int parent)
{
  while(parent!=-1)
  {
    nottake.push_back(make_pair(s,parent));
    s=parent;
    parent=par[parent];
  }
}
void dijkstra(int strt,int dest)
{
   priority_queue< pair< int,int >,vector< pair< int,int > >,greater< pair< int,int > > >pi;
   dist[strt]=0;
   pi.push(make_pair(dist[strt],strt));
   int i,j,k,a,b,c,u,w;
   while(!pi.empty())
   {
     a=pi.top().first;
     b=pi.top().second;
     pi.pop();
     for(i=0;i<path[b].size();i++)
     {
        u=path[b][i].first;
        w=path[b][i].second;
        if(u==dest)
        {
          if(dist[u]==(w+dist[b]))
          {
            store(dest,b);
            continue;
          }
        }
       if(dist[u]>(w+dist[b]))
       {
          dist[u]=(w+dist[b]);
            par[u]=b;
          if(u==dest)
          {
            nottake.clear();
            store(dest,b);
          }
          pi.push(make_pair(dist[u],u));
       }
     }
   }
} 
void dijkstra2(int strt)
{
  priority_queue< pair< int,int >,vector< pair< int,int > >,greater< pair< int,int > > >pi;
   dist[strt]=0;
   pi.push(make_pair(dist[strt],strt));
   int i,j,k,a,b,c,u,w;
   while(!pi.empty())
   {
     a=pi.top().first;
     b=pi.top().second;
     pi.pop();
     for(i=0;i<path[b].size();i++)
     {
        u=path[b][i].first;
        w=path[b][i].second;
        if(dist[u]>(w+dist[b]))
        {
          if(find(nottake.begin(),nottake.end(),make_pair(u,b))==nottake.end())
          {
            dist[u]=dist[b]+w;
            pi.push(make_pair(dist[u],u));
          }
        }
      }
    }         
}
int main()
{
  while(1)
  {
   int n,m,i,j,k,a,b,c,ans;
  cin >> n >> m;
   if(n==0&&m==0)
     break;
  int strt,dest;
  cin >> strt >> dest;
  for(i=0;i<m;i++)
  {
    cin >> a >> b >> c;
    path[a].push_back(make_pair(b,c));
  }
    reset();
    dijkstra(strt,dest);
    ans=dist[dest];
    if(ans==INT_MAX)
       cout << "-1\n";
    else
    {
      reset();
      dijkstra2(strt);
      ans=dist[dest];
      if(ans==INT_MAX)
        cout << "-1\n";
      else
        cout << ans << endl;
    }
     for(i=0;i<505;i++)
      path[i].clear();
 
  }
    return 0;
}