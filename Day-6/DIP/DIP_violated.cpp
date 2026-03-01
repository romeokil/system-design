// Dependency Inversion principle
// koi bhi high level interface directly low level interface se directly baat ni krte hai.
// CEO -> Manager -> Employee ye hierarchy follow hona chahiye.
// CEO -> Employee directly ceo employee se toh baat ni krega.

#include <iostream>
using namespace std;

class savetoSQL
{
public:
    void savetoSQLDB(string data)
    {
        cout << "Saving into SQL database -> INSERT INTO USERS VALUE " << data << endl;
    }
};
class savetoMongo
{
public:
    void savetoMongoDB(string data)
    {
        cout << "Saving to Mongo database -> db.users.insert (" << data << ")" << endl;
    }
};
class userService
{
private:
    savetoSQL sd;
    savetoMongo sm;

public:
    void savetoUserSQL(string user)
    {
        sd.savetoSQLDB(user);
    }
    void savetoUserMongo(string user)
    {
        sm.savetoMongoDB(user);
    }
};
int main()
{

    userService *us;
    us.savetoUserSQL("mohit");
    us->savetoUserMongo("arvind");

    return 0;
}