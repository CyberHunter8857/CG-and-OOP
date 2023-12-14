#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

class triangle{
    public:
    void line(float,float,float,float);
    void circle(int,int,int);
};

void triangle::line(float x1,float y1,float x2,float y2){
    int dx,dy,steps;
    float xin,yin,x,y;
    dx=x2-x1;
    dy=y2-y1;
    if(abs(dx)>=abs(dy)){
        steps=dx;
    }
    else{
        steps=dy;
    }
    xin=(float)dx/steps;
    yin=(float)dy/steps;
    x=x1;
    y=y1;
    putpixel(x,y,15);
    for(int i=0;i<steps;i++){
        x=x+xin;
        y=y+yin;
        x1=x+0.5;
        y1=y+0.5;
        putpixel(x1,y1,15);
    }
}

void triangle::circle(int x,int y,int r){
    int pk,x1,y1;
    x1=0;
    y1=r;
    pk=3- 2*r;
    putpixel(x,y,15);
    while(x1<=y1){
        if(pk<=0){
            pk=pk+ 4*(x1) +6;
        }
        else{
            pk=pk+ 4*(x1-y1)+ 10;
            y1=y1-1;
        }
        x1=x1+1;
        putpixel(x+x1,y+y1,15)
        ;
        putpixel(x+x1,y-y1,15);
        putpixel(x-x1,y+y1,15);
        putpixel(x-x1,y-y1,15);
        delay(10);
        putpixel(x+y1,y+x1,15);
        putpixel(x+y1,y-x1,15);
        putpixel(x-y1,y+x1,15);
        putpixel(x-y1,y-x1,15);
    }
}

int main(){
    int gd,gm,r1,r2;
    float len;
    triangle t;
    gd=DETECT;
    initgraph(&gd,&gm,(char*)"");
    setbkcolor(4);
    int x=640/2;
    int y=480/2;
    r1=100;
    r2=50;

    t.circle(x,y,r1);
    
    len=(int)sqrt(r1*r1-r2*r2);

    t.line(x,y-r1,x+len,y+r2);
    t.line(x-len,y+r2,x+len,y+r2);
    t.line(x,y-r1,x-len,y+r2);
    setcolor(15);

    t.circle(x,y,r2);

    getch();
    closegraph();
    return 0;
}