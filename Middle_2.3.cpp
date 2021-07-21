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
		Info = new std::string("Hello");
	}
	
	Vector(float x, float y, float z)
	{
		this -> x = x;
		this -> y = y;
		this -> z = z;
		Info = new std::string("Important!");
	}

	explicit Vector(int num)
	{
		x = num;
		y = num;
		z = num;
	}
	
	Vector(const Vector& other)
	{
		std::cout << "Copy!\n";
		x = other.x;
		y = other.y;
		z = other.z;
		Info = new std::string(*(other.Info));
	}

	~Vector()
	{
		std::cout << "Calling destructor! \n";
		delete Info;
	}

	Vector& operator=(const Vector& other)
	{
		std::cout << " operator = \n";
			x = other.x;
			y = other.y;
			z = other.z;
		if (other.Info)
		{
			if (Info) delete Info;
			Info = new std::string(*(other.Info));
		}

		return (*this);
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
	std::string* Info;
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
	Vector V1(3.0f, 10.f, 1.0f);
	Vector V2(3.0f, 12.0f, 3.0f);
	std::cout << V2<< '\n';
	V2 = V1;
	std::cout << V2;
}



