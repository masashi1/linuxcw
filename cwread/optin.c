/* -*- C -*- */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include "libbeep.h"
#include "libcw.h"
#include "cwread.h"
#include "almemsys.h"
#include "version.h"

int usage (void)
{
  char usage[] =
    "\ncwread is a study tool for morse code.\n"
    "- playing morse code, reading from a file.\n"
    "- using beep sound.\n\n"
    "cwrand [options]\n"
    "  --tone     , -t <value> : tone of beep(Hz). [700Hz]\n"
    "  --speed    , -s <value> : chars per min.    [130]\n"
    "  --in       , -f <value> : input file name.  [None]\n"
    "  --out      , -o <value> : output file name. [None]\n"
    "  --help     , -h         : this screen.      [None]\n"
    ;

  printf("\nVersion: %s\n", VERSION);
  puts(usage);
  exit(1);
}


/* Need more error checking. */
int optin (int argc, char * argv[], cw_length * cw_len, CWREAD_STAT *stat)
{
  int i, opt_index;
  extern char * optarg;
  struct option cwread_long_opt[] = {
    {"help",	no_argument,		NULL,	'h'},
    {"version", no_argument,		NULL,	'v'},
    {"in" ,	required_argument,	NULL,	'f'},
    {"speed",	required_argument,	NULL,	's'},
    {"tone",	required_argument,	NULL,	't'},
    {"out",	required_argument,	NULL,	'o'},
    {0,		0,			0,	0},
  };
  
  while((i = getopt_long(argc, argv, "s:f:t:o:hv",
			 cwread_long_opt, &opt_index))!= EOF){
    switch (i){
    case 'h':
    case 'v':
      usage();
      break;
      
    case 'f':
      /* printf("open file name <%s>\n", optarg); */
      stat->in = safe_memcpy(stat->in, optarg, BUF_LEN);
      break; 

    case 's':
      /* printf("cw speed set. <%s>\n", optarg); */
      stat->speed = strtol(optarg, (char **)NULL, 10);
      break; 

    case 't':
      /* printf("cw tone set. <%s>\n", optarg); */
      stat->tone = strtol(optarg, (char **)NULL, 10);
      break;

    case 'o':
      sscanf(stat->out, "%s", optarg);
      break;

    default:
      /* stat->in = safe_memcpy(stat->in, "/mmp/taro", BUF_LEN);
       * printf("file not open.\n"); */
      usage();
      break;
    }
  }
  return 0;
}
