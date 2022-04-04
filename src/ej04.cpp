#include "ej04.h"

int i = 0;

vector<actividad> actividades;
int cantActividades;

bool terminaAntes(actividad a, actividad b){
    return a.t <= b.t;
}

/* encuentra la actividad que termina lo más temprano posible y no se solapa
   con el último horario ocupado y devuelve su horario de fin, o -1 si no lo 
   encuentra */
int elegirGoloso(vector<actividad> &actividades, int h){
    int res = -1;
    while(i < actividades.size() && res == -1){
        if (actividades[i].s < h){
            res = actividades[i].t;
            //actividades.erase(actividades.begin(), actividades.begin()+1+i);
        }
        i++;
    }

    return res;
}

/* calcula el beneficio máximo del conjunto de actividades dado que está 
   ocupado hasta el horario h */
int actividadesGolosoCalcular (vector<actividad> &actividades, int h){
    int electa = elegirGoloso(actividades, h);
    if (i >= actividades.size() || electa == -1){
        return 0;
    } else {
        return 1 + actividadesGolosoCalcular(actividades, electa);
    }
}

/* devuelve el beneficio máximo posible del conjunto de actividades pasado 
   por parámetro */
int actividadesGoloso (vector<actividad> actividades){
    i = 0;
    sort(actividades.begin(), actividades.end(), terminaAntes);
    return actividadesGolosoCalcular(actividades, 0);
}