#include<iostream>
using namespace std;

class Sort
{
    private:
        int a[20], n;
    public:
        void input();
        void sort();
        void display();
};

void Sort::sort()
{
    int i=0,j=0, cur;
    for(i=1;i<n;i++)
    {
        cur = a[i];
        j=i-1;
        while((a[j]>cur) && j>=0)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = cur;
    }
}

void Sort::input()
{
    cout<<"Enter the number of elements : ";
    cin>>n;
    cout<<"\nEnter elements : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
}

void Sort::display()
{
    cout<<"Sorted array :\n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}

int main()
{
    Sort s;
    s.input();
    s.sort();
    s.display();
}