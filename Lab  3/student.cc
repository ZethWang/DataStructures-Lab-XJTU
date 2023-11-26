#include "student.h"
#include<string.h>
#include<string>
#include<fstream>
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<conio.h>
using namespace std;

Students::Students(char *sName,int sNumber,int sMath,int sEnglish,int sComputer)
{
    strcpy(Name,sName);
    Number=sNumber;
    Math=sMath;
    English=sEnglish;
    Computer=sComputer;
}
char* Students::GetName()
{
    return Name;
}
int Students::GetNumber()
{
    return Number;
}
int Students::GetMath()
{
    return Math;
}
int Students::GetEnglish()
{
    return English;
}
int Students::GetComputer()
{
    return Computer;
}
void Students::SetName(char* sName)
{
    strncpy(Name,sName,NUM1);
}
void Students::SetNumber(int sNumber)
{
        Number=sNumber;
}
void Students::SetMath(int sMath)
{
    Math=sMath;
}
void Students::SetEnglish(int sEnglish)
{
    English=sEnglish;
}
void Students::SetComputer(int sComputer)
{
    Computer=sComputer;
}
void Students::disply(Students &st1)
{
        cout<<st1.GetName()<<" "<<st1.GetNumber()<<" "<<st1.GetMath()<<" "<<st1.GetEnglish()<<" "<<st1.GetComputer()<<endl;
}