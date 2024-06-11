#pragma once
#include <iostream>
#include "clsShowScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"

using namespace std;
class clsAddNewUserScreen :protected clsShowScreen
{

private :

    static  void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter First Name : ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter Last Name : ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email : ";
        User.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone : ";
        User.Phone = clsInputValidate::ReadString();

        cout << "\nEnter Password : ";
        User.Password = clsInputValidate::ReadString();

        cout << "\nEnter The permissions : ";
        User.Permissions = _ReadPermissions();


    }
    static int _ReadPermissions()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUser::enPermissions::pListClients;
        }


        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }

        cout << "\nUsers Reigesters? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUsersRigisters;
        }


        return Permissions;

    }
    static void _PrintUser(clsUser User)
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



    static void  ShowAddNewUser()
    {

        char answer;

        cout << "\nAre you sure that want to add new User..?";
        cin >> answer;

        if (answer == 'y' || answer == 'Y')
        {
            _DrawScreenHeader("\t Add New User Screen");


            cout << "\nEnter User Name ?";
            string UserName = clsInputValidate::ReadString();

            while (clsUser::IsUserExist(UserName))
            {
                cout << "\nUser Name is Already Exist Chose another one\n";
                UserName = clsInputValidate::ReadString();
            }

            clsUser User = clsUser::GetAddNewUserObject(UserName);
            _ReadUserInfo(User);

            /* User.Save();
             _PrintUser(User);*/

            clsUser::enSaveResults SaveResult;

            SaveResult = User.Save();
            switch (SaveResult)
            {
            case clsUser::svSucceeded:
                cout << "\nThe User Added Successfully\n";
                _PrintUser(User);


                break;
            case clsUser::svFaildEmptyObject:

                cout << "\nError account was not saved because it's Empty";

                break;
            case clsUser::svFaildUserExists:

                cout << "\nError account was not saved because account number is used!\n";


                break;
            default:
                break;
            }


        }



    }

};
