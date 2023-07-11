#include <iostream>
using namespace std;

class Sort
{
    public:
        void Merge(int A[], int n);
        void MergeSort(int b[], int p, int c[], int q, int A[]);
        void Print(int a[], int n);
};

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
    Sort s;
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    cout<<"Enter array elements : \n";
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> A[i];
    }
    s.Merge(A,n);
    cout<<"\nSorted array :\n";
    s.Print(A, n);
    return 0;
}