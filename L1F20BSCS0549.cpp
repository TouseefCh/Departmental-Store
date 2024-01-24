#include<iostream>
#include<string>
using namespace std;

int main()
{
	int noOfshelfs = 0, positions = 0;
	cout << "Enter the number of shelf: ";
	cin >> noOfshelfs;
	cout << "Enter the number of positions in each shelf: ";
	cin >> positions;
	int option = -1;
	string **shelf = new string*[noOfshelfs];
	for (int i = 0; i < noOfshelfs; i++)
	{
		shelf[i] = new string[positions];
	}
	for (int i = 0; i < noOfshelfs; i++) {
		for (int j = 0; j < positions; j++) {
			shelf[i][j] = "*";
		}
	}
	while (option != 0) {
		cout << "\n\n\n 1: Insert an things" << endl;
		cout << " 2: Displaying all items" << endl;
		cout << " 3: Remove an item" << endl;
		cout << " 4: Remove all items" << endl;
		cout << " 5: Return total no of items" << endl;
		cout << " 6: find an item" << endl;
		cout << " 7: Update the item" << endl;
		cout << " 8: Check if the shell is empty" << endl;
		cout << " 9: Check if the shell is full" << endl;
		cout << " 0: Quit" << endl;
		cout << " Enter Choice : ";
		cin >> option;
		if (option == 1)
		{
			int shelfs, position;
			string things;
			cout << "Enter the shelf : ";
			cin >> shelfs;
			cout << "Enter the position : " ;
			cin >> position;
			cout << "Enter item: ";
			cin >> things;
			shelfs = shelfs - 1;
			position = position - 1;
			if (shelf[shelfs][position] == "*")
			{
				shelf[shelfs][position] = things;
				cout << "Added succesfully!";
			}
			else
			{
				bool done = true;
				for (int i = 0; i < positions; i++)
				{
					if (shelf[shelfs][i] == "*")
					{
						shelf[shelfs][i] = things;
						cout << "Added succesfully!";
						done = false;
						break;
					}
				}
				if (done == true)
				{
					cout << " There is no empty location on given shelf" << endl;
				}
			}
		}

		else if (option == 2)
		{
			for (int i = 0; i < noOfshelfs; i++)
			{
				cout << "Shelf: " << i + 1 << "-> ";
				for (int j = 0; j < positions; j++)
				{
					if (shelf[i][j] != "*")
						cout << shelf[i][j] << " ";
				}
				cout << "\n";
			}
		}
		else if (option == 3)
		{
			int shelfs, position;
			string things;
			cout << "Enter shelf : ";
			cin >> shelfs;
			cout << "Enter position : ";
			cin >> position;
			shelfs = shelfs - 1;
			position = position - 1;

			shelf[shelfs][position] = "*";
			cout << "Item deleted!" << endl;
		}

		else if (option == 4)
		{
			for (int i = 0; i < noOfshelfs; i++)
			{
				for (int j = 0; j < positions; j++)
				{
					shelf[i][j] = "*";
				}
			}
			cout << "All items removed from each shell" << endl;

		}
		else if (option == 5)
		{
			int count = 0;
			for (int i = 0; i < noOfshelfs; i++)
			{
				for (int j = 0; j < positions; j++)
				{
					if (shelf[i][j] != "*")
					{
						count++;
					}
				}
			}
			cout << "Total no of items are: " << count;
		}

		else if (option == 6)
		{
			string things;
			cout << "Enter item : " ;
			cin >> things;
			for (int i = 0; i < noOfshelfs; i++)
			{
				for (int j = 0; j < positions; j++)
				{
					if (shelf[i][j] == things)
					{
						cout << "Item found at \t shelf : " << i + 1 <<"\t"<< " Position : " << j + 1 << endl;
					}
				}
			}
		}

		else if (option == 7)
		{
			int shelfs, position;
			string things;
			cout << "Enter the shelf : ";
			cin >> shelfs;
			if (shelfs > noOfshelfs)
			{
				cout << "Error! Shelf not found!" << endl;
			}
			else
			{
				cout << "Enter the position : ";
				cin >> position;
				cout << "Enter item to replace with: ";
				cin >> things;
				shelfs = shelfs - 1;
				position = position - 1;
				shelf[shelfs][position] = things;
				cout << "Updated successfully!" << endl;
			}
		}

		else if (option == 8)
		{
			int shelfs;
			cout << "Enter shelf no" << endl;
			cin >> shelfs;
			shelfs = shelfs - 1;

			bool done = true;
			for (int i = 0; i<positions; i++)
			{
				if (shelf[shelfs][i] != "*")
				{
					cout << "Shelf is not empty!" << endl;
					done = false;
					break;
				}
			}
			if (done == true)
			{
				cout << "Shelf is empty!" << endl;
			}
		}
		else if (option == 9)
		{
			int shelfs;
			cout << "Enter shelf : ";
			cin >> shelfs;
			shelfs = shelfs - 1;
			bool done = true;
			for (int i = 0; i<positions; i++)
			{
				if (shelf[shelfs][i] == "*")
				{
					cout << "Shelf is not full!" << endl;
					done = false;
					break;
				}
			}
			if (done == true)
			{
				cout << "Shelf is full!" << endl;
			}

		}
	}
	return 0;
}