#include <iostream>
#include <iomanip>
#define SIZE 50
using namespace std;

struct Node //creating structure
{
    string name; //student name
    long roll;   //student roll number
    bool flag;   //flag for counter
    int chain;   //storing chaining element
};

class HashTable //create HashTable
{
    Node *h;
    int size; //size of table
public:
    HashTable() {}                   //non-parameterized constructor
    HashTable(int);                  //parameterized constructor, it creates hash table with default values
    void with_Replace(long, string); //function implements linear probing using chaining with replacement
    void display();                  //display Hashtable
};

HashTable ::HashTable(int n) //function create hash table with default values
{
    size = n;
    h = new Node[size];

    for (int i = 0; i < n; i++) //assign default values to variables
    {
        h[i].roll = 0;
        h[i].name = "";
        h[i].flag = false;
        h[i].chain = -1; //if there is no chaining, returns -1
    }
    cout << "\nHash Table created successfully !!!" << endl;
}

void HashTable ::with_Replace(long roll, string name) //function implements linear probing using chaining with replacement
{
    int location, i = 0, j; //initialize variable for location
    location = roll % size; //find modulus of roll number as its hash-key

    //case 1 : position is empty
    if (!h[location].flag)       //check, is there location unoccupied or availble
    {                            //if "YES"
        h[location].roll = roll; //assign values at that position
        h[location].name = name;
        h[location].flag = true;
    }
    //case 2 : element is present
    else //if locaation is already occupied
    {
        i = 0;                        //used to scan the table
        j = location;                 //
        while (i < size && h[j].flag) //scan all the table whenever you find empty position but elements should be less than size
        {
            j = (j + 1) % size; // maintain circular to come back from last
            i++;
        }

        if (i == size)                          //if total student is equal is size of created Hash-Table
        {                                       //this check whether replacement is possible or not
            cout << "\nHash-Table is Full !!!"; //if NOT, print table is full
            return;
        }

        //case 3 : element are present but both are giving different modulus
        if (h[location].roll % size != location) //if location is not equal to actual
        {
            i = h[location].roll % size;   //modulus of location of roll stored  in one variable i
            while (h[i].chain != location) //scan the entire table to find new location
                i = h[i].chain;            //chain the element
            h[i].chain = h[location].chain;

            while (h[i].chain != -1) //scan the element until you find empty chain
                i = h[i].chain;      //chain the position
            h[i].chain = j;

            h[j].roll = h[location].roll; //assign values at new location
            h[j].name = h[location].name;
            h[j].flag = true;
            h[j].chain = -1;

            h[location].roll = roll; //assign values of element one who actually belong
            h[location].name = name;
            h[location].flag = true;
            h[location].chain = -1;
        }
        //case 4 : element are present but both are giving same modulus
        else
        {
            h[j].roll = roll; //assign values
            h[j].name = name;
            h[j].flag = true;
            h[j].chain = -1;

            i = location; //chain the referece element at that position
            while (h[i].chain != -1)
                i = h[i].chain;
            h[i].chain = j;
        }
    }
}

void HashTable ::display() //function display the created Hash-Table
{
    cout << "\nSr.no\tName\tRoll-Num\tChain" << endl;
    cout << "===================================================================" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << setw(3) << i + 1 << setw(10) << h[i].name << setw(15) << h[i].roll << setw(10) << h[i].chain << endl;
    }
}

int main()
{
    int choice, size;
    string name;
    long roll;

    cout << "Enter size of the Hash Table:  "; //ask size for Hash-Table creation
    cin >> size;
    HashTable ht2(size); //alocate Hash-Table of asked size

    //MENU
    do
    {
        cout << "|==============HASH-TABLE==============|" << endl;
        cout << "|-----------(With-Replacement)---------|" << endl;
        cout << "|--------------------------------------|" << endl;
        cout << "|          1. Insert Data              |" << endl;
        cout << "|          2. Display Hash-Table       |" << endl;
        cout << "|          3. Exit                     |" << endl;
        cout << "|======================================|" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter student name : ";
            cin >> name;
            cout << "Enter student roll number : ";
            cin >> roll;
            ht2.with_Replace(roll, name);
            cout << "Data inserted successfully !" << endl;
            break;

        case 2:
            ht2.display();
            break;

        case 3:
            break;

        default:
            cout << "\nInvalid Choice!!!" << endl;
        }
    } while (choice != 3);
    return 0;
}
