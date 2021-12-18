#include <iostream>
using namespace std;
typedef struct edge
{
    int s, d, w;
} edg;
class Graph
{
public:
    int g[20][20];
    int V, E;

    edg e[100];

    int set[20][20], cnt[20];
    Graph() //default constructor which will be used to create adj matrix
    {
        V = 0;
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                g[i][j] = 0;
            }
        }
    }
    void make_graph();
    void display_graph();
    void edgelist();
    void selection_sort(edg e[100], int n);
    int kruskal(Graph &);
    int findset(int);
};
void Graph ::make_graph()
{
    int src, dest, cost;
    cout << "Enter the no. of vertices(nodes) : ";
    cin >> V;
    cout << "Enter the no. of edges : ";
    cin >> E;
    for (int i = 0; i < E; i++)
    {
        cout << "Enter the source ,destination and cost of " << (i + 1) << " edge : ";
        cin >> src >> dest >> cost;
        g[src][dest] = cost;
        g[dest][src] = cost; //assigning cost to edge for eg. src-----dest and vice versa as it is undirected graph
    }
}
void Graph ::display_graph()
{

    for (int i = 0; i < V - 1; i++)
    {
        cout << "List of Edges in MST";
        for (int j = i + 1; j < V; j++)
        {
            if (g[i][j] != 0)
                cout << "(Src,Dest,Weight) = (" << i << "," << j << "," << g[i][j] << ")";
        }
        cout << "\n";
    }
}
void Graph ::edgelist()
{
    int i, j, k = 0;
    for (i = 0; i < V; i++)
    {
        for (j = i; j < V; j++)
        {
            if (g[i][j] != 0)
            {
                e[k].s = i;
                e[k].d = j;
                e[k].w = g[i][j];
                k++;
            }
        }
    }
    cout << "src\tdes\tweight\n";
    for (i = 0; i < k; i++)
    {
        cout << e[i].s << "\t";
        cout << e[i].d << "\t";
        cout << e[i].w << "\n";
    }
    selection_sort(e, k);
}
void Graph ::selection_sort(edg e[100], int n)
{
    int temp = 0, min = 0, j, pos = 0, k, i, mins = 0, mind = 0, temps = 0, tempd = 0;
    edg tempe, mine;
    for (i = 0; i < n; i++)
    {
        mine = e[i];
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (e[j].w < mine.w)
            {
                mine = e[j];
                pos = j;
            }
        }
        tempe = e[i];
        e[i] = mine;
        e[pos] = tempe;
    }
    cout << "\nElements sorted are : ";
    for (k = 0; k < n; k++)
    {
        cout << "\n"
             << e[k].s << "\t" << e[k].d << "\t" << e[k].w;
    }
}
int Graph ::findset(int x)
{
    int i, j;
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < cnt[i]; j++)
        {
            if (x == set[i][j])
                return i;
        }
    }
    return -1;
}
int Graph ::kruskal(Graph &mst)
{
    int i, j, min_cost = 0;
    edgelist();

    for (i = 0; i < V; i++)
    {
        set[i][0] = i;
        cnt[i] = 1;
    }
    cout << "\nList of new edges is : \n";
    for (i = 0; i < E; i++)
    {
        int p1 = findset(e[i].s);
        int p2 = findset(e[i].d);

        if (p1 != p2)
        {
            mst.g[e[i].s][e[i].d] = e[i].w;
            mst.g[e[i].d][e[i].s] = e[i].w;
            min_cost = min_cost + e[i].w;
            cout << e[i].s << "\t" << e[i].d << "\t" << e[i].w << "\n";

            for (j = 0; j < cnt[p2]; j++)
            {
                set[p1][cnt[p1]] = set[p2][j];
                cnt[p1]++;
            }
            cnt[p2] = 0;
        }
    }
    return min_cost;
}
int main()
{
    Graph g, mst;
    int choice, total_cost;
    do
    {
        cout << "\nMenu \n1.Create graph \n2.Display the edges in graph \n3.Find the Minimum Spanning Tree \n4.Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            g.make_graph();
            break;
        case 2:
            g.display_graph();
            break;
        case 3:
            total_cost = g.kruskal(mst);
            cout << "\nMinimum Cost is : " << total_cost;
            break;
        case 4:
            break;
        default:
            cout << "Invalid Choice!!!" << endl;
        }
    } while (choice != 4);
    return 0;
}
