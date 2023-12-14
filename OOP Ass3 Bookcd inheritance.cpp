#include<iostream>
#include<string>
using namespace std;
class publication{
    string name;
    float price;
    public:
    void getdata();
    void display();
};
void publication::getdata(){
    cout<<"Enter title"<<endl;
    cin>>name;
    cout<<"Enter price"<<endl;
    cin>>price;
}
void publication::display(){
    cout<<"Title :"<<name<<endl;
    cout<<"Price :"<<price<<endl;
}
class book:public publication{
    int page;
    public:
    void insert();
    void Display();
};
void book::insert(){
    getdata();
    cout<<"Enter Pages"<<endl;
    try{
        cin>>page;
        if(page<=0){
        throw page;
        }
    }
    catch(int){
        cout<<"Pages can't be zero";
    }
}

void book::Display(){
    display();
    cout<<"Pages :"<<page<<endl;
}
class tape:public publication{
    float min;
    public:
    void time();
    void show();
};
void tape::time(){
    getdata();
    cout<<"Enter time"<<endl;
    cin>>min;
}
void tape::show(){
    display();
    cout<<"Time :"<<min<<endl;
}
int main(){
    book b;
    tape t;
    b.insert();
    b.Display();
    t.time();
    t.show();
    return 0;
}