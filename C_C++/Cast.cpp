#include<iostream>
#include<algorithm>
int main(){
    int a[] = {3,2,1};
    int size = sizeof(a)/sizeof(a[0]);
    std::sort(a, a+size);
    do {
    for(int b : a){std::cout << b << " ";};
    std::cout << std::endl;
    } while(std::next_permutation(a, a+size));
}