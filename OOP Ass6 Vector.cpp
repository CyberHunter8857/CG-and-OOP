#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class item{
    public:
    char name[10];
    int code;
    int quantity;

    bool operator==(const item &i1){
        if(code==i1.code) return 1;
        return 0;
    }

    bool operator<(const item &i1){
        if(code<i1.code) return 1;
        return 0;
    }
};

vector<item>o1;
void insert();
void print(item &i1);
void display();
void search();
int n;

void insert(){
    item i1;
    cout<<"Enter number of Items"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
    cout<<"Enter name of item :"<<endl;
    cin>>i1.name;
    cout<<"Enter code of item :"<<endl;
    cin>>i1.code;
    cout<<"Enter quantity of item :"<<endl;
    cin>>i1.quantity;
    o1.push_back(i1);
    }
}

void print(item &i1){
    for(int i=1;i<2;i++){
    cout<<"Item name :"<<i1.name<<endl;
    cout<<"Item code :"<<i1.code<<endl;
    cout<<"Item quantity :"<<i1.quantity<<endl;
    }
}

void display(){
    for_each(o1.begin(),o1.end(),print);
}

bool compare(const item &i1,const item & i2){
    return i1.code<i2.code;
}

void search(){
    vector<item>::iterator p;
    item i1;
    cout<<"Enter code to search item"<<endl;
    cin>>i1.code;
    p=find(o1.begin(),o1.end(),i1);
    if(p==o1.end()){
        cout<<"Not Found"<<endl;
    }
    else{
        cout<<"Found"<<endl;
        cout<<"Item name"<<p->name<<endl;
        cout<<"Item code"<<p->code<<endl;
        cout<<"Item quantity"<<p->quantity<<endl;
    }
}

int main(){
    insert();
    display();
    cout<<"\n\n Sorting"<<endl;
    sort(o1.begin(),o1.end(),compare);
    cout<<"Sorted on code"<<endl;
    display();
    search();
    return 0;
}