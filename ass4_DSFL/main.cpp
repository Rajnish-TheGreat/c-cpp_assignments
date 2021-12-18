#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define N 50


class que
{
    int quearr[N];
    int front, rare;

public:
    que()
    {
        front = -1;
        rare = -1;
    }
    int questatus()
    {
        if (front == -1)
            return -1;
        if ((rare + 1) % N == front)
            return 1;
        else
            return 0;
    };
    void enque(int num)
    {
        if (questatus() != 1)
        {
            if (front == -1)
                front = 0;
            rare = (rare + 1) % N;
            quearr[rare] = num;
        }
    };
    int deque()
    {
        int num;
        if (questatus() == -1)
            return -1;
        num = quearr[front];
        if (front == rare)
            front = rare = -1;
        else
            front = (front + 1) % N;
        return num;
    };
};

class index_holder
{
public:
    int index;
    index_holder *next;
    index_holder()
    {
        index = -1;
        next = NULL;
    }
    index_holder(int x)
    {
        index = x;
        next = NULL;
    }
};

class node
{
public:
    int index;
    string name;
    int month, day, year, numcom, numlike, numfriend;
    index_holder *next;
    node()
    {
        month = day = year = numcom = numlike = numfriend = 0;
        name[0] = '\0';
        next = NULL;
    }
    node(string nam, int d, int m, int y, int nlike, int ncom, int ind)
    {
        cout << "" << endl;
        name = nam;
        index = ind;
        day = d;
        month = m;
        year = y;
        numlike = nlike;
        numcom = ncom;
        next = NULL;
        numfriend = 0;
    }
};

class friend_network
{
    node *net[20];
    int visited[20] = {0};
    int num_users, mon;
    int total_user = 0;
    int min_comments, max_likes;

public:
    friend_network()
    {
        for (int i = 0; i < 20; i++)
            net[i] = NULL;
        num_users = max_likes = 0;
        min_comments = INT_MAX;
    }
    void make_connection(int i, int j);
    void connect_user();
    void new_user();
    void show_data();
    void show_adjacency();
    void BFS();
    void DFS(int, int);
    void DFS_CALL();
};
void friend_network::DFS(int ind, int mon)
{
    visited[ind] = 1;
    if (net[ind]->month == mon)
        cout << "Matched =" << net[ind]->name << endl;

    else
        cout << "Visited =" << net[ind]->name << endl;

    index_holder *temp = net[ind]->next;
    while (temp != NULL)
    {
        if (visited[temp->index] == 0)
        {
            DFS(temp->index, mon);
        }
        temp = temp->next;
    }
}
void friend_network::DFS_CALL()
{
    int ind, month;
    cout << "Enter the Index to start with>>";
    cin >> ind;
    cout << "Enter the Birthday Month to find>>";
    cin >> month;
    DFS(ind, month);
    for (int i = 0; i < 10; i++)
        visited[i] = 0;
}
void friend_network::BFS()
{
    int visited1[num_users] = {0};
    que q;
    index_holder *temp2;
    int mincomm = 0, maxlikes = 0;
    node *temp1;
    q.enque(0);
    visited1[0] = 1;
    int ind;
    cout << "BFS of Tree = ";
    while (q.questatus() != -1)
    {
        ind = q.deque();
        cout << net[ind]->name << "  ";
        if (max_likes < net[ind]->numlike)
        {
            max_likes = net[ind]->numlike;
            maxlikes = ind;
        }
        if (min_comments > net[ind]->numcom)
        {
            min_comments = net[ind]->numcom;
            mincomm = ind;
        }
        max_likes = max(max_likes, net[ind]->numlike);
        min_comments = min(min_comments, net[ind]->numcom);
        temp2 = net[ind]->next;
        while (temp2 != NULL)
        {
            if (visited1[temp2->index] != 1)
            {
                visited1[temp2->index] = 1;
                q.enque(temp2->index);
            }
            temp2 = temp2->next;
        }
    }
    cout << endl<< "Maximun Likes =" << net[maxlikes]->name << "\nMinimum Comments=" << net[mincomm]->name << endl;
}
void friend_network::new_user()
{
    int index;
    string name;
    int month, day, year, numcom, numlike, numfriend;
    cout << "\nEnter number of user you want to add: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\n\tUser: " << i + 1 << endl;
        cout << "Enter name :";
        cin.ignore();
        getline(cin, name);
        cout << "Enter DOB( dd mm yy)>> :";
        cin >> day >> month >> year;
        cout << "Enter number of comments  :";
        cin >> numcom;
        cout << "Enter number of num of likes  :";
        cin >> numlike;
        net[num_users] = new node(name, day, month, year, numlike, numcom, i);
        num_users++;
    }
}
void friend_network ::connect_user()
{
    cout << " Enter number of connection >>";
    int n, i, j;
    cin >> n;
    for (int k = 0; k < n; k++)
    {
        cout << " Enter index of two users>>";
        cin >> i >> j;
        make_connection(i, j);
    }
}
void friend_network::make_connection(int i, int j)
{
    index_holder *temp2 = new index_holder(j);
    net[i]->numfriend++;
    node *temp1 = net[i];
    if (temp1->next == NULL)
    {
        temp1->next = temp2;
        return;
    }
    index_holder *temp3;
    temp3 = temp1->next;
    while (temp3->next != NULL)
        temp3 = temp3->next;
    temp3->next = temp2;
}
void friend_network::show_data()
{
    cout << "\t -----Record-----\n\n";
    cout << setw(10) << "Name  "<< "  Birthdate  "<< "  friends" << "  Likes "<< " comments." << endl;
    for (int i = 0; i < num_users; i++)
    {
        cout << setw(20) << net[i]->name << "  " << net[i]->day << "/" << net[i]->month << "/" << net[i]->year << setw(10) << net[i]->numfriend << setw(10) << net[i]->numlike << setw(10) << net[i]->numcom << endl;
    }
    cout << endl;
}

void friend_network::show_adjacency()
{
    node *temp1;
    index_holder *temp2;
    int numfr = 0;
    cout << "Adjecency List:-" << endl;
    for (int i = 0; i < num_users; i++)
    {
        numfr = net[i]->numfriend;
        cout << setw(20) << net[i]->name << "[" << i << "]";
        if (net[i]->next == NULL)
            continue;
        temp2 = net[i]->next;
        while (numfr--)
        {
            cout << " -> " << setw(20) << net[temp2->index]->name;
            temp2 = temp2->next;
        }
        cout << endl;
    }
}

int main()
{
    int choice = 0;
    friend_network tree;
    do
    {
        cout << "\n1.Add user to network \n2.Add friend connection \n3.Show adjacency List \n4.Print user data \n5.Maximum Likes and Minimum Comments \n6.Find user by birthday month \n7.Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;
        cout << "\n";
        switch (choice)
        {
        case 1:
            tree.new_user();
            break;
        case 2:
            tree.connect_user();
            break;
        case 3:
            tree.show_adjacency();
            break;
        case 4:
            tree.show_data();
            break;
        case 5:
            tree.BFS();
            break;
        case 6:
            tree.DFS_CALL();
            break;
        case 7:
            break;
        default:
            cout << "Invalid choice!!!" << endl;
        }
    }while (choice != 7);
    return 0;
}
