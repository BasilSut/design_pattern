//Vasilii S.
// make obj of class without operator new
#include <iostream>
#include <string>
using std::cout;
using std::endl;
//using namespace std;

class Document {//интерфейсный класс
public:
    virtual void show() = 0; //чисто виртуальная функция
};

class TextDoc : public Document{
    static int count; //создается и инициализируется только один раз
public:
    void show(){
        //++count;
        cout<<"txt "<<++count<<endl;
    }
};

class ImageDoc : public Document{
    static int count;
public:
    void show(){
        cout<<"picture "<<++count<<endl;
    }
};

//фабричный метод, абстрактный(интерфейсный) класс
class Creator{
public:
    virtual Document* create() = 0;
};
 
class TextDocCreator : public Creator{
public:
    Document* create(){
        return new TextDoc();
    }
};

class ImageDocCreator : public Creator{
public:
    Document* create(){
        return new ImageDoc();
    }
}; 

int TextDoc::count = 0;
int ImageDoc::count = 0;
int main(){
    Creator *creator = new TextDocCreator();
    Document* myDoc1 = creator->create();

    creator = new ImageDocCreator();
    Document* myDoc2 = creator->create();
    Document* myDoc3 = creator->create();

    creator = new TextDocCreator();
    Document* myDoc4 = creator->create();
    Document* myDoc5 = creator->create();

    myDoc1->show();
    myDoc2->show();
    myDoc3->show();
    myDoc4->show();
    myDoc5->show();
    return 0;
}