#include <iostream>
#include <vector>

using namespace std;

struct tarea
{
    int s, t, b;
};

vector<tarea> tareas;
vector<int> p;
vector<int> memo;
int n;

int B(int i)
{
    for (int j = n-1; j >= i; j--)
    {
        memo[j] = max(memo[j+1], tareas[j].b + memo[p[tareas[j].t + 1]]);
    }

    return memo[i];
}
void solution()
{
    int i = 0;
    while(i < n)
    {
        if(memo[i] > memo[i+1])
        {
            cout << i << " ";
            i = p[tareas[i].t+1];
        }
        else i++;
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x, y, b;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> b;
        tareas.push_back({x, y, b});
    }

    p.resize((2 * n) + 2, -1);
    memo.resize(n + 1, -1);

    for (int i = 0; i < n; i++)
    {
        if (p[tareas[i].s] == -1)
            p[tareas[i].s] = i;
    }

    memo[n] = 0;

    p[(2 * n) + 1] = n;

    for (int i = (2 * n) + 1; i >= 0; i--)
    {
        if (p[i] == -1)
            p[i] = p[i + 1];
    }

    cout << B(0) << endl;
    solution();
    /* for (int i = 0; i < n + 1; i++)
    {
        cout << memo[i] << " ";
    } */
    return 0;
}
