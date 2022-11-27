#include<bits/stdc++.h>
#include <cstdio>

using namespace std;
int n, m, t;
vector<int> graph[200];
bool marcas[200];
int memoria[200];

void intersecttions(int nodo, int p) {
    if(memoria[nodo] > p || memoria[nodo] == 0) {
        memoria[nodo] = p;
    }
    if(marcas[nodo]){
        return;
    }
    marcas[nodo] = 1;
    for(int otroNodo: graph[nodo]){
        intersecttions(otroNodo, p + 1);
    }
    marcas[nodo] = 0;
}

void readInput(){
    cin >> n >> m >> t;
    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[b].push_back(a);
        graph[a].push_back(b);
    }
}

int contarLosQueSeSalvan()
 {
     int cont = 0;
     for(int i = 1; i < n; i++) {
        if(memoria[i] < t && memoria[i] != 0){
            cont++;
        }
     }
     return cont;

 }
int main() {

    readInput();
    intersecttions(n, 0);
    contarLosQueSeSalvan();
    printf("%d\n",contarLosQueSeSalvan());
    return 0;
}
