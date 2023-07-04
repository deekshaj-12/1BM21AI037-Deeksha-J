#include <iostream>
using namespace std;

class Sort
{
    private:
        int a[20], n;
    public:
        void selection();
        void getinput(int b[20], int num);
        void Print();
};

void Sort::selection()
{
    int i,j,min,temp;
    for(i=0;1<n-1;i++)
    {
        min = i;
        for(j=i+1;j<n;j++)
        {
            if(min>a[j])
                min = j;
        }
        temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }
}

void Sort::getinput(int b[20], int num)
{
    for(int i=0;i<num;i++)
    {
        a[i]=b[i];
    }
    n=num;
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
    int b[20], num;
    cout<<"Enter the number of elements"<<endl;
    cin>>num;
    cout<<"Enter array elements : ";
    for(int i=0;i<num;i++)
    {
        cin>>b[i];
    }
    Sort s;
    s.getinput(b,num);
    s.selection();
    cout<<"\nSorted array :\n";
    s.Print();
}
