#include<iostream>
template<unsigned long long N>
struct factorial_templete
{
    static const unsigned long long val = factorial_templete<N-1>::val * N; 
};
template<>
struct factorial_templete<0>
{
    static const unsigned long long val = 1ULL;
};
unsigned long long factorial_recusion(unsigned long long N)
{
    return N ? factorial_recusion(N-1) * N : 1;
}
unsigned long long factotial_loop(unsigned long long N)
{
    unsigned long long val = 1ULL;
    while(N)
    {
        val *= N--;
    }
    return val;
}
int main(void)
{
    std::cout << factorial_templete<25>::val << " " << factorial_recusion(25) << " " << factotial_loop(25);
    return 0;
}