#include <iostream>
#include <graphics.h>
#include <conio.h>
using namespace std;

#define c WHITE
void put8Pixel(int x,int y,int c){
    putpixel(250+x,250+y,c);
    putpixel(250+y,250+x,c);
    putpixel(250+y,250-x,c);
    putpixel(250+x,250-y,c);
    putpixel(250-x,250-y,c);
    putpixel(250-y,250-x,c);
    putpixel(250-y,250+x,c);
    putpixel(250-x,250+y,c);
}
void midPoint(int x,int y,int r){
    int p=(5/4)-r;
    x=0;
    y=r;
    put8Pixel(x,y,c);
    while(x<=y){
        if(p<0){
            p=p+2*x+3;
        }
        else{
            p=p+2*(x-y)+5;
            y--;
        }
        x++;
        put8Pixel(x,y,c);
    }
}
int main()
{
    int x,y,r;
    cout<<"nhap toa do tam cua duong tron:"<<endl;
    cout<<"x: ";
    cin>>x;
    cout<<"y: ";
    cin>>y;
    cout<<"nhap ban kinh R: ";
    cin>>r;

    initwindow(500,500);
    midPoint(x,y,r);

    getch();
    return 0;
}
