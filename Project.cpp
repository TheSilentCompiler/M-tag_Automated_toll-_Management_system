#include <iostream>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;

struct MTag {
    int MtagID;
    string ownerName;
    string vehicleNumber;
    double balance;
};

MTag cars[100];
int vehicleCount = 0;


void color(int c) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

// function declarations
void Add_vehicle();
void Deduct_Toll();
void Check_Balance();
void Recharge_Account();
void Vehicle_Search();
void Display_Vehicles();
void SaveFile();
void LoadFile();
void Delete_account();

int main() {

    LoadFile(); 

    int choice;
    
    do {
        color(13);
        cout<<endl<<setfill('#')<<setw(39)<<""<<endl
            <<"#"
            <<setfill(' ')<<setw(6)<<" ";
        color(15);    
        cout << "=== M-Tag Toll System ==="
             <<setfill(' ')<<setw(6)<<" ";
        color (13);     
        cout<<"#"<<endl;
        cout<<setfill('#')<<setw(39)<<""
            <<setfill(' ')<<endl<<endl;
        color(15);    
        cout<<setfill('.')<<setw(10)<<"";
            
        cout << "1. Add Vehicle";
        cout<<setfill('.')<<setw(14)<<""<<endl;
        cout<<setfill('.')<<setw(10)<<"";
        cout << "2. Deduct Toll";
        cout<<setfill('.')<<setw(14)<<""<<endl;
        cout<<setfill('.')<<setw(10)<<"";
        cout << "3. Check Balance";
        cout<<setfill('.')<<setw(12)<<""<<endl;
        cout<<setfill('.')<<setw(10)<<"";
        cout << "4. Recharge Account";
        cout<<setfill('.')<<setw(9)<<""<<endl;
        cout<<setfill('.')<<setw(10)<<"";
        cout << "5. Search Vehicle";
        cout<<setfill('.')<<setw(11)<<""<<endl;
        cout<<setfill('.')<<setw(10)<<"";
        cout << "6. Display All Vehicles";
        cout<<setfill('.')<<setw(5)<<""<<endl;
        cout<<setfill('.')<<setw(10)<<"";
        cout << "7. Delete Account";
        cout<<setfill('.')<<setw(11)<<""<<endl;
        cout<<setfill('.')<<setw(10)<<"";
        cout << "8. Exit";
        cout<<setfill('.')<<setw(21)<<""
            <<setfill(' ')<<endl<<endl;
        color(95);    
        cout << "Enter choice:";
        color(15);
        cout<<" ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) Add_vehicle();
        else if (choice == 2) Deduct_Toll();
        else if (choice == 3) Check_Balance();
        else if (choice == 4) Recharge_Account();
        else if (choice == 5) Vehicle_Search();
        else if (choice == 6) Display_Vehicles();
        else if(choice == 7) Delete_account ();
        else if (choice == 8) {
            SaveFile();
            cout << "Data saved. Exiting...\n";
        }
        else cout << "Invalid choice!\n";

    } while (choice != 8);

    return 0;
}

// Saving data info to file
void SaveFile() {
    fstream fileOut;
    fileOut.open("data.txt", ios::out);

    for (int i = 0; i < vehicleCount; i++) {
        fileOut << cars[i].MtagID << endl;
        fileOut << cars[i].ownerName << endl;
        fileOut << cars[i].vehicleNumber << endl;
        fileOut << cars[i].balance << endl;
    }

    fileOut.close();
}



void LoadFile() {
    fstream fileIn;
    fileIn.open("data.txt", ios::in);

    if (!fileIn) {
        return; 
    }

    while (true) {

        int id;
        string name;
        string number;
        double bal;

        if (!(fileIn >> id)) {
            break; 
        }

        fileIn.ignore();
        getline(fileIn, name);
        getline(fileIn, number);
        fileIn >> bal;
        fileIn.ignore();

        cars[vehicleCount].MtagID = id;
        cars[vehicleCount].ownerName = name;
        cars[vehicleCount].vehicleNumber = number;
        cars[vehicleCount].balance = bal;

        vehicleCount++;
    }

    fileIn.close();
}



// Add Vehicle

void Add_vehicle() {
    
    cout<<endl;
    cout<<setfill('*')<<setw(30)<<""
        <<setfill(' ')<<endl;
        
    cout << "*\t Add Vehicle \t     *"
         <<endl;

    cout<<setfill('*')<<setw(30)<<""
        <<setfill(' ')<<endl;
    cout << "Enter MTag ID: ";
    cin >> cars[vehicleCount].MtagID;
    cin.ignore();

    cout << "Enter Owner Name: ";
    getline(cin, cars[vehicleCount].ownerName);

    cout << "Enter Vehicle Number: ";
    getline(cin, cars[vehicleCount].vehicleNumber);

    cout << "Enter Balance: ";
    cin >> cars[vehicleCount].balance;

    vehicleCount++;
    cout<<endl;
    cout << "\033[1;4mVehicle Added Successfully!\033[0m";
    cout<<endl;
}



// Deduct Toll

void Deduct_Toll() {
    int id1;
    double toll;

    cout << "\033[1;4m";
    cout<<setfill ('-')<<setw(17)<<""
        <<setfill(' ');
    cout << "\n| Enter MTag ID |\n";
    cout << "\033[0;1m";    
    cout<<setfill ('-')<<setw(17)<<""
        <<setfill(' ')<<endl;
    
    cout<<"       ";    
    cin >> id1;
    cout<<setfill ('-')<<setw(17)<<""
        <<setfill(' ')<<endl;

    
    for (int i = 0; i < vehicleCount; i++) {
        if (cars[i].MtagID == id1) {
            cout << "Enter toll amount: ";
            cin >> toll;
            if (cars[i].balance >= toll) {
                cars[i].balance -= toll;
    const int trackLength = 40; 
    int position = 0;

    string car[3] = {
        "  ___  ",
        " /_[]\\_",
        " O    O"
    };

    cout << "Car is moving...\n";

    while (position < trackLength) {
        system("cls"); 

        for (int i = 0; i < 3; i++) {
            string padding(position, ' ');
            cout << padding << car[i] << endl;
        }

        Sleep(100); 
        position++;
    }

    
    for (int dissolve = 0; dissolve < 3; dissolve++) {
        system("cls"); 

        for (int i = dissolve; i < 3; i++) {
            string padding(trackLength, ' '); 
            cout << padding << car[i] << endl;
        }

        Sleep(400); 
    }        
    system("cls");

            cout << "\033[1;4mToll deducted!"
                 <<"\n\033[0mNew balance: " << cars[i].balance << endl
                 <<endl;
            } else {
                cout << "Not enough balance!\n";
                cout<<"Please Recharge Your Account!\n\n"
                    <<endl;
            }
            return;
        }
    }

    cout << "\033[1mVehicle not found!\033[0m\n";
}



// Check Balance

void Check_Balance() {
    int id2;

    cout << "\033[1;4m";
    cout<<setfill ('-')<<setw(17)<<""
        <<setfill(' ');
    cout << "\n| Enter MTag ID |\n";
    cout << "\033[0;1m";    
    cout<<setfill ('-')<<setw(17)<<""
        <<setfill(' ')<<endl;
    
    cout<<"       ";    
    cin >> id2;
    cout<<setfill ('-')<<setw(17)<<""
        <<setfill(' ')<<endl;

    for (int i = 0; i < vehicleCount; i++) {
        if (cars[i].MtagID == id2) {
            cout << "Balance = " << cars[i].balance << endl;
            return;
        }
    }

    cout << "Vehicle not found.\n";
}


// Recharge Account

void Recharge_Account() {
    int id3;
    double amount;

    cout << "\033[1;4m";
    cout<<setfill ('-')<<setw(17)<<""
        <<setfill(' ');
    cout << "\n| Enter MTag ID |\n";
    cout << "\033[0;1m";    
    cout<<setfill ('-')<<setw(17)<<""
        <<setfill(' ')<<endl;
    
    cout<<"       ";    
    cin >> id3;
    cout<<setfill ('-')<<setw(17)<<""
        <<setfill(' ')<<endl;

    cout << "Enter amount to recharge: ";
    cin >> amount;

    for (int i = 0; i < vehicleCount; i++) {
        if (cars[i].MtagID == id3) {
            cars[i].balance += amount;
            cout << "Recharge done. New balance: " << cars[i].balance << endl;
            return;
        }
    }

    cout << "Vehicle not found.\n";
}



// Search Vehicle

void Vehicle_Search() {
    int id4;
    cout << "\033[1;4m";
    cout<<setfill ('-')<<setw(17)<<""
        <<setfill(' ');
    cout << "\n| Enter MTag ID |\n";
    cout << "\033[0;1m";    
    cout<<setfill ('-')<<setw(17)<<""
        <<setfill(' ')<<endl;
    
    cout<<"       ";    
    cin >> id4;
    cout<<setfill ('-')<<setw(17)<<""
        <<setfill(' ')<<endl;
    
    for (int i = 0; i < vehicleCount; i++) {
        if (cars[i].MtagID == id4) {
            cout<<endl;
            color(11);
            cout<<setfill('*')<<setw(23)<<"";
            cout << "\n|";
            color(15);
            cout<<"\033[1m--- Vehicle Found ---\033[0m";
            color(11);
            cout<<"|\n";
            cout<<setfill('*')<<setw(23)<<""<<endl;
            color(15);
            cout << "Owner: " << cars[i].ownerName << endl;
            cout << "Vehicle No: " << cars[i].vehicleNumber << endl;
            cout << "Balance: " << cars[i].balance << endl;
            return;
        }
    }

    cout << "Vehicle not found.\n";
}



// Display All Vehicles

void Display_Vehicles() {
    if (vehicleCount == 0) {
        cout << "No vehicles added yet.\n";
        return;
    }

    cout<<endl;
            color(11);
            cout<<setfill('*')<<setw(21)<<"";
            cout << "\n*--- All Vehicle ---*\n";
            cout<<setfill('*')<<setw(21)<<"";
            color(15);
    for (int i = 0; i < vehicleCount; i++) {
        cout << "\nVehicle #" << (i + 1) << endl;
        cout << "MTag ID: " << cars[i].MtagID << endl;
        cout << "Owner: " << cars[i].ownerName << endl;
        cout << "Vehicle No: " << cars[i].vehicleNumber << endl;
        cout << "Balance: " << cars[i].balance << endl;
    }
}

bool found = false;
void Delete_account(){
    int deleteID;
    cout<<"Enter Your M-Tag to delete: "; 
    cin>>deleteID;
    found=false;
for(int i=0;i<vehicleCount;i++){
    if(cars[i].MtagID==deleteID){
        found=true;
        for(int j=i;j<vehicleCount-1;j++) cars[j]=cars[j+1];
        vehicleCount--;

        ofstream file("data.txt");
        for (int i = 0; i < vehicleCount; i++) {
        file << cars[i].MtagID << endl;
        file << cars[i].ownerName << endl;
        file << cars[i].vehicleNumber << endl;
        file << cars[i].balance << endl;
    }
        file.close();
        cout<<"Account  deleted!\n";
        break;
    }
}
if(!found) cout<<" ID not found!\n";
           
       
}
