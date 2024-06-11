#pragma once
#include <iostream>
#include <iomanip>
#include "Global.h"
#include "clsDate.h"
using namespace std;
class clsShowScreen
{


protected:



    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        clsDate Date;
        
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";

        cout << "\t\t\t\t\t " << "User: ";
        cout << CurrentUser.UserName<<endl;

        cout << "\t\t\t\t\t " << "Date: ";
        Date.Print();
    }

    static bool CheckAccessRights(clsUser::enPermissions Permissions)

    {

        if (!CurrentUser.AccessPermissions(Permissions))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
          return   true;

    }


};
    



