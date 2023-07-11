#include<iostream>
using namespace std;

class quick_sort
{
    int a[20],n;
    public:
        void getdata();
        void display();
        void quick(int,int);
        int partition(int,int);
};

void quick_sort::getdata()
{
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++)
        cin>>a[i];
    quick(0,n-1);
}

void quick_sort::display()
{
    cout<<"The sorted array is: ";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}

void quick_sort::quick(int l,int u)
{
    int j;
    if(l<u)
    {
        j=partition(l,u);
        quick(l,j-1);
        quick(j+1,u);
    }
}

int quick_sort::partition(int l,int u)
{
    int v,i,j,temp;
    v=a[l];
    i=l;
    j=u+1;
    do
    {
        do
            i++;
        while(a[i]<v&&i<=u);
        do
            j--;
        while(v<a[j]);
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);
    a[l]=a[j];
    a[j]=v;
    return(j);
}

int main()
{
    quick_sort q;
    q.getdata();
    q.display();
    return 0;
}
