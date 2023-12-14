 #include<iostream> 
#include<fstream> 
using namespace std;

class Student
{
char Name[20]; 
int Rollno;
public:
void accept()
{
cin>>Rollno; 
cin>>Name; 
}
void display()
{
cout<<"\n Rollno:"<<Rollno; 
cout<<"\n Name:"<<Name; 
}
};
int main()
{
Student s[5]; 
fstream f;
int i,n;
f.open("Ass4.txt");
cout<<"\n How many student information do you need to store?"; 
cin>>n;
cout<<"\n Enter information of student in this format(ROLLNO / NAME)"; 
for(i=1;i<=n;i++)
{
cout<<"\n Enter information of: "<<i<<" Student"<<endl; 
s[i].accept();
f.write((char*)&s[i],sizeof s[i]);
}
f.close();
f.open("Ass4.txt",ios::in);
cout<<"\n Information of Student is as follows:"; 
for(i=1;i<=n;i++)
{
f.read((char*)&s[i],sizeof s[i]); 
s[i].display();
}
f.close();
return 0;
}

