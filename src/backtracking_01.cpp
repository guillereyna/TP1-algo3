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

void chequear_invariante(){

    // Usa Q y K globales

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

        // idea guille: en vez de restaurar, solo hacer copias y reasignarselas a las variables globales


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