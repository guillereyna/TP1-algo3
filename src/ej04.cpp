#include "ej04.h"

size_t pos;

void print_vector(const vector<actividad>& v){
    int n = v.size();
    cout<<"{";
    for (int i = 0; i < n; i++)
    {
        cout << "(" << v[i].s << ", " << v[i].t << ") ";
    }
    cout << "}" << endl;
}

vector<actividad> A; //conjunto de actividades
vector<int> S; //subconjunto de actividades solucion

void read_input(){
    int cantActividades;
    cin >> cantActividades;

    for (int i = 0; i < cantActividades; i++){
        actividad act;
        cin >> act.s >> act.t;
        A.push_back(act);
        // cout << i << ": " << act.s << " " << act.t << endl;
    }
}

bool terminaAntes(actividad a, actividad b){
    return a.t <= b.t;
}

/* encuentra la actividad que termina lo más temprano posible y no se solapa
   con el último horario ocupado y devuelve su horario de fin, o -1 si no lo 
   encuentra */
int elegirGoloso(vector<actividad> &actividades, int h){
    int res = -1;
    while(pos < actividades.size() && res == -1){
        if (actividades[pos].s >= h){
            res = actividades[pos].t;
            S.push_back(pos);
            //actividades.erase(actividades.begin(), actividades.begin()+1+pos);
        }
        pos++;
    }

    return res;
}

/* calcula el beneficio máximo del conjunto de actividades dado que está 
   ocupado hasta el horario h */
int actividadesGolosoCalcular (vector<actividad> &actividades, int h){
    int electa = elegirGoloso(actividades, h);
    if (pos > actividades.size() || electa == -1){
        return 0;
    } else {
        return 1 + actividadesGolosoCalcular(actividades, electa);
    }
}

/* devuelve el beneficio máximo posible del conjunto de actividades pasado 
   por parámetro */
int actividadesGoloso (vector<actividad> &actividades){
    pos = 0;
    sort(actividades.begin(), actividades.end(), terminaAntes);
    return actividadesGolosoCalcular(actividades, 0);
}

int main (){
    read_input();
    int beneficio = actividadesGoloso(A);
    cout << beneficio << endl;
    for (size_t i = 0; i < S.size(); i++){
        cout << S[i] << " ";
    }
    cout << endl;
    return 0;
}