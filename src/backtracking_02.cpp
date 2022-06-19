#include <iostream>
#include <fstream>
#include <vector>
#include "auxiliares.hpp"
using namespace std;

// Variables de entrada
vector<int> V;
vector<vector<bool>> E;
vector<int> p;

void procesar(vector<int> &Q, int &max_sum, vector<int> &Q_max){
    int acc = 0;

    for(int e : Q){
        acc += p[e-1];
    }

    if(acc > max_sum){
        max_sum = acc;
        Q_max = Q;
    }
}

void eliminar_no_amigos(vector<int> &K, int v){
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

void restaurar_invariante(vector<int> &Q, vector<int> &K){
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

int sumaInflVec(const vector<int> & v){
    
    int res = 0;
    
    for(int e : v){
        res += p[e-1];
    }
    
    return res;
}

bool amigo_de_nadie_en_I(const int& e, const vector<int>& I){

	bool res = true;
	int i = 0;

	while(i < I.size() && res){

		res &= !(E[e-1][I[i]-1]);
		++i;

	}

	return res;
}
 

bool order(int a, int b){
	return p[a-1]<p[b-1];
}

void sortByInfluence(vector<int> &K){
    sort(K.begin(),K.end(),order);
}

int greedyMinPartitionK(const vector<int>& K, const vector<int>& p){
	
    //ordenar_influencia_decreciente2(K,p);
    //sortByInfluence(K);
	vector<vector<int > >Indeps;
	
    for(int r = K.size()-1; r >=0 ; --r){
		
        const int& e = K[r];
        bool pushed = false;
		
        for(int i = 0 ; i < Indeps.size(); ++i){ // obs: no agrega complejidad
			
            if(amigo_de_nadie_en_I(e,Indeps[i])) {
				
                Indeps[i].push_back(e);
				pushed = true;
                break;
			}
			
		}

		if(!pushed){
			vector<int> Inew = {e};
			Indeps.push_back(Inew);
		}
	}

	int pSum = 0;
    
    for(int i = 0 ; i < Indeps.size() ; ++i){
    
        pSum+=p[Indeps[i][0]-1];
    
    }

    return pSum;

}
int influencia(const vector<int >& Q, const vector<int> & infl){
    int acc = 0;

    for(int e : Q){
        acc += infl[e-1];
    }

    return acc;
}

bool poda2(vector<int>& K, const vector<int>& Q, const vector<int>& p, int max_sum){
    return ((greedyMinPartitionK(K, p) + 
            sumaInflVec(Q)) <= max_sum);
}

void mas_influyente_rec(vector<int> &Q, vector<int> &K, int &max_sum, vector<int> &Q_max){
    if(K.size() == 0){
        int inf_Q = influencia(Q, p); // O(n) 
        if(inf_Q > max_sum){
            max_sum = inf_Q;
            Q_max = Q;
        }               // O(n) -> imprimo Q
    }
    else{
        if(sumaInflVec(Q)+sumaInflVec(K) < max_sum) return;

        if(poda2(K,Q,p,max_sum)){
             return;
         }

        vector<int> K_aux = K;      // O(n)
        vector<int> Q_aux = Q;      // O(n)

        int v = K[K.size()-1];      // O(1)
        Q.push_back(v);             // O(1)
        K.pop_back();               // O(1)
        eliminar_no_amigos(K, v);      // O(n) -> saco los no amigos de K
        restaurar_invariante(Q, K);      // O(n²) -> chequeo en K amigos de Q
        mas_influyente_rec(Q, K, max_sum, Q_max);        // llamado recursivo
        //restaurar_1(Q,K)
        K = K_aux;                  // O(n)
        Q = Q_aux;                  // O(n)
        

        K.pop_back();               // O(1)
        restaurar_invariante(Q, K);      // O(n²)
        mas_influyente_rec(Q, K, max_sum, Q_max);        // llamdo recursivo
        //restaruar_2(Q,K)
        K = K_aux;                  // O(n)
        Q = Q_aux;                  // O(n)
    }
}

void mas_influyente(vector<int> &Q, vector<int> &K, int &max_sum, vector<int> &Q_max){
    sortByInfluence(K);    
    mas_influyente_rec(Q, K, max_sum, Q_max);
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

    // Variables de backtraking
    vector<int> Q = {};
    vector<int> K = V; // copy vector
    int max_sum = 0;
    vector<int> Q_max;

    //
    mas_influyente(Q,K,max_sum,Q_max);

    cout << max_sum << endl;
    
    for(int e: Q_max) {
        cout << e << " ";
    }

    cout << endl;

    return 0;
}