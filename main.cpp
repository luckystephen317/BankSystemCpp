#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

fstream file, ftemp;
int acctno, bal;
string acctname;
char accttype;

class Bank {
public:
	void Menu();
	void createAccount();
	void displayAccounts();
	void searchAccount();
	void makeWithdraw();
	void makeDeposit();
	
};

void Bank::Menu() {
	cout << "__________________________________" << endl;
	cout << "             Main Menu                " << endl;
	cout << "__________________________________" << endl;
	cout << "   1 : Create New Account." << endl;
	cout << "   2 : Dispaly All Accounts." << endl;
	cout << "   3 : Search For An Account." << endl;
	cout << "   4 : Make Deposit." << endl;
	cout << "   5 : Make Withdrawal." << endl;
	cout << "   6 : Exit." << endl;
	cout << "__________________________________" << endl;
}

void Bank::createAccount() {
	system("cls");
	cout << "__________________________________" << endl;
	cout << "       Add New Account." << endl;
	cout << "__________________________________" << endl;
	cout << "" << endl;
	cout << "Enter Account Number: ";
	cin >> acctno;
	cout << "Enter Account Name: ";
	cin >> acctname;
	cout << "Enter Account Type [C/S]: ";
	cin >> accttype;
	cout << "Enter Initial Account Balance: ";
	cin >> bal;
	file.open("database.txt", ios::out | ios::app);
	file << acctno << " " << acctname << " " << accttype << " " << bal << endl; 
	file.close();
}

void Bank::displayAccounts() {
	system("cls");
	cout << "__________________________________" << endl;
	cout << "       All Accounts." << endl;
	cout << "__________________________________" << endl;
	cout << "" << endl;
	file.open("database.txt", ios::in);
	if (!file)
	{
		cout << "Database Failed To Open!" << endl;
	} else {
		cout << "Account Name\t\tAccount Number\t\tAccount Type\t\tBalance" << endl;
		file >> acctno >> acctname >> accttype >> bal; 
		while(!file.eof()) {
			cout << acctno << "\t\t\t" << acctname << "\t\t\t" << accttype << "\t\t\tN" << bal << endl; 
			file >> acctno >> acctname >> accttype >> bal; 
		}
		system("pause");
		file.close();
	}
}

void Bank::searchAccount() {
	int acctno2, count(0);
	system("cls");
	cout << "__________________________________" << endl;
	cout << "       Search Account." << endl;
	cout << "__________________________________" << endl;
	cout << "" << endl;
	file.open("database.txt", ios::in);
	if (!file) {
		cout << "Database Failed To Open!" << endl;
	} else {
		cout << "Enter Account Number Of User: ";
		cin >> acctno2;
		file >> acctno >> acctname >> accttype >> bal; 
		while(!file.eof()) {
			if (acctno == acctno2) {
				cout << "Account Number: " << acctno << endl;
				cout << "Account Name: " << acctname << endl;
				cout << "Account Type: " << accttype << endl;
				cout << "Account Balance: " << bal << endl;
				count = 1;
				break;
			}
			file >> acctno >> acctname >> accttype >> bal; 
		}
		if (count == 0) {
			cout << "Record Not Found!" << endl;
		}
		system("pause");
		file.close();
	}
}

void Bank::makeWithdraw() {
	int acctno2, count(0), nbal, amt;
	string acctname2;
	char accttype2;
	system("cls");
	cout << "__________________________________" << endl;
	cout << "       Make Withdrawal." << endl;
	cout << "__________________________________" << endl;
	cout << "" << endl;
	file.open("database.txt", ios::in);
	ftemp.open("temp.txt", ios::out | ios::app);
	if (!file) {
		cout << "Database Failed To Open!" << endl;
	} else {
		cout << "Enter Account Number Of User: ";
		cin >> acctno2;
		file >> acctno >> acctname >> accttype >> bal; 
		while(!file.eof()) {
			if (acctno == acctno2) {
                //system("cls");
				cout << "Account Number: " << acctno << endl;
				cout << "Account Name: " << acctname << endl;
				cout << "Account Type: " << accttype << endl;
				cout << "Current Balance: N" << bal << endl;
				cout << "" << endl;
				cout << "Enter Amount to Withdraw: N";
				cin >> amt;
				if (amt > bal) {
					cout << "Insufficient Funds! Current Balance is N" << bal << endl;
					count = 1;
				} else {
					nbal = bal - amt;
					cout << "Funds Debited Successfully! Current Balance is N" << nbal << endl;
				}
				count = 1;
				ftemp << acctno2 << " " << acctname << " " << accttype << " " << nbal << endl; 
			} 
			else 
				ftemp << acctno << " " << acctname << " " << accttype << " " << bal << endl; 
				file >> acctno >> acctname >> accttype >> bal; 
				count = 1;
			
		} 
		if (count == 0) {
			cout << "Record Not Found!" << endl;
		}
	}
	system("pause");
	file.close();
	ftemp.close();
	remove("database.txt");
	rename("temp.txt", "database.txt");
}


void Bank::makeDeposit() {
	int acctno2, count(0), nbal, amt;
	string acctname2;
	char accttype2;
	system("cls");
	cout << "__________________________________" << endl;
	cout << "       Make Deposit." << endl;
	cout << "__________________________________" << endl;
	cout << "" << endl;
	file.open("database.txt", ios::in);
	ftemp.open("temp.txt", ios::out | ios::app);
	if (!file) {
		cout << "Database Failed To Open!" << endl;
	} else {
		cout << "Enter Account Number Of User: ";
		cin >> acctno2;
		file >> acctno >> acctname >> accttype >> bal; 
		while(!file.eof()) {
			if (acctno == acctno2) {
                //system("cls");
				cout << "Account Number: " << acctno << endl;
				cout << "Account Name: " << acctname << endl;
				cout << "Account Type: " << accttype << endl;
				cout << "Current Balance: N" << bal << endl;
				cout << "" << endl;
				cout << "Enter Amount to Withdraw: N";
				cin >> amt;
				if (amt <= 0) {
					cout << "Invalid Amount! Current Balance is N" << bal << endl;
					count = 1;
				} else {
					nbal = bal + amt;
					cout << "Funds Deposited Successfully! Current Balance is N" << nbal << endl;
				}
				count = 1;
				ftemp << acctno2 << " " << acctname << " " << accttype << " " << nbal << endl; 
			} 
			else 
				ftemp << acctno << " " << acctname << " " << accttype << " " << bal << endl; 
				file >> acctno >> acctname >> accttype >> bal; 
				count = 1;
			
		} 
		if (count == 0) {
			cout << "Record Not Found!" << endl;
		}
	}
	system("pause");
	file.close();
	ftemp.close();
	remove("database.txt");
	rename("temp.txt", "database.txt");
}



Bank bank;

int main() {
	system("color f0");
	int opt, recur(1);
	char x;
	while(recur) {
		system("cls");
		bank.Menu();
		cout << "Enter Option: ";
		cin >> opt;
		switch(opt) {
		case 1:
			do {
				bank.createAccount();
				cout << "" << endl;
				cout << "Add Another Account [y/n]:";
				cin >> x ;
			} while(x == 'y');
			break;
		case 2:
			bank.displayAccounts();
			break;
		case 3:
			bank.searchAccount();
			break;
		case 4:
			bank.makeDeposit();
			break;
		case 5:
			bank.makeWithdraw();
			break;
		case 6:
			cout << endl;
			return 0;
		default:
			cout << "Invalid Option Selected!" << endl;
			cout << endl;
		}
	}
	return 0;
}