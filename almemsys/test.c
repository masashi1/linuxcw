// test.c
// $Id: test.c,v 1.1.1.1 2007/09/19 05:49:54 sendan Exp $
// masashi shimakura

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/* #include<almemsys.h>  */
#include"almemsys.h"

int main(void)
{
int ret, sta, sto;
char * taro = (char *)calloc(12, sizeof(char));
char * hana = (char *)calloc(12, sizeof(char));
char * sachi = (char *)calloc(12, sizeof(char));

char c8[34];
char * ch8 = c8;
unsigned int in8;

char tt[1024];
char * ttt = tt;
char yy[1024];
char * yyy = yy;
memset(ttt, 0x00, 1024);
memset(yyy, 0x00, 1024);

ret = 0;
sta = 0;
sto = 0;


alversion();

self_memcpy(ttt, "12,34,56,78,90", 1024);
self_delim_get(ttt, yyy, ',', 3, 1024);
printf("ttt = %s, yyy = %s\n", ttt, yyy);

taro = safe_memcpy(taro, "abcdef", 256);
printf("SAFE_MEMCPY DATA =%s\n", taro);
taro = safe_strncat(taro, "12345", 256);
printf("SAFE_STRNCAT DATA =%s\n", taro);
hana = safe_sprintf(hana, 256,"%s, %s, %s\n", taro, "fvbj", "12345");
printf("SAFE_SPRINTF DATA =%s\n", hana);
sachi = delim_get(hana, sachi, ',', &ret, 0);
printf("DELIM_GET DATA1 =%s\n", sachi);
sachi = delim_get(hana, sachi, ',', &ret, 1);
printf("DELIM_GET DATA2 =%s\n", sachi);
sachi = delim_get(hana, sachi, ',', &ret, 2);
printf("DELIM_GET DATA3 =%s\n", sachi);
sachi = delim_get(hana, sachi, ',', &ret, 3);
printf("DELIM_GET DATA4 =%s\n", sachi);
taro = safe_memcpy(taro, "-a-1-20-345", 256);
printf("SAFE_MEMCPY DATA =%s", taro);
ret = ch_int(taro);
printf("CH_INT DATA= %s RET=%d\n", taro, ret);
ret = char_count(taro, '-');
printf("CHAR_COUNT DATA= %s RET=%d\n", taro, ret);
ret = char_get(taro, sachi, '-', 3);
printf("CHAR_GET DATA= %s DATA2= %s RET=%d\n", taro, sachi, ret);
ret = char_point(taro, '-', 4);
printf("CHAR_POINT DATA= %s RET=%d\n", taro, ret);
ret = clean_mem(taro, '+', 3);
printf("CLEAN_MEM DATA= %s RET=%d\n", taro, ret);
ret = count_memcpy(taro, "abcdefghijklmn", 3);
printf("COUNT_MEMCPY DATA= %s RET=%d\n", taro, ret);
taro = safe_memcpy(taro, "hanako-sashiko-ayako", 256);
ret = delim_count(taro, '-', 1, &sta, &sto);
printf("DELIM_COUNT DATA= %s RET=%d STA= %d STO= %d\n", taro, ret, sta, sto);
ret = mem_count(taro, '-');
printf("MEM_COUNT DATA= %s RET=%d\n", taro, ret);
ret = memcount_cpm(taro, "12345", 1, 3, 4);
printf("MEMCOUNT_CPM DATA= %s RET=%d\n", taro, ret);
taro = safe_memcpy(taro, "abcdef\r\n", 256);
ret = rm_crlf(taro, (int)strlen(taro));
printf("RM_CRLF DATA= %s RET=%d\n", taro, ret);
ret = set_mem(taro, 'd', (int)strlen(taro));
printf("SET_MEM DATA= %s RET=%d\n", taro, ret);
taro = safe_memcpy(taro, "02020", 256);
ret = swap_mem(taro, '2', '1');
printf("SWAP_MEM DATA= %s RET=%d\n", taro, ret);
ret = unlinkdir("/home/masashi/dirtest/");
printf("UNLINKDIR PATH= %s RET=%d\n", "/home/masashi/dirtest/", ret);
printf("char_wday(1) = %s\n", char_wday(1));
printf("char_mon(1) = %s\n", char_wday(1));
printf("utime_getr(, 'y') = %d\n", utime_getr(time(NULL), 'y'));
printf("utime_getr(, 'm') = %d\n", utime_getr(time(NULL), 'm'));
printf("utime_getr(, 'd') = %d\n", utime_getr(time(NULL), 'd'));
printf("cutime_getr('y') = %d\n", ctime_getr('y'));
printf("cutime_getr('m') = %d\n", ctime_getr('m'));
taro = message_id(taro, "test", "ms-n.com");
printf("Message_id(%s)\n", taro);

taro = safe_memcpy(taro, "jjjjjjjjjjjjj", 1000);
taro = safe_ujtoj(taro);
printf("safe_ujtoj(): <%s>\n", taro);

taro = safe_memcpy(taro, "@1234567890@", 1000);
taro = safe_ujtoj(taro);
taro = safe_memcpy(taro, "ふれふれこれこれはははははななななな", 1000);
printf("mime_ujtoj(): <%s>\n", mime_ujtoj(taro));
printf("randdata(): <%d>\n", randdata(0,25));
printf("randdata(): <%d>\n", randdata(0,25));
printf("randdata(): <%d>\n", randdata(0,25));
printf("randdata(): <%d>\n", randdata(0,25));
printf("randdata(): <%d>\n", randdata(0,25));
printf("randdata(): <%d>\n", randdata(0,25));

memset(ch8, 0x00, 34);
in8 = in_bit("01010101", 8);
ch8 = out_bit(in8, ch8, 8);

printf("in_bit() out_bit(): <%d><%s><%d>\n", in8, ch8, (int)in_bit(ch8, 8));

taro = safe_memcpy(taro, "121212121212121212", 1000);
printf("taro 1: <%s>\n", taro);
ret = rm_char(taro, '1');
printf("taro 2: <%s>%d\n\n", taro, ret);

taro = safe_memcpy(taro, "121212121212121212", 1000);
printf("taro 1: <%s>\n", taro);
ret = rm_char(taro, '2');
printf("taro 2: <%s>%d\n\n", taro, ret);

taro = safe_memcpy(taro, "101010101001", 1000);
printf("taro 1: <%s>\n", taro);
ret = rm_char(taro, '0');
printf("taro 2: <%s>%d\n\n", taro, ret);



return 0;
}




