#include<stdio.h>                                                                                                                                                  /*  บรรทัดที่  2  */
void main(void)                                                                               
{                                                                                                    
      struct simple                                                                       
    {                                                                                                    
      int  num;                                                                                        
      char ch;                                                                                 
    } a,b;                                                                                                                                                                            
      a.num = 9; a.ch='K';                                                          
      b.num = a.num+6; b.ch=a.ch-1;                                    
      printf("Number a = %d, Char a = %c\n", a.num, ++a.ch);          
      printf("Number b = %d, Char b = %c\n", b.num-6, b.ch);          
      printf("\nPress any key back to program...");                                                                                     
}       