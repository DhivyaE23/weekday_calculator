#include <stdio.h>
int main() {
    int day,month,year;
    int feb_days;
    int century;
    int i,leap_years=0;
    int normal_years=0;
    int prev_year,current_year,days_count=0;
    int final;
    printf("Enter date (dd mm yyyy):");
    scanf("%d %d %d",&day,&month,&year);
    if(year<=2000){
        printf("Invalid year");
        return 0;
    }
    if(month<1||day<1||day>31){
        printf("Invalid date");
        return 0;
    }
    if((year%4==0&&year%100!=0)||year%400==0){
        feb_days=29;
    }else{
        feb_days=28;
    }
    if((month==2&&day>feb_days)||(month==4&&day>30)||(month==9&&day>30)||(month==11&&day>30)){
        printf("Invalid date for given month");
        return 0;
    }
    century=year/100;
    if(century>=20)
    century=0;
    else if(century==19)
    century=1;
    else if(century==18)
    century=3;
    else 
    century=5;
    for(i=1;i<year-2000;i++){
        current_year=2000+i;
        if((current_year%4==0&&current_year%100!=0)||current_year%400==0)
        leap_years++;
        else
        normal_years++;
    }
    prev_year=(2*leap_years+normal_years)%7;
    if(month>1) 
    days_count+=31;
    if (month>2) 
    days_count+=feb_days;
    if(month>3) 
    days_count+=31;
    if(month>4) 
    days_count+=30;
    if(month>5) 
    days_count+=31;
    if(month>6) 
    days_count+=30;
    if(month>7) 
    days_count+=31;
    if(month>8) 
    days_count+=31;
    if(month>9) 
    days_count+=30;
    if(month>10) 
    days_count+=31;
    if(month>11) 
    days_count+=30;
    days_count=days_count+day;
    if(days_count>=7){
        days_count=days_count%7;
    }
    final=(century+prev_year+days_count)%7;
    printf("\nThe day for the given date is:");
    switch(final){
        case 0:printf("sunday");
        break;
        case 1:printf("Monday");
        break;
        case 2:printf("Tuesday");
        break;
        case 3:printf("wednesday");
        break;
        case 4:printf("Thursday");
        break;
        case 5:printf("Friday");
        break;
        case 6:printf("saturday");
        break;
    }
}