#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
   // Properties
   string name;
   float cgpa;

   // Methods
   void getPercentage()
   {
      cout << (cgpa * 10) << "% \n";
   }
};

class User
{
   string password; // this is private

   void deactivate()
   {
      cout << "deleting account" << endl;
   }

public:
   int id;
   string username;
   string bio;

   // how do we access private members in main code : using getters and setters
   // Setters -> set values
   void setPassword(string passVal){
      password=passVal;
   }

   // Getters -> get values
   string getPassword(){
      return password;
   }
};

int main()
{
   Student s1; // s1 is an object of class Student
   // cout<<sizeof(s1);
   s1.name = "Naitik";
   s1.cgpa = 7.95;
   cout << s1.name << " " << s1.cgpa << endl;
   s1.getPercentage();

   User u1;
   u1.id=240102271;
   u1.setPassword("Hello World");
   cout<<u1.getPassword()<<endl;
   return 0;
}