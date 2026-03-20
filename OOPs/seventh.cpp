#include<bits/stdc++.h>
using namespace std;

// Topics : Abstraction & Friend function and class :-

class Shape{
public:
   virtual void draw()=0; // abstract fnx, pure virtual function
};

class Circle : public Shape {
public:
   void draw(){
      cout<<"draw circle"<<endl;
   }
};
class Square : public Shape {
public:
   void draw(){
      cout<<"draw square"<<endl;
   }
};


class Example{
public:
  static int x;
};

int Example::x=0; // we cant initialize a static val inside class or if so we have to make it const -> static const x

class Example2{
public: 
   Example2(){
      cout<<"constructor.."<<endl;
   }
   ~Example2(){
      cout<<"destructor.."<<endl;
   }
};

class A {
   string secret = "secret data";
   friend class B; // now B class becomes the friend class of A
   friend void revealSecret(A &obj); // now revealSecret is a friend function of A 
};
class B{ 
public:
   void showSecret(A &obj){
      cout<<obj.secret<<endl;
   }
};

void revealSecret(A &obj){
   cout<<obj.secret<<endl;
}


int main(){
   Circle cir1;
   cir1.draw();
   Square sqr1;
   sqr1.draw();
   Example eg1;
   Example eg2;
   Example eg3;   
   cout<<eg1.x++<<endl;
   cout<<eg2.x++<<endl;
   cout<<eg3.x++<<endl;

   int a=0;
   if(a==0){
      static Example2 eg1;
   }
   cout<<"code ending.."<<endl; 
   // now ab pehli constuctor print hoga fir code ending.. and finally destructor because object program ke end me destroy hui unlike if static nahi hota tou us if block ke end me he ho jati

   A a1;
   B b1;
   b1.showSecret(a1); 
   revealSecret(a1);
   return 0;
}