// Middle_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>

class Storage
{
public:
	Storage(int size, char index, int column, int row)
	{
		this->size = size;
		this->num = new int[size];
		this->index = new char(index);
		this->column = column;
		this->row = row;
		this->Point = new int* [row];
		for (int i = 0; i< row; i++ )
		{
			Point[i] = new int[column];
		}
		FillStorage();
	}


	Storage& operator=(const Storage& other)
	{
		size = other.size;
		row = other.row;
		column = other.column;
		if (other.index && other.num && other.Point)
		{
			if (index) delete index;
			if (num) delete[] num ;
			if (Point) delete Point;

			index = new char(*(other.index));

			num = new int[size];
			for(int j = 0; j< size;j++ )
			{
				num[j] = other.num[j];
			}

			Point = new int* [row];
			for (int i =0; i<row; i++)
			{
				Point[i] = new int [column] ;
				for (int k = 0; k < column; k++)
					Point[i][k] = other.Point[i][k];
			}
		}
		return *this;
	}


	~Storage()
	{
		std::cout << "Calling destructor! \n";
		delete index;
		for (int k=0; k< row; k++)
		{
			delete [] Point[k];
		}
		delete[]num;
	}

	void PrintData() const
	{
		
		std::cout << "Print 2d array:\n";
		for (int i = 0; i < row; i++)
		{
			for (int j=0; j < column;j++)
			{
				std::cout << Point[i][j] << '\t';
			}
			std::cout << '\n';
		}
		std::cout << '\n';
		
		std::cout << "Print 1d array:\n ";
		for(int k=0; k <size; k++)
		{
			std::cout << num[k] <<'\t' ;
		}
		std::cout << '\n';
		std::cout << '\n';

	}
	void FillStorage() const
	{
		for(int k=0; k< size; k++)
		{
			num[k] = rand() % 99 + 1;
		}
		
		for (int i = 0; i<row; i++)
		{
			for (int j=0; j< column;j++)
			{
				 Point[i][j] = rand() % 20;
			}
		}
	}
	
private:
	int column;
	int row;
	int size;
	int* num;
	char* index;
	int** Point;
	
};

int main()
{
	Storage A(5, 'd', 2, 3);
	A.PrintData();
	
	Storage B(3, 's', 5, 4);
	B.PrintData();

	B = A;
	B.PrintData();
}



