#include <iostream>
using namespace std;

struct Tries
{
    char data;
    Tries* children[26];
    bool isTerminal;
    
    Tries()
    {
        data = '\0'; 
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
        isTerminal = false;
    }
    
    Tries(char data)
    {
        this->data = data;
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};

class createTries
{
public:
    Tries* root;

    createTries()
    {
        root = new Tries();
    }

    bool add(string data, Tries* trav, int strIndex = 0)
    {
        int PI = data[strIndex] - 'A';

        if (trav->children[PI] == nullptr)
        {
            trav->children[PI] = new Tries(data[strIndex]);
        }

        if (strIndex == data.length() - 1)
        {
            trav->children[PI]->isTerminal = true;
            return true;
        }

        return add(data, trav->children[PI], strIndex + 1);
    }

    bool search(string str, Tries* trav, int index = 0)
    {
        if (index == str.length()) 
        {
            return trav->isTerminal;
        }

        int PI = str[index] - 'A';

        if (trav->children[PI] == nullptr) 
        {
            return false;
        }

        return search(str, trav->children[PI], index + 1);
    }
};

int main()
{
    createTries T1;
    T1.add("HELLO", T1.root);
    
    T1.add("GOGO", T1.root);

    cout << "Searching HELLO: " << (T1.search("HELLO", T1.root) ? "Found" : "Not Found") << endl;

    cout << "Searching GOGO: " << (T1.search("GOGO", T1.root) ? "Found" : "Not Found") << endl;

    return 0;
}
