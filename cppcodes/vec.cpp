#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

void inVector(vector< int > &);
void outVector(const vector< int > &);

int main()
{
    vector< int > integers1(3);
    vector< int > integers2(5);

    cout <<"Size of integers1 is " << integers1.size() << "\nVector after initialisation:" << endl;
    outVector(integers1);

    cout << "Size of integers2 is " << integers2.size() << "\nVector after initialisation: "<< endl;
    outVector(integers2);

    cout << "\nEnter 8 ints" << endl;
    inVector(integers1);
    inVector(integers2);

    cout << "\nAfter input vectors contaion:\n" << "integers1:" <<endl;
    outVector(integers1);
    cout << "integers2: " << endl;
    outVector(integers2);

    cout << "Evaluating !=" << endl;
    if(integers1!=integers2)
        cout << "integers1!=integers2" << endl;

    vector<int> integers3(integers1);
    cout << "Size of integers3: "<< integers3.size() << "\nVector after initialisation: " <<endl;
    outVector(integers3);

    cout << "Assigning integers2 to integers1" << endl;
    integers1=integers2;

    cout << "integers1" << endl;
    outVector(integers1);
    cout << "integers2" << endl;
    outVector(integers2);

    if(integers1==integers2)
        cout << "integers1 and integers2 are equal" << endl;

    cout << "\nintegers1[2]: " << integers1[2] << endl;
}


void outVector(const vector<int> &arr)
{
    for(size_t i=0;i<arr.size();i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void inVector(vector<int> &arr)
{
    for(size_t i=0;i<arr.size();i++)
    {
        cin >> arr[i];
    }
}
