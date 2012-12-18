/* -*- C -*- */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include "libbeep.h"
#include "libcw.h"
#include "cwread.h"
#include "almemsys.h"

int optin (int argc, char * argv[], cw_length * cw_len, CWREAD_STAT *stat)
{
  int i, opt_index;
  extern char * optarg;
  struct option cwread_long_opt[] = {
    {"in" ,	required_argument,	NULL,	'f'},
    {"speed",	required_argument,	NULL,	's'},
    {"tone",	required_argument,	NULL,	't'},
    {"out",	required_argument,	NULL,	'o'},
    {0,		0,			0,	0},
  };
  
  while((i = getopt_long(argc, argv, "v:s:f:t:o:",
			 cwread_long_opt, &opt_index))!= EOF){
    switch (i){
    case 'f':
      printf("open file name <%s>\n", optarg);
      stat->in = safe_memcpy(stat->in, optarg, BUF_LEN);
      break; 

    case 's':
      printf("cw speed set. <%s>\n", optarg);
      stat->speed = strtol(optarg, (char **)NULL, 10);
      cw_speedset(cw_len, stat->speed);
      break; 

    case 't':
      printf("cw tone set. <%s>\n", optarg);
      stat->tone = strtol(optarg, (char **)NULL, 10);
      cw_toneset(cw_len, stat->tone);
      break;

    case 'o':
      sscanf(stat->out, "%s", optarg);
      break;

    default:
      stat->in = safe_memcpy(stat->in, "/mmp/taro", BUF_LEN);
      printf("file not open.\n");
      break;
    }
  }
  return 0;
}
