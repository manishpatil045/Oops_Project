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

<<<<<<< HEAD
=======
int idx_naam(string n)
{
    ifstream dfile("drivers.txt");
    string line;
    int index = 0;
    while (getline(dfile, line))
    {
        if (line.find("Name: ") != string::npos)
        {
            string dname = line.substr(6);
            if (dname == n)
            {
                dfile.close();
                return index;
            }
            index++;
        }
    }
    dfile.close();
    return -1;
}

>>>>>>> 3694daa1937cc531070a9ab6f5fc8e32024ceada
class user
{
public:
    string name;
    int mobile;

<<<<<<< HEAD
    user(string n = "TestUser", int m = 1234567890)
=======
    user(string n = "", int m = 0)
>>>>>>> 3694daa1937cc531070a9ab6f5fc8e32024ceada
    {
        name = n;
        mobile = m;
    }
};

<<<<<<< HEAD
class passanger;

=======
>>>>>>> 3694daa1937cc531070a9ab6f5fc8e32024ceada
class driver
{
public:
    user *driv;
    string vehicle;
    int experience;

<<<<<<< HEAD
    driver(string n = "DefaultDriver", int m = (long long)9876543210LL, string v = "Car", int e = 5)
    {
        driv = new user(n, m);
=======
    driver(string n = "", int m = 0, string v = "", int e = 0) : driv(n, m)
    {
>>>>>>> 3694daa1937cc531070a9ab6f5fc8e32024ceada
        vehicle = v;
        experience = e;
    }

<<<<<<< HEAD
    ~driver()
    {
        delete driv;
    }

    void check_acount()
    {
        if (check(driv->name))
=======
    void check_acount()
    {
        if (check(driv.name))
>>>>>>> 3694daa1937cc531070a9ab6f5fc8e32024ceada
            cout << "account exist:\n";
        else
        {
            cout << "account created:\n";
            ofstream dfile("drivers.txt", ios::app);
            if (dfile.is_open())
            {
<<<<<<< HEAD
                dfile << "Name: " << driv->name << "\n";
                dfile << "Mobile: " << driv->mobile << "\n";
=======
                dfile << "Name: " << driv.name << "\n";
                dfile << "Mobile: " << driv.mobile << "\n";
>>>>>>> 3694daa1937cc531070a9ab6f5fc8e32024ceada
                dfile << "Vehicle: " << vehicle << "\n";
                dfile << "Experience: " << experience << "\n";
                dfile << "-----------------\n";
                dfile.close();
            }
        }
    }

    void check_driver_rides()
    {
<<<<<<< HEAD
        string searchName;
        cout << "Enter driver name to check history: ";
        cin >> searchName;

=======
>>>>>>> 3694daa1937cc531070a9ab6f5fc8e32024ceada
        ifstream file("rides.txt");
        string line;
        cout << "Ride history for driver: " << searchName << "\n";
        bool found = false;
<<<<<<< HEAD

        while (getline(file, line))
        {
            if (line.find("Driver: ") != string::npos && line.find(searchName) != string::npos)
            {
                found = true;
                cout << line << endl; 
                getline(file, line);  
                cout << line << endl;
                cout << "-----------------------\n";
=======
        while (getline(file, line))
        {
            if (line.find("Driver: ") != string::npos && line.find(driv.name) != string::npos)
            {
                found = true;
                file.seekg(-(int)line.size() - 1, ios::cur);
                string rideID, passenger, driver, rating, separator;
                getline(file, rideID);
                getline(file, passenger);
                getline(file, driver);
                getline(file, rating);
                getline(file, separator);
                cout << rideID << "\n"
                     << passenger << "\n"
                     << driver << "\n"
                     << rating << "\n";
                cout << separator << "\n";
>>>>>>> 3694daa1937cc531070a9ab6f5fc8e32024ceada
            }
        }

        if (!found)
<<<<<<< HEAD
            cout << "No rides found for " << searchName << endl;

=======
            cout << "No rides found for " << driv.name << endl;
>>>>>>> 3694daa1937cc531070a9ab6f5fc8e32024ceada
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

<<<<<<< HEAD
    passanger(string n = "DefaultPassenger", int m = 1112223333, int a = 25, int r = 0)
    {
        pass = new user(n, m);
=======
    passanger(string n = "", int m = 0, int a = 0, int r = 0) : pass(n, m)
    {
>>>>>>> 3694daa1937cc531070a9ab6f5fc8e32024ceada
        age = a;
        rides = r;
    }

<<<<<<< HEAD
    ~passanger()
    {
        delete pass;
    }

=======
>>>>>>> 3694daa1937cc531070a9ab6f5fc8e32024ceada
    void book_ride()
    {
        ifstream dfile("drivers.txt");
        string line;
<<<<<<< HEAD
        vector<driver *> driverList;
=======
        vector<string> drivers;
        vector<string> vehicles;
>>>>>>> 3694daa1937cc531070a9ab6f5fc8e32024ceada
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
<<<<<<< HEAD
                if (!dname.empty() && !dvehicle.empty() && !dexp.empty())
                {
                    driver *temp = new driver(dname, stoi(dmobile), dvehicle, stoi(dexp));
                    driverList.push_back(temp);
                    cout << index << ". " << dname << " (" << dvehicle << ")" << endl;
                    index++;
                }

=======
                cout << index << ". " << dname << "(" << dvehicle << ")" << endl;
                drivers.push_back(dname);
                vehicles.push_back(dvehicle);
                index++;
>>>>>>> 3694daa1937cc531070a9ab6f5fc8e32024ceada
                getline(dfile, line);
            }
        }
        dfile.close();
<<<<<<< HEAD

        if (driverList.empty())
        {
            cout << "No drivers available!\n";
            return;
        }

=======

        if (drivers.empty())
        {
            cout << "No drivers available!\n";
            return;
        }
>>>>>>> 3694daa1937cc531070a9ab6f5fc8e32024ceada
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
<<<<<<< HEAD
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

=======
        cout << "Ride booked with " << drivers[y] << " | Ride ID: " << randomNum << endl;
        int rating;
        cout << "please rate your driver(1-5):";
        cin >> rating;
>>>>>>> 3694daa1937cc531070a9ab6f5fc8e32024ceada
        ofstream file("rides.txt", ios::app);
        if (file.is_open())
        {
            file << "RideID: " << randomNum << "\n";
<<<<<<< HEAD
            file << "Passenger: " << pass->name << " (" << pass->mobile << ", age=" << age << ")\n";
            file << "Driver: " << driverList[y]->driv->name << "\n";
=======
            file << "Passenger: " << pass.name << " (" << pass.mobile << ", age=" << age << ")\n";
            file << "Driver: " << drivers[y] << "\n";
>>>>>>> 3694daa1937cc531070a9ab6f5fc8e32024ceada
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
<<<<<<< HEAD
        string searchName;
        cout << "Enter passenger name to check history: ";
        cin >> searchName;

=======
>>>>>>> 3694daa1937cc531070a9ab6f5fc8e32024ceada
        ifstream file("rides.txt");
        string line;
        cout << "Ride history for passenger: " << searchName << "\n";
        bool found = false;
<<<<<<< HEAD

        while (getline(file, line))
        {
            if (line.find("Passenger: ") != string::npos && line.find(searchName) != string::npos)
=======
        while (getline(file, line))
        {
            if (line.find("Passenger: ") != string::npos && line.find(pass.name) != string::npos)
>>>>>>> 3694daa1937cc531070a9ab6f5fc8e32024ceada
            {
                found = true;
                cout << line << endl; 
                getline(file, line);  
                cout << line << endl;
<<<<<<< HEAD
                getline(file, line); 
                cout << line << endl;
                cout << "-----------------------\n";
            }
        }

        if (!found)
            cout << "No rides found for " << searchName << endl;

=======
                getline(file, line);
                cout << line << endl;
                getline(file, line);
                cout << line << endl;
                getline(file, line);
                cout << line << endl;
            }
        }
        if (!found)
            cout << "No rides found for " << pass.name << endl;
>>>>>>> 3694daa1937cc531070a9ab6f5fc8e32024ceada
        file.close();
    }

    friend void rideSummary(driver *d, passanger *p);
};

<<<<<<< HEAD
void rideSummary(driver *d, passanger *p)
{
    cout << "\n===== Ride Summary =====\n";
    cout << "Driver: " << d->driv->name << " (" << d->vehicle << ", " << d->experience << " yrs exp)\n";
    cout << "Passenger: " << p->pass->name << " (Age: " << p->age << ", Mobile: " << p->pass->mobile << ")\n";
    cout << "========================\n";
}

=======
>>>>>>> 3694daa1937cc531070a9ab6f5fc8e32024ceada
void login(int x)
{
    if (x == 1)
    {
<<<<<<< HEAD
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
=======
        driver *p = new driver();
        cout << "1.name:\t";
        cin >> p->driv.name;
        cout << "2.mobile number:\t";
        cin >> p->driv.mobile;
        cout << "3.vehicle:\t";
        cin >> p->vehicle;
        cout << "4.experience(years):\t";
        cin >> p->experience;
>>>>>>> 3694daa1937cc531070a9ab6f5fc8e32024ceada
        p->check_acount();
        p->check_driver_rides();
        delete p;
    }
    else
    {
<<<<<<< HEAD
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

=======
        passanger *r = new passanger();
        cout << "1.name:\t";
        cin >> r->pass.name;
        cout << "2.mobile number:";
        cin >> r->pass.mobile;
        cout << "3.age:\t";
        cin >> r->age;
        cout << "4.no of passanger:\t";
        cin >> r->rides;
>>>>>>> 3694daa1937cc531070a9ab6f5fc8e32024ceada
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
<<<<<<< HEAD

=======
>>>>>>> 3694daa1937cc531070a9ab6f5fc8e32024ceada
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
