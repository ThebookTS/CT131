//BookTs

//hien thi thoi gian mac dinh
#include <stdio.h>
#include <string.h>
#include <time.h>

int main()
{
   struct tm t;
   t.tm_sec    = 15;
   t.tm_min    = 16;
   t.tm_hour   = 6;
   t.tm_mday   = 18;
   t.tm_mon    = 6;
   t.tm_year   = 118;
   t.tm_wday   = 5;

   puts(asctime(&t));
   
   return(0);
}
