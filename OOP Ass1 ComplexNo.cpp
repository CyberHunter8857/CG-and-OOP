#include <iostream>
using namespace std;
class complex{
	int real;
	int imaginary;
public:
	complex() 
	{
		real=0;
		imaginary=0;
    cout<<"Default value of Complex No. is :"<<real<<"+"<<imaginary<<"i"<<endl;
    
	}
	complex operator+(complex bb)
	{
		complex cc;
		cc.real=real+bb.real;
		cc.imaginary=imaginary+bb.imaginary;
		cout<<"Addition is : "<<cc.real<<"+"<<cc.imaginary<<"i"<<endl;
		return cc;
	}
	complex operator*(complex bb)
	{
		complex dd;
		dd.real=(real*bb.real)-(imaginary*bb.imaginary);
		dd.imaginary=(real*bb.imaginary)+(imaginary*bb.real);
		cout<<"Multiplication is: "<<dd.real<<"+"<<dd.imaginary<<"i"<<endl;
		return dd;
	}
	friend ostream&operator<<(ostream&output,complex&m);
	friend istream&operator>>(istream&input,complex&m);
};

ostream&operator<<(ostream &output,complex &m){
	output<<m.real<<"+"<<m.imaginary<<"i"<<endl;
	return output;
}
istream&operator>>(istream&input,complex&m){
	input>>m.real>>m.imaginary;
	return input;
}
int main() {

	complex aa;
	cout<<"Enter 1st Complex Number"<<endl;
	cin>>aa;
	complex bb;
	cout<<"Enter 2nd Complex Number"<<endl;
	cin>>bb;
	cout<<"The two complex numbers are:"<<endl;
	cout<<aa;
	cout<<bb;
	complex cc=aa+bb;
	complex dd=aa*bb;
	return 0;
}
