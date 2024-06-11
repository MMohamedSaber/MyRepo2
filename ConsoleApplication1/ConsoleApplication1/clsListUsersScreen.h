#pragma once
#include <iostream>
#include "clsShowScreen.h"
#include "clsUser.h"

using namespace std;

class clsListUsersScreen : protected clsShowScreen
{
private:
    static void _PrintClientRecord(clsUser User)
    {
        cout << setw(8) << left << "" << "| " << setw(12) << left << User.UserName;
        cout << "| " << setw(25) << left << User.FullName();
        cout << "| " << setw(12) << left << User.Phone;
        cout << "| " << setw(20) << left << User.Email;
        cout << "| " << setw(10) << left << User.Password;
        cout << "| " << setw(12) << left << User.Permissions;

    }

public:
    static void ShowListUser()
    {
        vector<clsUser> vUsers = clsUser::GetUsersList();

        string Title = "\t Show Users list";
        string subtitle = "\t (" + to_string(vUsers.size()) + ") Users(s).";
        _DrawScreenHeader(Title, subtitle); // You're calling a function _DrawScreenHeader here, which might be undefined.

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(12) << "User Name";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(12) << "Email";
        cout << "| " << left << setw(20) << "Phone";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions ";
        cout << setw(8) << left << "" << "\n\t____________________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else
            for (clsUser User : vUsers)
            {
                _PrintClientRecord(User);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t____________________________________________________________";
        cout << "_________________________________________\n" << endl;
    }
};
