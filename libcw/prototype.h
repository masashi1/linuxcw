

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


