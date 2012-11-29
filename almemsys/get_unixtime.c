#include<time.h>


// localな時間からUNIX時間をかえす。フォーマットチェックなし。
// mktime()はWeekを無視する。

time_t get_unixtime(int ye, int mo, int day, int hour, int min, int sec)
{
time_t ret;
struct tm t;
ret = 0;
if(ye < 1970){ ye = 1970; }
if(mo < 0){ mo = 0; }
if(day < 0){ day = 0; }
if(hour < 0){ hour = 0; }
if(min < 0){ min = 0; }
if(sec < 0){ sec = 0; }

t.tm_year = (ye - 1900);    /* 2001年 */
t.tm_mon  = (mo - 1);       /* 5月    */
t.tm_mday = day;            /* 20日   */
t.tm_wday = 0;              /* 曜日 */
t.tm_hour = hour;           /* 14時   */
t.tm_min  = min;            /* 20分   */
t.tm_sec  = sec;            /* 00秒   */
t.tm_isdst= -1;             /* 夏時間無効 */

ret = mktime(&t);

return ret;
}

