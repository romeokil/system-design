#include<iostream>
#include<string>

using namespace std;
// yaha pe hmlog just ek structure banaye hai ek structure bnae just for interface.
class Car{
    public:
        virtual void startEngine()=0;
        virtual void stopEngine()=0;
        virtual void shiftGear(int gear)=0;
        virtual void brake()=0;
        virtual void accelerate()=0;
        virtual ~Car() {}
};
// or ye hmlog actual car bnae hai jisme wo saara features/behaviours/methods 
// interface ke saath integerated hai.
class sportsCar:public Car{
    public:
        string brand;
        string model;
        bool isengineOn;
        int currentSpeed;
        int currentGear;

        sportsCar(string b,string m){
            this->brand=b;
            this->model=m;
            isengineOn=false;
            currentSpeed=0;
            currentGear=0;
        }

        void startEngine(){
            isengineOn=true;
            cout<<brand<<" "<<model<< " :Engine starts with a roar"<<endl;
        }

        void shiftGear(int gear){
            if(!isengineOn){
                cout<<brand<<" "<<model<<" :Engine OFF!!, Can't Shift the gear"<<endl;
                return ;
            }
            currentGear=gear;
            cout<<brand<<" "<<model<<" :Shifted to Gear. "<< currentGear<<endl;
        }

        void accelerate(){
            if(!isengineOn){
                cout<<brand<<" "<<model<<" :Engine OFF!!, Can't accelerate"<<endl;
                return ;
            }
            currentSpeed+=20;
            cout<<brand<<" "<<model<<" :Accelerating... "<<currentSpeed<<endl;
        }

        void brake(){
            if(!isengineOn){
                cout<<brand<<" "<<model<<" :Engine OFF!!, Can't take brake"<<endl;
                return ;
            }
            currentSpeed-=20;
            cout<<brand<<" "<<model<<" :Braking, Slowing Speed!!! "<<currentSpeed<<endl;
        }

        void stopEngine(){
            isengineOn=false;
            currentGear=0;
            currentSpeed=0;
            cout<<brand<<" "<<model<<" :Engine turned off "<<endl;
        }
};

int main(){

        Car *myCar= new sportsCar("Tata","Punch");
        myCar->startEngine();
        myCar->shiftGear(1);
        myCar->accelerate();
        myCar->shiftGear(2);
        myCar->accelerate();
        myCar->brake();
        myCar->stopEngine();

        delete myCar;
        return 0;
}