#include <iostream>
#include <conio.h>
#include <graphics.h>
using namespace std;

#define c WHITE
int Round(float y){
    return y+0.5;
}
void DDA(int x1,int x2, int y1,int y2){

    float m= (float)(y2-y1)/(x2-x1);
    float y=y1;
    int x=x1;
    while(x<=x2){
        y=y+m;
        putpixel(x,Round(y),c);
        x++;
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
    DDA(x1,x2,y1,y2);

    getch();
    closegraph();


}
