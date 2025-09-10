#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <fstream>
using namespace std;
vector<string> naam = {"patil", "vikas", "aryan", "manish"};
vector<string> gadi = {"SUV", "ALTO", "SUV", "Gwagonr"};
vector<int> mob = {888, 999, 111, 333};
vector<int> exp = {2, 5, 1, 6};
bool check(string name)
{
    int i = 0;
    while (i != naam.size())
    {
        if (name == naam[i])
            return true;
    }
    return false;
}
int idx_naam(string n)
{
    int i = 0;
    while (i != naam.size())
    {
        if (n == naam[i])
            return i;
    }
    return -1;
}
class user
{
public:
    string name;
    int mobile;
};
class driver
{
public:
    user driv;
    string vehicle;
    int experience;
    void check_acount()
    {
        if (check(driv.name))
        {
            cout << "acount exsist:\n";
        }
        else
        {
            cout << "acount not exist:\n";
        }
    }
    void check_driver_rides()
    {
        ifstream file("rides.txt");
        string line;
        cout << "Ride history for driver: " << driv.name << "\n";
        bool found = false;

        while (getline(file, line))
        {
            if (line.find("Driver: ") != string::npos &&
                line.find(driv.name) != string::npos)
            {
                found = true;
                cout << line << endl; 
                getline(file, line);
                cout << line << endl; 
            }
        }

        if (!found)
            cout << "No rides found for " << driv.name << endl;
        file.close();
    }
};
class passanger
{
public:
    user pass;
    int age;
    int rides;
    void book_ride()
    {
        for (int i = 0; i < 4; i++)
        {
            cout << i << naam[i] << endl
                 << gadi[i] << endl
                 << mob[i] << endl
                 << exp[i] << endl;
            cout << endl;
        }
        int y;
        cout << "choose any driver:\t";
        cin >> y;
        srand(time(0));
        int randomNum = rand() % 9000 + 1000;
        cout << "Ride booked with " << naam[y] << " | Ride ID: " << randomNum << endl;
        ofstream file("rides.txt", ios::app); 
        if (file.is_open())
        {
            file << "RideID: " << randomNum << "\n";
            file << "Passenger: " << pass.name
                 << " (" << pass.mobile << ", age=" << age << ")\n";
            file << "Driver: " << naam[y]
                 << " (" << mob[y] << ", " << gadi[y]
                 << ", exp=" << exp[y] << " years)\n";
            file << "---------------------------\n";
            file.close();
        }
    }
    void check_passanger_rides()
    {
        ifstream file("rides.txt");
        string line;
        cout << "Ride history for passenger: " << pass.name << "\n";
        bool found = false;

        while (getline(file, line))
        {
            if (line.find("Passenger: ") != string::npos &&
                line.find(pass.name) != string::npos)
            {
                found = true;
                cout << line << endl; 
                getline(file, line);
                cout << line << endl; 
                getline(file, line);
                cout << line << endl; 
            }
        }

        if (!found)
            cout << "No rides found for " << pass.name << endl;
        file.close();
    }
};
void login(int x)
{
    if (x == 1)
    {
        driver *p = new driver();
        cout << "1.name:\t";
        cin >> p->driv.name;
        cout << "2.mobile number:\t";
        cin >> p->driv.mobile;
        cout << "3.vehicle:\t";
        cin >> p->vehicle;
        cout << "4.experience(years):\t";
        cin >> p->experience;
        p->check_acount();
        p->check_driver_rides();
    }
    else
    {
        passanger *r = new passanger();
        cout << "1.name:\t";
        cin >> r->pass.name;
        cout << "2.mobile number:";
        cin >> r->pass.mobile;
        cout << "3.age:\t";
        cin >> r->age;
        cout << "4.no of passanger:\t";
        cin >> r->rides;
        int z;
        do
        {
            cout << "1.book ride:\n"
                 << "2.check_history:\n"
                 << "3.exit\n";
            cin >> z;
            if (z == 1)
            {
                r->book_ride();
            }
            else if (z == 2)
            {
                r->check_passanger_rides();
            }
        } while (z == 1 || z == 2);
    }
}
int main()
{
    cout << "login\n";
    int n;
    cout << "1.Driver\n2.Passanger:\n";
    cin >> n;
    login(n);
}