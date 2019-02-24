#include <iostream>
#include <conio.h>
#include <graphics.h>
using namespace std;

#define c WHITE
void bresenham(int x1,int x2,int y1,int y2){

    int dx=x2-x1;
    int dy=y2-y1;
    int p=2*dy-dx;
    int y=y1;
    int x=x1;
    while(x<=x2){
        if(p<0){
            p=p+2*dy;
        }
        if(p>=0){
            p=p+2*dy-2*dx;
            y=y+1;
        }
        x++;
        putpixel(x,y,c);

    }
}
int main()
{
    int x1,x2,y1,y2;
    cout<<"nhap toa do diem DAU: "<<endl;
    cout<<"x1= ";
    cin>>x1;
    cout<<"y1= ";
    cin>>y1;
    cout<<"nhap toa do diem CUOI: "<<endl;
    cout<<"x2= ";
    cin>>x2;
    cout<<"y2= ";
    cin>>y2;

    initwindow(500,500);
    bresenham(x1,x2,y1,y2);

    getch();
    return 0;

}
