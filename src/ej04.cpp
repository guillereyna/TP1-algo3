#include "ej04.h"

vector<actividad> actividades;
int cantActividades;

bool terminaAntes(actividad a, actividad b){
    return a.t <= b.t;
}

int elegirGoloso(vector<actividad> &actividades, int h){
    int i = 0;
    int res = -1;
    while(i < actividades.size() && res == -1){
        if (actividades[i].s < h){
            res = actividades[i].t;
            actividades.erase(actividades.begin()+i);
        }
        i++;
    }

    return res;
}

int actividadesGolosoCalcular (vector<actividad> &actividades, int h){
    int electa = elegirGoloso(actividades, h);
    if (actividades.size() == 0 || electa == -1){
        return 0;
    } else {
        return 1 + actividadesGolosoCalcular(actividades, h);
    }
}

int actividadesGoloso (vector<actividad> actividades){
    sort(actividades.begin(), actividades.end(), terminaAntes);
    return actividadesGolosoCalcular(actividades, 0);
}

int main (int argc, char* argv[]){
    return 0;
}