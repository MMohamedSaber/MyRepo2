#pragma once
#include <iostream>
#include "clsShowScreen.h"
#include "clsCurrenciesList.h"
#include "clsFindCurrency.h"
#include "clsUpdateCurrency.h"
#include "clsClculateCurrency.h"


class clsCurrencyScreen :protected clsShowScreen
{
private:
    enum enManageCurrencyMenueOptions {
        eListCurrency = 1, eFindCurrency = 2, eUpdateRate = 3,
        eCurrencyCalculator = 4, eMailMenu = 5
    };

    static short ReadCurrencyMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static void _GoBackToCurrenciesMenue()
    {
        cout << "\n\nPress any key to go back to Manage Users Menue...";
        system("pause>0");
        ShowCurrencyScreen();
    }

    static void _ShowCurrenciesList()
    {
        clsCurrenciesList::ShowCurrecylistScreen();
    }

    static void __ShowFindCurrency()
    {
        clsFindCurrency::ShowFindCurrencyScreen();
    }

    static void _ShowUpdateUserScreen()
    {
        clsUpdateCurrency::ShowUpdateCurrencyScreen();
    }

    static void _CalculateCurrency()
    {
        clsClculateCurrency::showClaculateCurrency();
    }

    static void _PerformCurrencyMenueOption(enManageCurrencyMenueOptions ManageUsersMenueOption)
    {

        switch (ManageUsersMenueOption)
        {
        case enManageCurrencyMenueOptions::eListCurrency:
        {
            system("cls");
            _ShowCurrenciesList();
            _GoBackToCurrenciesMenue();
            break;
        }

        case enManageCurrencyMenueOptions::eFindCurrency:
        {
            system("cls");
            __ShowFindCurrency();
            _GoBackToCurrenciesMenue();
            break;


        case enManageCurrencyMenueOptions::eUpdateRate:
        {
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToCurrenciesMenue();
            break;
        }

        case enManageCurrencyMenueOptions::eCurrencyCalculator:
        {
            system("cls");
            _CalculateCurrency();
            _GoBackToCurrenciesMenue();
            break;
        }

        case enManageCurrencyMenueOptions::eMailMenu:
        {
            system("cls");
            _GoBackToCurrenciesMenue();
            break;
        }


        }

        }
    }

    public:
        static void ShowCurrencyScreen()
        {

            if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
            {
                return;// this will exit the function and it will not continue
            }

            system("cls");
            _DrawScreenHeader("\t Currency Screen");

            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t\t  Currency Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] List Currency.\n";
            cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
            cout << setw(37) << left << "" << "\t[3] Currency Rate.\n";
            cout << setw(37) << left << "" << "\t[4] Curreny Calu.\n";
            cout << setw(37) << left << "" << "\t[5] Back.\n";
            cout << setw(37) << left << "" << "===========================================\n";

            _PerformCurrencyMenueOption((enManageCurrencyMenueOptions)ReadCurrencyMenueOption());
        }

    };

