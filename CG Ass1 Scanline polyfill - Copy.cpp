#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

class point{
    public:
    int k;
};
class scan:public point{
    public:
    int x[20],y[20];
    float slope[20],xint[20];
    void polygon(int n);
};

void scan::polygon(int n){
    float dx,dy;
    x[n]=x[0];
    y[n]=y[0];
    for(int i=0;i<n;i++){
        line(x[i],y[i],x[i+1],y[i+1]);
    }
    for(int i=0;i<n;i++){
        dx=x[i+1]-x[i];
        dy=y[i+1]-y[i];
        if(dy==0)
            slope[i]=1;
        else if(dx==0)
            slope[i]=0;
        else
            slope[i]=dx/dy;
    }
    for(int p=0;p<480;p++){
        k=0;
        for(int i=0;i<n;i++){
            if( ((y[i]<=p)&&(y[i+1]>p)) || ((y[i]>p)&&(y[i+1]<=p))){
                xint[k]=x[i]+slope[i]*(p-y[i]);
                k++;
            }
        }
        for(int i=0;i<k-1;i++){
            if(xint[i]>xint[i+1]){
                int temp=xint[i];
                xint[i]=xint[i+1];
                xint[i+1]=temp;
            }
        }
        for(int i=0;i<k;i+=2){
            setcolor(CYAN);
            line(xint[i],p,xint[i+1],p);
            delay(10);
        }
    }
}

int main(){
    scan p;
    int n;
    cout<<"Enter no of edges"<<endl;
    cin>>n;
    cout<<"Enter coordinates"<<endl;
    for(int i=0;i<n;i++){
        cin>>p.x[i]>>p.y[i];
    }
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    p.polygon(n);
    getch();
    closegraph();
    return 0;
}