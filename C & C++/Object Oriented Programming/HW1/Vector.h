//Muhammed Sefa Aydogan
//150150124
#include <iostream>
#include <cstring>	
#include <cmath>	

using namespace std;

class Vector{
	int size;
	int *value;
	
	public:
		
	Vector(int si=0, const int *val=NULL);		// Constructor
	
	Vector(const Vector &);		// Copy constructor
	
	~Vector(){ delete[] value; }	// Destructor	
	Vector operator+(const Vector &) const;	
	Vector& operator=(const Vector &);	// Assignment
	int operator*(const Vector&) const;			/*dot product*/
	Vector operator*(const int) const;			/*vector product*/
	
	void operator<<(const Vector &) const;
	
};

Vector::Vector(int si,const int *val){
	if (si >0){
	size=si;
	value=new int[size];
	int count;
	for (count=0; count <size; count++) value[count]=1;
	if (val)
		for (count=0; count <size; count++) 
			value[count]=val[count];
	}
	
	else {
	
  		cerr << " ERROR: Size" << endl;
  	}

}


Vector::Vector(const Vector& V){
	size = V.size;
	value = new int[size];
	for(int i=0;i<size;i++)
		value[i] = V.value[i];
}

	
void Vector::operator<<(const Vector &in) const{
	int j=0;
	cout <<"(" ;
	for(int i=size-1;i>=0;i--){	
		if(i==0)
			cout << in.value[j] << ")";
			
		else	
			cout << in.value[j] << ", ";
		
	
		
	j++;
	}
	}
	

	
Vector Vector::operator+(const Vector &in) const{
	
	
	if(size==in.size){
		int* sum = new int[size];
		for(int i=0;i<size;i++){
		
			sum[i]=value[i]+in.value[i];
			
		}
		return Vector(size,sum);
	}
	else
		cerr << " ERROR: Size"<< endl;


}


Vector& Vector::operator=(const Vector &in) // Assignment
{
	size=in.size;
	
	value=new int[size];
	int i;
	for (i=0; i <size; i++)
		 value[i]=in.value[i];
		 
	return *this;
}
int Vector::operator*(const Vector& v2) const{ // dot product
	if(size==v2.size){
		int sum=0;
		for(int i=0;i<size;i++)
		sum+=value[i]*v2.value[i];
	return sum;
	}
	else
		cerr << "ERROR: Size" << endl;
	
}

Vector Vector::operator*(const int x) const{  // vector product
	int* sca_pro_value=new int[size];
	for(int i=0;i<size;i++)
	{
		sca_pro_value[i]=value[i]*x;
	}
	return Vector(size,sca_pro_value);
}


