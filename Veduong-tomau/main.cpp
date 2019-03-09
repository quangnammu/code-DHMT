#include <iostream>
#include <conio.h>
#include <graphics.h>
using namespace std;
//thuat toan DDA

int Round(float y){
    return y+0.5;
}
void DDA(int x1,int x2, int y1,int y2){
    int c=15;
    float m= (float)(y2-y1)/(x2-x1);
    float y=y1;
    int x=x1;
    while(x<=x2){
        y=y+m;
        delay(3);
        putpixel(x,Round(y),c);
        x++;
    }
}

// thuat toan bresenham
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
        delay(3);
        putpixel(x,y,5);

    }
}
// thuat toan ve duong tron Midpoint ve duong tron
void put8Pixel(int x,int y,int c){
    delay(4);
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
    int c=2;
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
// thuat toan to mau

struct ToaDo
{
    int x,y;
};


void nhapDaGiac(ToaDo p[], int n)
{
    int i;
    for(i=0;i<n; i++){
        cout<<"Nhap toa do dinh "<<i+1<<" : "<<endl;
        cout<<"x["<<(i+1)<<"] = ";
        cin>>p[i].x;
        cout<<"y["<<(i+1)<<"] = ";
        cin>>p[i].y;
    }
    p[i].x=p[0].x;
    p[i].y=p[0].y;
}

void veDaGiac(ToaDo p[], int n)
{
    for(int i=0;i<n;i++)

        line(p[i].x,p[i].y,p[i+1].x,p[i+1].y);
}


// thuat toan Scanline
void ScanLine(ToaDo p[], int n)
{
    int xmin,xmax,ymin,ymax,c,mang[50];
    xmin=xmax=p[0].x;
    ymin=ymax=p[0].y;
    for(int i=0;i<n;i++){
        if(xmin>p[i].x) xmin=p[i].x;
        if(xmax<p[i].x) xmax=p[i].x;
        if(ymin>p[i].y) ymin=p[i].y;
        if(ymax<p[i].y) ymax=p[i].y;
    }
    float y;
    y=ymin+0.1;
    while(y<=ymax){
        int x,x1,x2,y1,y2,tg;
        c=0;
        for(int i=0;i<n;i++){

            x1=p[i].x;
            y1=p[i].y;
            x2=p[i+1].x;
            y2=p[i+1].y;
            if(y2<y1){
                tg=x1;x1=x2;x2=tg;
                tg=y1;y1=y2;y2=tg;
            }

            if(y<=y2&&y>=y1){
                if(y1==y2)  x=x1;
                else{
                    x=((y-y1)*(x2-x1))/(y2-y1);
                    x+=x1;
                }
                if(x<=xmax && x>=xmin)
                    mang[c++]=x;
            }
        }
        for(int i=0; i<c;i+=2){
                delay(3);
               line(mang[i],y,mang[i+1],y);
        }
        y++;
    }
}


// thuat toan to mau dua theo duong bien

void loang(int x, int y, int mauto, int maubien){
    int mauhientai=getpixel(x,y);
    if(mauhientai!=mauto&&mauhientai!=maubien){
        // delay(1);
        putpixel(x,y,mauto);
        loang(x-1,y,mauto,maubien);
        loang(x,y+1,mauto,maubien);
        loang(x+1,y,mauto,maubien);
        loang(x,y-1,mauto,maubien);
    }
}


int main()
{

    int num;

    cout<<"1. ve duong. \n2. to mau."<<endl;
    cin>>num;
    switch(num){
    case 1 :
        int num1;
        cout<< "1. thuat toan DDA. \n2. thuat toan Bresenham. \n3. thuat toan Mid Point ve duong tron.  "<<endl;
        cin>>num1;
        switch (num1){
        case 1:
            initwindow(500,500);
            DDA(200,400,100,300);
            break;
        case 2:
            initwindow(500,500);
            bresenham(200,400,100,300);
            break;
        case 3:
            initwindow(500,500);
            midPoint(200,200,150);
            break;
        }
        break;
    case 2 :
        int num2;
        int color,n;
        n=4;
        ToaDo p[n];
        cout<< "1. thuat toan to mau Scanline. \n2. thuat toan to mau theo duong bien.  "<<endl;
        cin>>num2;
        switch (num2){
        case 1:
            p[0].x=200;p[0].y=100;
            p[1].x=400;p[1].y=100;
            p[2].x=300;p[2].y=350;
            p[3].x=240;p[3].y=350;
            p[4].x=p[0].x;p[4].y=p[0].y;
            cout<<"Chon mau (0-15) : ";
            cin>>color;
            initwindow(500,500);
            veDaGiac(p,n);
            setcolor(color);
            ScanLine(p,n);
            break;
        case 2:

            p[0].x=200;p[0].y=100;
            p[1].x=400;p[1].y=100;
            p[2].x=300;p[2].y=350;
            p[3].x=240;p[3].y=350;
            p[4].x=p[0].x;p[4].y=p[0].y;
            cout<<"Chon mau (0-15) : ";
            cin>>color;
            initwindow(500,500);
            veDaGiac(p,n);
            int Sx=0, Sy=0;
            for(int i=0;i<n;i++){
                Sx+=p[i].x;
                Sy+=p[i].y;
            }
            loang(Sx/n,Sy/n,color,15);
            break;
        }
        break;

    }
    getch();
    closegraph();


}
