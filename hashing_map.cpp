#include <iostream>
#include <map>

using namespace std;

map<string, map<string, string>> dataAkun;

// Hash Function
int hashFunction(string password)
{
    return tolower(password[0]) - 97;
}

bool LoggedIn() //untuk menu login
{
    string username, password;

    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    string hash_key = to_string(hashFunction(password));

    cout << endl;
    if (dataAkun.find(hash_key) != dataAkun.end())
    {
        cout << "Successfully logged in!" << endl;
        cout << "==== Account Details ====" << endl;
        cout << "Username: " << dataAkun[hash_key]["username"] << endl;
        return true; // Return true for a successful login
    }
    else
    {
        cout << "Login failed!" << endl;
        return false; // Return false for a failed login
    }
}

bool Registered() //untuk menu register
{
    string fullname, username, password;

    cout << "Enter Fullname: ";
    cin >> fullname;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    string hash_key = to_string(hashFunction(password));

    map<string, string> dataDetail;
    dataDetail["username"] = username;
    dataDetail["fullname"] = fullname;

    dataAkun[hash_key] = dataDetail;
    return true;
}

bool AccountDetail() 
{
    cout << endl;
    for (auto i = dataAkun.begin(); i != dataAkun.end(); i++)
    {
        cout << "Key: " << i->first << "\t"
             << " Username: " << i->second["username"] << " Fullname: " << i->second["fullname"] << endl;
    }
}

// Menu
bool menu()
{
    while (true)
    {
        int choice; // Declare the choice variable here

        cout << endl;
        cout << "==== MENU ====" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;

        cout << endl;
        cout << "Pilih Menu: ";
        cin >> choice; // Read user's choice

        if (choice == 1)
        {
            bool status = Registered();
            
            if (status)
            {
                cout << "Registration successful!" << endl;
            }
            else
            {
                cout << "Registration failed!" << endl;
            }
        }
        else if (choice == 2)
        {
            bool status = LoggedIn();
            
            if (status)
            {
                cout << "Login successful!" << endl;
            }
            else
            {
                cout << "Login failed!" << endl;
            }
        }
        else if (choice == 3)
        {
            bool status = AccountDetail();
            break;
        }
        else
        {
            cout << "Invalid!" << endl;
        }
    }
}

int main()
{
    bool status = menu();
}
