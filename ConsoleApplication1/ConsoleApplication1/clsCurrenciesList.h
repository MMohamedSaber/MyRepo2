#pragma once
#include"clsCurrency.h"
#include"clsShowScreen.h"





class clsCurrenciesList :protected clsShowScreen
{
private:


    static void PrintUserRegesterRecordLine(clsCurrency Currency)
    {

        cout << setw(8) << left << "" << "| " << setw(35) << Currency.Country();
        cout << "| " << setw(10) << left << Currency.CurrencyCode();
        cout << "| " << setw(37) << left << Currency.CurrencyName();
        cout << "| " << setw(20) << left << to_string(Currency.Rate());

    }


public:


    static void ShowCurrecylistScreen()
    {
        vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();
        string Title = "\t  Currencies Screen";
        string SubTitle = "\t    (" + to_string(vCurrencies.size()) + ") Currensies(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t______________________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Country ";
        cout << "| " << left << setw(10) << "Code";
        cout << "| " << left << setw(37) << "Name";
        cout << "| " << left << setw(20) << "Rate";
        cout << setw(8) << left << "" << "\n\t______________________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vCurrencies.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsCurrency Transfer : vCurrencies)
            {

                PrintUserRegesterRecordLine(Transfer);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t______________________________________________________________";
        cout << "_________________________________________\n" << endl;

    }



};

