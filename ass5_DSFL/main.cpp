#include <iostream>
using namespace std;
class Graph
{
public:
    int g[20][20];
    int vertices, edges;
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
    int dijkstra(int); //algorithm to find shortest path
};
void Graph ::make_graph()
{
    int src, dest, cost;
    cout << "Enter the no. of vertices(nodes) : ";
    cin >> vertices;
    cout << "Enter the no. of edges : ";
    cin >> edges;
    for (int i = 0; i < edges; i++)
    {
        cout << "Enter the source ,destination and cost of " << (i + 1) << " edge : ";
        cin >> src >> dest >> cost;
        g[src][dest] = cost;
        g[dest][src] = cost; //assigning cost to edge for eg. src-----dest and vice versa as it is undirected graph
    }
}
void Graph ::display_graph()
{
    cout << "\n\t";
    for (int i = 0; i < vertices; i++)
    {
        cout << i << "\t";
    }
    cout << "\n";
    for (int i = 0; i < vertices; i++)
    {
        cout << i;
        for (int j = 0; j < vertices; j++)
        {
            cout << "\t" << g[i][j];
        }
        cout << "\n";
    }
}
int Graph ::dijkstra(int src)
{
    int cost[vertices][vertices], dist[vertices], visit[vertices], from[vertices]; //declaring cost matrix,distance array,visit array,from array
    int min_dist, next;
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++) //initializing the cost matrix
        {
            if (g[i][j] == 0)
            {
                cost[i][j] = 999; //if the cost is 0 for any edge it will be initialized  to large value i.e infinity
            }
            else
            {
                cost[i][j] = g[i][j];
            }
        }
    }
    for (int i = 0; i < vertices; i++)
    { //Initializinf distance array
        dist[i] = cost[src][i];
        visit[i] = 0;  //initializing the visit array to 0 because at the start all the vertex are not visited yet
        from[i] = src; //initialzing the from array to the src vertex value
    }
    dist[src] = 0;
    visit[src] = 1;
    int count = 0;
    while (count < vertices - 1)
    {
        min_dist = 999;
        for (int i = 0; i < vertices; i++)
        {
            if (dist[i] < min_dist && visit[i] == 0)
            {
                min_dist = dist[i];
                next = i;
            }
        }
        visit[next] = 1;
        for (int i = 0; i < vertices; i++)
        {
            if (visit[i] == 0)
            {
                if (min_dist + cost[next][i] < dist[i])
                {
                    dist[i] = (min_dist + cost[next][i]);
                    from[i] = next;
                }
            }
        }
        count++;
    }
    cout << "\n";
    for (int i = 0; i < vertices; i++)
    {
        cout << "\n Shortest Distance from " << src << "to " << i << " is :" << dist[i] << endl;
        cout << "\n And The path is : " << i;
        int j = i;
        do
        {
            j = from[j];
            cout << " -> " << j;
        } while (j != src);
        cout << "\n------------------------------------------------------";
    }
    return 0;
}
int main()
{
    Graph g;
    int choice;
    int src;
    do
    {
        cout << "\nMenu";
        cout << "\n1.Create Graph \n2.Display Graph \n3.Get the shortest path \n4.Exit\n";
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
            cout << "Enter the source vertex : ";
            cin >> src;
            g.dijkstra(src);
            break;
        case 4:
            break;
        default:
            cout << "Invaild Choice !!!";
        }
    } while (choice != 4);
    return 0;
}
