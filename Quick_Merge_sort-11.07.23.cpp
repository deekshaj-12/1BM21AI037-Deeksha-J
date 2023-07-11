#include <iostream>
using namespace std;

class Sort
{
    private:
        int a[10];
    public:
        void Merge(int A[], int n);
        void MergeSort(int b[], int p, int c[], int q, int A[]);
        void Quick(int l,int u);
        int partition(int l, int u);
        void getinput(int n, int A[]);
        void Print(int a[], int n);
        void print1(int n);
        //void swap(int& a, int& b);
};

void Sort::Quick(int l,int u)
{
    int j;
    if(l<u)
    {
        j=partition(l,u);
        Quick(l,j-1);
        Quick(j+1,u);
    }
}

int Sort::partition(int l,int u)
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

void Sort::Merge(int A[], int N)
{
    int i = 0, j = 0, k = 0;
    int mid = N/2;
    int b[mid], c[N-mid];
    if(N>1)
    {
        for(i = 0; i < N/2; i++)
        {
            b[i]=A[i];
        }
        for (k = N/2, j = 0; k < N; j++, k++)
        {
            c[j] = A[k];
        }
        Merge(b,mid);
        Merge(c,N-mid);
        MergeSort(b,mid,c,N-mid,A);
    }
}

void Sort::MergeSort(int b[], int p, int c[], int q, int A[])
{
    int i=0, j=0, k=0;
    while (i<p && j<q)
    {
        if(b[i]<c[j])
        {
            A[k] = b[i];
            i++;
        }
        else
        {
            A[k] = c[j];
            j++;
        }
        k++;
    }
    if(i==p)
    {
        while(j<q)
        {
            A[k] = c[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<p)
        {
            A[k] = b[i];
            i++;
            k++;
        }
    }
}

void Sort::getinput(int n, int A[])
{
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        A[i]=a[i];
    }
}

void Sort::print1(int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }
}

void Sort::Print(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<"\t";
    }
}

int main()
{
    int n, A[20];
    int choice;
    cout<<"Enter:\n1.Merge sort\n2.Quick sort"<<endl;
    cin>>choice;
    Sort s;
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    cout<<"Enter array elements : \n";
    s.getinput(n, A);
    if(choice==1)
    {
        s.Merge(A,n);
        s.Print(A, n);
    }
    else
    {
        s.Quick(0,n-1);
        s.print1(n);
    }
    cout<<"\nSorted array :\n";
    return 0;
}