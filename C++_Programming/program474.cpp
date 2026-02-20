#include<iostream>
using namespace std;

class ArrayX
{
    public:
        int *Arr;
        int iSize;

    ArrayX(int no)
    {
        cout<<"Inside Constructor \n";
        iSize = no;
        Arr = new int[iSize];
    }

    ~ArrayX()
    {
        cout<<"Inside Destructor \n";
        delete [] Arr;
    }

    void Accept()
    {
        int icnt = 0;

        cout<<"Enter the Elements : \n";

        for (icnt = 0; icnt < iSize; icnt++)
        {
            cin>>Arr[icnt];
        }
        
    }

    void Display()
    {
        int icnt = 0;
        cout<<"Elements of the Array are : \n";

        for (icnt = 0; icnt < iSize; icnt++)
        {
            cout<<Arr[icnt]<<"\t";
        }

        cout<<"\n";
    }

    int Addition()
    {
        int iSum = 0;
        int icnt = 0;

        for(icnt = 0; icnt < iSize; icnt++)
        {
            iSum = iSum + Arr[icnt];
        }

        return iSum;
    }
};

int main()
{
    int iValue = 0;

    cout<<"Enter the number of elements : \n";
    cin>>iValue;

    // Step 1 : Allocate the Memory
    ArrayX *aobj = new ArrayX(iValue);

    // Step 2 : Use the Memory
    aobj->Accept();
    aobj->Display();

    cout<<"Summation of all Elements : "<<aobj->Addition()<<"\n";

    // Step 3 : De-Allocate the Memory
    delete aobj;

    return 0;
}