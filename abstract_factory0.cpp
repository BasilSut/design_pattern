#include <iostream>
#include <string>
using std::cout;
using std::endl;

class Chair{
public:
    virtual void useChair() = 0;
};


class VictorianChair : public Chair {
public:
    void useChair() override{
        cout<<" Victorian Chair " <<endl;
    }
};

class ModernChair : public Chair {
public:
    void useChair() override{
        cout<<"Modern Chair " << endl;
    }
};

class Table{
public:
    virtual void useTable(Chair *chair) = 0;
};


class VictorianTable : public Table {
public:
    void useTable(Chair* chair) override{

        cout<<" Victorian Table with ";
        chair->useChair();
    } 
};

class ModernTable : public Table {
public:
    void useTable(Chair* chair)override{
        
        cout<<" Modern Table with ";
        chair->useChair();

    }
};

class Factory {
public:
    virtual Chair* createChair() = 0;
    virtual Table* createTable() = 0;
};

class VictorianFactory : public Factory{
public:
    Chair* createChair() override {
        return new VictorianChair();
    }
    Table* createTable() override {
        return new VictorianTable();
    }
};

class ModernFactory : public Factory{
public:
    Chair* createChair() override {
        return new ModernChair();
    }
    Table* createTable() override {
        return new ModernTable(); 
    }
};


int main(){
    Factory *facto = new VictorianFactory();
    Chair* chair1 = facto->createChair();
    Table* table1 = facto->createTable();
    table1->useTable(chair1);

    Factory *facto2 = new ModernFactory();
    Chair* chair2 = facto2->createChair();
    Table* table2 = facto2->createTable();
    table2->useTable(chair2);
    return 0;
}