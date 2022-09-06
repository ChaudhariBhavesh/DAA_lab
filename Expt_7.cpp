#include <bits/stdc++.h>
using namespace std;

#define MAXN 100
const int INF = 1e7;

int dis[MAXN][MAXN];
int Next[MAXN][MAXN];

void initialise(int V,
                vector<vector<int>> &graph)
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            dis[i][j] = graph[i][j];

            // No edge between node
            // i and j
            if (graph[i][j] == INF)
                Next[i][j] = -1;
            else
                Next[i][j] = j;
        }
    }
}

vector<int> constructPath(int u,
                          int v)
{
    int sum = 0;
    if (Next[u][v] == -1)
    {

        return {};
    }
    cout << dis[u][v] << " ";

    vector<int> path = {u};
    while (u != v)
    {
        u = Next[u][v];
        path.push_back(u);
    }

    return path;
}

void floydWarshall(int V)
{
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dis[i][k] == INF || dis[k][j] == INF)
                    continue;

                if (dis[i][j] > dis[i][k] + dis[k][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    Next[i][j] = Next[i][k];
                }
            }
        }
    }
}

void printPath(vector<int> &path)
{
    int n = path.size();
    for (int i = 0; i < n - 1; i++)
        cout << path[i] + 1 << " -> ";
    cout << path[n - 1] + 1 << endl;
}

int main()
{

    int V = 6;
    vector<vector<int>> graph = {{0, 30, 10, 40, 90, INF},
                                 {30, 0, INF, 30, 60, 50},
                                 {10, INF, 0, 10, INF, INF},
                                 {40, 40, 10, 0, INF, 55},
                                 {90, 60, INF, INF, 0, 20},
                                 {INF, 50, INF, 55, 20, 0}};

    initialise(V, graph);

    floydWarshall(V);
    vector<int> path;

    cout << " \n\t\t  WELCOME TO GOCEA\n";
    cout << " \n\t  Map of College :\n";
    cout << "\n\t\t      60        30\n";
    cout << "\t\t  (5)-------(2)------(1)\n";
    cout << "\t\t   |        /|       /| \n";
    cout << "\t\t   |       / |      / | \n";
    cout << "\t\t   |      /  |     /  | \n";
    cout << "\t\t 20|   50/   |    /   | \n";
    cout << "\t\t   |    /  30| 40/    |10 \n";
    cout << "\t\t   |   /     |  /     |  \n";
    cout << "\t\t   |  /      | /      | \n";
    cout << "\t\t  (6)-------(4)------(3)\n";
    cout << "\t\t        55        10 \n";
    cout << "\n\tVARIOUS LOCATIONS IN THE MALL : \n";
    cout << "\n\t1. Parking\n";
    cout << "\t2. Civil Department\n";
    cout << "\t3. Admin Garden\n";
    cout << "\t4. Admin Building\n";
    cout << "\t5. Extc Department\n";
    cout << "\t6. Library\n";

    int srcLoc, desLoc;
    cout << "Enter Source Location : ";
    cin >> srcLoc;

    cout << "Enter Destination Location : ";
    cin >> desLoc;

    path = constructPath(srcLoc - 1, desLoc - 1);
    printPath(path);

    return 0;
}