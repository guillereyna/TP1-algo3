#include <iostream>
#include <fstream>
#include <set>
#include <vector>

using namespace std;

struct VEp{
	vector<int> V;
	vector<vector<bool>> E;
	vector<int> p;

};
VEp readInput(){
	string trash;
	cin >> trash >> trash;
	

	int N,M;
	cin >> N >> M;
	
	vector<int> V;
	vector<vector<bool>> E(N,vector<bool>(N,false));
	vector<int> p(N);
	
	int participante, influencia;
	for(int i = 0 ; i < N ; ++i){
		cin >> trash >> participante >> influencia;

		p[participante-1] = influencia;
		//cerr<< "participante numero "<< participante << " con influencia "<<influencia<<"\n";
		V.push_back(participante);
	}


	int part1,part2;
	for(int i = 0 ; i < M ; ++i){
		cin >> trash >> part1 >> part2;

		//cerr<< part1 << " amigo de "<<part2<<"\n";
		E[part1-1][part2-1] = true;
		E[part2-1][part1-1] = true;

	}

	VEp res;
	res.V = V;
	res.E = E;
	res.p = p;

	return res;
	
	

}

template<class T>
void print_vector(const vector<T>& v){
    int n = v.size();
    cerr<<"{";
    for (int i = 0; i < n; i++)
    {
        cerr<<v[i]<<", ";
    }
    cerr << "}\n";
    
}

template<class T>
void print_matrix(const vector<vector <T >> & mat){
    for(vector<T> v : mat){
        print_vector(v);
    }
}

void ordenar_influencia_creciente(VEp &G){

	int min;
	int min_idx;
	int aux;

	for(int i = 0; i < G.p.size(); i++){

		min = G.p[i];
		min_idx = i;

		for(int j = i+1; j < G.p.size(); j++){

			if(min > G.p[j]){
				min = G.p[j];
				min_idx = j;
			}
		}

		aux = G.p[i];
		G.p[i] = G.p[min_idx];
		G.p[min_idx] = aux;

		aux = G.V[i];
		G.V[i] = G.V[min_idx];
		G.V[min_idx] = aux;

	}
}

void invertir_orden(VEp &G){

	int aux;

	for(int i = 0; i < (G.p.size()/2); i++){

		aux = G.p[i];
		G.p[i] = G.p[G.p.size()-i-1];
		G.p[G.p.size()-i-1] = aux;

		aux = G.V[i];
		G.V[i] = G.V[G.p.size()-i-1];
		G.V[G.p.size()-i-1] = aux;

	}

}