#include <iostream>
using namespace std;

class TOH
{
    public:
        int ctr=0;
        void toh(int a,int b,int c,int n);
};

void TOH::toh(int a,int b,int c,int n)
{
    if(n==0)
        return;
    toh(b,a,c,n-1);
    cout<<a<<" to "<<c<<"\n";
    ctr++;
    toh(c,b,a,n-1);
}

int main()
{
    int num;
    cout<<"Enter a number\n";
    cin>>num;
    TOH t;
    t.toh(1,2,3,num);
    cout<<"Number of shifts required "<<t.ctr;
    return 0;
}
