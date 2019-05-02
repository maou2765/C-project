#include "Car.h"
Car::Car(int nc, Color color,int mileage):engine(nc),color(color),mileage(mileage){}
Color Car::getColor() const{
    return color;
}
int Car::getMileage() const{
    return mileage;
}
int Car::getEngine() const{
    return engine.getNumCylinder();
}
void Car::start(){
    cout<<"Car with ";
    engine.Start();
}
void Car::brake(int distance){
    cout<<"Car with ";
    engine.Stop();
    mileage+=distance;
    cout<<"Driving distance: "<<distance<<endl;
}
void Car::print() const{
    string temp[]={"Black", "White", "Sliver", "Grey", "Red", "Blue"};
    cout<<"Engine:"<<engine.getNumCylinder()<<'\t'<<"Color: "<<temp[color]<<'\t'<<"Current Mileage: "<<mileage<<endl;
}
Car::~Car(){
    cout<<"Calling Car's destructor on the following car:"<<endl;
    print();
    cout<<endl;
}
