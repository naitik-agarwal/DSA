#include<bits/stdc++.h>
using namespace std;

// Topics : copy constructors, Shallow & Deep Copy, Destructors

class User{
private:
   int id;
   string password;

public:
   string username;
   User(){
      // would behave as default constructor
   }
   User(string username){ // parametrized constructor
      this->username=username;
   }
   // Copy constructor
   User(User &original){ // original is a reference and not a pointer here (because we want to have a referece to the original object)
      cout<<"copying..."<<endl;
      this->id=original.id; // didnt used -> as it was a ref and not a pointer (. is used for objects and references)
      this->password=original.password;
      this->username=original.username;
   }
   void setPassword(string pass){
      this->password=pass;
   }
   string getPassword(){
      return password;
   }
   ~User(){
      cout<<"object deletion...."<<endl;
      // No dma here (see next class for better understanding)
   }
};

class Student{
private:
   int rollNo;

public:
   string name;
   int marks; 
   int *friendBestMarks; // we allocated memory dynamically so explicitly create destructor
   Student(){
      // constructor without initialization
      friendBestMarks=nullptr;
   }
   Student(int rollNo,string name){
      this->rollNo=rollNo;
      this->name=name;
   }
   Student(Student &original){
      this->rollNo=original.rollNo;
      this->name=original.name;
      this->marks=original.marks;
      // this->friendBestMarks=original.friendBestMarks; // this is shallow copy (NO NEW MEMEORY CREATED)
      // to use deep copy : 
      this->friendBestMarks=new int;
      *this->friendBestMarks=*original.friendBestMarks;
   }
   void setRollno(int rollNo){
      this->rollNo=rollNo;
   }
   int getRollno(){
      return rollNo;
   }
   ~Student(){
      cout<<"Object deletion..."<<endl;
      if(friendBestMarks!=nullptr){
         delete friendBestMarks;
         friendBestMarks=nullptr;
      }
   }
};

int main(){
   User u0;
   User u1("240102271");
   u1.setPassword("Hitman");
   cout<<u1.username<<" "<<u1.getPassword()<<endl;
   User u2=User(u1);
   cout<<u2.username<<" "<<u2.getPassword()<<endl;

   Student s1(240102271,"Naitik");
   int x=5;
   s1.friendBestMarks=&x;
   Student s2=Student(s1);
   *s2.friendBestMarks=6;
   cout<<*s1.friendBestMarks<<endl;
   return 0;
}