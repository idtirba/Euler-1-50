#include <stdio.h>

main() {

   int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

   //initialize date to start at Tuesday 1 January 1901
   int sundays=0, year=1901, month=0, dayOfTheWeek=3;
   int daysInYear = 365, daysInTheMonth;
   
   while(year<2001) {
        month = 0;
        if(year%4 == 0 && ((year%100 > 0)|| (year%400 == 0))) {
           daysInMonth[1] = 29;
           daysInYear = 366;
        }
        else {
           daysInMonth[1] = 28;
           daysInYear = 365;
        }
        
        daysInTheMonth = daysInMonth[0];
        
        while(daysInYear) {
            if(dayOfTheWeek==1 && daysInTheMonth == daysInMonth[month])
               sundays++;
               
            daysInTheMonth--;
            dayOfTheWeek++;
            
            if(dayOfTheWeek > 7)
               dayOfTheWeek = 1;
               
            if(daysInTheMonth==0) {
                month++;
                
                if(month<12)
                   daysInTheMonth = daysInMonth[month];
            }

            daysInYear--;
        }
        year++;
        
    }
    printf("sundays: %d\n", sundays);

}