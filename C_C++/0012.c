#include <stdio.h>  

#include <string.h>  

//#include <stdlib.h>

  

 int drawtext(int type,int line,char mycha,int leng){   

      if (type==1){  

          if ((line==1)||(line==5)){  

             printf("..#..");  

       }else if ((line==2)||(line==4)){  

             printf(".#.#.");  

         }else{  

             printf("#.%c.#",mycha);  

         }  

     }else if(type==leng&&(type%3)!=0){

           if ((line==1)||(line==5)){  

             printf(".#..");  

         }else if ((line==2)||(line==4)){  

            printf("#.#.");  

         }else{  

             printf(".%c.#",mycha);  

        } 

         }else if((type%3)==0){  

         if ((line==1)||(line==5)){  

             printf("..*..");  

         }else if ((line==2)||(line==4)){  

            printf(".*.*.");  

         }else{  

             printf("*.%c.*",mycha);  

        }

        }else if((type%3)==2){  

         if ((line==1)||(line==5)){  

             printf(".#.");  

         }else if ((line==2)||(line==4)){  

            printf("#.#");  

         }else{  

             printf(".%c.",mycha);  

        }   

     } else if((type%3)==1){

            if ((line==1)||(line==5)){  

             printf(".#..");  

       }else if ((line==2)||(line==4)){  

             printf("#.#.");  

         }else{  

             printf(".%c.#",mycha);  

         }  

            }

     return 0;  

 }  

 int main() {  

     char strText[16];  

     int i,lenght,line;  

    scanf("%s",strText);  

     lenght = strlen(strText);  

     for (line=1;line<=5 ;line++ ){  

         for (i=1;i<=lenght ;i++ ){   

                drawtext(i,line,strText[i-1],lenght);  

        }  

        printf("\n");  

    } 

    //system("PAUSE"); 

     return 0;  

 }