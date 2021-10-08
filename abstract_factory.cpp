#include <iostream>
#include <string>
using std::cout;
using std::endl;

class Chair{
public:
    virtual void useChair() = 0;
    virtual size_t get_count() = 0;
};



class VictorianChair : public Chair {
    static size_t count;
public:
    void useChair() override{
        cout<<" Victorian Chair " << ++count << endl;
    }
    size_t get_count() override{
        return count;
    }
};

class ModernChair : public Chair {
    static size_t count;
public:
    void useChair() override{
        cout<<" Modern Chair " << ++count << endl;
    }
    size_t get_count() override{
        return count;
    }
};

class Table{
public:
    virtual void useTable() = 0;
    virtual void useTable_with_chair(Chair *chair) = 0;
};


class VictorianTable : public Table {
    static size_t count;
public:
    void useTable() override{
        cout<<" Victorian Table " << ++count << endl;
    }
    void useTable_with_chair(Chair* chair) override{
        cout<<" Victorian Table " 
              << ++count << " with ";
        chair->useChair();
    }
};

class ModernTable : public Table {
    static size_t count;
public:
    void useTable(){
        cout<<" Modern Table " << ++count << endl;
    }
    void useTable_with_chair(Chair* chair){
        cout<<" Modern Table " 
        << ++count << " with ";
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

size_t VictorianChair::count = 0;
size_t VictorianTable::count = 0;
size_t ModernChair::count = 0;
size_t ModernTable::count = 0;
int main(){
    Factory *facto = new VictorianFactory();
    Chair* chair1 = facto->createChair();
    Table* table1 = facto->createTable();
    table1->useTable_with_chair(chair1);

    Factory *facto2 = new ModernFactory();
    Chair* chair2 = facto2->createChair();
    Table* table2 = facto2->createTable();
    Table* table3 = facto2->createTable();
    table2->useTable_with_chair(chair2);
    table3->useTable_with_chair(chair2);
    return 0;
}   