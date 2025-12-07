#define MATRIX_EXPORTS
#include "Matrix.h"
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>
#include <iomanip>
#include <utility>
#include <type_traits>

template class Matrix<double>;
template class Matrix<float>;
template class Matrix<int>;

template<typename T>
list<pair<vector<vector<T>>, typename Matrix<T>::LUCache>> Matrix<T>::storedLU;

template<typename T>
const size_t Matrix<T>::CACHESIZE = 5;


template<typename T>
Matrix<T>::Matrix(int r, int c){
	
			rows = r;
			columns = c;
			data.resize(r,vector<T>(c,0));
		}

template<typename T>
Matrix<T>::Matrix(vector<vector<T> > &matrix){
			rows  = matrix.size();
			columns = matrix[0].size();
			data = matrix;
			
			for(int i =0; i<rows;i++){
				if(data[i].size() != columns){
					throw invalid_argument("Invalid matrix:inconsistent column sizes :( ");
				}
			}
			
		}

template<typename T>				
int Matrix<T>::getNumberOfRows(){
			return rows;
		}
		
template<typename T>		
int Matrix<T>::getNumberOfColumns(){
			return columns;
		}
	
template<typename T>	
T Matrix<T>::getElement(int r, int c){
			T x = data[r][c];
			return x;
		}
		
template<typename T>		
void Matrix<T>::setElement (int r, int c, T value){
			data[r][c]=value;
		}		
		
template<typename T>
Matrix<T> Matrix<T>::add(Matrix& m2){
			int r2 = m2.getNumberOfRows();
			int c2 = m2.getNumberOfColumns();
			if((rows!=r2) ||(columns!=c2)){
				throw invalid_argument("Matrix rows and columns should match :( ");
			}
			Matrix sum(rows, columns);
			
			for(int i = 0;i<rows; i++){
				for(int j = 0; j<columns; j++){	
			sum.data[i][j] = data[i][j]+m2.data[i][j];
				}
			}
			return sum;
		}

template<typename T>		
Matrix<T> Matrix<T>::subtract(Matrix& m2){
			int r2 = m2.getNumberOfRows();
			int c2 = m2.getNumberOfColumns();
			if((rows!=r2) ||(columns!=c2)){
				throw invalid_argument("Matrix rows and columns should match :( ");
			}
			Matrix difference(rows, columns);
			
			for(int i = 0;i<rows; i++){
				for(int j = 0; j<columns; j++){	
			difference.data[i][j] =data[i][j]-m2.data[i][j];
				}
			}
			return difference;
		}

template<typename T>
Matrix<T> Matrix<T>::multiply(Matrix& m2){

			int r2 = m2.getNumberOfRows();
			int c2 = m2.getNumberOfColumns();
			if(columns != r2){
				throw invalid_argument("Columns of first matrix should be equal to rows of second matrix :( ");
			}
			Matrix product(rows,c2);
			T sum = 0;
			
			for(int i = 0; i<rows;i++){
				for(int j = 0; j<c2;j++){
					for(int k = 0; k<columns; k++){
						sum += data[i][k]*m2.data[k][j];
					}
					product.data[i][j] = sum;
					sum = 0;
				}
			}
			return product;
		}

template<typename T>
Matrix<T> Matrix<T>::operator+(Matrix& m2){
			return add(m2);
		}
			
template<typename T>
Matrix<T> Matrix<T>::operator-(Matrix& m2){
			return subtract(m2);
		}
	
template<typename T>
Matrix<T> Matrix<T>::operator*(Matrix& m2){
			return multiply(m2);
		}	

template<typename T>
Matrix<T> Matrix<T>::inverse(){
			if(rows != columns){
				throw invalid_argument("Not invertible: not a square matrix :(");
			}
			if(!is_floating_point<T>::value){
				throw invalid_argument("Use double or float to invert");
			}
			Matrix<T> augmented(rows, 2*rows);
			for(int i = 0; i<rows ; i++){
				for(int j =0; j<columns;j++){
					augmented.data[i][j] = data[i][j];	
				}
			augmented.data[i][i+rows] = 1;
			}
			for(int i =0; i<rows; i++){
				T diagonal = augmented.data[i][i];
				if(diagonal ==0){
					throw invalid_argument ("Matrix is not invertible :(");
				}
				for(int j = 0; j<2*columns; j++){
					augmented.data[i][j] /= diagonal; 
				}
				for(int k =0; k<rows; k++){
					if(k==i){
						continue;
					}
				T factor = augmented.data[k][i];
				for(int l =0; l<2*columns;l++){
					augmented.data[k][l] -= factor*augmented.data[i][l];
				}
				}
			}
			Matrix<T> inverse (rows, columns);
			for(int i = 0; i<rows; i++){
				for(int j = 0; j<columns; j++){
					inverse.data[i][j] = augmented.data[i][j+columns];
				}
			}
		return inverse;
		}

template<typename T>
Matrix<T> Matrix<T>::transpose(){
	Matrix transpose (columns, rows);
	for(int i =0; i<rows; i++){
		for(int j = 0; j<columns; j++){
			transpose.data[j][i] = data[i][j];
		}	
	}
		return transpose;
}

template<typename T>
vector<T> Matrix<T>::solveLinear(vector<T>& v){
	
			if((rows != columns)||(rows != v.size())){
			throw invalid_argument("Coefficient matrix should be square and no. of rows in both coeff. and output should be same :(");
			}
			if(!is_floating_point<T>::value){
				throw invalid_argument("Use double or float to solve linear equations");
			}
			Matrix<T> L(rows, columns);
			for(int i = 0; i<rows; i++){
				L.data[i][i]=1;
			}
			Matrix<T> U(data);
			
			for(int i = 0; i<rows; i++){
				for(int j = i+1; j<rows; j++){
					
					T factor = U.data[j][i]/U.data[i][i];
					for(int k = 0; k<columns; k++){
		//				cout<<"For j "<<j << " For k " << k << " factor " << factor << " i " << i << endl;
						U.data[j][k] -= factor*U.data[i][k];
					}
					L.data[j][i]= factor;
				}
			}
			vector<T> intermediate (rows, 0) ;
			
			for(int i =0; i<rows; i++){
				intermediate[i] = v[i];
				for(int j = 0; j<i; j++){
					intermediate[i] -= intermediate[j]*L.data[i][j];
				}	
				intermediate[i] /= L.data[i][i];
			}
			
			vector<T> output (rows, 0) ;
			
			for(int i =rows -1; -1<i ; i--){
				output[i] = intermediate[i];
				for(int j = i+1; j<columns ; j++){	
					output[i] -= output[j]*U.data[i][j];
		}
			output[i] /= U.data[i][i];
		}
		
			
		//	cout<<"L"<<endl;
		//	L.display();
		//	cout<<"U"<<endl;
		//	U.display();
		//	Matrix product = L.multiply(U);
		//	cout<<"Input"<<endl;
		//	product.display();
		//	cout<<"Intermediate"<<endl;
		//	for(double x:intermediate){
		//		cout<<x<<endl;
		//	}
			return output;
		}

template<typename T>
bool Matrix<T>::getLUfromCache(vector<vector<T>>& L,vector<vector<T>>& U){
			for(auto x = storedLU.begin();x != storedLU.end(); x++){
				if(x->first ==data){
					L = x->second.L;
					U = x->second.U;
					cout<<"CACHE HIT!!!!! =D"<<endl;
					storedLU.splice(storedLU.begin(), storedLU, x);
					return true;
				}	
			}
			return false;
		}
			
template<typename T>
void Matrix<T>::addLUtoCache(vector<vector<T>>& L,vector<vector<T>>& U){
//			for(auto x = storedLU.begin(); x!= storedLU.end(); ++x){
//				if(x->first == data){
//					storedLU.erase(x);
//					cout<<"Previous Entry erased from Cache"<<endl;
//					break;	
//							
//				} 
//			}
			storedLU.push_front({data,{L,U}});
			cout<<"Data added in Cache"<<endl;
			if(storedLU.size() > CACHESIZE)	{
				cout<<"Last entry removed from Cache :("<<endl;
				storedLU.pop_back();
			} 
		}

template<typename T>
vector<T> Matrix<T>::solveLinearWithCache(vector<T>& v){
	
			if((rows != columns)||(rows != v.size())){
			throw invalid_argument("Coefficient matrix should be square and no. of rows in both coeff. and output should be same :(");
			}
			if(!is_floating_point<T>::value){
					throw invalid_argument("Use double or float to solve linear equations");
			}
//			cout<<"here on line 262"<<endl;
//			cout<<"here on line 263"<<endl;
			vector<vector<T>> L(rows, vector<T>(columns, 0));
//			cout<<"here on line 265"<<endl;
			vector<vector<T>> U = data;
//			cout<<"Initialized L and U"<<endl;
			if(!getLUfromCache(L,U)){
//				for(auto x = storedLU.begin();x != storedLU.end(); x++){
//					Matrix<T> Mat(x->first);
//					Mat.display();
//					cout<<"Line 276"<<endl;
//				}
				for(int i = 0; i<rows; i++){
					L[i][i]=1;
				}	
				cout<<"No LU in cache , adding"<<endl;
			
				for(int i = 0; i<rows; i++){
					for(int j = i+1; j<rows; j++){
	//					cout<<"Line 276 reached"<<endl;
						T factor = U[j][i]/U[i][i];
						for(int k = 0; k<columns; k++){
			//				cout<<"For j "<<j << " For k " << k << " factor " << factor << " i " << i << endl;
							U[j][k] -= factor*U[i][k];
						}
						L[j][i]= factor;
					}
				}
			//	cout<<"Line 285 reached"<<endl;
				addLUtoCache(L,U);
			//	cout<<"LU added to cache"<<endl;
			}		
			
			vector<T> intermediate (rows, 0) ;
			
			for(int i =0; i<rows; i++){
				intermediate[i] = v[i];
				for(int j = 0; j<i; j++){
					intermediate[i] -= intermediate[j]*L[i][j];
				}	
				intermediate[i] /= L[i][i];
			}
			
			vector<T> output (rows, 0) ;
			
			for(int i =rows -1; -1<i ; i--){
				output[i] = intermediate[i];
				for(int j = i+1; j<columns ; j++){	
					output[i] -= output[j]*U[i][j];
				}
			output[i] /= U[i][i];
			}		
//		//	cout<<"L"<<endl;
//		//	L.display();
//		//	cout<<"U"<<endl;
//		//	U.display();
//		//	Matrix product = L.multiply(U);
//		//	cout<<"Input"<<endl;
//		//	product.display();
//		//	cout<<"Intermediate"<<endl;
//		//	for(double x:intermediate){
//		//		cout<<x<<endl;
//		//	}
//			vector<T> output ={0,6,5};
			return output;
		}

template<typename T>
vector<T> Matrix<T>::linearRegression(){
	if(columns!=2){
		throw invalid_argument("Columns should be = 2 for (x,y)");
	}
	vector<vector<T>> x (rows, vector<T>(2,1));
	vector<vector<T>> y (rows, vector<T>(1,1));
	for(int i =0; i<rows; i++){
		x[i][1] = data[i][0];
		y[i][0] = data[i][1];
	}
	Matrix<T> output (x);
	Matrix<T> Y(y);
//	output.display();
	Matrix<T> output_t = output.transpose();
//	output_t.display();
	output = output_t*output;
//	cout<<"rows "<<output.getNumberOfRows()<<endl;
//	cout<<"Columns "<<output.getNumberOfColumns()<<endl;
//	output.display();
	output = output.inverse();
//	cout<<"Succesfully inverted"<<endl;
//	output.display();
	output = output*output_t;
	output = output*Y;
	vector<T> v;
	for(int i = 0; i<2; i++){
		v.push_back(output.data[i][0]);
	}
	return v;
	//{intercept, slope}
}

template<typename T>		
void Matrix<T>::display(){
			for(int i = 0;i<rows; i++){
				for(int j = 0; j<columns; j++){
					cout<<setw(8)<<fixed<<setprecision(2)<<data[i][j];
				}
				cout<<endl;
			}
		}		
		
		
