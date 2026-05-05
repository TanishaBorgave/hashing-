#include <iostream>
#include <vector>
using namespace std;

class HashTable
{
    int n;
    vector<int> table;

public:
    // Constructor
    HashTable(int size)
    {
        n = size;
        table.assign(n, -1); // initialize all with -1 (EMPTY)
    }

    // Hash function (Division method)
    int hashfun(int key)
    {
        return key % n;
    }

    // Insert using Linear Probing
    void insertKey(int key)
    {
        int idx = hashfun(key);
        int start = idx;

        while (table[idx] != -1)
        {
            idx = (idx + 1) % n;

            if (idx == start)
            {
                cout << "Hash table is full\n";
                return;
            }
        }

        table[idx] = key;
    }

    // Search key
    bool searchKey(int key)
    {
        int idx = hashfun(key);
        int start = idx;

        while (table[idx] != -1)
        {
            if (table[idx] == key)
                return true;

            idx = (idx + 1) % n;

            if (idx == start)
                break;
        }

        return false;
    }

    // Display table
    void show()
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << " -> ";
            if (table[i] == -1)
                cout << "EMPTY";
            else
                cout << table[i];
            cout << "\n";
        }
    }
};

int main()
{
    int n, m;
    cin >> n; // size of hash table
    HashTable ht(n);

    cin >> m; // number of elements

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        ht.insertKey(x);
    }

    ht.show();

    int key;
    cin >> key;

    if (ht.searchKey(key))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    return 0;
}