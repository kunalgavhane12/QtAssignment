#include <iostream>
using namespace std;

static int count = 0;

bool isLeapYear(int year)
{
    if(year%400==0 || (year%4==0 && year%100 !=0))
    return true;

    return false;
}

int monthofDay(int month, int year)
{
    if(month == 4 || month == 6 || month == 9 || month == 11)
    return 30;
    else if(month == 2)
    return isLeapYear(year)? 29:28;
    else
    return 31;
}

int countDays(int py, int by)
{
    for(int i = by + 1; i<py; i++)
    {
        if(!isLeapYear(i))
        count += 365;
        else 
        count += 366;        
    }

    return count;
}

int main()
{
    int pd,pm,py,bd,bm,by;
    cout<<"Enter Present date (DD MM YYYY): "<<endl;
    cin>>pd>>pm>>py;

    cout << "Enter Birthday Date (DD MM YYYY): "<<endl;
    cin>>bd>>bm>>by;
    int dx=0,dy=0;
    
    if(bm <= 12)
    {
        for(int i=bm; i<=12; i++)
        {
            dx += monthofDay(i,by);
        }
        if(isLeapYear(by))
        dx += 1;        
    }
    if(pm <= 12)
    {
        for(int i=pm; i<=12; i++)
        {
            dy += monthofDay(i,py);
        }
        if(isLeapYear(py))
        dy = 366 - dy;
        else
        dy = 365 - dy;
    }

    int result = (dx-bd) + (dy+pd);
    // cout<< "dx :" <<dx - bd<<" dy: " <<dy + pd<<endl;
    
    int y,m,d;
    y = py - by;

    if(pm < bm)
    {
        y--;
        m = 12 - (bm - pm);
    } 
    else
    {
        m = pm - bm; 
    }

    if(pd<bd)
    {
        m--;
        d = monthofDay(bm,by) - (bd - pd);
    }
    else
    {
        d = pd - bd;
    }

    int totalDay = countDays(py,by);
    int totalMonth = 12*y+m;

    cout<<"Age: "<<y<<" years," <<" Month: "<<m<<", "<<"Day: "<<d<<endl;
    cout<<"Total Days: "<<totalDay + result <<" Total Month: "<<totalMonth<<endl;


    return 0;
}