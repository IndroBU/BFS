/// Breath First-Search
/* No Problem
     A.List Time Complexity O(V+E)
   Indrojit Mondal
   Dept of Computer Science and Engineering , University of Barisal */
/*#include<bits/stdc++.h>
using namespace std;
vector<int>G[100];
int Vertex,Edge;
int StrCount=0;
int color[100];
int d[100];
int p[100];
#define Inf 132121;
string StringHome[100];
int Search_Index(string s)
{
    for(int I=1; I<=StrCount; I++)
    {
        if(StringHome[I]==s)
        {
            return I;
        }
    }
    StrCount = StrCount +1;
    StringHome[StrCount] = s;
    return StrCount;
}
void BFS(int s)
{
    queue<int>q;
    q.push(s);
    d[s]=0;
    color[s]=1;
    while(!q.empty()){
        int U= q.front();
            q.pop();
    for(int I=0; I<G[U].size(); I++)
    {
        int V= G[U][I];
        if(color[V]==0)
        {
            d[V] = d[U] +1;
            color[V]=1;
            p[V]=U;
            q.push(V);
        }

    }
       color[U]=2;
    }
}
void PathPrint(int s,int v)
{
    if(s==v) cout<<StringHome[s]<<" ";
    else if(p[v]==0) cout<<"No Path From Source To Destination ";
    else{
        PathPrint(s,p[v]);
        cout<<StringHome[v]<<" ";
    }
}
int main(){
    cin>>Vertex>>Edge;
    string s1,s2;
    int Node1, Node2;
    for(int I=1; I<=Edge; I++)
    {
        cin>>s1>>s2;
        Node1 = Search_Index(s1);
        Node2 = Search_Index(s2);
        G[Node1].push_back(Node2);

        G[Node2].push_back(Node1);
    }
    for(int I=1; I<=Vertex; I++)
    {
        color[I]=0;
        d[I]= Inf;
        p[I]=0;
    }
    string Source;
    cout<<"Enter Source : ";
    cin>>Source;
    cout<<"Enter Destination : ";
    string Dsn;
    cin>>Dsn;
    BFS(Search_Index(Source));
    PathPrint(Search_Index(Source),Search_Index(Dsn));
    cout<<endl;
    cout<<"Source To Destination Distance = "<<d[Search_Index(Dsn)]<<endl;

}*/
/// Breath First-Search
/* No Problem
   Indrojit Mondal
   A . Matrix Time Complexity O(V^2)
   Dept of Computer Science and Engineering , University of Barisal */
#include<bits/stdc++.h>
using namespace std;
//vector<int>G[100];
int G[100][100];
int Vertex,Edge;
int StrCount=0;
int color[100];
int d[100];
int p[100];
#define Inf 132121;
string StringHome[100];
int Search_Index(string s)
{
    for(int I=1; I<=StrCount; I++)
    {
        if(StringHome[I]==s)
        {
            return I;
        }
    }
    StrCount = StrCount +1;
    StringHome[StrCount] = s;
    return StrCount;
}
void BFS(int s)
{
    queue<int>q;
    q.push(s);
    d[s]=0;
    color[s]=1;
    while(!q.empty()){
        int U= q.front();
            q.pop();
      for(int V=1; V<=Vertex; V++)
      {
          if(G[U][V]==1 && color[V]==0)
          {
              color[V]=1;
              d[V]= d[U]+1;
              p[V]= U;
              q.push(V);
          }
      }
       color[U]=2;
    }
}
void PathPrint(int s,int v)
{
    if(s==v) cout<<StringHome[s]<<" ";
    else if(p[v]==0) cout<<"No Path From Source To Destination ";
    else{
        PathPrint(s,p[v]);
        cout<<StringHome[v]<<" ";
    }
}
int main(){
    cin>>Vertex>>Edge;
    string s1,s2;
    int Node1, Node2;
    for(int I=1; I<=Edge; I++)
    {
        cin>>s1>>s2;
        Node1 = Search_Index(s1);
        Node2 = Search_Index(s2);
        G[Node1][Node2]=1;

        G[Node2][Node1]=1;
    }
    for(int I=1; I<=Vertex; I++)
    {
        color[I]=0;
        d[I]= Inf;
        p[I]=0;
    }
    string Source;
    cout<<"Enter Source : ";
    cin>>Source;
    cout<<"Enter Destination : ";
    string Dsn;
    cin>>Dsn;
    BFS(Search_Index(Source));
    PathPrint(Search_Index(Source),Search_Index(Dsn));
    cout<<endl;
    cout<<"Source To Destination Distance = "<<d[Search_Index(Dsn)]<<endl;

}

