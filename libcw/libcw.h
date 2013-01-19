/* -*- mode: C; -*- */
#ifndef _LIBCW_H_

#define _LIBCW_H_

#define BUFF_LENG	10
#define CHAR_LENG	67
#define WCHAR_LENG	67

#define CW_DEF_FREQ     700       // おとのたかさ KHzていどのつもりん
#define CW_DEF_LENGTH   150       // おとのながさ

typedef struct cw_len cw_length;

struct cw_len{
  int mode;               // Default 0 欧文、和文ハ1
  int freq;               // 音程                           比率
  int length_default;     // 長点短点のベースになる長さ。    1(CW_DEF_LENGTH)
  int sp;                 // 短点の長さ。                    1
  int lp;                 // 長点の長さ。                    3
  int ps;                 // 二点間のスペースの長さ。        1
  int cs;                 // 二キャラクタ間のスペースの長さ。3
  int ws;                 // 二ワード間のスペースの長さ。    7
  char short_p;           // short point を定義するキャラ   (.)
  char long_p;            // long point を定義するキャラ    (-)
  char break_p;           // 文字間のbreak point を定義するキャラ   ( )
  char wbreak_p;          // 単語間のbreak point を定義するキャラ   (*)

  struct {                // ローマ字の辞書、記号対音列（-.-.）数字で対応。
    char note_sign[CHAR_LENG][BUFF_LENG];
    char char_sign[CHAR_LENG];
  } roman; 

  struct {                // 和文辞書、記号対音列（-.-.）数字で対応。
    char note_sign[WCHAR_LENG][BUFF_LENG];
    char char_sign[WCHAR_LENG][BUFF_LENG];
  } wabun; 

};

int cw_defaultset(cw_length * cw_len, int default_freq, int default_length);
int cw_speedset(cw_length * cw_len, int default_length);
int cw_toneset(cw_length * cw_len, int default_freq);
int cw_sign(cw_length * cw_len, int fd, char sign);
int cw_sign_wabun(cw_length * cw_len, int fd, char * sign);
int long_point(cw_length * cw_len, int fd);
int short_point(cw_length * cw_len, int fd);
int beep_bufout(cw_length * cw_len, int fd, char * buf);
int cw_default_memset(cw_length * cw_len);
int cw_default_memset_roman(cw_length * cw_len);
int cw_default_memset_wabun(cw_length * cw_len);
int char_no(cw_length * cw_len, char sign);
int char_no_wabun(cw_length * cw_len, char * sign);
int note_no(cw_length * cw_len, char * note);
char char_replace(char ch);

#endif
