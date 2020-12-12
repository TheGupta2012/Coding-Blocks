#include<bits/stdc++.h>
#include<algorithm>
#define tr(v,it) for(typeof(v.begin()) it=v.begin() ; it!=v.end() ; it++)
#define For(i,n) for(long long int i=0;i<n;i++)
using namespace std;
bool visited[100]={false};
long long intvisitall=0;
long long int findmin(vector <long long int> keys) // finding out the minimum of the vertices.keys from the V-S cut of the graph
{	long long int min=INT_MAX,ind;
	for(long long int i=1;i<keys.size();i++)
	{ if(keys[i]<min && visited[i]==false)
		{min=keys[i];
		ind = i;}
	}
	return ind;
}
long long int prims(long long int n, vector <pair <long long int,long long int> > edges[]) // edges is the adjacency list.
{	long long int minweight=0,ind,visitall;
	visitall=0;
	vector <long long int> parent(n+1);// parent array to store parent
	vector <long long int> keys(n+1); // keys array to store weights
	for(long long int i=1;i<=n;i++)
		{if(i==1)
		keys[i]=0;
		else
		keys[i]=INT_MAX;
		}
	parent[1]=-1;
	while(visitall!=n)
	{
		ind = findmin(keys);//finding minimum key from the vertex set V-S which has already not been visited.
		visited[ind]=true; // means ind has beeen transferred to the S cut.
		visitall++;
		for(long long int i=0;i<edges[ind].size();i++) // traversing through the adjacency list of the minimum key node.
		{
		    if(visited[edges[ind][i].first]==false && keys[edges[ind][i].first]>edges[ind][i].second) // means > "if the adjacent node of the current node is alredy not visited and its key value
		    																									// is greater than the weight of that node then update the key value and update the parent"

						{ keys[edges[ind][i].first] = edges[ind][i].second; //update the key of that node
						parent[edges[ind][i].first]=ind; } // make the parent of the node the current index

		}
	}
	minweight=accumulate(keys.begin(),keys.end(),0);
	return minweight;
}
int main()
{
	long long int n;
	cin>>n;
	long long int edge;
	cin>>edge;
	long long int s,e,w,k;
	k=1;
	set <long long int> vertex;
	vector < pair <long long int, long long int> > edges[n+1];
	while(edge--)
	{	//cout<<"Edge "<<k<<":";
		cin>>s;
		//if(s==-1) break;
		cin>>e>>w;
		vertex.insert(s+1);
		vertex.insert(e+1);
		edges[s+1].push_back(make_pair(e+1,w));
		edges[e+1].push_back(make_pair(s+1,w));
		k++;
	}
	long long int min_weight= prims(n,edges);
	cout<<min_weight;
	return 0;
}
