#include <iostream>
#include <fstream>
#include <vector>
#include "auxiliares.hpp"
using namespace std;

// Variables de entrada
vector<int> V;
vector<vector<bool>> E;
vector<int> p;

// Variables de backtraking
vector<int> Q;
vector<int> K;

int max_sum = 0;

vector<int> Q_max;

void procesar(){

    int acc = 0;

    for(int e : Q){
        acc += p[e-1];
    }

    if(acc > max_sum){
        max_sum = acc;
        Q_max = Q;
    }
    
}

void eliminar_no_amigos(int v){

    // usa K y E globales

    vector<int> K_aux;

    for(int e : K){

        if(E[v-1][e-1]) K_aux.push_back(e);

    }

    K = K_aux;
}

bool amigo_de_todos (int e, vector<int> &V) {

    bool res = true;

    for (int i = 0; i < V.size() && res; ++i) {
        if (V[i] != e && !E[V[i]-1][e-1]) res = false;
    }

    return res;
}

void chequear_invariante(){
    // Usa Q y K globales
    vector<int> K_aux0, K_aux1;
    
    // e in K amigos de todos en Q
    for (int e : K) {
        if (amigo_de_todos(e, Q)) {
            K_aux0.push_back(e);
        }
    }
    
    // e in K amigos de todos en K
    for (int e : K_aux0) {
        if (amigo_de_todos(e, K_aux0)){ 
            Q.push_back(e);
        } else {
            K_aux1.push_back(e);
        }
    }

    K = K_aux1;
}

void mas_influyente(vector<int> &Q, vector<int> &K){

    if(K.size() == 0){
        procesar();                 // O(n) -> imprimo Q
    }
    else{

        // poda
        int cota_influencia = 0;

        for(int e : Q){                 // O(n)
            cota_influencia += p[e-1];
        }
        for(int e : K){                 //O(n)
            cota_influencia += p[e-1];
        }

        if(cota_influencia < max_sum) return;   //O(1)

        // backtraking

        vector<int> K_aux = K;      // O(n)
        vector<int> Q_aux = Q;      // O(n)

        // se toma elemento de K
        int v = K[K.size()-1];      // O(1)
        Q.push_back(v);             // O(1)
        K.pop_back();               // O(1)
        eliminar_no_amigos(v);      // O(n) -> saco los no amigos de K
        chequear_invariante();      // O(n²) -> chequeo en K amigos de Q
        mas_influyente(Q,K);        // llamado recursivo
        
        //restaurar
        K = K_aux;                  // O(n)
        Q = Q_aux;                  // O(n)
        
        // no se toma elemento de K
        K.pop_back();               // O(1)
        chequear_invariante();      // O(n²)
        mas_influyente(Q,K);        // llamdo recursivo
        
        //restaruar
        K = K_aux;                  // O(n)
        Q = Q_aux;                  // O(n)

    }

}

int main(int argc, char* argv[]){

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    VEp sample = readInput(); // llamar con ./backtracking < sample.in

    ordenar_influencia_creciente(sample);

    V = sample.V;
    E = sample.E;
    p = sample.p;

    Q = {};
    K = V; // copy vector

    mas_influyente(Q,K);

    cout << max_sum << endl;
    
    for(int e: Q_max){

        cout << e << " ";

    }

    cout << endl;

    return 0;

}