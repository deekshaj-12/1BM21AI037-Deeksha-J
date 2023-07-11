#include <iostream>
using namespace std;

class Sort
{
    private:
        int a[10], n;
    public:
        void selection();
        void bubble();
        void getinput();
        void Print();
        void swap(int& a, int& b);
};

void Sort::bubble()
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i;j<n;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
            }
        }
    }
}

void Sort::selection()
{
    int i,j,min,temp;
    for(i=0;i<n-1;i++)
    {
        min = i;
        for(j=i+1;j<n;j++)
        {
            if(a[min]>a[j])
                min = j;
        }
        swap(a[min], a[i]);
    }
}

void Sort::swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void Sort::getinput()
{
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    cout<<"Enter array elements : ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
}

void Sort::Print()
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }
}

int main()
{
    int choice;
    cout<<"Enter:\n1.Bubble sort\n2.Selection sort"<<endl;
    cin>>choice;
    Sort s;
    s.getinput();
    if(choice==1)
        s.bubble();
    else if(choice==2)
        s.selection();
    else
        cout<<"Invalid Entry"<<endl;
    cout<<"\nSorted array :\n";
    s.Print();
    return 0;
}
