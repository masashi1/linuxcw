



// cha 単位で t 時 から mt 時間引いた時間を返す関数 0 - 1 = 23
int time_minus(int t, int mt, char cha)
{
int an, minu;
an = 0;
minu = 0;

switch(cha){
   case 'h': minu = 24;
             break;
   case 'i': minu = 60;
             break;
   default : minu = 12;
             break;
   }

if(t >= minu){ t = 0; }
if(t <= 0){ t = 0; }
if(mt >= minu){ mt = 0; }
if(mt <= 0){ mt = 0; }

if(t == 0 && mt <= minu){
    an = minu - mt;
    }
else if(t > 0 && mt <= t){
    an = t - mt;
    }
else if(t > 0 && mt > t){
    an = minu - (mt - t);
    }

if(an == minu){
    an = 0;
    }

return an;
}



