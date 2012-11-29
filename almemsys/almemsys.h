// almemsys.h
// $Id: almemsys.h,v 1.5 2007/11/01 06:01:24 sendan Exp $
// masashi shimakura


#ifndef _ALMEMSYS_H_
  #define _ALMEMSYS_H_

  #ifndef _STDIO_H_
    #include<stdio.h>
  #endif

  #ifndef _TIME_H_
    #include<time.h>
  #endif

  #ifndef _INET_H_
    #include<arpa/inet.h>
  #endif

  #ifndef _NETINET_IN_H_
    #include<netinet/in.h>
  #endif

  #ifndef _NETDB_H
    #include<netdb.h>
  #endif

  #ifndef _UNISTD_H_
    #include<unistd.h>
  #endif


  #define CL_VER "almemsys-1.0.8"

  #define HAVE_STDARGS
  #define VA_LOCAL_DECL va_list ap;
  #define VA_START(f) va_start(ap, f)
  #define VA_SHIFT(v,t) ; 
  #define VA_END va_end(ap)

  #ifndef BUF_DEFLEN 
    #define BUF_DEFLEN 128
  #endif
  #ifndef BUF_LEN
    #define BUF_LEN 256
  #endif
  #ifndef BUF_MAX
    #define BUF_MAX (1024 * 1024 * 2)
  #endif

//  debug option 
//  #define AL_DEBUG
//  #define SOCKET_BUG
//  #define FDCAT_BUG
//  #define SEND_RECV_BUG
//  #define MIME_BASE64_BUG


  /* ---- bufer ---- */
  int mem_count(char [], char);
  int mem_tcount(char [], char);
  int char_count(char [], char);
  int rm_char(char [], char);
  int char_point(char *, char, int);
  int char_get(char *, char *, char, int);
  int clean_mem(char [], char, int);
  int set_mem(char [], char, int);
  int rm_crlf(char [], int);
  int swap_mem(char [], char, char);
  int chmem(char [], int);
  int self_memcpy(char *, char *, int);
  int self_strncat(char *, char *, int);
  int self_delim_get(char *, char *, char, int, int);
  int count_memcpy(char *, char *, int);
  char * count_memcpy2(char *, char *, int, int);
  int delim_count(char *, char, int, int *, int *);
  int memcount_cpm(char *, char *, int, int, int);
  int ch_int(char *);
  int ch_int2(char *);
  int ch_int3(char *, char);
  int ch_int_v6(char *);
  int ch_int_v4(char *);
  char * ch_char(char *, char *);
  int self_memcmp(char *, char *);
  int alversion(void);
  int mlexit(void);
  int self_delim_get(char *, char *, char, int, int);

  /* --- heep bufer  ---- */
  char * safe_fpcat(FILE *, char *, int *, int);
  char * safe_fdcpm(int, char *, int *, int, int);
  char * safe_fdcat(int, char *, int *, int, int);
  char * safe_filefdcat(int, char *, int *, int, int);
  char * safe_memcpy(char *, char *, int); 
  char * safe_strncat(char *, char *, int); 
  char * safe_sprintf(char *, long int, const char *,...);
  char * delim_get(char *, char *, char, int *, int);
  char * swap_rn(char *, char);
  char * safe_ujtoj(char *);
  char * safe_base64(char *);
  char * safe_base64inheader(char *, char *);
  char * mime_ujtoj(char *);
  char * null_free(char *);

  /* --- socket --- */
  int socket_reada(int, char *, int);
  int socket_readas(int, char *, int, int, int);
  int socket_reads(int, char * , int, int);
  int socket_sends(int, char *, int, char);
  int socket_send(int, char *, int);
  char * select_fdcat(int sk, char * getdata, int * ret, int max, int interval);

  /* --- file --- */
  int file_copy(char *, char *);
  char * alget_read(char *, char *, int, int, int *, char, int, int);
  int alget_write(int, FILE *, int, char, int, int);
  int unlinkdir(char *);

  /* --- sp --- */
  int base64(char *, int, char *);
  char * base64_kai(char *);
  int ujtoj(unsigned char *, unsigned char *);
  int randdata(int, int);

  /* --- time --- */
  char * char_wday(int);
  char * char_mon(int);
  int utime_getr(time_t, char);
  int ctime_getr(char);
  int time_minus(int, int, char);
  time_t get_unixtime(int, int, int, int, int, int);
  int day_minus(int);
  int month_last(int, int);
  int month_minus(int);
  char * time_getr(char *);
  char * message_id(char * backdata, char * name, char * domain);

  /* --- socket --- */
  int socket_bind46(struct addrinfo * hints, char * addr, char * port, int * ls, int maxsock);
  char * socket_accept46(char * ipdate, fd_set rfd, int * s, int smax, int sockmax, int * sk, int * net);
  int socket_accept46rfd(fd_set * rfd, int * s, int smax);
  int socket_connect46(struct addrinfo * hints, char * ip, char * port, int * sk);

  int socket_connect(struct sockaddr_in *, int, char [], int *);
  int socket_bind(struct sockaddr_in *, int, char *, int *);
  int socket_accept(struct sockaddr_in *, int *, int *);

  /* --- thread --- */
  #include<pthread.h>
  int safe_pthread_mutex_lock(pthread_mutex_t *);

  /* --- bit --- */
  char * out_bit(unsigned int ina, char * bit, int bx);
  unsigned long in_bit(char * bit, char bx);

#endif


