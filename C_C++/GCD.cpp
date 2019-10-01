#include <algorithm>
#include <iostream>
#include <chrono>
class GCD
{
public :
    static int gcd_normal(int a,int b);
    static int gcd_euclidean(int a,int b);  
    static int gcd_factorization(int a,int b);     
};
int GCD::gcd_normal(int a,int b)
{
    for(int i=std::min(a,b);i>0;i--)
    {
        if(a%i==0 && b%i==0) return i;
    }
    return 1;
}
int GCD::gcd_euclidean(int a,int b)
{
    int low = std::min(a,b);
    int high = std::max(a,b);
    high%=low;
    return (high>0) ? gcd_euclidean(low,high) : low ;
}
int GCD::gcd_factorization(int a,int b)
{
    int gcd=1;
    int mins=std::min(a,b);
    bool loops=false;
    for(int i=2;i<=mins;i++)
    {
        do
        {
            loops=false;
            if(a%i==0 && b%i==0) 
            {
                gcd*=i;
                a/=i;
                b/=i;
                loops=true;
                mins=std::min(a,b);
            }
        } while (loops);
    }
    return gcd;
}
unsigned long long nanotime()
{
    return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
}
int main(int argc, char const *argv[])
{
    unsigned long long s1,s2;
    s1 = nanotime();
    GCD::gcd_normal(48454554,1185445450);
    s2 = nanotime();
    std::cout<< s2-s1 <<std::endl;
    s1 = nanotime();
    GCD::gcd_euclidean(48454554,1185445450);
    s2 = nanotime();
    std::cout<< s2-s1 <<std::endl;
    s1 = nanotime();
    GCD::gcd_factorization(48454554,1185445450);
    s2 = nanotime();
    std::cout<< s2-s1 <<std::endl;
    return 0;
}
