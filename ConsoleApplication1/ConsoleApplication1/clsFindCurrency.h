#pragma once
#pragma once
#include"clsCurrency.h"
#include"clsShowScreen.h"
#include"clsString.h"
#include"clsInputValidate.h"


class clsFindCurrency :protected clsShowScreen
{
private:
	enum enCodOrCountry { Code = 1,Country=2 };
	static void _PrintCurrencyCard(clsCurrency &Currency)
	{
		// Print Print Country Card will be here
		
		cout << "" << "Currency Card\n";
		cout << "" << "===========================================\n";
		cout << "" << "Country :"<<Currency.Country();
		cout << "\n" << "Currency:"<<Currency.CurrencyCode();
		cout << "\n" << "Code    :"<<Currency.CurrencyName();
		cout << "\n" << "Rate    :"<<Currency.Rate();
		cout << "\n" << "===========================================\n";
	}

static	void _FindByCode()
	{
		string Code;
		cout << "Enter the code you want..?";
		Code = clsInputValidate::ReadString();
		
	    clsCurrency	Currency = clsCurrency::FindByCode(Code);
		
		if (Currency.IsEmpty())
		{
			cout << "\n not Found..?\n";
		}
		else
		{
			_PrintCurrencyCard(Currency);
		}

	}


static short _ReadChoice()
{
	short Choice;

	cout << "Enter [1] Code , [2] Country ..?";

	Choice = clsInputValidate::ReadShortNumber();

	return Choice;

}


	static void _FindByCountry()
	{
		string Country;
		cout << "Enter the Country you want..?";
		Country = clsInputValidate::ReadString();

		clsCurrency	Currency = clsCurrency::FindByCountry(Country);

		if (Currency.IsEmpty())
		{
			cout << "\nEnter the Country you want..?\n";
		}
		else
		{
			_PrintCurrencyCard(Currency);
		}
	}

	static void _ChoiseCodeOrCountry(enCodOrCountry Choice)
	{
		switch (Choice)
		{
		case clsFindCurrency::Code:
			_FindByCode();
			break;
		case clsFindCurrency::Country:
			_FindByCountry();
			break;
		default:
			break;
		}
		
	}

public :


	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\t Find Currency Screen");
		_ChoiseCodeOrCountry((enCodOrCountry)_ReadChoice());
		
	}

};

