#include<iostream>
#include <cstdlib> 
 using namespace std;
 struct node 
 {// this is struct for creating a  new node 
    int data;
    node* next;
    node(int data)
    {
        this->data = data;
        this->next= nullptr;
    }
 };
 
 class createStack
 {  
    public :
    int size;
    int top;
    node *tail;
    node *root;
    
    createStack(int size)
    {// setting default variables ;
        this->size=size;
        this->top=0;
        this->root= nullptr;
        this->tail=root;     
    }
    
    int push(int data)
    {
        if(this->size<=top)
        {
            cout<<"THE STACK IS FULL";
            return 1; 
        }
       
         if(this->root==nullptr)
         { 
            this->root = new node(data);
            top++;
            tail = root;
            cout<<"NEW NODE IS ADDED IN THE STACK";
            return 0;
        }
        
        tail->next= new node (data);
        tail= tail->next;
        top++;
        cout<<"NEW NODE IS ADDED IN THE STACK"<<"\n";
        return 0;
         

    }
    int pop()
    {   node* trav=root;

        if(trav==nullptr)
        {
            cout<<"STACK IS EMPTY";
            return 1;
        }
        if(root->next==nullptr)
        {
            cout<<"POPPING LAST ELEMENT OF STACK"<<root->data;
            root=nullptr;
            this->tail=this->root;
            return 0;
        } 
        while(trav->next->next!=nullptr)
        {
            
            trav= trav->next;
        }

        cout<<"POPPING ELEMENT "<<trav->next->data<<"\n";
        tail= trav;
        trav= trav->next;
        delete(trav);
        top--;
        tail->next=nullptr;    
        return 0;        
    }
    int peek()
    {
        if(this->root==nullptr)
        {
            cout<<"STACK IS EMPTY"<<"\n";
            return 0;
        }
        cout<<"LAST ELEMENT IS "<<tail->data<<"\n";
        return 0;

    }
    int traverse()
    {
        node* trav=root;
        system("clear");
        while(trav!=nullptr)
        {
            cout<<"\t"<<trav->data<<"\n";
            trav=trav->next;
        }
        return 0;
    }
};
int main ()
{
    int choice, value,size;
cout<<"Enter size of stack "<<"\n";
cin>>size;

    createStack S1(size); 
    while (1) {
        cout << "\nStack Operations Menu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Traverse\n";
        cout << "5. Get  Remaning Size of Stack\n";
        cout << "6. Exit \n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if(S1.size <= S1.top) {
                    cout << "Stack is full\n";
                    cout << "Press Enter to continue...";
                    cin.ignore(); 
                    cin.get();  
                    system("clear");
                    break;
                }

                cout << "Enter the value to push: ";
                cin >> value;
                S1.push(value);
                break;
            case 2:
                S1.pop();

                break;
            case 3:
                S1.peek();
                cout << "Stack is full\n";
                cout << "Press Enter to continue...";
                cin.ignore(); 
                cin.get();  
                system("clear");
                break;
            case 4:
                S1.traverse();
                cout << "Press Enter to continue...";
                cin.ignore(); 
                cin.get();  
                system("clear");
                break;
            case 5:
                cout<<"Remening size of stack is "<<S1.size-S1.top<<"\n";
                cout << "Press Enter to continue...";
                cin.ignore(); 
                cin.get();  
                system("clear");
                break;
            case 6:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice, please try again.\n";
                cout << "Press Enter to continue...";
                cin.ignore(); 
                cin.get();  
                system("clear");
        }
        system("clear");
    }

    return 0;
}
