#include <iostream>
#include <vector>


using namespace std;

int cantActividades;

struct actividad {
    int pos, start;
};

typedef vector<vector<actividad>> Schedule;

vector<int> S; //subconjunto de actividades solucion

/* construye un vector de 2n vectores de actividades, donde cada elemento i del
vector contiene un vector con todas las actividades que terminan en la hora i.
Suponiendo que generar un vector vacio es O(1) y push_back() es O(1), se
genera un vector en O(2n) y luego se recorre el input en O(n).
O(2n) + O(n) = O(n) */
Schedule read_input(){
    cin >> cantActividades;

    Schedule A(2*cantActividades + 1); //O(2n)

    int start;
    int end;

    for (int i = 0; i < cantActividades; i++){ //O(n)
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
int elegirGoloso(const Schedule &actividades, int h){
    for (int i = h+1; i < 2*cantActividades+1; i++){
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
   ocupado hasta el horario h
   Siempre se encuentra la proxima actividad que termina lo mas temprano
   posible arrancando desde el tiempo en el que termina la última actividad
   elegida golosamente, por lo que se "visita" cada actividad a lo sumo
   una única vez, en O(n) tiempo. */
int actividadesGoloso (const Schedule &actividades, int h){
    int electa = elegirGoloso(actividades, h);
    if (electa == -1 || electa > 2*cantActividades) return 0;
    return 1 + actividadesGoloso(actividades, electa);
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(0);
    Schedule A = read_input();
    int beneficio = actividadesGoloso(A, -1);
    cout << beneficio << endl;
    for (size_t i = 0; i < S.size(); i++){
        cout << S[i] << " ";
    }
    cout << endl;
    return 0;
}