#include<iostream>
#include<stack>
 
using namespace std;
 
#define V 6
//0  1  2  3  4  5
int graph[V][V] = { 
	{0, 1, 0, 0, 0, 0},	//0
	{0, 0, 1, 1, 1, 0},	//1
	{1, 0, 0, 1, 0, 0},	//2
	{0, 0, 0, 0, 0, 0},	//3
	{0, 0, 0, 0, 0, 1},	//4
	{0, 0, 0, 0, 1, 0}  //5
};		
 
int transpose[V][V];
stack < int >S;
bool visited[V];
 
void doDFS (int vertex, bool doPrint){
	int v = 0;
	int u = vertex;

	if (doPrint)
		cout << u << " ";
	
	if( !visited[u] )
		visited[u] = true;  // u being processed
 
	for (v = 0; v < V; v++){
		// if there is directed edge from vertex u to vertex v
		// and vertex v is not visited
		if (!doPrint){
			if (graph[u][v] && !visited[v])
				doDFS (v, doPrint);
		}else{
			if (transpose[u][v] && !visited[v])
				doDFS (v, doPrint);
		}
	}
	// store the vertex u in stack S
	if(!doPrint)
		S.push (u); // u finished

	if(doPrint)
		cout<<endl;
} 
//// 
int main (){
  // mark all vertoces not visited
  int i = 0;
  for (i = 0; i < V; i++)
    visited[i] = false;
 
	// run dfs algoritm on graph      
	for (i = 0; i < V; i++){
		if (!visited[i]){
			// do dfs on i , but do not print i
			doDFS (i, false);
		}
	}
 
  // After running doDFS, the stack S contain
  // the vertices of the graph , according to their
  // finish time, the node at which dfs starts, finish
  // at the last.
 
  // now Transpose the graph, means 
  // we are reversing the connection 
  // for example if there is directed edge from u to v
  // then after reversing , there will be edge from v to u
 
	int r = 0;
	int c = 0;
	for (r = 0; r < V; r++)
		for (c = 0; c < V; c++)
			transpose[r][c] = graph[c][r];
 
	// reinit for visited array false
	// running dfs again on transpose of the graph 
	for (i = 0; i < V; i++)
	   visited[i] = false;
 
	// run doDFS again with doPrint true;
	cout<<"Folowing are the connected conponents\n";
 
	while(!S.empty()){
		int v = S.top();
		S.pop();
		if (!visited[v])
		  doDFS (v, true);
	}
  return 0;
}