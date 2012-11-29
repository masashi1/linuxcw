


int m_last(int uu, int mon)
{
int ret;
ret = -1;

switch(mon){
   case 1: ret = 31; break;
   case 2: if(uu == 1){
              ret = 29;
              }
           else{
              ret = 28;
              }
                     break;
   case 3: ret = 31; break;
   case 4: ret = 30; break;
   case 5: ret = 31; break;
   case 6: ret = 30; break;
   case 7: ret = 31; break;
   case 8: ret = 31; break;
   case 9: ret = 30; break;
   case 10: ret = 31; break;
   case 11: ret = 30; break;
   case 12: ret = 31; break;
   default: ret = 0; break;
   }

return ret;
}



// 何年何月の最後の日を出す
int month_last(int ye, int mon)
{
int ret;
ret = -1;

switch(ye){
   case 2008: ret = m_last(1, mon); break;
   case 2009: ret = m_last(0, mon); break;
   case 2010: ret = m_last(0, mon); break;
   case 2011: ret = m_last(0, mon); break;
   case 2012: ret = m_last(1, mon); break;
   case 2013: ret = m_last(0, mon); break;
   case 2014: ret = m_last(0, mon); break;
   case 2015: ret = m_last(0, mon); break;
   case 2016: ret = m_last(1, mon); break;
   case 2017: ret = m_last(0, mon); break;
   case 2018: ret = m_last(0, mon); break;
   case 2019: ret = m_last(0, mon); break;
   case 2020: ret = m_last(1, mon); break;
   default: ret = 0; break;
   }

return ret;
}






