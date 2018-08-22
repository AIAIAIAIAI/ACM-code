#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
class Student
{
protected:
    char name[10];
    int id;
    int score;
public:
    Student(char *s,int i,int sc):id(i),score(sc)
    {
        strcpy(name,s);
    }
    void print()
    {
        cout<<"Student's name is:"<<name<<"\nID:"<<id<<"\nScore is :"<<score<<endl;
    }
};
class Teacher
{
protected:
    char name[10];
    int job_id;
public:
    Teacher(char *s,int i):job_id(i)
    {
        strcpy(name,s);
    }
    void print()
    {
        cout<<"Teacher's name is:"<<name<<"\nJob id:"<<job_id<<endl;
    }
};
class Postgraduate:public Student,public Teacher
{
    int grade;
    int id;
public:
    Postgraduate(char *s,int i,int sc,int gr):Student(s,i,sc),Teacher(s,i),grade(gr)
    {
    	
    }
    void print()
    {
        cout<<"Postgraduate's name is:"<<Student::name<<"\nID:"<<id<<"\nGrade is :"<<grade<<endl;
    }
};
int main()
{
    char s[20]="wqqw";
    Student st(s,12,120);
    char s1[20]="wang";
    Teacher te(s1,1001);
    st.print();
    return 0;
}