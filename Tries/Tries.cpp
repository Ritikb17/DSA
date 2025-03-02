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
    bool deleteStr(string str, Tries* trav, int index = 0)
    {
        if (index == str.length()) 
        {
            if(trav->isTerminal){
                cout<<"DELETED FROM TRIE";
                trav->isTerminal=false;
                return true;   
            }
            else{
                cout<<"NOT IN TRIE";
                return false;
            }
        }

        int PI = str[index] - 'A';

        if (trav->children[PI] == nullptr) 
        {
            return false;
        }

        return deleteStr(str, trav->children[PI], index + 1);
    }


    bool isStartWith(string str, Tries* trav,int index=0)
    {
        int PI = str[index]-'A';
        if(index == str.length()-1)
        {
            if(trav->children[PI]!=nullptr)
                return true;
            else
                return false;
            
        }
       
        if(trav->children[PI]!=nullptr)
        { index++;
            return isStartWith(str,trav->children[PI],index);
        }
        cout<<"not with you ";
                return false;
        
    }
};

int main()
{
    createTries T1;
    int choice;
    string word;
    
    while (true)
    {
        cout << "\n----- Trie Operations Menu -----\n";
        cout << "1. Add a word to the trie\n";
        cout << "2. Search for a word in the trie\n";
        cout << "3. Delete a word from the trie\n";
        cout << "4. Check if any word starts with a prefix\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter the word to add (uppercase): ";
                cin >> word;
                if (T1.add(word, T1.root))
                    cout << word << " added to the trie.\n";
                else
                    cout << "Failed to add " << word << ".\n";
                    cin.ignore(); 
                    cin.get();  
                    system("clear");
                    break;

            case 2:
                cout << "Enter the word to search for (uppercase): ";
                cin >> word;
                if (T1.search(word, T1.root))
                    cout << word << " found in the trie.\n";
                else
                    cout << word << " not found in the trie.\n";
                    cin.ignore(); 
                    cin.get();  
                    system("clear");
                    break;

            case 3:
                cout << "Enter the word to delete (uppercase): ";
                cin >> word;
                if (!T1.deleteStr(word, T1.root))
                    cout << word << " could not be deleted.\n";
                    cin.ignore(); 
                    cin.get();  
                    system("clear");
                    break;

            case 4:
                cout << "Enter the prefix to check (uppercase): ";
                cin >> word;
                if (T1.isStartWith(word, T1.root))
                    cout << "There is a word that starts with " << word << ".\n";
                else
                    cout << "No word starts with " << word << ".\n";
                    cin.ignore(); 
                    cin.get();  
                    system("clear");
                    break;

            case 5:
                cout << "Exiting the program...\n";
                return 0;

            default:
                cout << "Invalid choice, please try again.\n";
                cout << "Press Enter to continue...";
                cin.ignore(); 
                cin.get();  
                system("clear");
        }
    }

    return 0;
}
