#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void passgen_file(FILE *, int flag);

int main(int argc, char *argv[])
{
  time_t t;

  
  srand((unsigned) time(&t)); /*random seed based on time*/
  
  if (argc > 1) {
		for (int i = 1; i < argc; i++) {
			FILE *fp = fopen(argv[i], "r");
			if (fp == NULL) {
				perror(argv[i]);
				return EXIT_FAILURE;
			}
			passgen_file(fp,0);
			fclose(fp);
		}
	} else {
		passgen_file(stdin,1);
	}
  
  return EXIT_SUCCESS;
}

void passgen_file(FILE * fp,int flag){
  
  int len;
  int i;
  int r;
  int mode = 0;
  char c = 'a';
 
  if(flag) fprintf(stderr,"how many characters long? \n");
  scanf("%d",&len);
  getchar(); /*flush \n*/
  if(flag) fprintf(stderr,"With capitals y\\n? \n");
  c = fgetc(fp);
  if(c == 'y') mode++;
  if(flag) fprintf(stderr,"With symbols y\\n? \n");
  fgetc(fp);
  c = fgetc(fp);
  if(c == 'y') mode+=2;
  
  for(i=0;i<len;i++){
    
    switch (mode) {
      /*we want a random number from some ranges. We make a bigger range and map the ranges we want to parts of that range*/
      case 0:
        r = rand() / (RAND_MAX / (35+ 1) + 1);
        if(r<10) r = r+48;
        else r = r+97-10;
        putchar(r);
        break; 

      case 1:
        r = rand() / (RAND_MAX / (61+ 1) + 1);
        if(r<10) r = r+48;
        else if(r<36) r = r+65-10;
        else r = r+97-26-10;
        putchar(r);
        break;

      case 2:
        r = rand() / (RAND_MAX / (64+ 1) + 1);
        if(r<33) r = r+32;
        else r = r+91-32;
        putchar(r);
        break;

      default:
        r = 33 + rand() / (RAND_MAX / (90+ 1) + 1);
        putchar(r);
        break;
    }
  }
}

/* 
 * ascii no-cap-no-sym 48-57 97-122 range:10+26=36 
 * ascii no-sym 48-57 65-90 97-122 range:10+26+26=62
 * ascii no-cap 33-64 91-122 range:32+32=64
 * ascii all 33-122 range: 90 
*/
