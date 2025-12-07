#include "Matrix.h"
#include <iostream>
#include <vector>
using namespace std;

int main(){
	cout << "Unit Test Cases start" <<endl;
	
	Matrix<double> m (3,3);
	cout << "Constructor Test Case" <<endl;
	m.display();
	vector<double> p = { 3.5,6.0 };
	//vector<double> q = {-4,6};	
	vector<vector<double> > v1 = {{2,3},{-5, 9.6},{0,-7.8}};
	vector<vector<double> > v2 = {{5,3},{-5, 10},{20,-7}};
	Matrix<double> a (v1);
	//a.display();
	Matrix<double> m2 (v2);
	//m2.display();
	Matrix<double> sum = a.add(m2);
	cout<< "Test case for addition -double" << endl;
	cout<< "Matrix1"<<endl;
	a.display();
	cout<< "Matrix2"<<endl;
	m2.display();
	cout<< "Sum"<<endl;
		

	sum.display();
    cout<<"Test case for operator overloading add -double"<<endl;
	Matrix<double> sum2 = a+m2;
	sum2.display();
//   cout<< "Test case for invalid matrix" << endl;
//	vector<vector<double> > v3 = {{5,3},{10},{20,-7}};
//	Matrix<double> m3(v3); (for invalid matrix)
	cout<< "Test case for substraction -double" << endl;
	Matrix<double> difference = a.subtract(m2);
	difference.display();
	cout<< "Test case for multiplication -int" << endl;
	vector<vector<int> > v4 = { {1, 2},{3, 4},{5, 6}};
	vector<vector<int> > v5 = {{7, 8, 9},{10, 11, 12}};
	Matrix<int> m4(v4);
	Matrix<int> m5(v5);
	Matrix<int> product = m4.multiply(m5);
	product.display();
	cout<< "Test case for multiplication overload -int" << endl;
	Matrix<int> product2 = m4*m5;
	product2.display();
	
	cout<<"Test case for inversion -double"<<endl;
	vector<vector<double> > v6 = { {3,2},{1,1}};
	Matrix<double> m6(v6);
	Matrix<double> m7 = m6.inverse();
	cout<<"Input matrix"<<endl;
	m6.display();
	cout<<"Inverse matrix"<<endl;	
	m7.display();
	
	cout<<"Test case for inversion -float"<<endl;
	vector<vector<float> > v6f = { {1.5,2.0,-0.5},{0.0,1.0,3.0},{2.0,-1.0,1.0}};
	Matrix<float> m6f(v6f);
	Matrix<float> m7f = m6f.inverse();
	//m7f.display();
	cout<<"Input matrix"<<endl;
	m6f.display();
	cout<<"Inverse matrix"<<endl;	
	m7f.display();	
	
	cout<< "Test case for LUD double type" << endl;
	vector<vector<double> > v7 = { {4,6},{2,4}};
	Matrix<double> m8(v7);
	vector<double> ab = {9,7};
	vector<double> L = m8.solveLinear(ab);
	cout<< "Test case for LUD input double type" << endl;
	for(double x11:ab){
		cout<<x11<<endl;
	}
	cout<< "Test case for LUD matrix double type" << endl;
	m8.display();
	cout<< "Test case for LUD double type solution" << endl;
	for(double x11:L){
		cout<<x11<<endl;
	}
	vector<vector<double> > v8 = { {2,4,6},{1,3,5},{2,1,2}};
	Matrix<double> m9(v8);
	vector<double> ac = {9,7,0};
	vector<double> UL = m9.solveLinear(ac);
//	cout<<"Intermediate for LUD"<<endl;
//	vector<vector<double> > v9 = { {1,1,1},{4,3,-1},{3,5,3}};
//	Matrix<double> m10(v9);
//	vector<double> v10 = {1,6,4};
//	vector<double> v11 = m10.solveLinear(v10);
//	for(double x11:v11){
//		cout<<x11<<endl;
//	}
	cout<<"Linear Equations 4 variables"<<endl;
	vector<vector<double> > v12 = { {1,2,3,4},{2,-1,1,3},{3,1,-2,1},{1,4,1,-1}};
	Matrix<double> m11(v12);
	vector<double> v13 ={20, 10, 5, 12};
	cout<< "Test case for LUD matrix float type input" << endl;
	for(auto x14:v13){
		cout<<x14<<endl;
	}
	cout<< "Test case for LUD matrix float type input" << endl;
	m11.display();
	cout<< "Test case for LUD float type solution output" << endl;
	vector<double> v14 = m11.solveLinear(v13);
	for(float x14:v14){
		cout<<x14<<endl;
	}
	cout<<"------LU cache 1-----"<<endl;
	vector<double> v15 = m11.solveLinearWithCache(v13);
	for(double x15:v15){
		cout<<x15<<endl;
	}
	cout<<"------LU cache trial 2-----"<<endl;
	vector<double> v16 = m11.solveLinearWithCache(v13);
	for(auto x16:v16){
		cout<<x16<<endl;
	}
	
	cout<<"------LU cache trial3 -----"<<endl;
	vector<vector<double> > v17 = { {1,1,1,1},{1,-1,1,-1},{2,1,-1,1},{-1,2,1,-1}};
	vector<double> v19 = {10,-2,5,2};
	Matrix<double> m12(v17);
	vector<double> v18 = m12.solveLinearWithCache(v19);
	for(auto x16:v18){
		cout<<x16<<endl;
	}
	cout<<"------LU cache trial 4-----"<<endl;
	vector<double> v20 = m11.solveLinearWithCache(v13);
	for(auto x16:v20){
		cout<<x16<<endl;
	}
	cout<<"------Linear regression-----"<<endl;
	vector<vector<double> > v21 = {{1,1},{2,3},{3,4},{4,8}};
	Matrix<double> m13(v21);
	vector<double> v22 = m13.linearRegression();
	cout<<"Line 139"<<endl;
	for(auto x:v22){
		cout<<x<<endl;
	}
	
	return 0;
}
