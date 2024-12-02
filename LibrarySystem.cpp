#include <iostream>
using namespace std;

struct stBooks
{
	string BookName;
	int BookId = 0;
	int quantity = 0;
	int ManyBorrowTime = 0;
};

struct stUser
{
	string UserName;
	string BorrowBook = "none";
	bool isBorrow;
	int UserId = 0;
};

struct stLibSys
{
	stBooks Books[50];
	stUser Users[50];
	int BookLength = 0;
	int UserLength = 0;
};

stBooks GetBookInfo()
{
	stBooks Book;
	cout << "\nEnter Book Id: ";
	cin >> Book.BookId;
	cout << "Enter Book Name: ";
	cin >> Book.BookName;
	cout << "Enter Book Quantity: ";
	cin >> Book.quantity;
	cout << endl;
	return Book;
}

stUser GetUserInfo()
{
	stUser User;
	cout << "\nEnter User Name: ";
	cin >> User.UserName;
	cout << "Enter User Id: ";
	cin >> User.UserId;
	cout << endl;
	return User;
}

void addBooks(stLibSys& LibSys)
{
	LibSys.Books[LibSys.BookLength] = GetBookInfo();
	LibSys.BookLength++;
}

void addUsers(stLibSys& LibSys)
{
	LibSys.Users[LibSys.UserLength] = GetUserInfo();
	LibSys.UserLength++;
}

void PrintBooks(stLibSys libSys)
{
	for (int i = 0; i < libSys.BookLength; i++)
	{
		cout << "\nBook Id : " << libSys.Books[i].BookId << " // Book Name: " << libSys.Books[i].BookName << endl;
		cout << "Book Quantity: " << libSys.Books[i].quantity << " // Borrow Times: " << libSys.Books[i].ManyBorrowTime << endl;
		cout << "________________________________________\n";
	}
}

void PrintUsers(stLibSys libSys)
{
	for (int i = 0; i < libSys.UserLength; i++)
	{
		cout << "\nUser Name: " << libSys.Users[i].UserName << " // User Id: " << libSys.Users[i].UserId << " // Borrowed Book: " << libSys.Users[i].BorrowBook << endl;
		cout << "________________________________________\n";
	}
}

void PrintWhoBorrowed(stLibSys LibSys)
{
	for (int i = 0; i < LibSys.UserLength; i++)
	{
		if (LibSys.Users[i].isBorrow == 1)
		{
			cout << endl;
			cout << LibSys.Users[i].UserName << endl;
			cout << "_______________\n";
		}
	}
}

void BorrowBook(stLibSys& LibSys)
{
	string userName, bookName;
	cout << "\nEnter User Name: ";
	cin >> userName;
	cout << "Enter Book Name: ";
	cin >> bookName;

	for (int i = 0; i < LibSys.UserLength; i++)
	{
		if (LibSys.Users[i].UserName == userName)
		{
			LibSys.Users[i].BorrowBook = bookName;
			LibSys.Users[i].isBorrow = 1;
		}
	}

	for (int j = 0; j < LibSys.BookLength; j++)
	{
		if (LibSys.Books[j].BookName == bookName)
		{
			LibSys.Books[j].ManyBorrowTime++;
		}
	}
}

void ReturnBook(stLibSys& LibSys)
{
	string userName, bookName;
	cout << "\nEnter User Name: ";
	cin >> userName;
	cout << "Enter Book Name: ";
	cin >> bookName;

	for (int i = 0; i < LibSys.UserLength; i++)
	{
		if (LibSys.Users[i].UserName == userName)
		{
			LibSys.Users[i].BorrowBook = "none";
			LibSys.Users[i].isBorrow = 0;
		}
	}

	for (int j = 0; j < LibSys.BookLength; j++)
	{
		if (LibSys.Books[j].BookName == bookName)
		{
			LibSys.Books[j].ManyBorrowTime--;
		}
	}
}

void BookPrefix(stLibSys LibSys)
{
	string Prefix = "";
	string UserPrefix;

	cout << "\nEnter Book Prefix: ";
	cin >> UserPrefix;

	for (int i = 0; i < LibSys.BookLength; i++)
	{
		Prefix = Prefix + LibSys.Books[i].BookName[0];
		Prefix = Prefix + LibSys.Books[i].BookName[1];
		
		if (Prefix == UserPrefix)
		{
			cout << LibSys.Books[i].BookName << endl;
			cout << "__________\n";
		}

		Prefix = "";
	}
}

void DisplaySelectScreen()
{
	int Choice;
	stLibSys LibSys;

	do
	{
		cout << "Library Menu:" << endl;
		cout << "1]  Add Book" << endl;
		cout << "2]  Search Book By Prefix" << endl;
		cout << "3]  Print Who Borrowed Book By Name" << endl;
		cout << "4]  Print Library By Id" << endl;
		cout << "5]  Print Library By Name" << endl;
		cout << "6]  Add User" << endl;
		cout << "7]  User Borrow Book" << endl;
		cout << "8]  User Return Book" << endl;
		cout << "9]  Print Users" << endl;
		cout << "10] Exit" << endl;
		cout << "\n\n";
		cout << "Enter Your Menu Choice [1 - 10]: " << endl;

		cin >> Choice;

		switch (Choice)
		{
		case 1:
			addBooks(LibSys);
			break;
		case 2:
			BookPrefix(LibSys);
			break;
		case 3:
			PrintWhoBorrowed(LibSys);
			break;
		case 4:
			PrintBooks(LibSys);
			break;
		case 5:
			PrintBooks(LibSys);
			break;
		case 6:
			addUsers(LibSys);
			break;
		case 7:
			BorrowBook(LibSys);
			break;
		case 8:
			ReturnBook(LibSys);
			break;
		case 9:
			PrintUsers(LibSys);
			break;
		}


	} while (Choice != 10);
	
}




int main()
{
	DisplaySelectScreen();
	return 0;
}