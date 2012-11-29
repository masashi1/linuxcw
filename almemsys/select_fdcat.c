
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

#include "almemsys.h"


//char * select_fdcat(int sk, char * getdata, int * ret, int max, int interval);

// #define SOCKET_RECVBUG


char * select_fdcat(int sk, char * getdata, int * ret, int max, int interval)
{
struct timeval tv;
int retval, getcount, indata, inlen, count, plen;
char bf[BUF_DEFLEN];
char * buf;

buf = bf;
indata = 0;
inlen = 0;
count = 0;
plen = 0;

#ifdef SOCKET_RECVBUG
fprintf(stderr,"SOCKET_RECVBUG: select_fdcat(1): interval time set %d \n", interval);
#endif

if(getdata == NULL){
   getdata = (char *)calloc(BUF_LEN, sizeof(char));
   }
else{
   getdata = null_free(getdata);
   }


fd_set rfds;
tv.tv_sec = interval;
tv.tv_usec = 0;
* ret = 0;
getcount = 0;

FD_ZERO(&rfds);
FD_SET(sk, &rfds);


retval = select(sk + 1, &rfds, NULL, NULL, &tv);

switch(retval){

   case -1: 
            #ifdef SOCKET_RECVBUG
            fprintf(stderr,"SOCKET_RECVBUG: select_fdcat(1) retval=%d line=%d file=%s err=%s\n",
              retval, __LINE__, __FILE__, strerror(errno));
            #endif
            * ret = -1;
            return getdata;
   case 0:
            #ifdef SOCKET_RECVBUG
            fprintf(stderr,"SOCKET_RECVBUG: select_fdcat(2) retval=%d line=%d file=%s err=%s\n",
               retval, __LINE__, __FILE__, strerror(errno));
            #endif
            * ret = -2;
            return getdata;
   default:

         while(1){

            indata = read(sk, buf, BUF_DEFLEN);

            if(indata <= 0){
               if(errno != 11 && errno != 25){
                  #ifdef SOCKET_RECVBUG
                  fprintf(stderr, "SOCKET_RECVBUG: select_fdcat(3): farst read err indata=%d\n", indata);
                  fprintf(stderr, "SOCKET_RECVBUG: select_fdcat(3-2): ERRNO: %d %s\n", errno, strerror(errno));
                  #endif
                  * ret = -3;
                  break;
                  }
               else{
                  sleep(1);
//                #ifdef SOCKET_RECVBUG
                  fprintf(stderr, "SOCKET_RECVBUG: select_fdcat(4): ERRNO: %d %s\n", errno, strerror(errno));
//                #endif
                  getcount++;
                  if(getcount > 5){
                     * ret = -4;
                     break;
                     }
                  }
               } // if
            else{

               buf[indata] = (char)0x00;

               if(indata <= BUF_DEFLEN && indata > 0){

                  if(max >= (inlen + indata)){
                     inlen = inlen + indata;
                     if((getdata = (char *)realloc(getdata, sizeof(char) * (inlen + 1)))==NULL){
                        fprintf(stderr,"The memory cannot be newly secured. \n");
                        exit(1);
                        }
                     strncat(getdata, buf, (indata + 1));
                     clean_mem(buf, '\0', BUF_DEFLEN);
                     count = mem_count(getdata, (char)0x0a);
                     if(getdata[count] == (char)0x0a && count >= 0){
                        getdata[count+1] = (char)0x00;
                        #ifdef SOCKET_RECVBUG
                        fprintf(stderr,"SOCKET_RECVBUG: select_fdcat(5): (1nomall)CO=<%d>COALL=<%d>RIALCO=<%d>DATA=<%s>PO<%p><%d>\n",
                          indata, inlen, (int)strlen(getdata), getdata, getdata, count);
                        #endif
                        #ifdef SEND_RECV_BUG
                        fprintf(stderr,"RECV >> size=%d data=<%s>", strlen(getdata), getdata);
                        #endif
                        * ret = 1;
                        break;
                        }

                     }

                  if(max < (inlen + indata)){
                     plen = indata - (inlen - max);
                     inlen = max;
                     fprintf(stderr,"memory max count err. %d\n", inlen);
                     if((getdata = (char *)realloc(getdata, sizeof(char) * (inlen + 1)))==NULL){
                        fprintf(stderr,"The memory cannot be newly secured. \n");
                        exit(1);
                        }
                     strncat(getdata, buf, (plen + 1));
                     clean_mem(buf, '\0', BUF_DEFLEN);
                     getdata[inlen - 1] = (char)0x0a;
                     getdata[inlen] = (char)0x00;
                     #ifdef SOCKET_RECVBUG
                     fprintf(stderr,"SOCKET_RECVBUG: select_fdcat(6): (1nomall)CO=<%d>COALL=<%d>RIALCO=<%d>DATA=<%s>PO<%p><%d>\n",
                       indata, inlen, (int)strlen(getdata), getdata, getdata, count);
                     #endif
                     while(1){
                        indata = read(sk, buf, BUF_DEFLEN);
                        if(indata == 0){
                           * ret = -5;
                           break;
                           }
                        count = mem_count(buf, (char)0x0a);
                        if(buf[count] == (char)0x0a && count >= 0){
                           fprintf(stderr,"data cut of buf over err. \n");
                           * ret = 2;
                           break;
                           }
                        clean_mem(buf, '\0', BUF_DEFLEN);
                        }
                     }
                  }


               #ifdef SOCKET_RECVBUG
               fprintf(stderr,"SOCKET_RECVBUG: select_fdcat(7) ret=%d line=%d file=%s err=%s size=%d\n",
                  * ret, __LINE__, __FILE__, strerror(errno), strlen(getdata));
               fprintf(stderr,"%s\n", getdata);
               #endif
               } // else

            }  // while

      break;

   }  // switch


//   if(* ret >= 1 || * ret < 0){
//      break;
//      }
//   else{
//      #ifdef SOCKET_RECVBUG
//      fprintf(stderr,"SOCKET_RECVBUG: select_fdcat(8L) Loop Loop. ret=%d line=%d file=%s err=%s size=%d\n",
//         * ret, __LINE__, __FILE__, strerror(errno), strlen(getdata));
//      #endif
//      }


return(getdata);
}






