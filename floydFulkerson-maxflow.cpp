#include<bits/stdc++.h>
using namespace std;

int N=100;

int graph[N][N] = {-1};
int flow[N][N];
bool visited[N];


void bfs(int vertex ,int src,int sink, int parent[]) {
    bool visited(vertex);
    for (int i=0;i<vertex; i++){
        visited[i]= false;       
    }
    queue<int> q;
    q.push(src);
    visited[src]= true;

    while(!q.empty()) {
        int x = q.front();
        cout << x << "->";
        q.pop();

        for(int i=0;i<vertex;i++){
            if(graph[x][i] != 1 && visited[i] == false){\
                visited[i]= true;
                q.push(i);
            }
        }
    }
}

int main(){
    int vertex,edge;
    cin >> vertex;

    for(int i=0; i<vertex ; i++) {
        int n1,n2,weight; // weight = capacity
        cin >> n1 >> n2 >> weight;

        graph[n1][n2] = weight;

    }

    for(int i=0; i<edge;i++)
}
