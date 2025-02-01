#include <iostream>
using namespace std;

struct Tries
{
    char data;
    Tries* children[26];
    bool isTerminal;
    Tries()
    {
        for( int i=0;i<26;i++)
        {
            children[i]=nullptr;
        }
        isTerminal=false;
    }
    Tries(char data)
    {
        this->data=data;
        for( int i=0;i<26;i++)
        {
            children[i]=nullptr;
        }
        isTerminal=false;
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
    
    bool add(string data, Tries* trav,int strIndex=0)
    {
        
        int PI = data[strIndex]-'A';
        Tries* temp;
        if( trav->children[PI]==nullptr)
        {
            trav->children[PI]= new Tries(data[strIndex]);
            if(data.length()-1==strIndex)
            {
                temp= trav->children[PI];
                temp->isTerminal=true;
                return true;
            }
            return true;
            
        }
        else
        {
           return  add(data,trav->children[PI],strIndex+1);
        }
        
    }
};

int main()
{   
    createTries T1;
    T1.add("HELLO",T1.root);
    return 0;
}