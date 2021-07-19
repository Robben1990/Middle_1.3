// Middle_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>

class Vector
{
public:
	Vector()
	{
		x = 0;
		y = 0;
		z = 0;
	}
	Vector(float x, float y, float z)
	{
		this -> x = x;
		this -> y = y;
		this -> z = z;
	}
	friend bool operator>(const Vector& A, const Vector& B);

	friend Vector operator*(const Vector& A, const float& B);

	friend Vector operator+(const Vector& a, const Vector& b);

	friend Vector operator- (const Vector& A, const Vector& B);

	friend std::ostream& operator<< (std::ostream& out,const Vector& A);

	friend std::istream& operator>> (std::istream& in, Vector& A);


	operator float()
	{
		return sqrt(x * x + y * y + z * z);
	}
	
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
bool operator>(const Vector& A, const Vector& B)
{
	return false;
}

Vector operator* (const Vector& A, const float& B)
{
	return Vector(A.x * B , A.y * B  ,A.z * B);
}

Vector operator+(const Vector& a,const Vector& b)
{
	return Vector(a.x + b.x, a.y + b.y, a.z + b.z);
}

Vector operator- (const Vector& A, const Vector& B)
{
	return Vector(A.x - B.x, A.y - B.y, A.z - B.z);
}

std::ostream& operator<< (std::ostream& out,const Vector& A)
{
	out << ' ' << A.x << ' ' << A.y << ' ' << A.z;
	return out;
}

std::istream& operator>> (std::istream& in,  Vector& A)
{
	in >> A.x;
	in >> A.y;
	in>> A.z;
	return in;
}

int main()
{
	Vector A(1.0f, 2.0f, 5.0f);
	Vector B(4.0f, 5.0f, 10.0f);
	Vector C;
	C = B + A;

	std::cout << A + B<<'\n';
	std::cout << B[1];
	std::cout << float(C)<<'\n';
	std::cout << "A length is " << static_cast <float>(A)<<'\n';
	std::cout << B*5.5f << '\n';
	std::cout << B - A <<'\n';
	
	Vector D;
	std::cout << "Enter coordinates: \n";
	std::cin >> D;
	std::cout << "Vector D: " << D;

}


