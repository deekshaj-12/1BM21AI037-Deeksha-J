#include <iostream>
using namespace std;

class FIB
{
    private:
        int n;
    public:
        int fibonacci(int n);
};

int FIB::fibonacci(int n)
{
    if(n==1||n==2)
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    int n,i;
    cout<<"Enter a number\n";
    cin>>n;
    FIB f;
    for(i=1;i<=n;i++)
    {
        cout<<f.fibonacci(i)<<"  ";
    }
    return 0;
}