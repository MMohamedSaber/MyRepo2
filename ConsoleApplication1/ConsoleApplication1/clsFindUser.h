#pragma once
#include <iostream>
#include "clsShowScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"


class clsFindUser :protected clsShowScreen
{


private:
    static void _PrintUser(clsUser& User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }

public:




    static void ShowFindUserScreen()
    {

        _DrawScreenHeader("\Find User Screen");

        string UserName = "";

        cout << "\nPlease Enter User UserName: ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nAccount number is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);
        _PrintUser(User1);


        if (!User1.IsEmpty())
        {
            cout << "\nClient Found :-)\n";
            _PrintUser(User1);
        }
        else
        {
            cout << "\nClient Was not Found :-(\n";
        }



    }


};


















