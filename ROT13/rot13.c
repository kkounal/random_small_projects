#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void rot13(int  * str);

int main(void)
{
  int c = 5;
  int * str;
  int i;
  int j=200;
  while(1){
      i=0;
      printf("Press 1 to encrypt or decrypt, any other key to exit \n");
      scanf("%d",&c);
      getchar();
      if(c == 1){
        printf("Give string to encrypt or decrypt, ~ to stop: \n");
        str = (int *) calloc(j,sizeof(char)); 
        c=getchar();
        while( (c != EOF && (c != '~') ) && i<100000){
            str[i] = c;
            i++;
            c= getchar();
            if(i>j){
                j=i*2;
                str = (int *) realloc(str, j);    
            }
        }
        str[i] = '\0';
        rot13(str);
        free(str);
      }
      else{
        exit(0);
      }

  }


  return EXIT_SUCCESS;
}

void rot13(int * str){
    int i=0;
    int j;
    while(str[i] != '\0'){

        if(str[i]>64 && str[i]<91){
            str[i] = str[i] + 13;
            if( (j = str[i]-90) > 0)
                str[i] = 64 + j;
        }
        
        else if(str[i]>96 && str[i]<123){
            str[i] = str[i] + 13;
            if( (j = str[i]-122) > 0)
                str[i] = 96 + j;
        }
        putchar(str[i]);
        i++;
    }
    putchar('\n');

}

/*ascii 65-90 A-Z  97-122 a-z
 * */
