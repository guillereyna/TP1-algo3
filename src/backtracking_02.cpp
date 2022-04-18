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
	return p[a-1]>p[b-1];
}

void sortByInfluence(vector<int >& K){
	sort(K.begin(),K.end(),order);
}

int greedyMinPartitionK(vector<int>& K, 
                                          const vector<int>& p){
	
    sortByInfluence(K);
	vector<vector<int > >Indeps;
	
    for(int e : K){
		
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

bool poda2(vector<int>& K, const vector<int>& Q, const vector<int>& p){
    return ((greedyMinPartitionK(K, p) + 
            sumaInflVec(Q)) <= max_sum);
}
void mas_influyente(vector<int> &Q, vector<int> &K){

    if(K.size() == 0){
        procesar();                 // O(n) -> imprimo Q
    }
    else{

        if(sumaInflVec(Q)+sumaInflVec(K) < max_sum) return;

        if(poda2(K,Q,p)){
             return;
         }

        vector<int> K_aux = K;      // O(n)
        vector<int> Q_aux = Q;      // O(n)

        int v = K[K.size()-1];      // O(1)
        Q.push_back(v);             // O(1)
        K.pop_back();               // O(1)
        eliminar_no_amigos(v);      // O(n) -> saco los no amigos de K
        chequear_invariante();      // O(n²) -> chequeo en K amigos de Q
        mas_influyente(Q,K);        // llamado recursivo
        //restaurar_1(Q,K)
        K = K_aux;                  // O(n)
        Q = Q_aux;                  // O(n)
        

        K.pop_back();               // O(1)
        chequear_invariante();      // O(n²)
        mas_influyente(Q,K);        // llamdo recursivo
        //restaruar_2(Q,K)
        K = K_aux;                  // O(n)
        Q = Q_aux;                  // O(n)

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


    //vector<vector<int>> part = greedyMinPartitionK(K,p);
    mas_influyente(Q,K);

    cout << max_sum << endl;
    
    for(int e: Q_max){

        cout << e << " ";

    }

    cout << endl;

    return 0;
}