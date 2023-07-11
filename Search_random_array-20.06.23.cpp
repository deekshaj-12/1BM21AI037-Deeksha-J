#include <iostream>
#include <chrono>
#include <time.h>
#include <random>
#include <ctime>
using namespace std;

class search
{
    private:
        int key, n;
        int a[10000];
    public:
        void ls();
        void bs();
        void sort();
        void swap(int& a,int& b);
        void randomArray(int min, int max);
        void getinput(int k,int num);

};

void search::sort()
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

void search::swap(int& a, int& b) 
{
    int temp = a;
    a = b;
    b = temp;
}

void search::randomArray(int min, int max)
{
    random_device rd;
    mt19937 generator(rd());
    srand(time(0));
    uniform_int_distribution<int> distribution(min, max);
    for (int i = 0; i < n; ++i)
    {
        a[i] = distribution(generator);
    }
}

void search::ls()
{
    int i=0;
    auto start1 = std::chrono::high_resolution_clock::now();
    for(;i<n;i++)
    {
        start1 = std::chrono::high_resolution_clock::now();
        if(a[i]==key)
        {
            cout<<"\n\nFound at "<<i+1<<" position   - By linear search"<<endl;
            break;
        }
    }
    auto finish1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> t = finish1 - start1;
    std::cout << "\n\nElapsed time: " << t.count() << " s";
    if(i==n)
    {
        cout<<"\nNot found  -  linear search";
    }
}


void search::bs()
{
    void sort();
    int l=0, h=n-1, m;
    auto start2 = std::chrono::high_resolution_clock::now();
    while(l<=h)
    {
        auto start2 = std::chrono::high_resolution_clock::now();
        m= (h+l)/2;
        if(a[m]==key)
        {
            cout<<"\nFound at position "<<m+1<<"  - by binary search"<<endl;
            break;
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
    auto finish2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> t = finish2 - start2;
    std::cout << "\n\nElapsed time: " << t.count() << " s";
    if(l>h)
    {
        cout<<"\nNot found  - binary search";
    }
}

void search::getinput(int k,int num)
{
    key=k;
    n=num;
}

int main()
{
    int n, k, c;
    cout<<"\n1.linear search\n2.binary search";
    cin>>c;
    printf("\nEnter the number of elements : ");
    scanf("%d",&n);
    printf("\nEnter the key element : ");
    scanf("%d",&k);
    search s;
    s.getinput(k,n);
    s.randomArray(1,1000);
    if(c==1)
        s.ls();
    else
        s.bs();
    return 0;
}