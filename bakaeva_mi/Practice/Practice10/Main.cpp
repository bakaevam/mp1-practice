#include "Container.h"
#include "ContainerPointers.h"
#include "Exception.h"
#include <Windows.h>
#include <iostream>

using namespace std;

int main()
{
    Container<int, 10> C1(3);

    try
    {
        cout << "   -TEST#1-" << endl << "  Container: ";
        C1.Print();

        cout << "\n  Add element = 9 and element = 25";
        C1.Add(9);
        C1.Add(25);
        C1.Print();

        cout << "\n  Find for item 9, index = " << C1.Find(9) << endl;
        cout << "\n  Container[2] = " << C1[2] << endl;
        cout << "\n  Add 6 new elements";
        for (int i = 0; i < 6; i++)
        {
            C1.Add(i + 1);
            C1.Print();
        }
    }
    catch (Exception exp)
    {
        exp.Print();
    }
    try
    {
        cout << "\n  Delete all elements\n";
        int k = 0;
        while (C1.GetCount() != 0)
            C1.Delete(C1[k]);
        C1.Print();
    }
    catch (Exception exp)
    {
        exp.Print();
    }

    int* a[5];
    int b[5] = { 2, 10, 0, 8, 95 };
    for (int i = 0; i < 5; i++)
        a[i] = &(b[i]);

    Container<int*, 10> C2(a, 5);
    Container<int*, 10> C3(C2);

    cout << "   -TEST#2-" << endl;
    try
    {
        cout << "  Container #1: ";
        C2.Print();
        cout << "  Copied Container #2:  ";
        C3.Print();

        int tmp = 25;
        int* itmp = &tmp;
        cout << "  Container #1 + new point";
        C2.Add(itmp);
        C2.Print();
    }
    catch (Exception exp)
    {
        exp.Print();
    }
    try 
    {
        cout << "  Delete Container #1[0] ";
        C2.Delete(&C2[0]);
        C2.Print();
    }
    catch (Exception exp)
    {
        exp.Print();
    }
    try
    {
        cout << "  Print Container #1[1] ";
        cout << "\n  " << &C2[1] << endl;
    }
    catch (Exception exp)
    {
        exp.Print();
    }
    system("pause");
    return 0;
}