//Muhammed Sefa Aydoðan
//150150124

#include <iostream>
#define MAX_OPERATOR_SIZE 50
using namespace std;

class Operator{
	
	int center_x;
	int center_y;
	int op_size;
	
	public:
			int *op_arr_x;      // to track the coordinates of the operators 
			int *op_arr_y;      //	to track the coordinates of the operators
			Operator (int x, int y, int size){
				center_x=x-1;
				center_y=y-1;
				op_size=size;
				
			};
		
			void reset(int new_x, int new_y , int new_size){              // reset function used in move operations 
				center_x=new_x-1;	
				center_y=new_y-1;
				op_size=new_size;
			};
		
			void set_x( int new_x ){
				center_x=new_x;
				
			};		
			int get_x(){
				return center_x;
			};
			
			void set_y( int new_y ){
				center_y=new_y;
			};
			int get_y(){
				return center_y;
			};
			
			void set_size( int new_size ){
				op_size=new_size;
			};
			
			int get_size(){
				return op_size;
			};	
};
class ArithmeticOperator: public Operator {
	char sign;
	
	public:
		ArithmeticOperator( int x, int y, int size , char sign) : Operator(x,y,size) {
			this->sign = sign;
			if(sign=='+'||sign=='x'){			
				op_arr_x=new int[size*4+1];
				op_arr_y=new int[size*4+1];
			}
			else{
				op_arr_x=new int[size*2+1];
				op_arr_y=new int[size*2+1];
			}
		};
		char get_sign();
		void print_operator();
		
};
char ArithmeticOperator::get_sign(){
	return sign;
}
void ArithmeticOperator::print_operator(){
	int cent_x=get_x();
	int cent_y=get_y();
	int size=get_size();
	
	
	cout <<  "ARITHMETIC_OPERATOR[" << sign << "], CENTER_LOCATION[" << cent_x+1 << "," << cent_y+1 << "], SIZE[" << size << "]" << endl;
	
} 


class OperatorGrid {
	
	int grid_rows;
	int grid_cols;
	char **grid;
	
	int num_operators;
	ArithmeticOperator *operators[MAX_OPERATOR_SIZE];
	
	public:
		OperatorGrid(int rows, int cols);
		~OperatorGrid();
			
		bool place_operator (ArithmeticOperator *);
		bool move_operator (int , int , char , int);
		void print_operators();
		
		void place_op(ArithmeticOperator *);           // this is void place_op. here I filled grid with given info and kept the coordinates to use later for finding center
		int find_center(int, int);						// for move operations, finds the center of that operator
		bool BorderError(int,int,int,char);            	// checking for any border error
		bool ConflictError(int ,int ,int ,char);		// checking for any conflict error
		void DeleteGrid(int,int,int,char);				// deletes the operator's old locations to move for a new location
		
};
OperatorGrid::OperatorGrid(int rows, int cols){			//Constructer
	
	grid_rows=rows-1;
	grid_cols=cols-1;
	num_operators=0;
	grid= new char*[rows];
	for(int i=0;i<rows;i++){
		grid[i] = new char[cols];
	}
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++)
			grid[i][j] = '*';       // first I filled grid with this character to use later for checking in the section of movement and placement
		
	}
	
	
}
OperatorGrid::~OperatorGrid(){					//Destructor
	for (int i = 0; i < grid_rows; i++)
  	{
  		delete [] grid[i];
   	}
	delete[]grid;
	
	
	
	for(int i=0;i<num_operators;i++)	delete [] operators[i];
	
	cout << "DESTRUCTOR: GIVE BACK[" << grid_rows +1 <<"," << grid_cols +1 << "] chars." <<endl;
	cout << "DESTRUCTOR: GIVE BACK[" << num_operators << "] Operators." << endl;
	
	
}

bool OperatorGrid::place_operator(ArithmeticOperator * artop){
		
	char  a= artop->get_sign();

	int center_x= artop->get_x();
	int center_y= artop->get_y();
	int size= artop->get_size();
	
	bool border_sign = BorderError(center_x,center_y,size,a);
	bool conflict_sign= ConflictError(center_x,center_y,size,a);
	if(!border_sign){
		cout << "BORDER ERROR: Operator " << a << " with size " << size << " can not be placed on (" << center_x+1 << "," << center_y+1 << ")."<< endl;
	}
	if(!conflict_sign){	//if there are border error and conflict error 
		cout << "CONFLICT ERROR: Operator " << a << " with size " << size << " can not be placed on (" << center_x+1 << "," << center_y+1 << ")."<< endl;			
	}
	if(!conflict_sign || !border_sign){
		return false;
	}
	operators[num_operators]=artop;	
	place_op(artop);
	cout << "SUCCESS: Operator " << a << " with size " << size <<" is placed on (" << center_x+1 << "," << center_y+1 <<").\n";
	
	num_operators++;	// after every succesfull placement num_operators increased by 1.
	return true;	
}


bool OperatorGrid::move_operator(int x, int y, char direction, int move_by){
	int a=find_center(x,y);  // with given coordinates, finds the operator that has that location.
	bool flag= false;
	
	int center_x=operators[a]->get_x();     // gets center location of that operator to start the movement operations
	int center_y=operators[a]->get_y();
	int size=operators[a]->get_size();
	char sign=operators[a]->get_sign();
	
	DeleteGrid(center_x,center_y,size,sign);  // deletes the old locations and filled with '*'
	
	if(direction=='L'){ // first, checking for any error than if there is not any error, moves that operators to the left by given quantity. rest of the if loops are doing the same thing. 
			if(!BorderError(center_x,center_y-move_by,size,sign)){
				cout << "BORDER ERROR: Operator " << sign << " can not be moved from (" << center_x+1 << "," << center_y+1 << ") to (" << center_x+1 << "," << center_y+1 - move_by <<")."<< endl;
				if(!ConflictError(center_x,center_y-move_by,size,sign)){
					cout << "CONFLICT ERROR: " << sign << " can not be moved from (" << center_x+1 << "," << center_y+1 << ") to (" << center_x+1 << "," << center_y+1 - move_by <<")."<< endl; 
					place_op(operators[a]);
					flag=false;
					return flag;
				}
				return false;
			}
			else if(!ConflictError(center_x,center_y-move_by,size,sign)){			
				cout << "CONFLICT ERROR: " << sign << " can not be moved from (" << center_x+1 << "," << center_y+1 << ") to (" << center_x+1 << "," << center_y+1 - move_by <<")."<< endl; 
				place_op(operators[a]);
				flag=false;
				return flag;
				
			}
			else {
				operators[a]->reset(center_x,center_y-move_by,size);
				place_op(operators[a]);
				cout << "SUCCESS: " << sign << " moved from (" << center_x + 1 <<"," << center_y+1 << ") to ("<< center_x+1 <<","<< center_y-move_by+1 <<")."<<endl;
				flag = true;
		}
		}
	else if(direction=='R'){
		
			if(!BorderError(center_x,center_y+move_by,size,sign)){
				cout << "BORDER ERROR: Operator " << sign << " can not be moved from (" << center_x+1 << "," << center_y+1 << ") to (" << center_x+1 << "," << center_y+1  + move_by<<")."<< endl;
				if(!ConflictError(center_x,center_y+move_by,size,sign)){
					cout << "CONFLICT ERROR: " << sign << " can not be moved from (" << center_x+1 << "," << center_y+1 << ") to (" << center_x+1 << "," << center_y+1  + move_by<<")."<< endl; 
					place_op(operators[a]);
					flag= false;
					return flag;
				}
				place_op(operators[a]);
				flag = false;
				return flag;
			}
			else if(!ConflictError(center_x,center_y+move_by,size,sign)){			
				cout << "CONFLICT ERROR: " << sign << " can not be moved from (" << center_x+1 << "," << center_y+1 << ") to (" << center_x+1  << "," << center_y+1  + move_by <<")."<< endl; 
				place_op(operators[a]);
				flag=false;
				return flag;
				
			}
			else {
				operators[a]->reset(center_x,center_y+move_by,size);
				place_op(operators[a]);
				cout << "SUCCESS: " << sign << " moved from (" << center_x + 1 <<"," << center_y+1 << ") to ("<< center_x+1 <<","<< center_y+1  + move_by<<")."<<endl;
				return true;
				
			}
				
			
		}
		else if(direction=='D'){
			if(!BorderError(center_x+move_by,center_y,size,sign)){
				cout << "BORDER ERROR: Operator " << sign << " can not be moved from (" << center_x+1 << "," << center_y+1 << ") to (" << center_x+1 + move_by<< "," << center_y+1  <<")."<< endl;
				if(!ConflictError(center_x+move_by,center_y,size,sign)){
					cout << "CONFLICT ERROR: " << sign << " can not be moved from (" << center_x+1 << "," << center_y+1 << ") to (" << center_x+1 + move_by<< "," << center_y+1 - move_by <<")."<< endl; 
					place_op(operators[a]);
					flag=false;
					return flag;
				}
				place_op(operators[a]);
				flag=false;
				return flag;
			}
			else if(!ConflictError(center_x+move_by,center_y,size,sign)){			
				cout << "CONFLICT ERROR: " << sign << " can not be moved from (" << center_x+1 << "," << center_y+1 << ") to (" << center_x+1 + move_by << "," << center_y+1  <<")."<< endl; 
				place_op(operators[a]);
				flag=false;
				return flag;
				
			}
			else {
				operators[a]->reset(center_x+move_by,center_y,size);
				place_op(operators[a]);
				cout << "SUCCESS: " << sign << " moved from (" << center_x + 1 <<"," << center_y+1 << ") to ("<< center_x+1 + move_by+1 <<","<< center_y <<")."<<endl;
				flag=true;
			
			
		}
		}
		
		else if(direction=='U'){
			
				if(!BorderError(center_x-move_by,center_y,size,sign)){
					cout << "BORDER ERROR: Operator " << sign << " can not be moved from (" << center_x+1 << "," << center_y+1 << ") to (" << center_x+1 - move_by<< "," << center_y+1  <<")."<< endl;
						if(!ConflictError(center_x-move_by,center_y,size,sign)){
							cout << "CONFLICT ERROR: " << sign << " can not be moved from (" << center_x+1 << "," << center_y+1 << ") to (" << center_x+1 - move_by<< "," << center_y+1 <<")."<< endl; 
							place_op(operators[a]);
							flag=false;
							return flag;
				}
					place_op(operators[a]);
					flag=false;
					return flag;
				}
				else if(!ConflictError(center_x-move_by,center_y,size,sign)){			
					cout << "CONFLICT ERROR: " << sign << " can not be moved from (" << center_x+1 << "," << center_y+1 << ") to (" << center_x+1 - move_by << "," << center_y+1  <<")."<< endl; 
					place_op(operators[a]);
					flag=false;
					return flag;				
					}
					
				else {
				operators[a]->reset(center_x-move_by,center_y,size);
				place_op(operators[a]);
				cout << "SUCCESS: " << sign << " moved from (" << center_x + 1 <<"," << center_y+1 << ") to ("<< center_x+1 - move_by+1 <<","<< center_y +1 <<")."<<endl;
				flag= true;
			
			
				}
		
	}
	return flag;
}
		
void OperatorGrid::DeleteGrid(int center_x,int center_y,int size,char sign){          // deletes the old locations and filled with '*' for every symbol 
	if(sign=='+'){
			for(int i=center_y-size;i<center_y+size;i++){			
				grid[center_x][i]='*';			
			}		
			int j=center_x-size;
			while(j<center_x+size){			
			
					grid[j][center_y]='*';	
					j++;				
				}
			}			
	
	
	else if(sign=='x'){
		int i = center_x-size;
		int j = center_y-size;		
		while( j <= center_y+size && i <= center_x+size){
		
			grid[i][j]='*';
			i++;
			j++;
		}
		int x = center_x-size;
		int y= center_y+size;
		while( x <= center_x+size && y >= center_y-size){
			grid[x][y]='*';
		 	x++;
			y--;
		}		
	}
	
	else if(sign=='/'){
		int i = center_x+size;
		int j= center_y+size;
		while( i >= center_x-size && j >= center_y-size){
			grid[i][j]='*';
			i--;
			j--;
			}		
	}
	
	else if(sign=='-'){
		for(int i = center_y-size; i <= center_y+size; i++)
			grid[center_x][i]='*';		
	}
}

void OperatorGrid::place_op(ArithmeticOperator * artop){  // this is void place_op. here I filled grid with given info and kept the coordinates to use later for finding center
	char  a= artop->get_sign();
	
	int center_x= artop->get_x();
	int center_y= artop->get_y();
	int size= artop->get_size();
		
	if(a=='+'){		
			int k = 0;


			for(int i=center_y-size;i<center_y+size;i++){					
				grid[center_x][i]='+';
				 
				operators[num_operators]->op_arr_y[k] = i;            // records the coordinates one by one.
				operators[num_operators]->op_arr_x[k] = center_x;
				k++;
			}
				k=2*size+1;
			for(int j=center_x-size;j<center_x+size;j++){			
				grid[j][center_y]='+';
				if(j!=center_x){
					operators[num_operators]->op_arr_x[k] = j;
					operators[num_operators]->op_arr_y[k] = center_y;
					k++;					
				}		
			}	
				
	}
	else if(a=='x'){
		int k=0;
		int i = center_x-size;
		int j = center_y-size;		
		while( j <= center_y+size && i <= center_x+size && k<2*size+1){
			grid[i][j]='x';
			operators[num_operators]->op_arr_x[k] =i;
			operators[num_operators]->op_arr_y[k] =j;
			i++;
			j++;
			k++;
			
		}
		k=2*size+1;
		int x = center_x-size;
		int y= center_y+size;
		while( x <= center_x+size && y >= center_y-size && k<4*size+1){
			if(y==center_y && x==center_x){
				x++;
				y--;
			}
			else{				
			grid[x][y]='x';	
			operators[num_operators]->op_arr_x[k] =x;
			operators[num_operators]->op_arr_y[k] =y;	
		 	x++;
			y--;
			k++;			
			}

		}
			
	}
	
	else if(a=='/'){

		int k=0;
		int i = center_x-size;
		int j= center_y+size;
		while( i <= center_x+size && j >= center_y-size){
			
			grid[i][j]='/';
			operators[num_operators]->op_arr_x[k] =i;
			operators[num_operators]->op_arr_y[k] =j;
			i++;
			j--;
			k++;
			}
		
	}
	
	else if(a=='-'){
	
		int k=0;
		for(int i = center_y-size; i <= center_y+size; i++){		
			grid[center_x][i]='-';
			operators[num_operators]->op_arr_x[k] =center_x;
			operators[num_operators]->op_arr_y[k] =i;
			k++;
			
			}
	}
}

int OperatorGrid::find_center(int x,int y){               // with the recorded locations, loops finds the given location in the coordinates and return the rigth operators
	if(grid[x][y]=='+'||grid[x][y]=='x'){
	
		for(int i = 0; i<num_operators; i++){
			for(int j = 0; j< operators[i]->get_size() * 4 + 1; j++){
				if(operators[i]->op_arr_x[j] == x && operators[i]->op_arr_y[j] == y){
					return i;
				}
			}
		}
	}
	else if(grid[x][y]=='-'|| grid[x][y]== '/'){
		for(int i = 0; i<num_operators; i++){
			for(int j = 0; j< operators[i]->get_size() * 2 + 1; j++){
				if(operators[i]->op_arr_x[j] == x && operators[i]->op_arr_y[j] == y){
					return i;
				}
			}
		}
	}
	
	return 0;
}	

void OperatorGrid::print_operators(){		//Print operator
	for(int i=0;i<num_operators;i++){
		operators[i]->print_operator();
	}
}

int main(){
	
	
	// will fill by teacherr??
	
	
	
	
	
	
	
	
	return 0;
}




bool OperatorGrid::ConflictError(int x,int y,int size,char sign){
	int k=1;
	char a=sign;
	bool check = true;
	if(a=='+'){
		while(y+k < grid_cols  &&  y-k>0 && x+k < grid_rows && x-k > 0 && k < size ){		
			
				if(grid[x][y+k]=='*' && grid[x+k][y]=='*' && grid[x-k][y]=='*' && grid[x][y-k]=='*' && grid[x][y]  =='*' ) 
					check=true;				
				else{
					check=false;
					return check;
				}
				k++;
		}
	}
	else if(a=='x'){
		while (y+k<grid_cols  &&  y-k>0 && x+k < grid_rows && x-k > 0 && k<=size ){
		
			if(	grid[x-k][y-k]=='*'&&	grid[x-k][y+k]=='*'&&	grid[x+k][y-k]=='*'&&	grid[x+k][y+k]=='*'&&	grid[x][y]	  =='*' ) {
					check=true;			                                                                                                 		
					
			}
			else{
				check=false;
				return check;				
			}
			k++;
		}
	}
	else if(a=='-'){
		while(y+k<grid_cols  &&  y-k>0 && k<=size ){		
			if(	grid[x][y-k]=='*'&&		grid[x][y+k]=='*'&&		grid[x][y]=='*' ){
				check=true;		
	
			} 
			else{
				check=false;
				return check;
			}
			k++;			
		}
	}	
	else if(a=='/'){
		while(y+k<grid_cols  &&  y-k>0 && x+k < grid_rows && x-k > 0 && k<=size){
			if(	grid[x-k][y+k]=='*' &&	grid[x+k][y-k]=='*'&&	grid[x][y]	  =='*' ){
				check=true;		
			} 
			else{
				check=false;
				return check;				
			}
			k++;			
		}	
	}
	else {
		cout << "Invalid Input" << endl;
		return false;
	}
	return check;
}

bool OperatorGrid::BorderError(int x,int y,int size,char sign){
	bool check= false;
	if(sign=='+'){	
		if(x+size > grid_rows || x-size < 0 || y+size > grid_cols || y-size < 0){
			
			return check;
		}	
			
		else 
			return !check;		
	}
	else if(sign == 'x'){
		if(x+size > grid_rows || x-size < 0 || y+size > grid_cols || y-size < 0)	
			return check;
		else 
			return !check;	
	}
	else if(sign == '-'){
		if(y+size > grid_rows || y-size < 0) 
			return check;
		else
			return !check;
	}
	else if(sign == '/'){
		if(x+size > grid_rows || x-size < 0 || y+size > grid_cols || y-size < 0) 
			return check;
		else 
			return !check;
	}
	else
		return check;
	
}

