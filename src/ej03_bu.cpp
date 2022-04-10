#include <iostream>
#include <vector>

using namespace std;

struct tarea
{
    int t, b, index;
};
vector<int> dp;
vector < vector<tarea> >tareas;
int cantTareas;
vector<int> padres;
vector<int>auxiliar;

void BTsolution()
{
    for(int i = 2*cantTareas; i >= 0; i--)
    {
        dp[i] = dp[i+1];
        for(auto j:tareas[i])
        {
            if(dp[i] < dp[j.t+1]+j.b)
            {
                dp[i] = dp[j.t+1]+j.b;
                padres[i] = j.index;
            }
        }
    }
    cout << dp[0] << endl;
    int i = 0;
    while(i < (2*cantTareas)+1)
    {
        if(dp[i] > dp[i+1])
        {
            cout << padres[i] << " ";
            i = auxiliar[padres[i]] + 1;
        }
        else i++;
    }
    cout << endl;
}
int main()
{
    int x, y, b;
    tarea entrada;
    cin >> cantTareas;
    dp.resize((2*cantTareas)+2, 0);
    tareas.resize((2*cantTareas)+2, vector< tarea >());
    padres.resize((2*cantTareas)+2, -1);
    for(int i = 0; i < cantTareas; i++)
    {
        cin >> x >> y >> b;
        auxiliar.push_back(y);
        tareas[x].push_back({y, b, i});
    }
    BTsolution();
    return 0;
}
