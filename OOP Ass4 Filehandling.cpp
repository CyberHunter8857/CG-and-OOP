
// #include<iostream>
// #include<fstream>
// using namespace std;
// int main(){
//     fstream file;
//     string s;
//     string x;
//     file.open("data.txt",ios::out);
//     cout<<"Entr Data -"<<endl;
//     getline(cin,s);
//     file<<s;
//     file.close();
//     file.open("data.txt",ios::in);
//     cout<<"INFO is :"<<endl;
//     file>>x;
//     cout<<x;
//     file.close();
//     return 0;
// }

#include<iostream>
#include<fstream>
using namespace std;
int main(){
    fstream file;
    string s;
    string x;
	int n,i;
	cout<<"Enter size"<<endl;
	cin>>n;
    file.open("data.txt",ios::out);
	for(i=0;i<n;i++){
	    cout<<"Entr Data -"<<endl;
    	getline(cin,s);
    	file<<s;
	}
    file.close();
    file.open("data.txt",ios::in);
	for(i=0;i<n;i++){
		cout<<"INFO is :"<<endl;
    	file>>x;
    	cout<<x;
	}
    file.close();
    return 0;
}