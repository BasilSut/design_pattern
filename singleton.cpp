#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class singleton
{
    
private:
    singleton() { }
    static singleton* Singlet;
    string value;
public:
    singleton(const singleton&) = delete;
    void operator = (const singleton&) = delete;

    static singleton* GetInstance(){
        if(Singlet == nullptr)
            Singlet = new singleton();
        return Singlet;
    }

    string getValue() const{
        return value;
    }
    void setValue(string v){
        value =v;
    } 
};




int main(){
    singleton::GetInstance()->setValue("hell0\n");
    cout<<singleton::GetInstance()->getValue();
    return 0;
}



singleton* singleton::Singlet = nullptr;
