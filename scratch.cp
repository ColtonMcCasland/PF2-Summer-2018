

#include <math.h>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

//----------------------------------------------
template <class DataType>
class Numbers
{
public:
    // Constructors
    Numbers();
    ~Numbers();
    
    // Methods
    void readFile(string filename);
    int getCount();
    DataType getValue(int index);
    DataType findMin();
    DataType findMax();
    DataType findMean();
    DataType findVar();
    DataType findstdDev();
    
private:
    static const int SIZE = 100;
    int Count;
    DataType Data[SIZE];
};

//----------------------------------------------
template <class DataType>
Numbers<DataType>::Numbers()
{
    // Initialize variables
    Count = 0;
    for (int i = 0; i < SIZE; i++)
        Data[i] = 0;
}

//----------------------------------------------
template <class DataType>
Numbers<DataType>::~Numbers()
{
}

//----------------------------------------------
template <class DataType>
void Numbers<DataType>::readFile(string filename)
{
    // Open input file
    ifstream din;
    din.open(filename.c_str());
    if (din.fail())
        return;
    
    // Read integers into Data array
    Count = 0;
    DataType num;
    din >> num;
    while (!din.eof() && Count < SIZE)
    {
        Data[Count++] = num;
        din >> num;
    }
    din.close();
}

//----------------------------------------------
template <class DataType>
int Numbers<DataType>::getCount()
{
    return Count;
}

//----------------------------------------------
template <class DataType>
DataType Numbers<DataType>::getValue(int index)
{
    // Return specified value
    if (index < Count)
        return Data[index];
    else
        return 0;
}

//----------------------------------------------
template <class DataType>
DataType Numbers<DataType>::findMin()
{
    // Search array for min
    DataType min = Data[0];
    for (int index = 0; index < Count; index++)
        if (min > Data[index])
            min = Data[index];
    return min;
}

//----------------------------------------------
template <class DataType>
DataType Numbers<DataType>::findMax()
{
    // Search array for max
    DataType max = Data[0];
    for (int index = 0; index < Count; index++)
        if (max < Data[index])
            max = Data[index];
    return max;
}

//----------------------------------------------
template <class DataType>
DataType Numbers<DataType>::findMean()
{
    // Calculate mean value of array
    DataType total = 0;
    for (int index = 0; index < Count; index++)
        total += Data[index];
    if (Count > 0)
        return total / Count;
    else
        return 0;
}

//not sure if varience works
template <class DataType>
DataType Numbers<DataType>::findVar()
{
    DataType mean = findMean();
    int Count = getCount();
    DataType temp = 0;
    
    for(int i = 0; i < Count; i++)
    {
        temp += (Data[i] - mean) * (Data[i] - mean);
    }
    return temp / Count;
}

//if varience works then this should too
template <class DataType>
DataType Numbers<DataType>::findstdDev()
{
    return sqrt(findVar());
}

int main()
{
    string filename;
    cout << "Enter filename:";
    cin >> filename;
    
    // Process int numbers
    Numbers <int> num;
    num.readFile(filename);
    cout << "min = " << num.findMin() << endl;
    cout << "max = " << num.findMax() << endl;
    cout << "mean = " << num.findMean() << endl;
    
    // Process float numbers
    Numbers <float> num2;
    num2.readFile(filename);
    cout << "min = " << num2.findMin() << endl;
    cout << "max = " << num2.findMax() << endl;
    cout << "mean = " << num2.findMean() << endl;
    cout << "Var = " << num2.findVar() << endl;
    cout << "Std Dev = " << num2.findstdDev() << endl;
    
    // Process short numbers
    Numbers <short> num3;
    num3.readFile(filename);
    cout << "min = " << num3.findMin() << endl;
    cout << "max = " << num3.findMax() << endl;
    cout << "mean = " << num3.findMean() << endl;
    cout << "Var = " << num3.findVar() << endl;
    cout << "Std Dev = " << num3.findstdDev() << endl;
    
    // Process long numbers
    Numbers <long> num4;
    num4.readFile(filename);
    cout << "min = " << num4.findMin() << endl;
    cout << "max = " << num4.findMax() << endl;
    cout << "mean = " << num4.findMean() << endl;
    cout << "Var = " << num4.findVar() << endl;
    cout << "Std Dev = " << num4.findstdDev() << endl;
    
    // Process double numbers
    Numbers <double> num5;
    num5.readFile(filename);
    cout << "min = " << num5.findMin() << endl;
    cout << "max = " << num5.findMax() << endl;
    cout << "mean = " << num5.findMean() << endl;
    cout << "Var = " << num5.findVar() << endl;
    cout << "Std Dev = " << num5.findstdDev() << endl;
    
}
