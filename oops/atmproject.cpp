#include <bits/stdc++.h>
#include<conio.h>
#define int long long int 
using namespace std;
/*Mini Project -ATM
-check balance
-cash withdraw
-user details
-update mobile no.*/

class atm{
private:
    int account_no;
    string name;
    int pin;
    double balance;
    string mobile;

public:
    //initial setter function
    void setData(int account_no_a,string name_a,int pin_a,
    double balance_a,string mobile_a){
        account_no=account_no_a;
        name=name_a;
        pin=pin_a;
        balance=balance_a;
        mobile=mobile_a;
    }
    //getter function
    int getAccountNo(){
        return account_no;
    }

    string getName(){
        return name;
    }

    int getPin(){
        return pin;
    }

    double getBalance(){
        return balance;
    }

    string getMobile(){
        return mobile;
    }


    void setMobile(string prev,string newm){
        if(prev==mobile){
            mobile=newm;
            cout<<"Successfully updated new mobile no."<<endl;
            _getch();
        }else{
            cout<<"Incorrect old mobile no"<<endl;
             _getch();
        }
    }

    void cashWithDraw(int amount_a){
        if(amount_a>0 and amount_a<balance){
            balance-=amount_a;
            cout<<"Please collect your cash"<<endl;
            cout<<"Updated Balance: "<<balance<<endl;
            _getch();
        }else{
            cout<<"Invalid Amount"<<endl;
            _getch();
        }
    }

};



int  main(){

int choice=0,enterPIN;
int enterAccountNo;

system("cls");

atm user1;
user1.setData(1234567,"Tim",1111,45000.90,"9723169052");

do{
    system("cls");
    cout<<"***welcome to atm***"<<endl;
    cout<<"Enter Account No"<<endl;
    cin>>enterAccountNo;
    cout<<endl;
    cout<<"Enter pin"<<endl;
    cin>>enterPIN;

    if(enterAccountNo==user1.getAccountNo() and
    enterPIN==user1.getPin()
    ){
        do
        {
            int amount=0;
            string oldMobileNo,newMobileNo;
            system("cls");

    cout<<"***welcome to atm***"<<endl;
    cout<<"Select Options"<<endl;
    cout<<"1. check balance"<<endl;
    cout<<"2. cash withdraw"<<endl;
    cout<<"3. show user details"<<endl;
    cout<<"4. update mobile no."<<endl;
    cout<<"5. Exit"<<endl;
    cin>>choice;

    switch (choice)
    {
    case 1:
        cout<<endl<<"your bank balance is:"<<user1.getBalance();
        _getch();
        break;
    case 2:
        cout<<endl<<"Enter Amount:"<<endl;
        cin>>amount;
        user1.cashWithDraw(amount);
        
        break;
    case 3:
        cout<<endl<<"**details are--"<<endl;
        cout<<endl<<"->Account no"<<user1.getAccountNo()<<endl;
        cout<<endl<<"->name"<<user1.getName()<<endl;
        cout<<endl<<"->Balance"<<user1.getBalance()<<endl;
        cout<<endl<<"->Mobile no"<<user1.getMobile()<<endl;
       _getch();
        break;
    case 4:
        cout<<endl<<"Enter old Mobile no"<<endl;
        cin>>oldMobileNo;

     cout<<endl<<"Enter new Mobile no"<<endl;
        cin>>newMobileNo;

        user1.setMobile(oldMobileNo,newMobileNo);
        break;
    case 5:
        exit(0);
    
    default:
    cout<<endl<<"Enter valid data";

    }

        } while (1);
        
    }


}while(1);







return 0;
}