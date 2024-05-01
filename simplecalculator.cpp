#include<iostream>
using namespace std;

class calculator
{

    private:
      float n1;
      float n2;
      float result;

    public:

     void getdata()
     {
        cout<<"\nEnter the first number:";
        cin>>n1;
        cout<<"Enter the second number:";
        cin>>n2;
     }

     void sum()
     {
      result=n1+n2;
      cout<<"The sum is "<<result<<endl;  
     }

     void sub()
     {
        result=n1-n2;
        cout<<"The difference is "<<result<<endl;
     }

     void product()
     {
        result=n1*n2;
        cout<<"The product is "<<result<<endl;
     }

     void division()
     {
        result=n1/n2;
        cout<<"The qoutient is "<<result<<endl;
     }

};

int main()
{
    string ch;
    int op;

    calculator obj;

    while(ch!="no")
    {
        cout<<"1 for addition\n2 for subtraction\n3 for multiplication\n4 for division\n";
        cout<<"Enter your choice :";
        cin>>op;

        switch(op)
        {
            case 1:
              obj.getdata();
              obj.sum();
            break;

            case 2:
               obj.getdata();
               obj.sub();
            break;

            case 3:
                obj.getdata();
                obj.product();
            break;

            case 4:
                obj.getdata();
                obj.division();
            break;

            default:
             cout<<"Invalid option"<<endl ;           

        }

        cout<<"\nDo you want to continue[yes/no]:";
        cin>>ch;
        cout<<"\n";
    }
return 0;
}
