#include <iostream>
#pragma once

#if defined(_WIN32) || defined(_WIN64)
    #define MATRIX_API __declspec(dllexport)
#else
    #define MATRIX_API __attribute__((visibility("default")))
#endif



#include <vector>
#include <list>
#include <stdexcept>
#include <iomanip>
#include <utility>
#include <type_traits>
using namespace std;

template<typename T>



class MATRIX_API Matrix {
	
	
	private:
		int rows;
		int columns;
		vector<vector<T> > data;
		
	public:
		Matrix(int r, int c);
		
		Matrix(vector<vector<T> > &matrix);
		
		struct LUCache{
			vector<vector<T>> L;
			vector<vector<T>> U;
		};
		static list<pair<vector<vector<T>>,LUCache>> storedLU;
		static const size_t CACHESIZE;
		
		void addLUtoCache(vector<vector<T>>& L,vector<vector<T>>& U);
		
		bool getLUfromCache(vector<vector<T>>& L,vector<vector<T>>& U);
		
		int getNumberOfRows();
		int getNumberOfColumns();
		
		T getElement(int r, int c);
		void setElement (int r, int c, T value);
		
		Matrix add(Matrix& m2);

		Matrix subtract(Matrix& m2);
	
		Matrix multiply(Matrix& m2);
		
		Matrix operator+(Matrix& m2);
		Matrix operator-(Matrix& m2);
		Matrix operator*(Matrix& m2);
		
		Matrix transpose();
		
		Matrix inverse();

		vector<T> solveLinear(vector<T>& v);
		
		vector<T> solveLinearWithCache(vector<T>& v);
		
		vector<T> linearRegression();
		
    	void display();
		
//		~Matrix();
		
};



