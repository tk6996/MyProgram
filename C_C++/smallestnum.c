#include <stdio.h>

int main(){
    int n, i, j, temp;
    scanf("%d",&n);
    int num[n];
    for(i = 0; i < n; i++){
        scanf("%d",&num[i]);
    }
    for(i = 0; i < n; i++){

        for(j = i;  j < n; j++){
            if(num[i] > num[j]){
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }

        }

    }
    /*for(i = 0; i < n ; i++){
        if(num[0] == 0){
            if(num[i] != 0){
                num[0] = num[i];
                num[i] = 0;
                break;
            }
        }
    }
*/
    for(i = 0; i < n; i++){
        printf("%d",num[i]);
    }

    return 0;
}
