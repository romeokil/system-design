#include<iostream>
#include<string>

using namespace std;
// yaha pe proper sportscar hi ek bana diye hai.
// or hmlog dekhe the ki encapsulation me data restrict krne ka koshish krte hai
// for data security reason.
class sportsCar{
    private:
        string brand;
        string model;
        bool isengineOn;
        int currentSpeed;
        int currentGear;

    public:
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

        sportsCar *myCar= new sportsCar("Tata","Punch");
        myCar->startEngine();
        myCar->shiftGear(1);
        myCar->accelerate();
        myCar->shiftGear(2);
        myCar->accelerate();
        myCar->brake();
        myCar->stopEngine();

        // ab dekho hm bahar se yaha pe speed set kr rhe hai but ky real life hm speed control kr skte hai
        // ki hm jb chahe speed 500 kr de.
        // ni hmko accelerate krna pdega tbhi hm speed jo hai badha skte hai.

        // Data security ke liye hm us variable ko private bana diye. toh jaise hi private kiye
        // hmlog ko error aane laga ab hmlog direct currentSpeed access ni kr skte hai.
        // agr hmlog access krna chahe toh getter setter function ke through kr skte hai.
        // getter setter ka use hmlog variables/characters ka use krke krte hai.
        
        // myCar->currentSpeed=500;


        // cout<<"Current speed of the car is ->"<< myCar->currentSpeed<<endl;

        delete myCar;
        return 0;
}