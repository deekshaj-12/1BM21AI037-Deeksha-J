#include <iostream>
using namespace std;

class GCD
{
    private:
        int m,n;
    public:
        int gcd(int m, int n);
        void getinput(int M,int N);
};

int GCD::gcd(int m, int n)
{
    if(m%n==0)
    {
        return n;
    }
    else if(m>n)
    {
        return gcd(n,m%n);
    }
    else
    {
        gcd(n,m);
    }

}

void GCD::getinput(int M,int N)
{
    m=M;
    n=N;
}

int main()
{
    int m,n,res;
    cout<<"Enter 2 numbers\n";
    cin>>m>>n;
    GCD g;
    g.getinput(m,n);
    res = g.gcd(m,n);
    cout<<res;
    return 0;
}
