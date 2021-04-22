#include <iostream> // bez .h 

using namespace std; //brak przestrzeni nazw std

class X //klasa abstrakcyjna 
{ 
public:
    static int x1;
    void virtual fun1() { cout << "funkcja fun1 z klasy X"<<endl; } //dodaje  endl dla estetyki
    void virtual fun2() {} //nie mogła byc statyczna i rowna 0 
}; 

    class Y : public X 
    {
    public: 
        void virtual fun1() { cout << "funkcja fun1 z klasy Y" << endl; } 
        void fun2() { cout << "funkcja fun2 z klasy Y" << endl; } 
    };

    class Z : public X {
    public:  
        void fun1() { cout << "funkcja fun1 z klasy Z" << endl; }
        void fun2() { cout << "funkcja fun2 z klasy Z" << endl; } 
    };
     int main()
    {  
        //X ob1;//nie definiujemy ob. z klas abstrakcyjnych   
        Y ob2; 
        Z ob3; 
        ob2.fun1(); //brak nawiasu przy wywołaniu
        ob2.fun2(); //  
        X* wsk = &ob2; 
        wsk->fun1();  
        wsk->fun2(); 
        wsk->X::fun1();
        wsk->X::fun2(); 
        wsk = &ob3;  
        wsk->fun1(); 
        wsk->fun2(); 
        wsk->X::fun1(); 
        wsk->X::fun2(); // na obiekt X 

        return 0;
    }