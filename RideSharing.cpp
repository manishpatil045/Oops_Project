#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
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
};
class passanger{
    public:
    user pass;
    int age;
    int rides;
};
void driver_login(){
    driver *p=new driver();
        cout<<"1.name"; cin>>p->driv.name;
        cout<<"2.mobile number"; cin>>p->driv.mobile;
        cout<<"3.vehicle"; cin>>p->vehicle;
        cout<<"4.experience(years)"; cin>>p->experience;
}
void rider_login(){
    passanger *r=new passanger();
        cout<<"1.name:"; cin>>r->pass.name;
        cout<<"2.mobile number"; cin>>r->pass.mobile;
        cout<<"3.age"; cin>>r->age;
        cout<<"4.rides"; cin>>r->rides;
}
int main(){
    int i;
    cout<<"login\n";
    int n;
    cout<<"1.Driver\n2.Passanger:\n";
    cin>>n;
    (n==1)?driver_login():rider_login();   
}