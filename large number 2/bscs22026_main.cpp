#include<iostream>
#include<fstream>
#include<string>
#include"bscs22026_HugeIntegers.h"
using namespace std;


//-------------------------  Load and Print 2nd Function -----------------------------------------


//void loadAllNumbers(HugeIntegers**& AllNum, int& size, string fname)
//{
//	ifstream rdr(fname);
//	rdr >> size;
//	AllNum = new HugeIntegers * [size];
//	for (int i = 0; i < size; i++)
//	{
//		while (rdr.peek() == '\n' || rdr.peek() == ' ')
//			rdr.ignore();
//		AllNum[i] = new HugeIntegers(rdr);
//	}
//}
//
//void printAllNumbers(HugeIntegers** AllNum, int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		cout << AllNum[i];
//		cout << endl;
//	}
//}

//----------------------------------------------------------------------------------------------




void loadAllNumbers(HugeIntegers*& AllNum, int& size, string fname)
{
	ifstream rdr(fname);
	rdr >> size;
	AllNum = new HugeIntegers[size];
	for (int i = 0; i < size; i++)
	{
		while (rdr.peek() == '\n' || rdr.peek() == ' ')
			rdr.ignore();
		AllNum[i].loadInteger(rdr);
	}
}

void inputAllNumbers(HugeIntegers*& AllNum, int& size)
{
	cout << "\nHow many Numbers you want to use : ";
	cin >> size;
	AllNum = new HugeIntegers[size];
	for (int i = 0; i < size; i++)
	{
		cout << "\nEnter N" << i + 1 << endl;

		while (cin.peek() == '\n' || cin.peek() == ' ')
			cin.ignore();
		AllNum[i].inputInteger();
	}
}

void printAllNumbers(HugeIntegers* AllNum, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "N" << i + 1 << " : ";
		cout << AllNum[i];
		cout << endl;
	}
}






int main()
{
	
	HugeIntegers* AllNum{}, R;
	int size = 0 , n, o, n1, n2;
	cout << "1- Load from file\n2- Input\n";
	cin >> n;
	switch (n)
	{
	case 1:
		loadAllNumbers(AllNum, size, "bscs22026_input.txt");
		break;
	case 2:
		inputAllNumbers(AllNum, size);
		break;
	}
	
	cout << "Numbers Are :\n";
	printAllNumbers(AllNum, size);
	while (true)
	{
		cout << "\n\nPress 0 to End\nPress 1 to continue\n";
		cin >> n;
		if (n == 0)
		{
			break;
		}
		system("cls");
		cout << "Numbers Are :\n";
		printAllNumbers(AllNum, size);
		cout << "\nWhich operation you want to run :\n1- +\n2- -\n3- *\n4- /\n5- %\n6- +=\n7- -=\n8- *=\n9- /=\n10- %=\n11- -(Negation)\n12- ++(Pre Increment)\n13- --(Pre Decrement)\n14- ++(Post Increment)\n15- --(Post Deccrement)\n16- <\n17- <=\n18- >\n19- >=\n20- ==\n21- !=\n";
		cin >> o;
		system("cls");
		cout << "Numbers Are :\n";
		printAllNumbers(AllNum, size);
		if (o >= 11 && o <= 15)
		{
			cout << "\nIt is a unary operator\nSo we shall get one number\nEnter Second number " << 1 << '-' << size << " : ";
			cin >> n1;
		}
		else
		{
			cout << "\nEnter First number " << 1 << '-' << size << " : ";
			cin >> n1;
			cout << "\nEnter Second number " << 1 << '-' << size << " : ";
			cin >> n2;
		}
		
		switch (o)
		{
		case 1:
			R = AllNum[n1 - 1] + AllNum[n2 - 1];
			cout << "\nR = n" << n1 << " + n" << n2;
			cout << "\nR = " << R;
			break;
		case 2:
			R = AllNum[n1 - 1] - AllNum[n2 - 1];
			cout << "\nR = n" << n1 << " - n" << n2;
			cout << "\nR = " << R;
			break;
		case 3:
			R = AllNum[n1 - 1] * AllNum[n2 - 1];
			cout << "\nR = n" << n1 << " * n" << n2;

			cout << "\nR = " << R;
			break;
		case 4:
			R = AllNum[n1 - 1] / AllNum[n2 - 1];
			cout << "\nR = n" << n1 << " / n" << n2;
			cout << "\nR = " << R;
			break;
		case 5:
			R = AllNum[n1 - 1] % AllNum[n2 - 1];
			cout << "\nR = n" << n1 << " % n" << n2;
			cout << "\nR = " << R;
			break;
		case 6:
			AllNum[n1 - 1] += AllNum[n2 - 1];
			cout << "\nn" << n1 << " += n" << n2;
			cout << "\nn" << n1 << " = " << AllNum[n1 - 1];
			break;
		case 7:
			AllNum[n1 - 1] -= AllNum[n2 - 1];
			cout << "\nn" << n1 << " -= n" << n2;
			cout << "\nn" << n1 << " = " << AllNum[n1 - 1];
			break;
		case 8:
			AllNum[n1 - 1] *= AllNum[n2 - 1];
			cout << "\nn" << n1 << " *= n" << n2;
			cout << "\nn" << n1 << " = " << AllNum[n1 - 1];
			break;
		case 9:
			AllNum[n1 - 1] /= AllNum[n2 - 1];
			cout << "\nn" << n1 << " /= n" << n2;
			cout << "\nn" << n1 << " = " << AllNum[n1 - 1];
			break;
		case 10:
			AllNum[n1 - 1] %= AllNum[n2 - 1];
			cout << "\nn" << n1 << " %= n" << n2;
			cout << "\nn" << n1 << " = " << AllNum[n1 - 1];
			break;
		case 11:
			R = -AllNum[n1 - 1];
			cout << "\nR = -n" << n1;
			cout << "\nR = " << R;
			break;
		case 12:
			R = ++AllNum[n1 - 1];
			cout << "\nR = ++n" << n1;
			cout << "\nR = " << R;
			break;
		case 13:
			R = --AllNum[n1 - 1];
			cout << "\nR = --n" << n1;
			cout << "\nR = " << R;
			break;
		case 14:
			R = AllNum[n1 - 1]++;
			cout << "\nR = n++" << n1;
			cout << "\nR = " << R;
			break;
		case 15:
			R = AllNum[n1 - 1]--;
			cout << "\nR = n--" << n1;
			cout << "\nR = " << R;
			break;
		case 16:
			cout << "\nn" << n1 << " < n" << n2;
			if (AllNum[n1 - 1] < AllNum[n2 - 1])
			{
				cout << "\nn" << n1 << " is smaller then n" << n2;
			}
			else
				cout << "\nn" << n1 << " is not smaller then n" << n2;
			break;
		case 17:
			cout << "\nn" << n1 << " <= n" << n2;
			if (AllNum[n1 - 1] <= AllNum[n2 - 1])
			{
				cout << "\nn" << n1 << " is smaller then and equal to n" << n2;
			}
			else
				cout << "\nn" << n1 << " is not smaller then and equal to n" << n2;
			break;
		case 18:
			cout << "\nn" << n1 << " > n" << n2;
			if (AllNum[n1 - 1] > AllNum[n2 - 1])
			{
				cout << "\nn" << n1 << " is greater then n" << n2;
			}
			else
				cout << "\nn" << n1 << " is not smaller then n" << n2;
			break;
		case 19:
			cout << "\nn" << n1 << " >= n" << n2;
			if (AllNum[n1 - 1] >= AllNum[n2 - 1])
			{
				cout << "\nn" << n1 << " is greater then and equal to n" << n2;
			}
			else
				cout << "\nn" << n1 << " is not greater then and equal to n" << n2;
			break;
		case 20:
			cout << "\nn" << n1 << " == n" << n2;
			if (AllNum[n1 - 1] == AllNum[n2 - 1])
			{
				cout << "\nn" << n1 << " is equal to n" << n2;
			}
			else
				cout << "\nn" << n1 << " is not equal to n" << n2;
			break;
		case 21:
			cout << "\nn" << n1 << " != n" << n2;
			if (AllNum[n1 - 1] != AllNum[n2 - 1])
			{
				cout << "\nn" << n1 << " is not equal to n" << n2;
			}
			else
				cout << "\nn" << n1 << " is equal to n" << n2;
			break;
		}
	}

}