#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <fstream>
using namespace std;

bool check(string name)
{
    ifstream dfile("drivers.txt");
    string line;
    while (getline(dfile, line))
    {
        if (line.find("Name: ") != string::npos)
        {
            string dname = line.substr(6);
            if (dname == name)
            {
                dfile.close();
                return true;
            }
        }
    }
    dfile.close();
    return false;
}

class user
{
public:
    string name;
    int mobile;

    user(string n = "TestUser", int m = 1234567890)
    {
        name = n;
        mobile = m;
    }
};

class passanger;

class driver
{
public:
    user *driv;
    string vehicle;
    int experience;

    driver(string n = "DefaultDriver", int m = (long long)9876543210LL, string v = "Car", int e = 5)
    {
        driv = new user(n, m);
        vehicle = v;
        experience = e;
    }

    ~driver()
    {
        delete driv;
    }

    void check_acount()
    {
        if (check(driv->name))
            cout << "account exist:\n";
        else
        {
            cout << "account created:\n";
            ofstream dfile("drivers.txt", ios::app);
            if (dfile.is_open())
            {
                dfile << "Name: " << driv->name << "\n";
                dfile << "Mobile: " << driv->mobile << "\n";
                dfile << "Vehicle: " << vehicle << "\n";
                dfile << "Experience: " << experience << "\n";
                dfile << "-----------------\n";
                dfile.close();
            }
        }
    }

    void check_driver_rides()
    {
        string searchName;
        cout << "Enter driver name to check history: ";
        cin >> searchName;

        ifstream file("rides.txt");
        string line;
        cout << "Ride history for driver: " << searchName << "\n";
        bool found = false;

        while (getline(file, line))
        {
            if (line.find("Driver: ") != string::npos && line.find(searchName) != string::npos)
            {
                found = true;
                cout << line << endl; 
                getline(file, line);  
                cout << line << endl;
                cout << "-----------------------\n";
            }
        }

        if (!found)
            cout << "No rides found for " << searchName << endl;

        file.close();
    }

    friend void rideSummary(driver *d, passanger *p);
};

class passanger
{
public:
    user *pass;
    int age;
    int rides;

    passanger(string n = "DefaultPassenger", int m = 1112223333, int a = 25, int r = 0)
    {
        pass = new user(n, m);
        age = a;
        rides = r;
    }

    ~passanger()
    {
        delete pass;
    }

    void book_ride()
    {
        ifstream dfile("drivers.txt");
        string line;
        vector<driver *> driverList;
        int index = 0;
        cout << "Available drivers:\n";

        string dname, dmobile, dvehicle, dexp;
        while (getline(dfile, line))
        {
            if (line.find("Name: ") != string::npos)
            {
                dname = line.substr(6);
                getline(dfile, line);
                dmobile = line.substr(8);
                getline(dfile, line);
                dvehicle = line.substr(9);
                getline(dfile, line);
                dexp = line.substr(12);
                if (!dname.empty() && !dvehicle.empty() && !dexp.empty())
                {
                    driver *temp = new driver(dname, stoi(dmobile), dvehicle, stoi(dexp));
                    driverList.push_back(temp);
                    cout << index << ". " << dname << " (" << dvehicle << ")" << endl;
                    index++;
                }

                getline(dfile, line);
            }
        }
        dfile.close();

        if (driverList.empty())
        {
            cout << "No drivers available!\n";
            return;
        }

        int y;
        cout << "Choose any driver (0-" << driverList.size() - 1 << "): ";
        cin >> y;

        if (y < 0 || y >= driverList.size())
        {
            cout << "Invalid choice. Defaulting to 0.\n";
            y = 0;
        }

        srand(time(0));
        int randomNum = rand() % 9000 + 1000;
        cout << "Ride booked with " << driverList[y]->driv->name << " | Ride ID: " << randomNum << endl;

        int rating = 5;
        cout << "Default rating = " << rating << endl;

        char choice;
        cout << "Do you want to change the rating? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y')
        {
            cout << "Enter new rating (1-5): ";
            cin >> rating;
        }

        ofstream file("rides.txt", ios::app);
        if (file.is_open())
        {
            file << "RideID: " << randomNum << "\n";
            file << "Passenger: " << pass->name << " (" << pass->mobile << ", age=" << age << ")\n";
            file << "Driver: " << driverList[y]->driv->name << "\n";
            file << "Rating: " << rating << "\n";
            file << "---------------------------\n";
            file.close();
        }

        rideSummary(driverList[y], this);

        for (auto d : driverList)
            delete d;
    }

    void check_passanger_rides()
    {
        string searchName;
        cout << "Enter passenger name to check history: ";
        cin >> searchName;

        ifstream file("rides.txt");
        string line;
        cout << "Ride history for passenger: " << searchName << "\n";
        bool found = false;

        while (getline(file, line))
        {
            if (line.find("Passenger: ") != string::npos && line.find(searchName) != string::npos)
            {
                found = true;
                cout << line << endl; 
                getline(file, line);  
                cout << line << endl;
                getline(file, line); 
                cout << line << endl;
                cout << "-----------------------\n";
            }
        }

        if (!found)
            cout << "No rides found for " << searchName << endl;

        file.close();
    }

    friend void rideSummary(driver *d, passanger *p);
};

void rideSummary(driver *d, passanger *p)
{
    cout << "\n===== Ride Summary =====\n";
    cout << "Driver: " << d->driv->name << " (" << d->vehicle << ", " << d->experience << " yrs exp)\n";
    cout << "Passenger: " << p->pass->name << " (Age: " << p->age << ", Mobile: " << p->pass->mobile << ")\n";
    cout << "========================\n";
}

void login(int x)
{
    if (x == 1)
    {
        string name, vehicle;
        int mobile, experience;

        cout << "Enter Driver Name: ";
        cin >> name;

        cout << "Enter Mobile Number: ";
        cin >> mobile;

        cin.ignore();
        cout << "Enter Vehicle Type: ";
        getline(cin, vehicle);

        cout << "Enter Driving Experience (in years): ";
        cin >> experience;

        driver *p = new driver(name, mobile, vehicle, experience);
        p->check_acount();
        p->check_driver_rides();
        delete p;
    }
    else
    {
        string pname;
        int pmobile, page;

        cout << "Enter Passenger Name: ";
        cin >> pname;
        cout << "Enter Mobile Number: ";
        cin >> pmobile;
        cout << "Enter Age: ";
        cin >> page;

        passanger *r = new passanger(pname, pmobile, page);
        r->check_passanger_rides();

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

        delete r;
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
