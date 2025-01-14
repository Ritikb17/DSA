#include <iostream>
using namespace std;


struct Node
{
    int data;
    Node *next;
    Node *previous;
    Node (int data,Node *previous)
    {
        this->data=data;
        this->previous=previous;
        next=nullptr;
       
    };
};

class Linked
{
    public:
   
    Node *head;
    Node *tail;
    Linked()
    {
        head=nullptr;    
    }
     void add(int data)
     {
         if(head==nullptr)
         {
             head= new Node(data,nullptr);
             tail=nullptr;
         }
         else
         {
            Node *temp= head;
            while(temp->next!=nullptr)
            {
                temp=temp->next;
            }
            temp->next= new Node(data,temp);
            tail=temp->next;
             
         }
     }
     
     
     void reverseTraverse()
     {
         if(tail==nullptr)
         {
             cout<<"The list is empty";
         }
         else
         {
             Node *temp=tail;
             while(temp!=nullptr)
             {
                cout<<temp->data<<" ";
                temp=temp->previous;
             }
         }
     }
     
     void disp()
     {
         if(head==nullptr)
         {
             cout<<"Linked list is empty ";
         }
         else
         {
            Node *temp= head;
            while(temp!=nullptr)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
           
             
         }
     }
     void deleteLast()
      {
        if(tail==nullptr)
         {
             cout<<"The list is empty";
         }else
         {
             Node *temp=tail;
             tail=tail->previous;
             delete(temp);
             tail->next=nullptr;
         }
      }
      void deleteFirst()
      {
          if(head==nullptr)
          {
              cout<<"The list is empty ";
            }
            else
            {
                Node *temp;
                temp=head;
                head=head->next;
                delete(temp);
            }
      }
     
     
     
     void deleteSpecific(int pos)
     {
         if(head==nullptr)
         {
            cout<<"list is empty";
         }
         else{
            Node *trav= head;
            for (int i=0;i<pos-1;i++)
            {
                trav=trav->next;
            }
           
           
           
            if(trav==head)
            {
                deleteFirst();
               
            }
            else{
                if(trav==tail)
                {
                    deleteLast();
                }
                else{
                    trav->previous->next=trav->next;
                    trav->next->previous=trav->previous;
                    delete(trav);
                }
           
            }
           
         }
     }
     
     
     
     
      ~Linked()
{
    Node *temp;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

};
int main()
{
    Linked L1;
    L1.add(1);
    L1.add(2);
    L1.add(3);
    L1.add(4);
   
    L1.disp();
   
    cout<<"\n";
   
   
    L1.deleteSpecific(1);
    L1.disp();
   

    return 0;
}

