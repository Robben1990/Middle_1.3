// Middle_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Vector
{
public:
	Vector(float x, float y, float z)
	{
		this -> x = x;
		this -> y = y;
		this -> z = z;
	}

	friend Vector operator+(const Vector& a, const Vector& b);
	friend std::ostream& operator<< (std::ostream& out,const Vector& A);
	float operator[]( int index)
	{
		switch (index)
		{
		case 0: return x; break;
		case 1: return y; break;
		case 2: return z; break;
		default: std::cout << "Index error";
			break;
		}
		
	}
private:
	float x;
	float y;
	float z;
};

Vector operator+(const Vector& a,const Vector& b)
{
	return Vector(a.x + b.x, a.y + b.y, a.z + b.z);
}

std::ostream& operator<< (std::ostream& out,const Vector& A)
{
	out << ' ' << A.x << ' ' << A.y << ' ' << A.z;
	return out;
}


int main()
{
	Vector A(1.0f, 2.0f, 5.0f);
	Vector B(4.0f, 5.0f, 10.0f);

	std::cout << A + B<<'\n';
	std::cout << B[1];
}


