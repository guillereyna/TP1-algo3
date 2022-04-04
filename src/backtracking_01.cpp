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

void procesar(){

    // usa Q global

}

void eliminar_amigos(int v){

    // usa K y E globales

    vector<int> K_aux;

    for(int e : K){

        if(!E[v-1][e-1]) K_aux.push_back(e);

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
    
    for (int e : K) {
        if (amigo_de_todos(e, Q)) {
            K_aux0.push_back(e);
        }
    }
    
    for (int e : K_aux0) {
        if (amigo_de_todos(e, K_aux0)){ 
            Q.push_back(e);
        } else {
            K_aux1.push_back(e);
        }
    }

    K = K_aux1;
}

void mas_influyente(vector<int> &K, vector<int> &Q){

    if(K.size() == 0){
        procesar();
    }
    else{

        int v = K[-1];
        Q.push_back(v);
        K.pop_back();
        eliminar_amigos(v);
        chequear_invariante();
        mas_influyente(Q,K);
        //restaurar_1(Q,K)

        K.pop_back();
        chequear_invariante();
        mas_influyente(Q,K);
        //restaruar_2(Q,K)

    }

}

int main(int argc, char* argv[]){

    // Q = {};
    // K = {1,2,3,4};
    // p = {1,4,3,8};
    // E = {{0,1,1,0},
    //      {1,0,1,1},
    //      {1,1,0,0},
    //      {0,0,1,0}};

    VEp sample = readInput(); // llamar con ./backtracking < sample.in

    V = sample.V;
    E = sample.E;
    p = sample.p;

    Q = {};
    K = V; // copy vector

    // mas_influyente(K,Q);

    return 0;
}