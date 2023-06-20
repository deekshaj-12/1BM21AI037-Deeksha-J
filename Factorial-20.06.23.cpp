#include <iostream>
using namespace std;

class FACT
{
    private:
        int n;
    public:
        int factorial(int n);
};

int FACT::factorial(int n)
{
    if(n==1||n==0)
        return 1;
    else
        return factorial(n-1)*n;
}

int main()
{
    int n,i;
    cout<<"Enter a number\n";
    cin>>n;
    FACT f;
    cout<<f.factorial(n);
    return 0;
}