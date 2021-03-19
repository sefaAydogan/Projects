//Muhammed Sefa Aydogan
//150150124

#include <iostream>
#include <fstream>
#include <string>
#include "Polynomial.h"
#include "Vector.h"

using namespace std;



int main(){	
int num_of_pol;
	ifstream myfile ("Polynomial.txt");
  	if (myfile.is_open()){
	   	myfile >> num_of_pol; 
    	}
    Polynomial *P[num_of_pol];
    int degree=0;
    int *coeff;
    
    for(int i=0;i<num_of_pol;i++){ // gets degrees and coeffs from text and puts them to P[i] object
    	myfile >> degree;
    	int *coeff=new int[degree];
    	for(int j=0;j<degree+1;j++){
    		myfile >> coeff[j];
    		Polynomial *polly = new Polynomial(degree,coeff);
			P[i] = polly;
		}
    	}     	
    myfile.close();  
    
    int num_of_vec;
	ifstream myfile2 ("Vector.txt");
  	if (myfile2.is_open()){
	   	myfile2 >> num_of_vec; 
    	}
    Vector *V[num_of_vec];
    int size=0;
    int *value;
    
    for(int i=0;i<num_of_vec;i++){ // gets sizes and values from text and puts them to V[i] object
    	myfile2 >> size;
    	int *value=new int[size-1];
    	for(int j=0;j<size;j++){
    		myfile2 >> value[j];
    		Vector *vec = new Vector(size,value);
			V[i] = vec;
		}    		
		}
    
     myfile2.close();    
	int opt=1;
	
	cout << "Polynomial and Vector List Program!" << endl << "Polynomials and Vectors are read from text files!" << "\n" << endl;   //user's console
	cout << "Possible Actions:" << endl << "1. Print Polynomial and Vector lists" << endl;
	cout << "2. Do a polynomial operation" << endl << "3. Do a vector operation" << endl;
	cout << "4. Help: Print possible actions" << endl << "0. Exit the program" << "\n\n" << endl;
	
	while(opt!=0){	  // loop until user gives '0'
	
	cout << "Enter an option: " ;
	cin >> opt;
		
	if(opt==1){
		cout << "Vectors:" << endl;
			for(int i=0;i<num_of_vec;i++){
		
			cout << i+1 << ". "	;
    		*(V[i]) << *(V[i]);
    		cout << "\n";
    	}
    	cout << endl;		
		
		cout << "Polynomials:" << endl;
			for(int i=0;i<num_of_pol;i++){
		
			cout << i+1 << ". "	;
    		*(P[i]) << *(P[i]);
    		cout << "\n";
    		}    	
		}	
	if(opt==2){
		cout << "Which polynomial operation would you like to do?((+:addition, *:multiplication):" << endl;
		
		int a,b;
		char x;
		cin >> a;
		x=getchar();
		cin >> b;
		
		if(x=='+'){	
			Polynomial Add_P = *(P[a-1]) + *(P[b-1]);
			cout << "(";
			*(P[a-1]) << *(P[a-1]);
			cout << ") + (";
			*(P[b-1]) << *(P[b-1]);
			cout << ") = ";
			Add_P << Add_P;
			cout << "\n\n";	
		
		}
		if(x=='*'){
			Polynomial Mulp_P = *(P[a-1]) * (*P[b-1]);
			cout << "(";
			*(P[a-1]) << *(P[a-1]);
			cout << ") * (";
			*(P[b-1]) << *(P[b-1]);
			cout << ") = ";
			Mulp_P << Mulp_P;
			cout << "\n\n";	
		}		
	}	
	if(opt==3){
		cout << "Which vector operation would you like to do?((+:addition, *:scalar multiplication, .:dot product):" << endl;
		int a,b;
		char x;
		cin >> a;
		x=getchar();
		cin >> b;
		
		if(x=='+'){		
		
		 	Vector New_V = *(V[a-1]) + *(V[b-1]);
			*(V[a-1]) << *(V[a-1]);
			cout << " + ";
			*(V[b-1]) << *(V[b-1]);
			cout << " = ";
			New_V << New_V;
			cout << "\n\n";			
		}
		
		if(x=='*'){
			Vector Sca_Vec = *(V[a-1]) * b;
			*(V[a-1]) << *(V[a-1]);
			cout << " * ";
			cout << b;
			cout << " = ";
			Sca_Vec << Sca_Vec;
			cout << "\n\n";			
		}
		
		if(x=='.'){
			int dot_pro = (*V[a-1]) * (*V[b-1]);
			*(V[a-1]) << *(V[a-1]);
			cout << " . ";
			*(V[b-1]) << *(V[b-1]);
			cout << " = ";
			cout << dot_pro << endl;
			cout << "\n";			
			}	
		}
	
	if(opt==4){
		cout << "\nPossible Actions:" << endl << "1. Print Polynomial and Vector lists" << endl;
		cout << "2. Do a polynomial operation" << endl << "3. Do a vector operation" << endl;
		cout << "4. Help: Print possible actions" << endl << "0. Exit the program" << "\n" << endl;
	
		}	
	}
	
	
	return 0;
}
