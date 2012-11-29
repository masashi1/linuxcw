// file_copy.c
// $Id: file_copy.c,v 1.1.1.1 2007/09/19 05:49:54 sendan Exp $
// masashi shimakura

#include<stdio.h>


/* --------- FILE COPY -------- */
int file_copy(char * file1, char * file2)
{
int stat;
FILE * fp;
FILE * fp2;
int inA;

stat = 0;

if((fp = fopen(file1, "r+"))!=NULL){
   if((fp2 = fopen(file2, "w+"))!=NULL){
      while(stat == 0){
         inA = getc(fp);
         switch(inA){
            case EOF: stat = 1;  break;
            default : putc(inA, fp2); break;
            }
         }
      }
   else {
      fprintf(stderr,"file_copy(): %s file not open.\n", file2);
      stat = -1;
      return(stat);
      }
   fclose(fp);
   fclose(fp2);
   }
else {
   fprintf(stderr,"file_copy(): %s file not open.\n", file1);
   stat = -1;
   return(stat);
   }

return(stat);
}



