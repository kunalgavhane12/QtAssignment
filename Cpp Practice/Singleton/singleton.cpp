#include <iostream>
using namespace std;

class Singleton{

    static Singleton *p;
    Singleton(){
        cout<<"Constructor in private"<<endl;
    }
    public:
    static Singleton * create_object(){
        if(p==nullptr)
        {
            p = new Singleton();
            return p;
        }
        else
        {
            return p;
        }
    }
    void show()
    {
        cout<< "Address: " << p<<endl;
    }

    ~Singleton()
    {
        if(p!=0)
        {
            delete p;        
        }
        
        p=nullptr;
    }

};

Singleton *Singleton::p = nullptr;

int main()
{
    Singleton *s1, *s2, *s3;
    s1=Singleton::create_object();   
    s2=Singleton::create_object();   
    s3=Singleton::create_object();   

    s1->show();
    s2->show();
    s3->show();


   return 0;
}
