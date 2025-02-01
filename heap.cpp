

#include<iostream>
#include<vector>
using namespace std;
class Heap
{
  public :
  vector<int> ary;
  void add(int Data)
  {
    int size = ary.size();
    int p=0;
    ary.push_back(Data);
    
        while(size>0)
        {
            p=(size-1)/2;
            if(ary[size]>ary[p])
            {
                swap(ary[size],ary[p]);
                size=p;
            }
            else
            {
                break;
            }
            
        }
        
  }
  
  void print()
  {
      for (int i=0;i<ary.size();i++)
      {
          cout<<ary[i]<<" ";
      }
  }
  
  
  void heapify(int index)
  {
      int leftI= 2*index+1;
      int rightI=2*index+2;
      int bignoI;
      if(isLeaf(index))
      {
          return ;
      }
      if(leftI==ary.size()-1)
      {
          if(ary[leftI]>ary[index])
          {
              swap(ary[leftI],ary[index]);
              return;
          }
          return;
      }
      
      if(ary[leftI]>ary[rightI])
        {bignoI=leftI;}
        else{
            bignoI=rightI;
        }
      if(ary[bignoI]>ary[index])
      {
          swap(ary[bignoI],ary[index]);
          heapify(bignoI);
      }
      else
      {
          return;
      }
      
      
  }
  
  void deletelast()
  {
      int size=ary.size();
      if(size==0)
      {
          cout<<"heap is empty";
          return;
      }
      ary[0]=ary[size-1];
      ary.pop_back();
      heapify(0);
      
  }
  private:
  bool isLeaf(int index)
  {
      if(2*index+1>ary.size()-1)
        return true;
            

    return false;
  }
};

int main()
{
    Heap h;
    h.add(10);
    h.add(20);
    h.add(30);
    h.add(40);
    h.add(50);
    h.add(60);
    h.deletelast();
    h.print();
    return 1;
}