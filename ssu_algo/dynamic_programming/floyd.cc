#include <iostream>
#include <vector>
#define INF 0xFFFF    // for infinity value

using namespace std;
void print_vector(vector<vector<int>> v)
{
    for (const auto &i: v)
    {
        for (const auto &j: i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void floyd2(
    int n,
    const vector<vector<int>> W,
    vector<vector<int>> &D,
    vector<vector<int>> &P)
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            P[i][j] = 0;
        }
    }

    D = W;

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (D[i][k] + D[k][j] < D[i][j])
                {
                    P[i][j] = k+1;
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }
}

void path(int q, int r, vector<vector<int>> &P)
{
    if (P[q-1][r-1] != 0)
    {
        path(q, P[q-1][r-1], P);
        cout << " v" << P[q-1][r-1];
        path(P[q-1][r-1], r, P);
    }
}

int main()
{
    int n;
    cout << "Type n: ";
    cin >> n;

    vector<vector<int>> W(n, vector<int> (n));
    vector<vector<int>> D(n, vector<int> (n));
    vector<vector<int>> P(n, vector<int> (n));

    cout << "Type W:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> W[i][j];
            if (W[i][j] == -1)
            {
                W[i][j] = INF;
            }
        }
    }

    floyd2(n, W, D, P);

    int q, r;
    cout << "Type q, r: ";
    cin >> q >> r;

    cout << endl << "Output D: " << endl;
    print_vector(D);

    cout << endl << "Output P: " << endl;
    print_vector(P);
    cout << endl;

    cout << "Shortest path of q to r: v" << q;
    path(q, r, P);
    cout << " v" << r << endl;

    return 0;
}
