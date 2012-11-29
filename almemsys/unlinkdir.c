// unlinkdir.c
// $Id: $
// masashi shimakura

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<dirent.h>
#include<unistd.h>
#include"almemsys.h"



/* --------- FILE COPY -------- */
int unlinkdir(char * dirpath)
{
int ret, stat;
DIR * dp;
struct dirent * dirstat;

char * filename = (char *)calloc(5, sizeof(char));

ret = 0;
stat = 0;

if((dp = opendir(dirpath))!=NULL){

   for( ;(dirstat = readdir(dp))!=(struct dirent *)NULL; ){

      if(0 != self_memcmp(dirstat->d_name, ".")){
         if(0 != self_memcmp(dirstat->d_name, "..")){
            filename = safe_memcpy(filename, dirpath, BUF_MAX);
            filename = safe_strncat(filename, "/", BUF_MAX);
            filename = safe_strncat(filename, dirstat->d_name, BUF_MAX);
            stat = unlink(filename);
            if(stat < 0){
               fprintf(stderr,"unlinkdir(): not delete file name. <%s>\n", filename);
               ret = ret - 1;
               }
            else{
               #ifdef UNLINK_DIR
               fprintf(stderr,"unlinkdir(): delete file. <%s>\n", filename);
               #endif
               }
            }
         }
      }

   closedir(dp);
   }
else {
   fprintf(stderr,"unlinkdir(): open dir. <%s>\n", dirpath);
   ret = -1;
   }

free(filename);
return(ret);
}



