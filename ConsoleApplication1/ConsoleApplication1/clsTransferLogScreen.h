#pragma once
#include <iostream>
#include "clsShowScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "Global.h"

class clsTransferLogScreen:protected clsShowScreen
{

    static void PrintUserRegesterRecordLine(clsBankClient::stLoginsListScreen Logs)
    {

        cout << setw(8) << left << "" << "| " << setw(22) << Logs.Date;
        cout << "| " << setw(10) << left << Logs.SourceAccount;
        cout << "| " << setw(10) << left << Logs.DistnationAccount;
        cout << "| " << setw(10) << left << Logs.Amount;
        cout << "| " << setw(15) << left << Logs.SourceBalance;
        cout << "| " << setw(15) << left << Logs.DistnationBalance;
        cout << "| " << setw(15) << left << Logs.UserName;


    }


public:
    vector <clsUser::stLoginRegiterRecord> vLoginsUsersRegister = clsUser::GetLoginRegisterList();
    string Title = "\t  Users Registring Screen";
    string SubTitle = "\t    (" + to_string(vLoginsUsersRegister.size()) + ") user(s).";


    static void ShowTransfersScreen(){
        vector <clsBankClient::stLoginsListScreen> vLoginsUsersRegister = clsBankClient::GetLoginsTransfersList();
        string Title = "\t  Transfers Registring Screen";
        string SubTitle = "\t    (" + to_string(vLoginsUsersRegister.size()) + ") user(s).";

    _DrawScreenHeader(Title, SubTitle);

    cout << setw(8) << left << "" << "\n\t______________________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << setw(8) << left << "" << "| " << left << setw(22) << "Date And Time ";
    cout << "| " << left << setw(10) << "s.Acc ";
    cout << "| " << left << setw(10) << "d.Acc";
    cout << "| " << left << setw(11) << "Amount";
    cout << "| " << left << setw(15) << "s.Balance";
    cout << "| " << left << setw(15) << "d.Balance";
    cout << "| " << left << setw(10) << "User Name";
    cout << setw(8) << left << "" << "\n\t______________________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (vLoginsUsersRegister.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (clsBankClient::stLoginsListScreen Transfer : vLoginsUsersRegister)
        {

            PrintUserRegesterRecordLine(Transfer);
            cout << endl;
        }

    cout << setw(8) << left << "" << "\n\t______________________________________________________________";
    cout << "_________________________________________\n" << endl;

}




};

