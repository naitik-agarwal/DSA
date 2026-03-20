#include<bits/stdc++.h>
using namespace std;

// Topics : Polymorphism

class Print{
public:
   // Function overloading
   void show(int x){
      cout<<"int: "<<x<<endl;
   }
   void show(string str){
      cout<<"string: "<<str<<endl;
   }
};

class Complex {
private:
   int real;
   int img;
public:
   Complex(int r,int i){
      this->real=r;
      this->img=i;
   }
   void showNum(){
      cout<<real<<"+"<<img<<"i"<<endl;
   }
   Complex operator + (Complex &c2){ // operator overloading
      // addition of two complex numbers
      int resReal=this->real+c2.real; 
      int resImg=this->img+c2.img;
      Complex c3(resReal,resImg);
      return c3;
   }
};

int main(){
   Print obj;
   obj.show(123);
   obj.show("Naitik");
   obj.show(34.5); // why it compiled it as int and not as string

   Complex c1(1,2),c2(3,4);
   c1.showNum();
   c2.showNum();
   Complex c3=c1+c2;
   c3.showNum();
}