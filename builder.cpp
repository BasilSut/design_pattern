//Vasilii S.
//builder - пораждающий паттерн
//один и тот же код строительства для разных объектов
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class House{
    string aboutHouse;
public:
    House():aboutHouse(" "){
        
    }
    string AboutHouse() const{
        return aboutHouse;
    }
    void appendFeature(string str){
        aboutHouse += str;
    }

};

class Builder{
public:
    virtual void createHouse() = 0;
    virtual void createGarage() = 0;
    virtual void createGarden() = 0;

    virtual House* get_House() = 0;
};

class CityHouseBuilder : public Builder {
    House* house;

    public:
        CityHouseBuilder(){
            house = new House();
        }
        ~CityHouseBuilder(){
            delete house;
        }
        void createHouse() override{
            house->appendFeature("City house ");
        }

        void createGarage() override{
            house->appendFeature("with underground parking ");
        }
        void createGarden() override{
            house->appendFeature("with park ");
        }
        House* get_House() override{
            return house;
        }
        
};

class CottegeHouseBuilder : public Builder {
    House* house;

    public:
        CottegeHouseBuilder(){
            house = new House();
        }
        ~CottegeHouseBuilder(){
            delete house;
        }
        void createHouse() override{
            house->appendFeature("Cottege house ");
        }

        void createGarage() override{
            house->appendFeature("with garage for 1 car place ");
        }
        void createGarden() override{
            house->appendFeature("with farm ");
        }
        House* get_House() override{
            return house;
        }
        
};

class Prorab{
    Builder* builder;
public:
    Prorab(Builder* b):builder(b){}
    ~Prorab(){
        delete builder;
    }

    void setBuilder(Builder* b){
        builder = b;
    }
    House* BuildMinimalFeatureHouse(){
        builder->createHouse();
        return builder->get_House();
    }

    House* BuildFullFeatureHouse(){
        builder->createHouse();
        builder->createGarage();
        builder->createGarden();
        return builder->get_House();
    }
};



int main(){
    Builder* builder = new CityHouseBuilder();
    Prorab *director = new Prorab(builder);
    House* house1 =director->BuildMinimalFeatureHouse();
    cout<< house1 -> AboutHouse() <<endl;
    director->setBuilder(new CottegeHouseBuilder());
    House* house2 = director->BuildFullFeatureHouse();
    cout<< house2->AboutHouse() <<endl;
    return 0;
}