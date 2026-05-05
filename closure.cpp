#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool contains(string s, char c)
{
    return s.find(c) != string::npos;
}

// closure function
string closure(string attrs, vector<pair<string, string>> fds)
{
    bool changed = true;

    while (changed)
    {
        changed = false;

        for (auto fd : fds)
        {
            string lhs = fd.first;
            string rhs = fd.second;

            bool canApply = true;

            for (char c : lhs)
            {
                if (!contains(attrs, c))
                {
                    canApply = false;
                    break;
                }
            }

            if (canApply)
            {
                for (char c : rhs)
                {
                    if (!contains(attrs, c))
                    {
                        attrs += c;
                        changed = true;
                    }
                }
            }
        }
    }
    return attrs;
}

string checkCandidateKey(string a, string b)
{
    if (a.length() != b.length())
    {
        return " is not a candidate key.";
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (a == b)
    {
        return " is a candidate key.";
    }

    return " is not a candidate key.";
}

int main()
{
    string attrs = "A";
    string all = "ABCD";

    vector<pair<string, string>> fds = {
        {"A", "B"},
        {"B", "C"},
        {"C", "D"}};

    string result = closure(attrs, fds);

    cout << "Closure of " << attrs << " = " << result << endl;
    cout << attrs << checkCandidateKey(result, all) << endl;

    return 0;
}