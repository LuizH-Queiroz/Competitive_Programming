#include <bits/stdc++.h>
using namespace std;




//Declarações de variáveis
#define endl '\n'
#define ll long long
#define ld long double
#define llu unsigned long long int


//Debug
#define debug(x) cout << #x << "=" << x << endl;
#define debug2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl;


//Resumo de métodos das estruturas de dados
#define pb push_back
#define mp make_pair


//Resumo de métodos de algoritmos
#define all(x) x.begin(), x.end()
#define MsetZ(x) memset(x, 0, sizeof x)
#define MsetN(x) memset(x, -1, sizeof x)
#define sortall(x) sort(all(x))


// Resumo de iteradoes
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k, k<n? i<n: i>n; k<n? i += 1: i -= 1)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)


//Declaração de estruturas de dados
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<pii> vvpii;




//valor comum em problemas com módulo
const int mod = 1'000'000'007;




int main() {
    ios::sync_with_stdio(0);
    ///////////////////////
    int t, n;
    char val;
    vector<vector<int>> rows;
    vector<vector<int>> cols;


    cin >> t;
    while (t--)
    {
        cin >> n;

        rows = vector<vector<int>>(n);
        cols = vector<vector<int>>(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> val;
                rows[i].push_back(val);
                cols[j].push_back(val);
            }
        }

        // cout << endl;
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << rows[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        // cout << endl;
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << cols[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        for (int i = n-1, j = 0; j < i; i--, j++)
        {
            reverse(rows[i].begin(), rows[i].end());
            reverse(cols[j].begin(), cols[j].end());
        }


        // cout << endl;
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << rows[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        // cout << endl;
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << cols[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        

        int operations = 0;
        int maximum;
        for (int first = 0, last = n-1; first < last; first++, last--)
        {
            for (int i = 0; i < n; i++)
            {
                maximum = max(max(rows[first][i], rows[last][i]), max(cols[first][i], cols[last][i]));
                operations += maximum - rows[first][i];
                operations += maximum - rows[last][i];
                operations += maximum - cols[first][i];
                operations += maximum - cols[last][i];
            }
        }

        cout << operations/2 << endl;
    }


    return 0;
}