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

int DP(int i)
{
    if(i > 2*cantTareas) return 0;
    if(dp[i] != -1) return dp[i];
    dp[i] = DP(i+1);
    for(auto j:tareas[i])
    {
        if(dp[i] < (DP(j.t+1) + j.b))
        {
            dp[i] = DP(j.t+1) + j.b;
            padres[i] = j.index;
        }
    }
    return dp[i];
}

void solution()
{
    vector<int>sol;
    int i = 0;
    while(i < (2*cantTareas)+1)
    {
        if(DP(i) > DP(i+1))
        {
            sol.push_back(padres[i]);
            i = auxiliar[padres[i]] + 1;
        }
        else i++;
    }
    for(auto x:sol)
        cout << x << " ";
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x, y, b;
    cin >> cantTareas;
    dp.resize((2*cantTareas)+2, -1); ///O(n)
    tareas.resize((2*cantTareas)+1, vector< tarea >());///O(n)
    padres.resize((2*cantTareas)+1, -1);///O(n)
    for(int i = 0; i < cantTareas; i++)///O(n)
    {
        cin >> x >> y >> b;
        tareas[x].push_back({y, b, i});
        auxiliar.push_back(y);
    }
    cout << DP(0) << endl;
    solution();
    return 0;
}
