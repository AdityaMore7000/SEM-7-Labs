#include <iostream>
using namespace std;

int recursiveFibonacci(int n)
{
    if (n <= 1)
        return n;
    return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
}

int iterativeFibonacci(int n)
{

    int a = 0;
    int b = 1;
    if (n <= 1)
        return n;
    int fib = 1;
    for (int i = 2; i <= n; i++)
    {
        fib = a + b;
        a = b;
        b = fib;
    }
    return fib;
}

int main()
{
    int n;
    bool flag = 1;
    do{
    int choice;
    cout<<"Press 1 for iterative fibonacci\n";
    cout<<"Press 2 for recursive fibonacci\n";
    cin>>choice;
    cout<<"Enter a number :\n";
    cin>>n;
    switch (choice)
    {
    case 1:
        {
            int ans = iterativeFibonacci(n);
            cout<<"Result : "<<ans<<'\n';
        }
        break;
    case 2:{
            int ans = recursiveFibonacci(n);
            cout<<"Result : "<<ans<<'\n';
            break;
    }
    default:
        cout<<"Invalid choice!!\n";

        break;
    }
    int ch;
        cout<<"Press 1 to try again. \nPress 0 to exit\n";
        cin>>ch;
        if(!ch){
            flag = 0;
        }
    }while(flag);
    return 0;
}