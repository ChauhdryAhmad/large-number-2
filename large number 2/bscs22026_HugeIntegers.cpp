#include"bscs22026_HugeIntegers.h"

#include<string>

void HugeIntegers::assign(const HugeIntegers& H)
{
	this->ds = new int[H.size];
	for (int i = 0; i < H.size; i++)
	{
		this->ds[i] = H.ds[i];
	}
	this->isNeg = H.isNeg;
	this->size = H.size;
}

HugeIntegers::HugeIntegers()
{
	size = 0;
	ds = nullptr;
	isNeg = false;
}

HugeIntegers::HugeIntegers(int n)
{
	size = n;
	ds = new int[size] {};
	isNeg = false;
}

HugeIntegers::HugeIntegers(HugeIntegers& H)
{
	this->assign(H);
}

void HugeIntegers::insertAtEnd(int*& Vs, int& size, int n)
{
	HugeIntegers Hp(size + 1);
	for (int i = 0; i < size; i++)
	{
		Hp.ds[i] = Vs[i];
	}
	Hp.ds[size] = n;
	size++;
	delete[]Vs;
	Vs = Hp.ds;
}

void HugeIntegers::loadInteger(ifstream& rdr)
{
	/*char sym;
	sym = rdr.peek();
	if (sym == '-')
	{
		this->isNeg = true;
		rdr.ignore();
	}
	else
	{
		this->isNeg = false;
	}
	string line;
	getline(rdr, line);
	this->size = line.size();
	this->ds = new int[size];
	for (int i = 0; i < size; i++)
	{
		this->ds[size - 1 - i] = line[i] - '0';
	}*/

	rdr >> *this;



	/*char sym;
	sym = rdr.peek();
	if (sym == '-')
	{
		isNeg = true;
		rdr.ignore();
	}
	else
	{
		isNeg = false;
	}
	rdr.get(sym);
	while (rdr && sym != '\n')
	{
		int n = sym - '0';
		insertAtEnd(ds, size, n);
		rdr.get(sym);
	}*/
}

void HugeIntegers::inputInteger()
{
	cin >> *this;
}

HugeIntegers::HugeIntegers(ifstream& rdr)
{
	this->loadInteger(rdr);
}

HugeIntegers HugeIntegers::zero()
{
	HugeIntegers R(1);
	R[0] = 0;
	return R;
}

HugeIntegers HugeIntegers::one()
{
	HugeIntegers R(1);
	R[0] = 1;
	return R;
}

const HugeIntegers HugeIntegers::ADDQuantityWise(const HugeIntegers& H)const
{

	HugeIntegers R(size + 1);
	int carry = 0, ans = 0;
	for (int i = 0; i < R.size; i++)
	{
		ans = ((*this)[i] + H[i] + carry) % 10;
		carry = ((*this)[i] + H[i] + carry) / 10;
		R[i] = ans;
	}
	trim(R);
	return R;
}

const HugeIntegers HugeIntegers::SUBQuantityWise(const HugeIntegers& H)const
{
	HugeIntegers R(size);
	int carry = 0, ans = 0;
	for (int i = 0; i < R.size; i++)
	{
		(*this).ds[i] -= carry;
		if ((*this)[i] < H[i])
		{
			carry = 1;
			ans = (10 + (*this)[i]) - H[i];
		}
		else
		{
			ans = (*this)[i] - H[i];
			carry = 0;
		}
		R[i] = ans;
	}
	trim(R);
	if (R.size == 0)
	{
		R = this->zero();
	}
	return R;
}

bool HugeIntegers::LessThanQuantityWise(const HugeIntegers& H)const
{
	if (size > H.size)
		return false;
	if (size < H.size)
		return true;
	for (int i = size - 1; i >= 0; i--)
	{
		if ((*this)[i] > H[i])
			return false;
		if ((*this)[i] < H[i])
			return true;
	}
	return false;
}

bool HugeIntegers::GreaterThanQuantityWise(const HugeIntegers& H)const
{
	if (H.LessThanQuantityWise(*this))
		return true;
	return false;
}

bool HugeIntegers::EqualQuantityWise(const HugeIntegers& H)const
{
	if (H.LessThanQuantityWise(*this) || H.GreaterThanQuantityWise(*this))
		return false;
	return true;
}

int& HugeIntegers::operator[](int i)
{
	return ds[i];
}

int HugeIntegers::operator[](int i)const
{
	if (i >= size)
		return 0;
	return ds[i];
}

void HugeIntegers::extractFromEnd(HugeIntegers& H)
{
	HugeIntegers Hp(H.size - 1);
	for (int i = 0; i < Hp.size; i++)
	{
		Hp.ds[i] = H.ds[i];
	}
	delete[]H.ds;
	H.ds = Hp.ds;
	H.size--;
}

void HugeIntegers::trim(HugeIntegers& H)
{
	for (int i = H.size - 1; i >= 0; i--)
	{
		if (H.ds[i] != 0)
			break;
		extractFromEnd(H);
	}
}

const HugeIntegers& HugeIntegers:: operator=(const HugeIntegers& H)
{
	if (this == &H)
		return *this;
	else
	{
		//delete[]this->ds;
		this->assign(H);
		return *this;
	}
}

//ofstream& operator<<(ofstream& wtr, const HugeIntegers& H)
//{
//	//if (!wtr)
//	//	cout << "bsdk";
//	//wtr << ((H.isNeg) ? "-" : "+");
//	//for (int i = 0; i < H.size; i++)
//	//{
//	//	;
//
//	//	//wtr << H.ds[H.size - 1 - i];
//	//}
//
//	//return wtr;
//}

ostream& operator<<(ostream&, const HugeIntegers& H)
{
	cout << ((H.isNeg) ? "-" : "+");
	for (int i = 0; i < H.size; i++)
	{
		cout << H.ds[H.size - 1 - i];
	}
	return cout;
}

istream& operator>>(istream&, HugeIntegers& H)
{
	char sym;
	sym = cin.peek();
	if (sym == '-')
	{
		H.isNeg = true;
		cin.ignore();
	}
	else
	{
		H.isNeg = false;
	}
	string line;
	getline(cin, line);
	H.size = line.size();
	H.ds = new int[H.size];
	for (int i = 0; i < H.size; i++)
	{
		H.ds[H.size - 1 - i] = line[i] - '0';
	}
	return cin;
}

ifstream& operator>>(ifstream& rdr, HugeIntegers& H)
{
	char sym;
	sym = rdr.peek();
	if (sym == '-')
	{
		H.isNeg = true;
		rdr.ignore();
	}
	else
	{
		H.isNeg = false;
	}
	string line;
	getline(rdr, line);
	H.size = line.size();
	H.ds = new int[H.size];
	for (int i = 0; i < H.size; i++)
	{
		H.ds[H.size - 1 - i] = line[i] - '0';
	}
	return rdr;
}

HugeIntegers HugeIntegers::operator-()
{
	HugeIntegers R = *this;
	R.isNeg = !(*this).isNeg;
	return R;
}

HugeIntegers HugeIntegers::operator+(const HugeIntegers& H)const
{
	HugeIntegers R;
	if ((*this).isNeg == H.isNeg)
	{
		if ((*this).GreaterThanQuantityWise(H))
		{
			R = (*this).ADDQuantityWise(H);
			R.isNeg = this->isNeg;
		}
		else
		{
			R = H.ADDQuantityWise(*this);
			R.isNeg = H.isNeg;
		}
	}
	else
	{
		if ((*this).GreaterThanQuantityWise(H))
		{
			R = (*this).SUBQuantityWise(H);
			R.isNeg = this->isNeg;
		}
		else
		{
			R = H.SUBQuantityWise(*this);
			R.isNeg = H.isNeg;
		}
	}
	return R;
}

HugeIntegers HugeIntegers::operator+=(const HugeIntegers& H)
{
	*this = *this + H;
	return *this;
}

HugeIntegers HugeIntegers::operator-(HugeIntegers& H)const
{
	HugeIntegers R;
	R = (*this) + (-H);
	return R;
}

HugeIntegers HugeIntegers::operator-=(HugeIntegers& H)
{
	*this = *this - H;
	return *this;
}

HugeIntegers HugeIntegers::operator++()
{
	*this += HugeIntegers::one();
	return *this;
}

HugeIntegers HugeIntegers::operator--()
{
	*this += -HugeIntegers::one();
	return *this;
}

HugeIntegers HugeIntegers::operator++(int d)
{
	HugeIntegers H = *this;
	*this += HugeIntegers::one();
	return H;
}

HugeIntegers HugeIntegers::operator--(int d)
{
	HugeIntegers H = *this;
	*this += -HugeIntegers::one();
	return H;
}

bool HugeIntegers::operator==(const HugeIntegers& H)const
{
	if ((*this).EqualQuantityWise(H))
		return true;
	return false;
}

bool HugeIntegers::operator>(const HugeIntegers& H)const
{
	if ((*this).isNeg != H.isNeg)
	{
		if (!(*this).isNeg)
			return true;
		else
			return false;
	}
	else
	{
		if (!(*this).isNeg)
			return (*this).GreaterThanQuantityWise(H);
		else
			return (*this).LessThanQuantityWise(H);
	}
}

bool HugeIntegers::operator>=(const HugeIntegers& H)const
{
	if (((*this) > H) || ((*this) == H))
		return true;
	return false;
}

bool HugeIntegers::operator<(const HugeIntegers& H)const
{
	if (H > (*this))
		return true;
	return false;
}

bool HugeIntegers::operator<=(const HugeIntegers& H)const
{
	if (((*this) < H) || ((*this) == H))
		return true;
	return false;
}

bool HugeIntegers::operator!=(const HugeIntegers& H)const
{
	if ((*this) == H)
		return false;
	return true;
}


/*
HugeIntegers& HugeIntegers::operator*(const HugeIntegers& H)const
{
	HugeIntegers R, A;
	R=this->zero();
	A = this->one();
	for (HugeIntegers counter = A; counter <= H; counter++)
	{
		R += *this;
	}
	return R;
}

HugeIntegers HugeIntegers::operator*=(const HugeIntegers& H)
{
	*this = (*this) * H;
	return *this;
}

HugeIntegers HugeIntegers::operator/(HugeIntegers H)const
{
	HugeIntegers R, A;
	R = *this;
	HugeIntegers count;
	count = this->zero();
	while (R >= 0 && R >= H)
	{
		R -= H;
		count++;
	}
	return count;
}

HugeIntegers HugeIntegers::operator/=(HugeIntegers H)
{
	*this = (*this) / H;
	return *this;
}

*/

HugeIntegers& HugeIntegers::operator*(const HugeIntegers& H)const
{
	HugeIntegers T, A, B, R, f, count;
	count = this->one();
	T = this->zero();
	A = *this;
	A.isNeg = false;
	B = H;
	B.isNeg = false;
	f = this->zero();
	while (B != f)
	{
		R = A; count = this->one();
		while ((count + count) <= B)
		{
			R += R;
			count += count;
		}
		T += R; B -= count;
	}
	if (this->isNeg == H.isNeg)
		T.isNeg = false;
	else
		T.isNeg = true;
	return T;
}

HugeIntegers HugeIntegers::operator*=(const HugeIntegers& H)
{
	*this = *this * H;
	return *this;
}

HugeIntegers HugeIntegers::operator/(HugeIntegers H)const
{
	HugeIntegers T, A, B, R, f, count;
	count = this->one();
	T = this->zero();
	A = *this;
	A.isNeg = false;
	B = H;
	B.isNeg = false;
	f = this->zero();
	while (A != f)
	{
		R = B; count = this->one();
		while (R + R <= A)
		{
			R += R;
			count += count;
		}

	
		if (A > 0)
		{
			T += count;
			A -= R;
		}
		else
		{
			count = this->one();
			T -= count;
			break;
		}
	
		
	}
	if (this->isNeg == H.isNeg)
		T.isNeg = false;
	else
		T.isNeg = true;

	return T;
}

HugeIntegers HugeIntegers::operator/=(HugeIntegers H)
{
	*this = *this / H;
	return *this;
}

HugeIntegers HugeIntegers::operator%(HugeIntegers H)const
{
	HugeIntegers T, A, B, R, f,r,q, count;
	count = this->one();
	q = *this;
	T = this->zero();
	A = *this;
	A.isNeg = false;
	B = H;
	B.isNeg = false;
	f = this->zero();
	while (A != f)
	{
		R = B; count = this->one();
		while (R + R <= A)
		{
			R += R;
			count += count;
		}
		if (A > 0)
		{
			T += count;
			A -= R;
		}
		else
		{
			count = this->one();
			T -= count;
			break;
		}
	}
	r = ((q) - (T * H));
	if (this->isNeg == H.isNeg)
		r.isNeg = false;
	else
		r.isNeg = true;
	return r;
}

HugeIntegers HugeIntegers::operator%=(HugeIntegers H)
{
	*this = *this % H;
	return *this;
}

HugeIntegers::~HugeIntegers()
{

}
