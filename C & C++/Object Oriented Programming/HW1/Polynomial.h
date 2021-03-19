//Muhammed Sefa Aydogan
//150150124

#include <iostream>
#include <cstring>	
#include <cmath>		
using namespace std;

class Polynomial{
	int degree;		// degree
	int *coeff;		// pointer to coefficients
 public:
	Polynomial(int deg=0, const int *co=NULL);		// Constructor
	Polynomial(const Polynomial &);		// Copy constructor
	
	~Polynomial(){ delete[] coeff; }	// Destructor
	const Polynomial & operator=(const Polynomial &);	// Assignment
	Polynomial operator+(const Polynomial &) const;		// +
	Polynomial operator*(const Polynomial&) const;
	void operator<<(const Polynomial&) const;
};

Polynomial::Polynomial(int deg, const int *co)	// Constructor
{
 if (deg >0){
	degree=deg;
	coeff=new int[degree+1];
	int count;
	for (count=0; count <=degree; count++) coeff[count]=1;
	if (co)
		for (count=0; count <=degree; count++) coeff[count]=co[count];
	}
	else
  		cerr << " ERROR: Degree" << endl;
}

Polynomial::Polynomial(const Polynomial &in)	// Copy constructor
{
	degree=in.degree;
	coeff=new int[degree+1];
	int count;
	for (count=0; count <=degree; count++)
		 coeff[count]=in.coeff[count];
}


void Polynomial::operator<<(const Polynomial &in) const{
	int j=0;
	for(int i=in.degree;i>=0;i--){
		
			if(in.coeff[j]==1)	{
				if(i==1)
					cout << "x";
				else if(i==0)
					cout << "1";
				else 
					cout << "x^" << i;
			}	
					
			
			
			else{
				if(i==1)
					cout << in.coeff[j] << "x";
				else if(i==0)
					cout <<  in.coeff[j];
				else
					cout << in.coeff[j] << "x^" << i ;
			}
				
			
			if(i!=0)
				cout << " + ";
				
		
		
	j++;
}
}
 
const Polynomial & Polynomial::operator=(const Polynomial &in) // Assignment
{
	degree=in.degree;
	delete coeff;
	coeff=new int[degree+1];
	int count;
	for (count=0; count <=degree; count++)
		 coeff[count]=in.coeff[count];
	return *this;
}

Polynomial Polynomial::operator+(const Polynomial &in) const     // +
{
	int max_d,min_d;
	int* cof;
	int dif= degree > in.degree ? (degree-in.degree) : (in.degree-degree);
	max_d= degree > in.degree ? degree : in.degree;
	cof= new int[max_d+1];
	
	if(degree!=in.degree){
	
	for(int i=0;i<dif;i++)
		cof[i]= degree > in.degree ? coeff[i] : in.coeff[i];
	
	for(int i=0;i<=max_d-dif;i++)
		if(max_d==degree)
			cof[i+dif]= coeff[i+dif]+in.coeff[i];
		else
			cof[i+dif]=coeff[i]+in.coeff[i+dif];

}	
	else
		for(int i=0;i<=max_d;i++)
			cof[i]= coeff[i]+in.coeff[i];

		
	return Polynomial(max_d,cof);
	
}
Polynomial Polynomial::operator*(const Polynomial& in) const{
	
	int pro_deg=degree+in.degree;
	int *pro_coeff= new int[pro_deg+1];
	
	for(int i=0;i<=degree;i++){
		for(int j=0;j<=in.degree;j++){
			pro_coeff[i+j] += coeff[i]*in.coeff[j];
		}
	}
	
	
	
	return Polynomial(pro_deg,pro_coeff);
}

