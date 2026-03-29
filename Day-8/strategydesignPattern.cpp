#include<iostream>
using namespace std;

class WalkableRobot{
    public:
        virtual void Walk()=0;
};  
class WalkOnly:public WalkableRobot{
    public:
        void Walk() override{
            cout<<"can Walk"<<endl;
        }
};
class NoWalk:public WalkableRobot{
    public:
        void Walk() override{
            cout<<"No Walk"<<endl;
        };
};
class TalkableRobot{
    public:
        virtual void Talk()=0;
};
class TalkOnly:public TalkableRobot{
    public:
        void Talk() override{
            cout<<"Can talk"<<endl;
        }
};
class NoTalk:public TalkableRobot{
    public:
        void Talk() override{
            cout<<"No Talk"<<endl;
        }
};
class FlyableRobot{
    public:
        virtual void fly()=0;
};
class FlyOnly:public FlyableRobot{
    public:
        void fly() override{
            cout<<"Can Fly"<<endl;
        }
};
class NoFly:public FlyableRobot{
    public:
        void fly() override{
            cout<<"No Fly"<<endl;
        }
};
class Robot{
    protected:
        WalkableRobot* walkbehaviour;
        TalkableRobot* talkbehaviour;
        FlyableRobot* flybehaviour;
    public:
        Robot(WalkableRobot* w,TalkableRobot* t,FlyableRobot* f){
            walkbehaviour=w;
            talkbehaviour=t;
            flybehaviour=f;
        }
        void walk(){
            walkbehaviour->Walk();
        }
        void talk(){
            talkbehaviour->Talk();
        }
        void fly(){
            flybehaviour->fly();
        }
        virtual void projection()=0;
};
class CompanionRobot:public Robot{
    public:
        CompanionRobot(WalkableRobot* w,TalkableRobot* t,FlyableRobot* f):Robot(w,t,f){}
        void projection() override{
            cout<<"Companion Robot features...."<<endl;
        }
};
class WorkerRobot:public Robot{
    public:
        WorkerRobot(WalkableRobot* w,TalkableRobot* t,FlyableRobot* f):Robot(w,t,f){}
        void projection() override{
            cout<<"Worker Robot features..."<<endl;
        }
};
int main(){
    Robot * robo1=new CompanionRobot(new WalkOnly(),new TalkOnly(),new NoFly());
    Robot* robo2=new WorkerRobot(new NoWalk(),new NoTalk(), new FlyOnly());
    robo1->walk();
    robo1->talk();
    robo1->fly();
    robo1->projection();

    cout<<"Just for the gap-----------"<<endl;

    robo2->walk();
    robo2->talk();
    robo2->fly();
    robo2->projection();
}