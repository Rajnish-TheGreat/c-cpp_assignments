#include <iostream>
#include <climits>
using namespace std;
class Graph
{
public:
    int g[20][20];
    int V, E;
    Graph() //default constructor which will be used to create adj matrix
    {
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
    void prims_algo();
    void printMST(int parent[], int graph[20][20]);
    minKey(int key[], bool mstSet[]);
};
void Graph ::make_graph()
{
    int src, dest, cost;
    cout << "Enter the no. of Offices: ";
    cin >> V;
    cout << "Enter the no. Connections : ";
    cin >> E;
    for (int i = 0; i < E; i++)
    {
        cout << "Enter the source ,destination and cost of " << (i + 1) << " connection : ";
        cin >> src >> dest >> cost;
        g[src][dest] = cost;
        g[dest][src] = cost; //assigning cost to edge for eg. src-----dest and vice versa as it is undirected graph
    }
}
void Graph ::display_graph()
{
    cout << "\n\t";
    for (int i = 0; i < V; i++)
    {
        cout << i << "\t";
    }
    cout << "\n";
    for (int i = 0; i < V; i++)
    {
        cout << i;
        for (int j = 0; j < V; j++)
        {
            cout << "\t" << g[i][j];
        }
        cout << "\n";
    }
}
int Graph ::minKey(int key[], bool mstSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}
void Graph ::prims_algo()
{
    // Array to store constructed MST
    int parent[V];

    // Key values used to pick minimum weight edge in cut
    int key[V];

    // To represent set of vertices included in MST
    bool mstSet[V];
    // Initialize all keys as INFINITE
    int i;
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX;
    mstSet[i] = false;

    // Always include first 1st vertex in MST.
    // Make key 0 so that this vertex is picked as first vertex.
    key[0] = 0;
    parent[0] = -1; // First node is always root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the minimum key vertex from the
        // set of vertices not yet included in MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of
        // the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not
        // yet included in MST
        for (int v = 0; v < V; v++)

            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (g[u][v] && mstSet[v] == false && g[u][v] < key[v])
                parent[v] = u, key[v] = g[u][v];
    }

    // print the constructed MST
    printMST(parent, g);
}
void Graph ::printMST(int parent[], int graph[20][20])
{
    int i;
    cout << "Edge \tWeight\n";
    int totalcost = 0;
    for (i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
        totalcost = totalcost + graph[i][parent[i]];
    }
    cout << "Minimum cost is : " << totalcost;
}

int main()
{
    Graph g;
    int choice;
    do
    {
        cout << "\nMenu \n1.Enter connection and charge \n2.Display route and charges \n3.Minimum Cost ofConnection \n4.Exit \n";
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
            g.prims_algo();
            break;
        default:
            cout << "Invalid Choice!!!";
        }
    } while (choice != 4);
    return 0;
}
