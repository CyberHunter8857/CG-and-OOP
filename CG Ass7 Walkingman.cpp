#include<iostream> 
#include<graphics.h> 
using namespace std; 
class walkingman { 
int A,B; 
public:
void draw(int,int); 
void draw(int); 
}; 
void walkingman::draw(int i) { 
line(20,400,600,400); //platform
if(i%2==0){ 
line(25+i,400,35+i,350); //left leg
line(45+i,400,35+i,350); //right leg
line(35+i,310,25+i,350); //left hand
delay(10); 
}
line(35+i,350,35+i,310); //body
circle(35+i,300,10); //head
line(35+i,310,50+i,330); //right hand
line(50+i,330,50+i,280); //umbrella stick
line(15+i,280,85+i,280); //umbrella horizontal line
arc(50+i,280,0,180,35); //umbrella body
} 

void walkingman::draw(int x,int y) { //rain
A=x; 
B=y; 
for(int j=0;j<100;j++) { 
outtextxy(rand()%A,rand()%(B-50),"!"); 
setcolor(15); 
} 
} 
int main() { 
int gd=DETECT,gm; 
int A,B,j,i; 
walkingman obj; 
initgraph(&gd,&gm,""); 
for(i=0;i<500;i++) 
{ 
obj.draw(i); 
A=getmaxx(); 
B=getmaxy(); 
obj.draw(A,B); 
delay(80); 
cleardevice(); 
} 
getch(); 
} 


// #include<iostream>
// #include<graphics.h>
// using namespace std;

// class man{
//     int A,B;
//     public:
//     void draw(int);
//     void draw(int,int);
// };

// void man::draw(int i){
//     line(20,400,600,400);
//     if(i%2==0){
//         line();
//         line();
//     }
//     else{
//         line();
//         line();
//         line();
//         circle();
//         line();
//         arc();
//         line();
//     }
// }

// void man::draw(int x,int y){
//     A=x;
//     B=y;
//     for(int i=0;i<100;i++){
//         outtextxy(rand()%A,rand()%(B-50),"!");
//         setcolor(RED);
//     }
// }

// int main(){
//     man m;
//     int gd=DETECT,gm;
//     initgraph(&gd,&gm,"");
//     for(int i=0;i<500;i++){
//         m.draw(i);
//         int A=getmaxx();
//         int B=getmaxy();
//         m.draw(A,B);
//         delay(50);
//         cleardevice();
//     }
//     getch();
// }