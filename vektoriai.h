#ifndef VEKTORIAI_H
#define VEKTORIAI_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <iomanip>
#include <fstream>
using namespace std;
random_device rd;
mt19937 mt(rd());
uniform_int_distribution<int> dist(0, 10);

struct studentas
{
    int n;         
    vector<int> nd; 
    string vardas;
    string pavarde;
    double average;
    double mediana;
    int egzaminas;
};
void VP(int, string &, string &);
void Random(int, vector<int> &);
void IvestisSk(int , vector<int> &);
double Average(vector<int> &, double &);
void Median(vector<int> &, double &);
void printmed(string &,string &,double &);
void printave(string &,string &,double &);
int studentEntry();
int ManualEntry();
int HomeworkKnown();
int SA();
int Choosefile();
int File();




#endif