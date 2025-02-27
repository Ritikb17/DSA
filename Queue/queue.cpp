#include<iostream>
#include <cstdlib> 

using namespace std;
struct node 
{
    int data;
    node* next;
    node(int data)
    {
        this->data=data;
        this->next=nullptr;
    }
};
class createQueue
{
    public:
    node* root;
    node* head;
    int size;
    int top;
    
    createQueue(int size)
    {
        this->size=size;
        this->top=0;
        this->root=nullptr;
        this->head=nullptr;
    }
    int push(int data)
    {
        if(this->top>=this->size)
        {
            cout<<"QUEUE IS FULL";
            return 1;
        }
        if(root==nullptr)
        {
            root = new node(data);
            cout<<"PUSHED IN QUEUE"<<"\n";
            head = root;
            top++;
            return 0;
        }
        node* trav= this->root;
        while(trav->next!=nullptr)
        {
            trav=trav->next;
        }
         trav->next= new node(data);
         this->top++;
         cout<<"PUSHED IN QUEUE"<<"\n";
         return 0;
    }
    int pop()
    
    {
        if(root==nullptr)
        {
            cout<<"QUEUE IS EMPTY";
            return 1;
        }
        node *trav=root;
        root=root->next;
        cout<<" REMOVING VALUE  "<<trav->data<<"\n";
        delete(trav);
        return 0;
    }
    int traverse()
    {   node *trav = root;
        while(trav!=nullptr)
        {
            cout<<" "<<trav->data<<"\n";
            trav=trav->next;
        }
         return 0;
    }

};
int main() {
    int size, choice, value;
    cout << "Enter the size of the queue: ";
    cin >> size;

    createQueue Q1(size);

    do {
        cout << "\nQueue Operations Menu:\n";
        cout << "1. Push an element\n";
        cout << "2. Pop an element\n";
        cout << "3. Traverse the queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if(Q1.size<=Q1.top)
            {   system("clear");
                cout<<"QUEUE IS FULL";
                break;
            }
            cout << "Enter value to push: ";
            cin >> value;
            Q1.push(value);
            cout << "Press Enter to continue...";
            cin.ignore(); 
            cin.get();  
            system("clear");
            break;
        case 2:
            Q1.pop();
            cout << "Press Enter to continue...";
            cin.ignore(); 
            cin.get();  
            system("clear");
            break;
        case 3:
            cout << "Queue: ";
            Q1.traverse();
            cout << "Press Enter to continue...";
            cin.ignore(); 
            cin.get();  
            system("clear");
            break;
        case 4:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
            cout << "Press Enter to continue...";
            cin.ignore(); 
            cin.get();  
            system("clear");
            
        }
    } while (choice != 4);

    return 0;
}
