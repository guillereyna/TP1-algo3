#include <iostream>
#include <vector>

using namespace std;

int cantActividades;

struct actividad {
    int pos, start;
};

typedef vector<vector<actividad>> Schedule;

vector<int> S; //subconjunto de actividades solucion

Schedule read_input(){
    cin >> cantActividades;

    Schedule A(2*cantActividades);

    int start;
    int end;

    for (int i = 0; i < cantActividades; i++){
        cin >> start >> end;
        actividad act;
        act.pos = i; act.start = start;
        A[end].push_back(act);
    }

    return A;
}


/* encuentra la actividad que termina lo más temprano posible y no se solapa
   con el último horario ocupado y devuelve su horario de fin, o -1 si no lo 
   encuentra */
int elegirGoloso(Schedule &actividades, int h){
    int i = h;
    for (; i < 2*cantActividades; i++){
        i++;
        for(actividad act : actividades[i]){
            if (act.start > h){
                S.push_back(act.pos);
                return i;
            }
        }
    }
    return -1;
}

/* calcula el beneficio máximo del conjunto de actividades dado que está 
   ocupado hasta el horario h */
int actividadesGoloso (Schedule &actividades, int h){
    int electa = elegirGoloso(actividades, h);
    if (electa == -1 || electa >= 2*cantActividades) return 0;
    return 1 + actividadesGoloso(actividades, electa);
}

int main (){
    Schedule A = read_input();
    int beneficio = actividadesGoloso(A, 0);
    cout << beneficio << endl;
    for (size_t i = 0; i < S.size(); i++){
        cout << S[i] << " ";
    }
    cout << endl;
    return 0;
}