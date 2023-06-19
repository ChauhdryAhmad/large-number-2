#pragma once

#pragma once
#include<iostream>
#include<fstream>
using namespace std;


class HugeIntegers
{
private:
	int size;
	int* ds;
	bool isNeg;
	void assign(const HugeIntegers&);
	static void insertAtEnd(int*& Vs, int& size, int n);
	static void extractFromEnd(HugeIntegers&);
	const HugeIntegers ADDQuantityWise(const HugeIntegers&)const;
	const HugeIntegers SUBQuantityWise(const HugeIntegers&)const;
	bool LessThanQuantityWise(const HugeIntegers&)const;
	bool GreaterThanQuantityWise(const HugeIntegers&)const;
	bool EqualQuantityWise(const HugeIntegers&)const;
	static void trim(HugeIntegers&);
	static HugeIntegers zero();
	static HugeIntegers one();
public:
	~HugeIntegers();
	HugeIntegers();
	HugeIntegers(int n);
	HugeIntegers(HugeIntegers&);
	HugeIntegers(ifstream& rdr);
	void loadInteger(ifstream& rdr);
	void inputInteger();
	int& operator[](int i);
	int operator[](int i)const;

	const HugeIntegers& operator=(const HugeIntegers&);
	friend ostream& operator<<(ostream&, const HugeIntegers&);
	friend istream& operator>>(istream&, HugeIntegers&);
	friend ifstream& operator>>(ifstream&, HugeIntegers&);
	friend ofstream& operator<<(ofstream&, const HugeIntegers&);

	HugeIntegers operator-();
	HugeIntegers operator+(const HugeIntegers&)const;
	HugeIntegers operator+=(const HugeIntegers&);
	HugeIntegers operator-(HugeIntegers&)const;
	HugeIntegers operator-=(HugeIntegers&);


	HugeIntegers operator++();
	HugeIntegers operator--();
	HugeIntegers operator++(int d);
	HugeIntegers operator--(int d);

	bool operator==(const HugeIntegers&)const;
	bool operator>(const HugeIntegers&)const;
	bool operator>=(const HugeIntegers&)const;
	bool operator<(const HugeIntegers&)const;
	bool operator<=(const HugeIntegers&)const;
	bool operator!=(const HugeIntegers&)const;


	HugeIntegers& operator*(const HugeIntegers&)const;
	HugeIntegers operator*=(const HugeIntegers&);
	HugeIntegers operator/(HugeIntegers)const;
	HugeIntegers operator/=(HugeIntegers);
	HugeIntegers operator%(HugeIntegers)const;
	HugeIntegers operator%=(HugeIntegers);




};


