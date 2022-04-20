#include <iostream>
#include <fstream>
#include <vector>
#include "auxiliares_02.hpp"
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

    vector<int> K_aux0;

    for(int e : K){

        if(E[v-1][e-1]) K_aux0.push_back(e);

    }

    K = K_aux0;
}

bool amigo_de_todos (int e, vector<int> &V) {

    bool res = true;

    for (int i = 0; i < (int) V.size() && res; ++i) {
        if (V[i] != e && !E[V[i]-1][e-1]) res = false;
    }

    return res;
}

bool amigo_de_ninguno(int e, vector<int> &K){

    bool res = true;

    for(int i = 0; i < (int) K.size(); i++){
        if(E[e-1][K[i]-1]) res = false;
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

bool influence(int a, int b){
	return p[a-1]>p[b-1];
}

bool invert_influence(int a, int b){
	return p[a-1]<p[b-1];
}

bool poda_por_independientes(){

    vector<vector<int>> indeps; // vector de conjuntos independientes
    // sort de K por influencia (se pasa por referencia)
    sort(K.begin(),K.end(),influence);

    // Creo particion de conjuntos independientes
    for(int e : K){

        int pushed = false;

        for(int i = 0; i < (int) indeps.size(); i++){

            if(amigo_de_ninguno(e,indeps[i])){

                indeps[i].push_back(e);
                pushed = true;
                break;

            }
        }

        if(!pushed){

            vector<int> I;
            I.push_back(e);
            indeps.push_back(I);

        }
    }

    // calculo cota
    int cota_influencia = 0;

    // sumo influencias de Q
    for(int e : Q){                 // O(n)
        cota_influencia += p[e-1];
    }

    // sumo influencia de del mayor de cada I
    for(int i = 0; i < (int) indeps.size(); i++){                 //O(n)
        cota_influencia += p[indeps[i][0]-1];
    }

    return cota_influencia < max_sum; // resultado

}

void mas_influyente(vector<int> &Q, vector<int> &K){

    if(K.size() == 0){
        procesar();                 // O(n) -> imprimo Q
    }
    else{

        // poda
        /*
        int cota_influencia = 0;

        for(int e : Q){                 // O(n)
            cota_influencia += p[e-1];
        }
        for(int e : K){                 //O(n)
            cota_influencia += p[e-1];
        }

        if(cota_influencia < max_sum) return;   //O(1)
        */

        //poda por independientes
        if(poda_por_independientes()) return;

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

int main(){

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    VEp sample = readInput(); // llamar con ./backtracking < sample.in

    //ordenar_influencia_decreciente(sample);
    //invertir_orden(sample.V);

    V = sample.V;
    E = sample.E;
    p = sample.p;

    sort(V.begin(),V.end(),invert_influence);// ordena menor a mayor

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