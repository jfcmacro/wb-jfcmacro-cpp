#include <vector>
#include <iostream>
#include <queue>
using namespace std;

typedef pair <int, int> dist_node;
typedef pair <int, int> arco;

const int MAXN = 500;
const int INF = 1 << 30;
vector <arco> g[MAXN];      //Arcos    g[u] = { <v1,w1> , <v2,w2> , ... } :: ( u -> vn con wn )
int d[MAXN];                //Distancias
vector<int> p[MAXN];        //Predecesores

int answer[MAXN];
int last_node;

int dijkstra(int s, int n,int t){
    for (int i = 0; i <= n; i++){
        d[i] = INF;
    }
    p[s].push_back(-1);
    priority_queue < dist_node, vector <dist_node>,greater<dist_node> > q;
    d[s] = 0;
    q.push(dist_node(0, s));
    while (!q.empty()){
        int dist = q.top().first;
        int cur = q.top().second;
        q.pop();
        if (dist > d[cur]) continue;
        for (int i = 0; i < g[cur].size(); ++i){
            int next = g[cur][i].first;
            int w_extra = g[cur][i].second;
            if (d[cur] + w_extra < d[next]){
                d[next] = d[cur] + w_extra;
                p[next].clear();
                p[next].push_back(cur);
                q.push(dist_node(d[next], next));
            }
            else if(d[cur] + w_extra == d[next]){
                p[next].push_back(cur);
            }
        }
    }
    return d[t];
}

void findpath (int t, int depth){
    if(t == 0){                         //Un camino fue encontrado (t==0 donde 0 es el nodo inicial del camino)
        vector<int> camino;             //Camino: Vector de Enteros
        for(int i = depth-1; i >= 0; i--){
            camino.push_back(answer[i]);
        }
        camino.push_back(last_node);
        for(int i = 0;i<camino.size()-1;i++){    //Recorro el camino
            int x = camino[i];                   //Obtengo el nodo inicial
            int y = camino[i+1];                 //Obtengo el nodo final
            for(int j = 0; j < g[x].size() ; j++){
                if(g[x][j].first == y){          //Busco el arco con los nodos obtenidos
                    g[x][j].second =INF;         //Hago el peso de dicho arco infinito
                    break;
                }
            }

        }
    }
    for(int i = (int)p[t].size()-1; i >= 0; i--){
        answer[depth] = p[t][i];
        findpath(p[t][i], depth+1);
    }
}

int main(){
    int nroNodos,nroArcos;  // n : Numero de nodos , m : Numero de producciones
    int w,s;  // w: Nodo inicial , s: Nodo final
    // cin >> nroNodos;
    // cin >> nroArcos;
    // cout << endl;
    while(cin >> nroNodos >> nroArcos){

        if (nroNodos == 0 && nroArcos == 0) break;

        cin>>w>>s;

        last_node=s;

        for(int i = 0; i < nroArcos; ++i){
            int u, v, w;
            cin >> u >> v >> w;
            g[u].push_back(arco(v, w));  //Creación de un arco (u -> v con w)
        }

        int i;
        i = dijkstra(w, nroNodos,s);     //Dijkstra Inicial -- i = Camino más corto de w a s
        findpath(s, 0);
        i = dijkstra(w, nroNodos, s);    //Dijkstra Final -- i = Camino casi más corto de w a s

        if(i==INF){
            i =-1;
        }
        cout<<i<<endl;

        for(int i = 0; i < nroNodos; i++){ //Eliminar los arcos
            g[i].clear();
        }


        //cin >> nroNodos >> nroArcos;
    }

    return 0;
}

