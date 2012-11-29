
// このファイルはlibcwの使い方のデモのソースになります。
// デフォは欧文ですが、'{ｱｲｳｴｵ}'で和文モードに切り替え可能です。
// 和文モードの中で英文を表現するにはcwでは通常'()'でくくるので、'}(abc){'と記入すること。
// つまり'{'で和文モードになり、'}'で英文モードになります。
// ARやHHのように結合する場合は'<HH>'と記入してください。
// この点に関しては和文欧文の違いはありません。



#include<stdio.h>
#include"libbeep.h"
#include"libcw.h"



int main(void)
{
int fd, co;
fd = -1;


// cw用の構造体を定義します。
cw_length cw_len;

// デフォルトの符号データベースを初期化
cw_default_memset(&cw_len);

// デフォルトの信号の長さ(3)と周波数(2)を設定
cw_defaultset(&cw_len, 700, 80);

// beepデバイスファイルを開いてFDを得る
fd = beep_fdopen(fd);

// 符号データベースの検索
// キャラから番号検索
printf("char_no(): %d\n", char_no(&cw_len, 'a'));
// 符号列から番号検索
printf("note_no(): %d\n", note_no(&cw_len, "-.-."));


// 指定された文字列からCWを鳴らす関数
// デフォの設定は。。。
// 短点          '.'
// 長点          '-'
// 文字間の空白  ' '
// 単語間の空白  '*'
// それ意外の文字は何も起こらないが電気とあなたの労働力の無駄。
beep_bufout(&cw_len, fd, ".... .-.*.... .-.*.... .-.***.-,-.*. .***");

// 単純にローマ字を指定し、音を出してみる。
for(co = 0; co < 3; co++){
   cw_sign(&cw_len, fd, 'c');
   cw_sign(&cw_len, fd, ' ');
   cw_sign(&cw_len, fd, 'q');
   cw_sign(&cw_len, fd, '*');
   }

// さも返事ああったかのように、周波数とスピードを少々変えてみます。(笑い）
cw_defaultset(&cw_len, 880, 70);

cw_sign(&cw_len, fd, 'j');
cw_sign(&cw_len, fd, ' ');
cw_sign(&cw_len, fd, 'a');
cw_sign(&cw_len, fd, ' ');
cw_sign(&cw_len, fd, '1');
cw_sign(&cw_len, fd, ' ');
cw_sign(&cw_len, fd, 'a');
cw_sign(&cw_len, fd, ' ');
cw_sign(&cw_len, fd, 'b');
cw_sign(&cw_len, fd, ' ');
cw_sign(&cw_len, fd, 'c');
cw_sign(&cw_len, fd, '*');

cw_sign(&cw_len, fd, 'd');
cw_sign(&cw_len, fd, ' ');
cw_sign(&cw_len, fd, 'e');
cw_sign(&cw_len, fd, '*');

cw_sign(&cw_len, fd, 'k');
cw_sign(&cw_len, fd, '*');


// beepのFDを開放し終了。
beep_close(fd);

return 0;
}




