#include<bits/stdc++.h>
using namespace std;

// topics : Inheritance

class Animal{
public:
   string color;
   void eat(){
      cout<<"eats"<<endl;
   }
   void breathe(){
      cout<<"breates"<<endl;
   }
};

class Fish : protected Animal { // now class Fish has inherited properties and methods of class Animal
public:
   int fins;
   void swim(){
      eat();
      cout<<"swims"<<endl;
   }
};

class Teacher{
public:
   int salary;
   string subject;
};

class Student{
public:
   int rollNumber;
   int cgpa;
};

class Ta: public Teacher, public Student{ // Multiple inheritance
public:
   string name;
};

int main(){
   Fish f1;
   f1.fins=3;
   f1.swim();
   Ta ta1;
   ta1.salary=50000;
   ta1.cgpa=9.6;
   ta1.name="Shraddha";
   cout<<ta1.salary<<" "<<ta1.cgpa<<endl;
   return 0;
}