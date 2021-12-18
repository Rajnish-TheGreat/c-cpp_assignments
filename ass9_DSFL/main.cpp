#include <iostream>
#define MAX 100
using namespace std;

//student record
struct student
{
    int rank;
    int roll;
};

typedef struct student student;
//heap class
class heap
{
public:
    int A[MAX];
    void heapify(int, int);
    void buildheap(int);
    void heapSort(int *, int);
    void Display(int);
};

void swap(int &a, int &b)
{ //swap function for heapify
    int temp;
    temp = a;
    a = b;
    b = temp;
}

//heapify for creating min heap

void heap::heapify(int n, int i)
{
    int temp;
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && A[l] < A[smallest])
    {
        smallest = l; //if left child is smaller than root
    }
    if (r < n && A[r] < A[smallest])
    {
        smallest = r; //if right chld is smaller than the root
    }
    if (smallest != i)
    {
        swap(A[i], A[smallest]);
        heapify(n, smallest);
    }
}
//heapify for heap sort

void heapify_sort(int *arr, int n, int i)
{
    int temp;
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] < arr[smallest])
    {
        smallest = l;
    }
    if (r < n && arr[r] < arr[smallest])
    {
        smallest = r;
    }
    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        heapify_sort(arr, n, smallest);
    }
}
void heap::buildheap(int n)
{
    int start = (n / 2) - 1;
    for (int i = start; i >= 0; i--)
    {
        heapify(n, i); //using heapify on non leaf nodes
    }
}

void heap::Display(int n)
{
    cout << "Rank" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << endl; //displaying min heap
    }
}

//heap sort for getting lowest rank or largest rank
void heap::heapSort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = A[i]; //copying min heap to another array
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify_sort(arr, i, 0);
    }
}

int main()
{
    int choice, n, arr[10], head;
    student s[100];
    heap h;

    //menu driven
    do
    {
        cout << "\nMenu \n1.Create Heap Table \n2.Display Heap \n3.Highest Rank Student(Min Heap) \n4.Lowest Rank(Heap sort) \n5.Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter no. of students to be added" << endl;
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "Enter rank of student" << endl;
                cin >> s[i].rank;
                cout << "Enter roll of student" << endl;
                cin >> s[i].roll;
                h.A[i] = s[i].rank;
            }
            h.buildheap(n);
            break;
        case 2:
            h.Display(n);
            break;
        case 3:
            head = h.A[0];
            for (int i = 0; i < n; i++)
            {
                if (head == s[i].rank)
                {
                    cout << "The highest ranker is: " << s[i].rank << " Roll no. " << s[i].roll << endl;
                }
            }
            break;
        case 4:
            h.heapSort(arr, n);
            if (n < 10)
            {
                for (int i = 0; i < n; i++)
                {
                    cout << arr[i] << "\t";
                }
            }
            else
            {
                for (int i = 0; i < 10; i++)
                {
                    cout << arr[i] << "\t";
                }
            }
            break;
        case 5:
            break;
        default:
            cout << "Invalid Choice!!!";
        }
    } while (choice != 5);
}
