#include <iostream>
using namespace std;

class search
{
    private:
        int a[20], key, n;
    public:
        void ls();
        void bs();
        void getinput(int s[],int k,int num);

};

void search::ls()
{
    int i=0;
    for(;i<n;i++)
    {
        if(a[i]==key)
        {
            cout<<"\nFound at "<<i+1<<" position   - By linear search";
            return;
        }
    }
    if(i==n)
    {
        cout<<"\nNot found  - by linear search";
    }
}

void search::bs()
{
    int l=0, h=n-1, m;
    while(l<h)
    {
        m= n/2;
        if(a[m]==key)
        {
            cout<<"\nFound at position "<<m+1<<"  - by binary search";
            return;
        }
        else if(key > a[m])
        {
            l=m+1;
        }
        else if(key < a[m])
        {
            h=m-1;
        }
    }
    if(l>=h)
    {
        cout<<"\nNot found  - by binary search";
    }
}

void search::getinput(int s[20],int k,int num)
{
    for(int i=0;i<num;i++)
    {
        a[i]=s[i];
    }
    key=k;
    n=num;
}
int main()
{
    int a[20];
    int n, k;
    printf("\nEnter the number of elements : ");
    scanf("%d",&n);
    printf("\nEnter the key elements : ");
    scanf("%d",&k);
    printf("\nEnter array elements : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    search s;
    s.getinput(a,k,n);
    s.ls();
    s.bs();
}