#include<iostream>
using namespace std;

template<class T>
class ArrayX
{
    public:
        T *Arr;
        int iSize;

    ArrayX(int no);
    ~ArrayX();
    void Accept();
    void Display();
    T Addition();
    T Maximum();
    int Frequency(T);
};

template<class T>
ArrayX<T> :: ArrayX(int no)
{
    cout<<"Inside Constructor \n";
    iSize = no;
    Arr = new T[iSize];
}

template<class T>
ArrayX<T> :: ~ArrayX()
{
    cout<<"Inside Destructor \n";
    delete [] Arr;
}

template<class T>
void ArrayX<T> :: Accept()
{
    int icnt = 0;

    cout<<"Enter the Elements : \n";

    for (icnt = 0; icnt < iSize; icnt++)
    {
        cin>>Arr[icnt];
    }
    
}

template<class T>
void ArrayX<T> :: Display()
{
    int icnt = 0;
    cout<<"Elements of the Array are : \n";

    for (icnt = 0; icnt < iSize; icnt++)
    {
        cout<<Arr[icnt]<<"\t";
    }

    cout<<"\n";
}

template<class T>
T ArrayX<T> :: Addition()
{
    T iSum = 0;
    int icnt = 0;

    // iSum = Arr[0] - Arr[0]; used for generic

    for(icnt = 0; icnt < iSize; icnt++)
    {
        iSum = iSum + Arr[icnt];
    }

    return iSum;
}

template<class T>
T ArrayX<T> :: Maximum()
{
    T iMax;
    int icnt = 0;

    iMax = Arr[0];

    for(icnt = 0; icnt < iSize; icnt++)
    {
        if(Arr[icnt] > iMax)
        {
            iMax = Arr[icnt];
        }
    }

    return iMax;
}

template<class T>
int ArrayX<T> :: Frequency(T iNo)
{
    int icnt = 0;
    int icount = 0;

    for(icnt = 0; icnt < iSize; icnt++)
    {
        if (Arr[icnt] == iNo)
        {
            icount++;
        }
    }
    return icount;
}

int main()
{
    int iValue = 0;

    cout<<"Enter the number of elements : \n";
    cin>>iValue;

    // Step 1 : Allocate the Memory
    ArrayX<int> *aobj = new ArrayX<int>(iValue);

    // Step 2 : Use the Memory
    aobj->Accept();
    aobj->Display();

    cout<<"Summation of all Elements : "<<aobj->Addition()<<"\n";

    cout<<"Maximum is : "<<aobj->Maximum()<<"\n";

    cout<<"Frequency is : "<<aobj->Frequency(11)<<"\n";

    // Step 3 : De-Allocate the Memory
    delete aobj;

    return 0;
}