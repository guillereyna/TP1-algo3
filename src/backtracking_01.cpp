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

void procesar(vector<int> &Q){

}

void eliminar_amigos(vector<int> &k, int v){

}

void chequear_invariante(vector<int> &Q, vector<int> &K){

}

void mas_influyente(vector<int> &K, vector<int> &Q){

    if(K.size() == 0){

        procesar(Q);

    }
    else{

        int v = K[-1];
        Q.push_back(v);
        K.pop_back();
        eliminar_amigos(K,v);
        chequear_invariante(Q,K);
        mas_influyente(Q,K);
        //restaurar_1(Q,K)

        K.pop_back();
        chequear_invariante(Q,K);
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

    // mas_influyente(K,Q);

    VEp sample = readInput();


    return 0;
}