#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <fstream>
using namespace std;
bool check(string name){
    ifstream dfile("drivers.txt");
    string line;
    while (getline(dfile, line)) {
        if (line.find("Name: ") != string::npos) {
            string dname = line.substr(6);
            if (dname == name) {
                dfile.close();
                return true;
            }
        }
    }
    dfile.close();
    return false;
}
int idx_naam(string n) {
    ifstream dfile("drivers.txt");
    string line;
    int index = 0;
    while (getline(dfile, line)) {
        if (line.find("Name: ") != string::npos) {
            string dname = line.substr(6);
            if (dname == n) {
                dfile.close();
                return index;
            }
            index++;
        }
    }
    dfile.close();
    return -1; 
}
class user{
public:
    string name;
    int mobile;
};
class driver{
public:
    user driv;
    string vehicle;
    int experience;
    void check_acount(){
        if (check(driv.name)) cout << "account exist:\n";
        else{ 
            cout << "account created:\n";
            ofstream dfile("drivers.txt", ios::app);
            if (dfile.is_open()) {
                dfile << "Name: " <<driv.name << "\n";
                dfile << "Mobile: " <<driv.mobile << "\n";
                dfile << "Vehicle: " << vehicle << "\n";
                dfile << "Experience: " << experience << "\n";
                dfile << "-----------------\n";
                dfile.close();
            }
    }
    }
    void check_driver_rides(){
        ifstream file("rides.txt");
        string line;
        cout << "Ride history for driver: " << driv.name << "\n";
        bool found = false;
        while (getline(file, line)){
            if (line.find("Driver: ") != string::npos && line.find(driv.name) != string::npos){
                found = true;
                file.seekg(-(int)line.size()-1, ios::cur); // move back to start of block
                string rideID, passenger, driver, rating, separator;
                getline(file, rideID);
                getline(file, passenger);
                getline(file, driver);
                getline(file, rating);
                getline(file, separator);
                cout << rideID << "\n" << passenger << "\n" << driver << "\n" << rating << "\n";
                cout << separator << "\n";
            }
        }

        if (!found) cout << "No rides found for " << driv.name << endl;
        file.close();
    }
};
class passanger{
public:
    user pass;
    int age;
    int rides;
    void book_ride(){
        ifstream dfile("drivers.txt");
        string line;
        vector<string> drivers;  
        vector<string> vehicles; 
        int index = 0;
        cout << "Available drivers:\n";
        string dname, dmobile, dvehicle, dexp;
        while (getline(dfile, line)) {
            if (line.find("Name: ") != string::npos) {
                dname=line.substr(6);
                getline(dfile, line); dmobile = line.substr(8);
                getline(dfile, line); dvehicle = line.substr(9);
                getline(dfile, line); dexp = line.substr(12);
                cout << index << ". " << dname <<"("<<dvehicle<<")"<< endl;
                drivers.push_back(dname);
                vehicles.push_back(dvehicle);
                index++;
                getline(dfile, line);
            }
        }
    dfile.close();

    if (drivers.empty()) {
        cout << "No drivers available!\n";
        return;
    }
        int y;
        cout << "choose any driver:\t";
        cin >> y;
        srand(time(0));
        int randomNum = rand() % 9000 + 1000;
        cout << "Ride booked with " << drivers[y] << " | Ride ID: " << randomNum << endl;
        int rating;
        cout<<"please rate your driver(1-5):";
        cin>>rating;
        ofstream file("rides.txt", ios::app);
        if (file.is_open()){
            file << "RideID: " << randomNum << "\n";
            file << "Passenger: " << pass.name<< " (" << pass.mobile << ", age=" << age << ")\n";
            file << "Driver: " << drivers[y] << "\n";
            file << "Rating: " << rating << "\n";
            file << "---------------------------\n";
            file.close();
        }
    }
    void check_passanger_rides(){
        ifstream file("rides.txt");
        string line;
        cout << "Ride history for passenger: " << pass.name << "\n";
        bool found = false;
        while (getline(file, line)){
            if (line.find("Passenger: ") != string::npos && line.find(pass.name) != string::npos){
                found = true;
                cout << line << endl;
                getline(file, line); cout << line << endl;
                getline(file, line); cout << line << endl;
                getline(file,line); cout<<line<<endl;
            }
        }
        if (!found) cout << "No rides found for " << pass.name << endl;
        file.close();
    }
};
void login(int x){
    if (x == 1){
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
    else{
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
        do{
            cout << "1.book ride:\n"<< "2.check_history:\n"<< "3.exit\n";
            cin >> z;
            if (z == 1){
                r->book_ride();
            }
            else if (z == 2){
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