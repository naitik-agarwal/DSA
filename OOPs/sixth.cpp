#include<bits/stdc++.h>
using namespace std;

// Topics : Runtime polymorphisms

class Parent {
public:
   void function(){
      cout<<"this is parent class function"<<endl;
   }
   
   virtual void hello(){
      cout<<"Parent hello"<<endl;
   }
};

class Child: public Parent {
public:
   void function(){
      cout<<"this is child class function"<<endl;
   }
   void hello(){
      cout<<"Child hello"<<endl;
   }
};

int main(){
   Child c1;
   c1.function();
   Parent *ptr;
   ptr=&c1; // Run time binding, means our c1 is a object of class child but we are binding it to a pointer of parent class
   // runtime binding means jab code run karna start karega tab binding hogi, its getting possible due to inheritance
   ptr->hello();
   return 0;
}

