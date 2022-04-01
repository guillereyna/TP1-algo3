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
		std::cout<< "participante numero "<< participante << " con influencia "<<influencia<<"\n";
		V.push_back(participante);
	}


	int part1,part2;
	for(int i = 0 ; i < M ; ++i){
		cin >> trash >> part1 >> part2;

		cout<< part1 << " amigo de "<<part2<<"\n";
		E[part1-1][part2-1] = true;
		E[part2-1][part1-1] = true;

	}

	VEp res;
	res.V = V;
	res.E = E;
	res.p = p;

	return res;
	
	

}
void print_vector(const vector<int >& v){
    int n = v.size();
    cout<<"{";
    for (int i = 0; i < n-1; i++)
    {
        cout<<v[i]<<", ";
    }
    cout<<v[n-1]<<"}\n";
    
}

void print_matrix(const vector<vector <int >> & mat){
    for(vector<int> v : mat){
        print_vector(v);
    }
}
