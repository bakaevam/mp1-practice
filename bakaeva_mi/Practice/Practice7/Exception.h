#pragma once
#include "iostream"
#include "string"
using namespace std;

class Exception
{
private:
    string mes;
public:
    Exception(string _mes) : mes(_mes) {};
    void Print()
    {
        cout << "\n  Error: " << mes << endl;
    }
};