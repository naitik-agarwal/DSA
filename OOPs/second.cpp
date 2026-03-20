#include<bits/stdc++.h>
using namespace std;

class Car {
   string name;
   string color;

public:
   void start(){
      cout<<"car has started..."<<endl;
   }
   void stop(){
      cout<<"car has stopped.."<<endl;
   }
   // constructors : used for initialization of properties
   Car(){ // Constructors without parameters
      cout<<"constructor is called. Object is being created..."<<endl;
   }
   Car (string name, string color){ // constuctors with parameters
      cout<<"constructor is called. Object is being created..."<<endl;
      this->name=name;
      this->color=color; // 'this' is a pointer
   }
   // here we have two constructors with same name -> constructors overloading
   string getName(){
      return name;
   }
   string getColor(){
      return color;
   }
};


int main(){
   Car c0; // this would automatically calls constuctor without parameters
   // Car c0(); this would be wrong because compiler would interpret as a function with no arguments and name c1 and of return type Car
   Car c1("BMW","Black");
   cout<<c1.getName()<<" "<<c1.getColor()<<endl;
   // copy construcctors (default made by c++)
   Car c2=c1;
   cout<<c2.getName()<<" "<<c2.getColor()<<endl;
   return 0;
}