// Dependency Inversion principle
// koi bhi high level interface directly low level interface se directly baat ni krte hai.
// CEO -> Manager -> Employee ye hierarchy follow hona chahiye.
// CEO -> Employee directly ceo employee se toh baat ni krega.

#include<iostream>
using namespace std;

class Database{
    public:
        virtual void save(string data)=0;
};

class savetoSQL:public Database{
    public:
        void save(string data){
            cout << "Saving into SQL database -> INSERT INTO USERS VALUE " << data << endl;
        }
};

class savetoMongo:public Database{
    public:
        void save(string data){
            cout << "Saving to Mongo database -> db.users.insert (" << data << ")" << endl;
        }
};

class userService{
    private:
        Database *db;
    public:
        userService(Database* database){
            db=database;
        }
        void savetoDB(string data){
            db->save(data);
        }
};

int main(){

    savetoSQL sd;
    savetoMongo sm;

    userService us1(&sd);
    us1.savetoDB("mohit");
    userService us2(&sm);
    us2.savetoDB("rohit");
    

    return 0;
}