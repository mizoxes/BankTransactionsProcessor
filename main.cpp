#include "MizoWindow.h"
#include "MizoBitmap.h"
#include "MizoException.h"

#include "AccountManager.h"
#include "TransactionManager.h"
#include "Deposit.h"
#include "Withdraw.h"
#include "Transfer.h"

#include <string>

using namespace std;
using namespace MizoUI;

#define WINDOW_WIDTH  400
#define WINDOW_HEIGHT 500

MizoWindow window("C++ Project", WINDOW_WIDTH, WINDOW_HEIGHT);
Account				 localAccount;
AccountManager		 accountManager;
TransactionManager 	 transactionManager;
MizoBitmap*			 login_logo;
MizoBitmap*			 ensah_logo;
string				 username;
string				 password;
string				 amount;
string				 receiverID;
string				 error;
int					 pageindex = 0;
bool				 updateTransactions = true;
vector<Transaction*> transactions;

bool IsNumber(const string& str)
{
    for (char const &c : str) {
        if (isdigit(c) == 0) return false;
    }
    return true;
}

void PAGE_Credits()
{
	window.Text(160, 50, "CREDITS", 0, 255, 0);
	window.Bitmap(125, 100, ensah_logo);
	window.Text(125, 250, "Hamza EL KAICHE", 255, 255, 255);
	window.Text(125, 300, "Dounia EZ-ZAHRI", 255, 255, 255);
	window.Text(125, 350, "Abdelghani ENNOUKRA", 255, 255, 255);
	window.Text(125, 400, "Imane GALLAB", 255, 255, 255);
	if (window.Button(125, 450, "    Back to Login", 0x5e, 0x34, 0x99, 255, 255, 255, 150))
	{
		pageindex = 0;
		//error = "";
	}
}

void PAGE_Login()
{
	window.Text(180, 50, "LOGIN", 0, 255, 0);
	window.Bitmap(85, 75, login_logo);

	window.Text(100, 282, "Username", 255, 255, 255);
	window.TextInput(175, 280, 150, username, 150, 150, 150);
	window.Text(100, 317, "Password", 255, 255, 255);
	
	window.TextInput(175, 315, 150, password, 150, 150, 150);
	if (window.Button(100, 350, "                 Login", 0x5e, 0x34, 0x99, 255, 255, 255, 225))
	{
		if (accountManager.LoadAccount(username, password, localAccount)) {
			error = "";
			pageindex = 1;
		}
		else {
			error = "Invalid username or password";
		}
	}

	window.Text(110, 400, error.c_str(), 255, 50, 50);

	if (window.Button(125, 450, "        Credits", 0x5e, 0x34, 0x99, 255, 255, 255, 150))
	{
		pageindex = 6;
	}
}

void PAGE_Menu()
{
	window.Text(50, 50, "Username:", 255, 255, 255);
	window.Text(140, 50, localAccount.GetUsername().c_str(), 40, 255, 40);
	window.Text(50, 80, "Money:", 255, 255, 255);
	window.Text(140, 80, (to_string(localAccount.GetMoney()) + " MAD").c_str(), 40, 255, 40);

	window.HorizentalLine(50, 120, 300, 180, 180, 180);

	if (window.Button(125, 150, "        Deposit", 0x5e, 0x34, 0x99, 255, 255, 255, 150))
	{
		pageindex = 2;
	}
	if (window.Button(125, 200, "       Withdraw", 0x5e, 0x34, 0x99, 255, 255, 255, 150))
	{
		pageindex = 3;
	}
	if (window.Button(125, 250, "        Transfer", 0x5e, 0x34, 0x99, 255, 255, 255, 150))
	{
		pageindex = 4;
	}
	if (window.Button(125, 300, "     Transactions", 20, 20, 150, 255, 255, 255, 150))
	{
		transactionManager.DestroyTransactions(transactions);
		transactions = transactionManager.GetAccountTransactionsByID(localAccount.GetID());
		updateTransactions = false;
		pageindex = 5;
	}

	if (window.Button(125, 450, "        Logout", 255, 100, 100, 255, 255, 255, 150))
	{
		pageindex = 0;
	}
}

void PAGE_Deposit()
{
	window.Text(170, 50, "DEPOSIT", 0, 255, 0);

	window.Text(100, 100, "How much do you want to deposit?", 255, 255, 255);
	//g_WindowHandle->Text(50, 155, "Amount", 255, 255, 255);
	window.TextInput(130, 150, 150, amount, 150, 150, 150);
	if (window.Button(130, 190, "        Deposit", 0x5e, 0x34, 0x99, 255, 255, 255, 150))
	{
		if (IsNumber(amount)) {
			int money = atoi(amount.c_str());
			localAccount.Deposit(money);
			
			window.Alert(amount + " MAD has been added to your account!");
			
			accountManager.SaveAccount(localAccount);
			transactionManager.SaveTransaction(Deposit(localAccount.GetID(), Date(), money));

			pageindex = 1;
			amount = "";
			error = "";
		}
		else {
			error = "Please enter a valid number";
		}
	}

	window.Text(75, 220, error.c_str(), 255, 40, 40);

	if (window.Button(125, 450, "        Cancel", 255, 100, 100, 255, 255, 255, 150))
	{
		pageindex = 1;
		error = "";
		amount = "";
	}
}

void PAGE_Withdraw()
{
	window.Text(170, 50, "WITHDRAW", 0, 255, 0);

	window.Text(100, 100, "How much do you want to withdraw?", 255, 255, 255);
	window.TextInput(130, 150, 150, amount, 150, 150, 150);
	if (window.Button(130, 190, "       Withdraw", 0x5e, 0x34, 0x99, 255, 255, 255, 150))
	{
		if (IsNumber(amount)) {
			int money = atoi(amount.c_str());
			if (money <= localAccount.GetMoney()) {
				localAccount.Withdraw(money);
			
				window.Alert(amount + " MAD has been withdrawn from your account!");
				
				accountManager.SaveAccount(localAccount);
				transactionManager.SaveTransaction(Withdraw(localAccount.GetID(), Date(), money));
	
				pageindex = 1;
				amount = "";
				error = "";
			}
			else {
				error = "You don't have that much";
			}
		}
		else {
			error = "Please enter a valid number";
		}
	}

	window.Text(75, 220, error.c_str(), 255, 40, 40);

	if (window.Button(125, 450, "        Cancel", 255, 100, 100, 255, 255, 255, 150))
	{
		pageindex = 1;
		error = "";
		amount = "";
	}
}

void PAGE_Transfer()
{
	window.Text(170, 50, "TRANSFER", 0, 255, 0);

	window.Text(100, 100, "How much do you want to transfer?", 255, 255, 255);
	window.TextInput(130, 130, 150, amount, 150, 150, 150);
	window.Text(75, 180, "To whom you want to tranfer this money?", 255, 255, 255);
	window.TextInput(130, 210, 150, receiverID, 150, 150, 150);
	if (window.Button(130, 270, "       Transfer", 0x5e, 0x34, 0x99, 255, 255, 255, 150))
	{
		if (IsNumber(amount) && IsNumber(receiverID)) {
			Account receiverAccount;
			if (accountManager.GetAccountByID(atoi(receiverID.c_str()), receiverAccount)) {
				int money = atoi(amount.c_str());
				if (money <= localAccount.GetMoney()) {
					localAccount.Withdraw(money);
					receiverAccount.Deposit(money);
					
					window.Alert(amount + " MAD has been transfered to account " + receiverID);
					
					accountManager.SaveAccount(localAccount);
					accountManager.SaveAccount(receiverAccount);
					transactionManager.SaveTransaction(Transfer(localAccount.GetID(), Date(), money, atoi(receiverID.c_str())));
	
					pageindex = 1;
					amount = "";
					receiverID = "";
					error = "";
				}
				else {
					error = "You don't have that much";
				}
			}
			else {
				error = "Account " + receiverID + " does not exist";
			}
		}
		else {
			error = "Please enter a valid number";
		}
	}

	window.Text(100, 320, error.c_str(), 255, 40, 40);

	if (window.Button(125, 450, "        Cancel", 255, 100, 100, 255, 255, 255, 150))
	{
		pageindex = 1;
		error = "";
		amount = "";
		receiverID = "";
	}
}

void PAGE_Transactions()
{
	window.Text(170, 50, "TRANSACTIONS", 0, 255, 0);
	int y = 100;

	window.Text(20, y, "type", 255, 255, 255);
	window.Text(140, y, "date", 255, 255, 255);
	window.Text(210, y, "amount", 255, 255, 255);
	window.Text(300, y, "receiverID", 255, 255, 255);
	window.HorizentalLine(20, y + 30, 350, 200, 200, 200);
	y += 50;

	for (auto transaction : transactions) {
		window.Text(20, y, Transaction::ToString(transaction->GetType()).c_str(), 255, 255, 255);
		window.Text(120, y, transaction->GetDate().ToString().c_str(), 255, 255, 255);
		window.Text(210, y, to_string(transaction->GetAmount()).c_str(), 255, 255, 255);
		if (transaction->GetType() == TransactionType::TRANSFER) {
			window.Text(300, y, to_string(((Transfer *)transaction)->GetReceiverID()).c_str(), 255, 255, 255);
		}
		else {
			window.HorizentalLine(300, y + 10, 70, 200, 200, 200);
		}
		y += 30;
	}
	
	if (window.Button(125, 450, "          Back", 0x5e, 0x34, 0x99, 255 , 255, 255, 150))
	{
		pageindex = 1;
	}
}

void Callback()
{
	switch (pageindex)
	{
	case 0:
		PAGE_Login();
		break;

	case 1:
		PAGE_Menu();
		break;

	case 2:
		PAGE_Deposit();
		break;

	case 3:	
		PAGE_Withdraw();
		break;

	case 4:
		PAGE_Transfer();
		break;

	case 5:
		PAGE_Transactions();
		break;

	case 6:
		PAGE_Credits();
		break;
	}
}

int main()
{
	login_logo = LoadBmp("res/login.bmp");
	ensah_logo = LoadBmp("res/ensah.bmp");
	window.SetBackgroundColor(90, 90, 90);

	window.SetCallback(Callback);
	window.Run();

	FreeBmp(login_logo);
	FreeBmp(ensah_logo);

	return 0;
}
