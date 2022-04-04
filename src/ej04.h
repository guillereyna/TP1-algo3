#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct actividad {
    int s, t;
};

int elegirGoloso(vector<actividad> &actividades, int h);
int actividadesGolosoCalcular (vector<actividad> &actividades);
int actividadesGoloso (vector<actividad> actividades);