#include <iostream>
int main(int argc, char const *argv[])
{
    int a[5][2]{{1,2},{3,4},{5,6},{7,8},{9,10}};
    for(int i=0;i<5;i++)for(int j=0;j<2;j++) std::cout << a[i][j] << " ";
    std::cout << "\n" << a[0][2] << " ";
    return 0;
}
