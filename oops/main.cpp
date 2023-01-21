#include <bits/stdc++.h>
using namespace std;



//--------------basic class-------------//

//class
class house{
    private:
     int length,breadth;
    public:
       
        void setdata(int x,int y){
            length=x;
            breadth=y;
        }
        int area(){
            return length*breadth;
        }
};



//--------------constructor-------------//



//non perameterized constructor

class Person{
    private:
    string name;
    int age;
    float height;
    public:
    Person(){
        name="";
        age=0;
        height=0.0f;
    }
    void getData(){
        cout<<name<<endl;
        cout<<age<<endl;
        cout<<height<<endl;
    }

};

// perameterized constructor

class Person1{
    private:
    string name;
    int age;
    float height;
    public:
    Person1(string name,int age,float height){
        this->name=name;
        this->age=age;
        this->height=height;
    }
    void getData(){
        cout<<name<<endl;
        cout<<age<<endl;
        cout<<height<<endl;
    }

};




//overloaded constructor

class A{
    private:
    int age;
    public:
    A(){
        age=0;
    }
    A(int x){
        age=x;
    }
    A(A&obj_1){
        age=obj_1.age;
    }
    int getData(){
        return age;
    }
};


//--------------task-------------//

class PhoneDetails{

    private:
        string name;
        string ram;
        int processor;
        int battery;
    public:
    PhoneDetails(string name,string ram,int processor,int battery){
        this->name=name;
        this->ram=ram;
        this->processor=processor;
        this->battery=battery;
    }

    void getDetails();
  

};
//we can assign by this method also
void PhoneDetails::getDetails(){
  cout<<name<<" "<<ram<<" "<<processor<<" "<<battery<<endl;
}


//--------------operator overloading-------------//

class A1{
private:
    int weight;
public:
    A1(int x=0){
        weight=x;
    }
    void printValue(){
        cout<<weight<<endl;
    }
    A1 operator + (A1 const &w)
    {
        A1 temp;
        temp.weight= weight+ w.weight;
        return temp;
    }

};

class A2{
    private:
    int val;
    public:
    A2(int x=0){
        val=x;
    }
    void printValue(){
        cout<<val<<endl;
    }
    void operator++(){
        ++val;
    }
    void operator++(int){
        val++;
    }

};

//--------------Inheritance-------------//


class Rectangle{
public:
    int length;
    int breadth;
    
    void area(){
        cout<<length*breadth<<endl;
    }

};

class Cuboid:public Rectangle{
public:
    int height;
    void vollume(){
        cout<<length*breadth*height<<endl;
    }

};

//constructor and inheritance

class base{
    public:
        base(){
            cout<<"default base class"<<endl;
        }
        base(int x){
            cout<<"parameterized base class"<<x<<endl;
            
        }
};

class derived:public base{
    public:
        derived(){
            cout<<"default derived class"<<endl;
        }

        derived(int x){
            cout<<"parameterized derived class"<<x<<endl;

        }
    
};


//--------------Virtual Function-------------//

class b1{
    public:
   virtual void show(){
        cout<<"Base Class"<<endl;
    }
};

class derived1:public b1{
    
    public:
    void show(){
        cout<<"derived Class 1"<<endl;
    }
};

class derived2:public b1{
    
    public:
    void show(){
        cout<<"derived Class 2"<<endl;
    }
};

//--------------Virtual Destructor-------------//

class d1{
    public:
    //if we not make this virtual then only half of object deleted
   virtual ~d1(){
        cout<<"base class deleted"<<endl;
    }
};

class d1base:public d1{
    
    public:
    ~d1base(){
        cout<<"derived class deleted"<<endl;
    }
};


//--------------Operator Overloading-------------//

class opoverload{
    private:
    int weight;
    public:
    opoverload(int x){
        weight=x;
    }
   bool operator>(opoverload x){
        return weight>x.weight;
     } 
};


class test{
    public:
    void fun()const{
        cout<<"const called"<<endl;
    }
    void fun(){
        cout<<"simple called"<<endl;
    }
};

class xyz{

};

int main()
{
    
    
    //basic class

    // house h1;
    // h1.setdata(3,4);
    //cout<<h1.area()<<endl;



    //constuctor class

    //Person1 h2("dhruvit",21,5.6);
   // h2.getData();
    

    //overloaded constructor

    // A obj_1(10);
    // A obj_2(obj_1);


    //task

    //PhoneDetails p1("samsung","8GB",56,100);
    //p1.getDetails();
    //cout<<obj_2.getData()<<endl;


    //operator overloading

    // int a=25,b=34,c=0;
    // c=a+b;
    // cout<<c<<endl;

    // A1 person1(78);
    // A1 person2(98);
    // A1 total=person1+person2;
    // total.printValue();

    //++ operator overload

    // int a=63;
    // ++a;

    A2 Jon(63);
    ++Jon;
    Jon++;
    Jon.printValue();

//    Cuboid c;
//    c.length=10;
//    c.breadth=20;
//    c.height=30;

//    c.area();
//    c.vollume();

//    derived d1;

//    derived d2(8);
    
    // b1 *ptr;
    // ptr=new derived1();
    // ptr->show();

    // ptr=new derived2();
    // ptr->show();   

    // d1 *ptr=new d1base;
    // delete ptr;

    // int w1,w2;
    // cin>>w1>>w2;

    // opoverload jon(w1);
    // opoverload rick(w1);

    // if(jon>rick){
    //     cout<<"1st"<<endl;
    // }else{
    //     cout<<"2nd"<<endl;

    // }


return 0;
  
}
  









